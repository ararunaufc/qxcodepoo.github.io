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

```
addAlu _name _name ...
addAlu alice edson bruno
showAllAlu
  [alice bruno edson]

addDis poo aps
addDis fup
showAllDis
  [aps fup poo]
```

- **Realizar Matrícula - 4 P**
    - Matricular o aluno em uma ou mais disciplinas.
    - Mostrar as disciplinas de um aluno.
    - Mostrar os alunos de uma disciplina.

```
# matric _aluno _disc _disc ...
matric bruno fup aps poo
matric alice fup poo
matric edson fup
showAlu bruno
  bruno [aps fup poo]
showDis fup
  fup [alice bruno edson]
```
- **Desmatricular - 2.0 P**
    - Remover disciplinas de um aluno.

```
# desmatric _aluno _disc _disc ...
desmatric bruno poo aps
showAlu bruno
  bruno [fup]
showDis poo
  poo [alice]
```
- **Removendo alunos do sistema - 1.0 P**
    - Remover aluno mantendo a integridade do sistema.

```
# rmAlu _aluno
rmAlu bruno
showAlu bruno
  fail: aluno bruno nao existe
showDis fup
  fup [alice edson]
```

## Diagrama de Classes

![](/assets/matricula/diagrama.png)

## Guide
[Guide](/assets/matricula/guide)