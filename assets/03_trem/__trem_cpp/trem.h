#ifndef TREM_H
#define TREM_H

#include "locomotiva.h"
#include "vagao.h"
#include "passageiro.h"
#include <vector>

class Trem
{
    Locomotiva * loc;
    vector<Vagao *> vagoes;
public:
    Trem(Locomotiva * loc)
    {
        this->loc = loc;
    }
    void addVagao(Vagao * v){
        if((int) vagoes.size() < loc->getMaxVagoes())
            vagoes.push_back(v);
    }
    bool embarcar(Passageiro * p){
        for(Vagao * v : vagoes)
            if(v->embarcar(p))
                return true;
        return false;
    }

    Passageiro * desembarcar(int id){
        for(Vagao * v : vagoes){
            auto p = v->desembarcar(id);
            if(p != nullptr)
                return p;
        }
        return nullptr;
    }

    void show(){
        cout << "{";
        for(Vagao * v : vagoes)
            v->show();
        cout << "}\n";
    }
};

#endif // TREM_H
















