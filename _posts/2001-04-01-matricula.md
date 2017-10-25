---
layout: post
title:  "Época de Matrícula"
category: 'Expert'
introduction: Oba, aceitaram minha matrícula em POO. Eita pitombas, foi com o David!
description: 
image: '/assets/04_1_matricula/figura.png'
tags:
- nxn
- repositórios
---

Vamos criar um sistema da cadastro de alunos e disciplinas. Após isso, vamos matricular e remover alunos das disciplinas. Aqui, cada aluno sabe quais as disciplinas em que está matriculado e a disciplina sabe os alunos que ela contém.

## Funcionalidades

### Repositórios Individuais - 3.0 P

- Adicionar aluno passando id do aluno.
- Mostrar os todos os alunos cadastrados.
- Adicionar disciplina passando o id da disciplina.
- Mostrar as todas as disciplinas cadastradas.

```
# adicionando alunos
addAlu alice
addAlu edson
addAlu bruno
showAllAlu
  [alice bruno edson]

# adicionando disciplinas
addDis poo
addDis aps
addDis fup
showAllDis
  [aps fup poo]
```

### Realizar Matrícula - 4 P

- Matricular o aluno em uma ou mais disciplinas.
- Mostrar as disciplinas de um aluno.
- Mostrar os alunos de uma disciplina.

```
# addAD _aluno _disc _disc ...
addAD bruno fup aps poo
addAD alice fup poo
addAD edson fup

showAlu bruno
  bruno [ aps fup poo ]
showDis fup
  fup [ alice bruno edson ]
```

### Remover matricula - 2.0 P

- Remover disciplinas de um aluno.

```
# rmAD _aluno _disc _disc ...
rmAD bruno poo aps

showAlu bruno
  bruno [ fup ]
showDis poo
  fup [ alice ]
```

### Removendo alunos do sistema - 1.0 P

- Remover aluno pela de uma disciplina.
    - Lembre de remover a entrada de aluno em cada uma de suas disciplinas.

```
#rmAlu _aluno
rmAlu bruno
showAlu bruno
  fail: aluno bruno nao existe
showDis fup
  fup [ alice edson ]
```

## Diagrama de Classes

![](/assets/04_1_matricula/diagrama.png)

## Testes


```
# adicionando alunos
addAlu alice
addAlu edson
addAlu bruno
showAllAlu
  [alice bruno edson]


# adicionando disciplinas
addDis poo
addDis aps
addDis fup
showAllDis
  [aps fup poo]


# addAD _aluno _disc _disc ...
addAD bruno fup aps poo
addAD alice fup poo
addAD edson fup
showAlu bruno
  bruno [ aps fup poo ]
showDis fup
  fup [ alice bruno edson ]


# rmAD _aluno _disc _disc ...
rmAD bruno poo aps
showAlu bruno
  bruno [ fup ]
showDis poo
  fup [ alice ]


# rmAlu _aluno
rmAlu bruno
showAlu bruno
  fail: aluno bruno nao existe
showDis fup
  fup [ alice edson ]
```


## Controller

- Versão em C++, adapte para sua linguagem.
- Link para classe repository.h e poo.h para POO EC: [GIST](https://gist.github.com/senapk/cfd93eb69f28c34eaa1981476e7a7bcf)

```c++
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include "alu_dis.h"
#include "poo.h"
#include "repository.h"
using namespace std;

string HELP = R"(
addAlu  _aluno
addDis  _disc
addAD   _aluno _disc _disc ...
showDis _disc
showAlu _aluno
rmAD    _aluno _disc _disc ...
showAllAlu
showAllDis
rmAlu   _aluno
)";

class Controller {
    Repository<Aluno> r_alu;
    Repository<Discp>  r_dis;
    RelAluDisc rel_ad;

public:
    Controller():
        r_alu("aluno"),
        r_dis("discp")
    {
    }

    string process(string line){
        auto ui = poo::split(line);
        auto cmd = ui[0];

        if(cmd == "help")
            return HELP;
        else if(cmd == "addAlu")
            r_alu.add(ui[1], Aluno(ui[1]));
        else if(cmd == "addDis")
            r_dis.add(ui[1], Discp(ui[1]));
        else if(cmd == "addAD")
            for(int i = 2; i < (int) ui.size(); i++)
                rel_ad.addAD(r_alu.get(ui[1]), r_dis.get(ui[i]));
        else if(cmd == "showAlu")
            return r_alu.get(ui[1])->toString();
        else if(cmd == "showDis")
            return r_dis.get(ui[1])->toString();
        else if(cmd == "rmAD")
            for(int i = 2; i < (int) ui.size(); i++)
                rel_ad.rmAD(r_alu.get(ui[1]), r_dis.get(ui[i]));
        else if(cmd == "showAllAlu"){
            string saida = "Alunos [ ";
            for(auto aluno : r_alu.values())
                saida += aluno.nome + " ";
            return saida + "]";
        }else if(cmd == "showAllDis"){
            string saida = "Disc [ ";
            for(auto disc : r_dis.values())
                saida += disc.nome + " ";
            return saida + "]";
        }else if(cmd == "rmAlu"){
            auto aluno = r_alu.get(ui[1]);
            for(auto disc : aluno->getAllDis())
                rel_ad.rmAD(aluno, disc);
            r_alu.rm(ui[1]);
        }else if(cmd == "fim")
            return "";
        else
            return "comando invalido";
        return "done";
    }

    void commandLine() {
        std::cout << "Digite help, cmd ou fim:" << std::endl;
        string line = "";
        while(line != "fim"){
            line = poo::getCmd();//pega uma linha valida
            std::cout << line << std::endl; //mostra o comando
            try {
                string resp = this->process(line);
                std::cout << poo::tab2(resp) << std::endl;
            } catch(const std::string& e) {
                std::cout << e << std::endl;
            }
        }
    }
};
#endif
```