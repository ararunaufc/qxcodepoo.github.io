#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H
#include <sstream>
#include <iostream>

using namespace std;


enum Tipo {PESSOA, ANIMAL};

class Passageiro
{
protected:
    Tipo tipo;
    int id;
public:
    Passageiro(int id):
        id(id)
    {}
    int getId(){
        return id;
    }

    virtual Tipo getTipo(){
        return tipo;
    }
    virtual ~Passageiro(){
    }

    virtual string toString() = 0;
};

class Pessoa : public Passageiro{
    string nome;
public:
    Pessoa(int id, string nome):
        Passageiro(id)
    {
        this->nome = nome;
        tipo = PESSOA;
    }
    string getNome(){
        return nome;
    }
    string toString(){
        stringstream ss;
        ss << id << " "  << nome;
        return ss.str();
    }

};

#endif // PASSAGEIRO_H


















