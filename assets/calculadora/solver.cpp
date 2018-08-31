#include <iostream>
#include <sstream>
#include <iomanip> //setprecision
using namespace std;

struct Calc{
    int bateria;
    int limiteBateria;

    Calc(){
        this->limiteBateria = 5;
        this->bateria = 0;
    }
    void charge(int carga){
        bateria += carga;
        if(bateria > limiteBateria)
            bateria = limiteBateria;
    }
    void gastarBateria(){
        if(bateria <= 0)
            throw "failure: bateria insuficiente";
        this->bateria -= 1;
    }
    float soma(float a, float b){
        gastarBateria();
        return a + b;
    }
    float div(float a, float b){
        gastarBateria();
        if(b == 0)
            throw "failure: divisao por zero";
        return a/b;
    }
};


struct Controller{
    Calc calc;

    string shell(string line){
        stringstream out;
        stringstream in(line);
        string op;
        in >> op;
        if(op == "help"){
            out << "sum _a _b; div _a _b; show; charge _carga; end";
        }else if(op == "sum"){
            float a, b;
            in >> a >> b;
            out << "= " << fixed << setprecision(1) << calc.soma(a, b);
        }else if(op == "div"){
            float a, b;
            in >> a >> b;
            out << "= " << fixed << setprecision(1) << calc.div(a, b);
        }else if(op == "charge"){
            float charge;
            in >> charge;
            calc.charge(charge);
            out << "success";
        }else if(op == "show"){
            out << "battery = " << calc.bateria;
        }else 
            out << "failure: comando invalido";
        return out.str();
    }
};

int main(){
    Controller c;
    string line;
    while(true){
        getline(cin, line);
        cout << "$" << line << endl;
        if(line == "end")
            break;
        try{
            cout << c.shell(line) << endl;
        }catch(const char* error){
            cout << error << endl;
        }
    }
    return 0;
}