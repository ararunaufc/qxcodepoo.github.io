#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Cliente{
    string id;
    string fone;

    Cliente(string id = "", string fone = ""){
        this->id = id;
        this->fone = fone;
    }
    string toString(){
        stringstream ss;
        ss << this->id << ":" << this->fone;
        return ss.str();
    }
};

struct Sala{
    vector<Cliente*> cadeiras;

    Sala(int qtd = 0):
        cadeiras(qtd, nullptr)
    {
    }

    ~Sala(){
        for(Cliente * cli : cadeiras)
            delete(cli);
    }

    bool reservar(string id, string fone, int ind){
        int qtd = cadeiras.size();
        if((ind < 0) || (ind >= qtd)){
            cout << "failure: cadeira nao existe";
            return false;
        } 
        if(cadeiras[ind] != nullptr){ 
            cout << "failure: cadeira ja esta ocupada"; 
            return false;
        }
        for(int i = 0; i < (int) cadeiras.size(); i++){
            if((cadeiras[i] != nullptr) && (cadeiras[i]->id == id)){
                cout << "failure: cliente ja esta no cinema";
                return false;
            }
        }
        cadeiras[ind] = new Cliente(id, fone);
        return true;
    }

    bool cancelar(string id){
        for(int i = 0; i < (int) cadeiras.size(); i++){
            if(cadeiras[i] != nullptr && cadeiras[i]->id == id){
                delete cadeiras[i];
                cadeiras[i] = nullptr;
                return true;
            }
        }
        cout << "failure: cliente nao esta no cinema";
        return false;
    }

    string toString(){
        stringstream ss;
        ss << "[ ";
        for(Cliente * cliente : cadeiras)
            if(cliente != nullptr)
                ss << cliente->toString() << " ";
            else
                ss << "- ";
        ss << "]";
        return ss.str();
    }
};

struct Controller{
    Sala sala;

    string shell(string line){
        stringstream in(line);
        stringstream out;
        string op;
        in >> op;
        if(op == "show"){
            out << sala.toString();
        }else if(op == "init"){
            int qtd;
            in >> qtd;
            sala = Sala(qtd);
            out << "success";
        }else if(op == "reservar"){
            string id, fone;
            int ind;
            in >> id >> fone >> ind;
            if(sala.reservar(id, fone, ind))
                out << "success";
        }else if(op == "cancelar"){
            string id;
            in >> id;
            if(sala.cancelar(id))
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