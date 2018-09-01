#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

namespace Label{
    const string saque = "saque";
    const string deposito = "deposito";
    const string tarifa = "tarifa";
    const string extorno = "extorno";
    const string abertura = "abertura";
}

struct Operacao{
    enum Label {debito, deposito, tarifa, extorno, abertura};
    int indice;
    string label;
    float value;
    float saldo;

    Operacao(int indice = 0, string label = "", float value = 0, float saldo = 0):
        indice(indice), label(label), value(value), saldo(saldo){
    }

    string toString(){
        stringstream ss;
        ss <<  setw(2) << this->indice << ":"
            << setw(9) << this->label  << ":" 
            << setw(5) << this->value  << ":" 
            << setw(5) << this->saldo;
        return ss.str();
    }
};

struct Conta{
    vector<Operacao> extrato;
    int numero;
    float saldo;
    int nextOp;
    Conta(int numero = 0):
        numero(numero), saldo(0), nextOp(0)
    {
        pushOperacao(Label::abertura, 0);
    }

    void pushOperacao(string label, float value){
        saldo += value;
        extrato.push_back(Operacao(nextOp, label, value, saldo));
        nextOp += 1;
    }

    bool debitar(string label, float value){
        if(value <= 0){
            cout << "failure: valor invalido" << endl;
            return false;
        }
        if(value > this->saldo){
            cout << "failure: saldo insuficiente" << endl;
            return false;
        }
        pushOperacao(label, -value);
        return true;
    }

    bool extornar(int indice){
        if(indice < 0 || indice >= (int) extrato.size()){
            cout << "failure: indice " << indice << " invalido" << endl;
            return false;
        }
        if(extrato[indice].label != Label::tarifa){
            cout << "failure: indice " << indice << " nao e tarifa" << endl;
            return false;
        }
        pushOperacao(Label::extorno, -extrato[indice].value);
        return true;
    }

    bool creditar(string label, float value){
        if(value <= 0){
            cout << "failure: valor invalido" << endl;
            return false;
        }
        pushOperacao(label, value);
        return true;
    }

    string toString(){
        stringstream ss;
        ss << "conta:" << this->numero << " saldo:" << this->saldo;
        return ss.str();
    }

    vector<Operacao> getExtrato(int n = 0){
        if(n == 0)
            n = extrato.size();
        vector<Operacao> saida;
        for(int i = (int) extrato.size() - n; i < (int) extrato.size(); i++)
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
            out << conta.toString() << endl;
        }else if(op == "init"){
            int numero;
            in >> numero;
            conta = Conta(numero);
            out << "success" << endl;
        }else if(op == "saque"){
            float value;
            in >> value;
            if(conta.debitar(Label::saque, value))
                out << "success" << endl;
        }else if(op == "tarifa"){
            float value;
            in >> value;
            if(conta.debitar(Label::tarifa, value))
                out << "success" << endl;
        }else if(op == "deposito"){
            float value;
            in >> value;
            if(conta.creditar(Label::deposito, value))
                out << "success" << endl;
        }else if(op == "extornar"){
            float value;
            while(in >> value){
                if(conta.extornar(value)) //aqui precisa ser o cout.
                    cout << "success: indice " << value << " extornado" << endl;
            }
        }else if(op == "extrato"){
            for(auto& op : conta.getExtrato())
                out << op.toString() << endl;
        }else if(op == "extratoN"){
            int n;
            in >> n;
            for(auto& op : conta.getExtrato(n))
                out << op.toString() << endl;
        }else{
            out << "failure: operacao invalida" << endl;
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
            cout << shell(line);
        }
    }
};

int main(){
    Controller c;
    c.exec();
    return 0;
}