---
layout: post
title:  "Calculadora"
category: 'Novice' 
introduction: Vamos somar, dividir e lançar excessões.
description:
image: '/assets/calculadora/figura.jpg'
tags:
- base
---

O objetivo dessa atividade é implementar uma calculadora a bateria. Se há bateria, ela executa operações de soma, multiplicação e divisão. É possível também mostrar a quantidade de bateria e recarregar a calculadora. Ela avisa quando está sem bateria e se há tentativa de divisão por 0.

Nessa atividade, você deverá criar três classes. 
- A classe Calculadora que realiza as operações e lança excessões caso a bateria acabe ou haja divisão por 0. A Classe Calculadora não se comunica diretamente com o usuário através de comandos de print. Ela apenas executa cálculos e retorna resultados. 
- A segunda classe é um Controlador que implementa o shell que processa perguntas em respostas.
- A terceira classe é quem faz a interface com o usuário que faz entrada e saída. 

---
## [Run](/assets/calculadora/main.html)


---
## Funcionalidades
Seu sistema deverá:

### Parte 1

- Iniciar a calculadora. 
    - Ao iniciar, sua calculadora terá bateria para efetuar duas operações matemáticas.
- Mostrar a bateria da calculadora.
- Recarregar a bateria passando como parametro a quantidade de carga.
    - O máximo de carga que a bateria suporta é cinco unidades.
- Realizar operações de soma.

```
show
  bateria: 2
soma 4 3
  = 7
show
  bateria: 1
soma 8 9
  = 17 
show
  bateria: 0
```

### Parte 2

- Se não houver mais bateria, notifique o usuário, lançando uma excessão.
- Efetue operações de divisão. 
    - Se houver divisão por 0, notifique o usuario.

```
soma 1 1
  fail: bateria insuficiente
charge 10
  done
show
  bateria: 5
div 6 3
  = 2
div 7 0
  fail: divisao por zero
show
  bateria: 3
```

---
## Raio X

```c++
class Calculadora  
  + bateria: int
  --
  + charge(value: int): void
  + soma(a: float, b: float): float
  + div(a: float, b: float): float
  --
  + constructor, toString
```


---
## Soluções

[Java](/assets/calculadora/java)

[Python](/assets/calculadora/python)
