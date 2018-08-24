#include <iostream>
using namespace std;

struct Calc{
    int bateria;
    int limiteBateria;

    Calc(){
        this->limiteBateria = 5;
        this->bateria = 2;
    }
    void charge(int carga){
        bateria += carga;
        if(bateria > limiteBateria)
            bateria = limiteBateria;
    }
    void gastarBateria(){
        if(bateria <= 0)
            throw "fail: bateria insuficiente";
        this->bateria -= 1;
    }
    float soma(float a, float b){
        gastarBateria();
        return a + b;
    }
    float div(float a, float b){
        gastarBateria();
        if(b == 0)
            throw "fail: divisao por zero";
        return a/b;
    }
};

#include <sstream>
template <class T>
T get(stringstream& ss){
    T t;
    ss >> t;
    return t;
}

struct Controller{
    Calc calc;

    string shell(string line){
        stringstream out;
        stringstream ui(line);
        string op = get<string>(ui);
        if(op == "help"){
            out << "sum _a _b; div _a _b; show; charge _carga; end";
        }else if(op == "soma"){
            float a, b;
            ui >> a >> b;
            out << "= " << calc.soma(a, b);
        }else if(op == "div"){
            float a, b;
            ui >> a >> b;
            out << "= " << calc.div(a, b);
        }else if(op == "charge"){
            calc.charge(get<int>(ui));
            out << "done";
        }else if(op == "show"){
            out << "bateria = " << calc.bateria;
        }else 
            out << "fail: comando invalido";
        return out.str();
    }
};

int main(){
    Controller c;
    string line;
    while(true){
        getline(cin, line);
        cout << line << endl;
        if(line == "end")
            break;
        try{
            cout << "  " << c.shell(line) << endl;
        }catch(const char* error){
            cout << error << endl;
        }
    }
    return 0;
}