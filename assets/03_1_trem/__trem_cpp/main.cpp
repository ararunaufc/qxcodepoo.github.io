#include <iostream>

#include "locomotiva.h"
#include "vagao.h"
#include "passageiro.h"
#include "trem.h"

using namespace std;


int main()
{
    Locomotiva loc(3);
    Trem trem(&loc);
    VagaoPessoas v1(1, 3);
    VagaoPessoas v2(2, 2);
    VagaoPessoas v3(3, 4);

    trem.addVagao(&v1);
    trem.addVagao(&v2);

    Pessoa * p1  = new Pessoa(1, "");
    Pessoa p2(2, "");
    Pessoa p3(3, "");
    Pessoa p4(4, "");
    Pessoa p5(5, "");
    Pessoa p6(6, "");
    Pessoa p7(7, "");
    Pessoa p8(8, "");
    Pessoa p9(9, "");

    trem.embarcar(&p9);
    trem.embarcar(&p2);
    trem.embarcar(&p3);
    trem.embarcar(&p4);
    trem.embarcar(&p5);

    trem.addVagao(&v3);
    trem.embarcar(p1);
    trem.show();


    auto p = trem.desembarcar(4);

    trem.show();
    trem.embarcar(&p6);
    trem.show();
    trem.embarcar(p);
    p = trem.desembarcar(1);
    delete(p);
    trem.show();


    cout << "Hello World!" << endl;
    return 0;
}

