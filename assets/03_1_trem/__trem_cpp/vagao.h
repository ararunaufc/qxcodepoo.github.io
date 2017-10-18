#ifndef VAGAO_H
#define VAGAO_H

#include "passageiro.h"
#include <vector>

using namespace std;

#include <vector>
#include <map>

class Vagao
{
protected:
    int id;
    vector<Passageiro *> pass;
public:
    Vagao(int id):
        id(id)
    {
    }
    virtual bool embarcar(Passageiro * pa) = 0;
    virtual Passageiro * desembarcar(int id) = 0;
    virtual void show(){
        cout << " ";
        for(Passageiro * pa : pass){
            if(pa != nullptr)
                cout << pa->toString();
            else
                cout << "_ ";
        }
    }

};

class VagaoPessoas : public Vagao{
    int capacidade;
    int qtd {0};
public:
    VagaoPessoas(int id, int capacidade):
        Vagao(id), capacidade(capacidade){
        for(int i = 0; i < capacidade; i++)
            pass.push_back(nullptr);
    }

    bool embarcar(Passageiro *pa){
        if(pa->getTipo() != PESSOA)
            return false;
        if(qtd == capacidade)
            return false;
        for(int i = 0; i < (int)pass.size(); i++){
            if(pass[i] == nullptr){
                pass[i] = pa;
                qtd++;
                break;
            }
        }
        return true;
    }

    virtual Passageiro* desembarcar(int id){
        Passageiro * aux = nullptr;
        for(int i = 0; i < (int)pass.size(); i++){
            if(pass[i] != nullptr && pass[i]->getId() == id){
                aux = pass[i];
                pass[i] = nullptr;
                qtd--;
            }
        }
        return aux;
    }


    virtual void show(){
        cout << "(";
        Vagao::show();
        cout << ")";
    }


};

#endif // VAGAO_H














