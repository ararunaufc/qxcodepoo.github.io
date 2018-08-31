#include <iostream>
#include <cstdio>
#include <clocale>
#include <sstream>

using namespace std;

struct Carro{
    int pass; // Passageiros
    int passMax; // limite de Passageiros
    float gas; // tanque
    float gasMax; // limite do tanque
    float km; // quantidade de quilometragem

    Carro(int pass = 0, int passMax = 2, float gas = 0,float gasMax = 10,float km = 0){
        this->pass = pass; // Passageiros
        this->passMax = passMax; // limite de Passageiros
        this->gas = gas; // tanque
        this->gasMax = gasMax; // limite do tanque
        this->km = km; // quantidade de quilometragem
    }

    string toString(){
        stringstream saida;
        saida << "pass: " << pass << ", gas: " << gas << ", km: " << km; //nao endl
        return saida.str();
    }

    bool in(){
        if (pass < passMax){
            pass += 1;
            return true;
        }
        cout << "failure: limite de pessoas atingido";
        return false;
    }

    bool out(){
        if (pass > 0){
            pass-=1;
            return true;
        }
        cout << "failure: nao ha ninguem no carro";
        return false;
    }
    
    void fuel(float gas){
        this->gas += gas;
        if(this->gas > gasMax)
            this->gas = gasMax;
    }

    bool drive (float km){
        if(this->pass == 0){
            cout << "failure: nao ha ninguem no carro";
        }
        else if(this->gas < (km / 10)){
            cout << "failure: gasolina insuficiente";
        }else{
            this->gas = gas - km / 10;
            this->km = this->km + km;
            return true;
        }
        return false;
    }    
};

struct Controller{
    Carro car;

    string shell(string line){
        stringstream in(line);
        stringstream out;
        string op;
        in >> op;
        if(op == "help")
            out << "in; out; show; fuel _gat; drive _km";
        else if(op == "in"){
            if(car.in())
                out << "success";
        }else if(op == "out"){
            if(car.out())
                out << "success";
        }else if(op == "show"){
            out << car.toString();
        }else if (op == "drive"){
            float km;
            in >> km;
            if(car.drive(km))
                out << "success";
        }else if (op == "fuel"){
            float gas;
            in >> gas;
            car.fuel(gas);
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
    setlocale(LC_ALL, "Portuguese");
    Controller c;
    c.exec();
    return 0;
}

