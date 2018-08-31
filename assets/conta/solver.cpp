#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

const string label_saque = "debito";
const string label_deposito = "deposito";
const string label_tarifa = "tarifa";
const string label_extorno = "extorno";
const string label_abertura = "abertura";

struct Operacao{


    int indice;
    string label;
    float value;
    float saldo;

    Operacao(int indice = 0, string label = "", float value = 0, float saldo = 0):
        indice(indice), label(label), value(value), saldo(saldo){
    }

    string toString(int indice){
        stringstream ss;
        ss <<  setprecision(2) << this->indice << ":"
            << setw(8)         << this->label  << ":" 
            << setprecision(5) << this->value  << ":" 
            << setprecision(6) << this->saldo;
        return ss.str();
    }
};

struct Conta{
    vector<Operacao> extrato;
    int numero;
    float saldo;

    Conta(int numero = 0):
        numero(numero), saldo(0)
    {
        pushOperacao(Operacao::label_abertura, 0, 0);
    }

    void pushOperacao(string label, float value, float saldo){
        static int nextOp = 0;
        extrato.push_back(Operacao(nextOp, label, value, saldo));
        nextOp += 1;
    }

    bool debitar(string label, float value){
        if(value <= 0){
            cout << "failure: valor invalido";
            return false;
        }
        if(value > this->saldo){
            cout << "failure: saldo insuficiente";
            return false;
        }
        this->saldo -= value;
        pushOperacao(label, -value, saldo));
        return true;
    }

    bool creditar(string label, float value){
        if(value <= 0){
            cout << "failure: valor invalido";
            return false;
        }
        this->saldo += value;
        pushOperacao(label, value, saldo);
        return true;
    }

    string toString(){
        stringstream ss;
        ss << "conta: " << this->numero << "saldo: " << this->saldo;
        return ss.str();
    }

    vector<Operacao> getExtrato(int n = 0){
        if(n == 0)
            n = extrato.size();
        vector<Operacao> saida;
        for(int i = (int) extrato.size - n; i < (int) extrato.size(); i++)
            saida.push_back(extrato[i]);
        return saida;
    }
};

struct Controller{
    Conta conta;

    string shell(string line){
        stringstream in(line);
        stringstream out;
        string op;
        in >> op;
        if(op == "show"){
            out << conta.toString();
        }else if(op == "nome"){
            int numero;
            in >> numero;
            conta = Conta(numero);
            out << "success";
        }else if(op == "saque"){
            float value;
            in >> value;
            if(conta.debitar(Operacao::label_saque, value))
                out << "success";
        }else if(op == "tarifa"){
            float value;
            in >> value;
            if(conta.debitar(Operacao::label_tarifa, value))
                out << "success";
        }else if(op == "deposito"){
            float value;
            in >> value;
            if(conta.creditar(Operacao::label_deposito, value))
                out << "success";
        }else if(op == "extornar"){
            float value;
            in >> value;
            if(conta.debitar(Operacao::label_tarifa, value))
                out << "success";
        }

        else if(op == "deposito"){
            int indice;
            in >> indice;
            if(conta.rm(indice))
                out << "success";
        }else if(op == "update"){
            string nome;
            in >> nome;
            conta = Conta(nome);
            string fone_serial;
            while(in >> fone_serial){
                stringstream ss(fone_serial);
                string label, fone;
                getline(ss, label, ':');
                getline(ss, fone);
                if(Operacao::validate(fone))
                    conta.add(Operacao(label, fone));
            }
            out << "success";
        }
        return out.str();
    }

    void exec(){
        string line;
        while(true){
            getline(cin, line);
            cout << "$" << line << endl;
            if(line == "end")
                return;
            cout << shell(line) << endl;
        }
    }
};

int main(){
    Controller c;
    c.exec();
    return 0;
}