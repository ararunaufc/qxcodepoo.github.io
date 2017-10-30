---
layout: post
title:  "Época de Matrícula"
category: 'Expert'
introduction: Oba, aceitaram minha matrícula em POO. Eita pitombas, foi com o David!
description: 
image: '/assets/matricula/figura.png'
tags:
- nxn
- repositórios
---

Vamos criar um sistema da cadastro de alunos e disciplinas. Após isso, vamos matricular e remover alunos das disciplinas. Aqui, cada aluno sabe quais as disciplinas em que está matriculado e a disciplina sabe os alunos que ela contém.

## Funcionalidades

- **Repositórios Individuais - 3.0 P**
    - Adicionar aluno passando id do aluno.
    - Mostrar os todos os alunos cadastrados.
    - Adicionar disciplina passando o id da disciplina.
    - Mostrar as todas as disciplinas cadastradas.
- **Realizar Matrícula - 4 P**
    - Matricular o aluno em uma ou mais disciplinas.
    - Mostrar as disciplinas de um aluno.
    - Mostrar os alunos de uma disciplina.
- **Desmatricular - 2.0 P**
    - Remover disciplinas de um aluno.
- **Removendo alunos do sistema - 1.0 P**
    - Remover aluno mantendo a integridade do sistema.


## Testes

```
#######################################
# adicionando alunos
#######################################

addAlu alice
addAlu edson
addAlu bruno
showAllAlu
  [alice bruno edson]

#######################################
# adicionando disciplinas
#######################################
addDis poo
addDis aps
addDis fup
showAllDis
  [aps fup poo]

#######################################
# matriculando
#######################################

# matric _aluno _disc _disc ...
matric bruno fup aps poo
matric alice fup poo
matric edson fup
showAlu bruno
  bruno [aps fup poo]
showDis fup
  fup [alice bruno edson]

#######################################
# desmatriculando
#######################################

# desmatric _aluno _disc _disc ...
desmatric bruno poo aps
showAlu bruno
  bruno [fup]
showDis poo
  poo [alice]

#######################################
# jubilando
#######################################

# rmAlu _aluno
rmAlu bruno
showAlu bruno
  fail: aluno bruno nao existe
showDis fup
  fup [alice edson]


```

## Diagrama de Classes

![](/assets/matricula/diagrama.png)

## Orientacoes

Temos algumas complicações aqui. Vamos fazer a matricula chamando
adicionar aluno em disciplina ou chamando adicionar disciplina na
class aluno?

Precisamos manter as informações em ambas as entidades. Uma possibilidade
é manter as listas públicas e implementar o método de inserir apenas
em uma das entidades. Assim o método pode fazer alterações em ambas
as listas.

Em c++, temos a funcionalidade do friend, que permite deixar as listas
privadas e dar acesso apenas à classe que queremos permitir modificar as
listas.

Uma outra forma mais trabalhosa, porém mais segura é permitir matrícula
vindo de qualquer uma das classes e colocar alguns controles para evitar
o loop. É assim que está apresentado à seguir, mas sinta-se livre para
usar o método que preferir para executar o exercício.

Obs: em java você pode atribuir visibilidade de pacote, o que garante que
fora do pacote, nenhuma classe terá acesso à variável. Você pode também
utilizar a notação do python com __ na frente da variável. Essa notação
significa dizer "olhar a variável/método é público, mas eu sugiro veementemente
que você não mexa nele".

``` python
class Discp:
    m_aluno #mapa<id, Aluno>
    idDiscp #nome da disciplina;

    def constructor(nome)
        # inicialize todos os atributos

    def matricular(aluno)
        # se ja tem o aluno em m_aluno
            # retorne
        # adicione o aluno em m_aluno
        # chame aluno.addDisc

    def desmatricular(idAluno)
        # tente pegar o aluno em m_aluno
        # se aluno nao existe
            # retorne
        # remova aluno de m_aluno
        # chame aluno.rmDisc
    
    def getAllAlu()
        # retorna o array de alunos da disciplina

    def toString()
        # o nome da disciplina

class Aluno:
    m_discp #a lista que guarda os alunos
    # sugiro que implemente como Map<string, Discp>

    idAluno #nome do aluno

    def constructor(idAluno)
        # inicialize TODAS as variavies

    def matricular(discp)
        # aqui vai o MESMO codigo de insercao disciplina
        # so que utilizando as variaveis de Aluno

    def desmatricular(idDiscp)
        # o mesmo codigo de remover de disciplina refletido

    def toString()
        # retorna o nome do aluno

```

