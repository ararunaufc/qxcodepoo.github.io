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

- **[2.0 P] Inicializando.** 
    - Realizar operações de soma substração e mostrar o resultado.
- **[2.0 P] Colocando bateria.**
    - Mostrar a bateria da calculadora.
    - Diminuir a bateria em uma unidade em cada operação matemática realizada.
    - Recarregar a bateria passando a quantidade de carga como parâmetro.
        - A bateria tem carga máxima de 5 unidades.
- **[2.0 P] Acabando a bateria.**
  - Se não houver mais bateria, seu programa deve notificar o usuário e não dar a resposta da operação matemática.
- **[2.0 P] Divisão.**
- Efetuar operações de divisão. 
    - Se houver divisão por 0, notifique o usuario. Mesmo que não haja resultado, essa divisão ainda consome uma unidade de bateria.


```python

#######################################
# Inicializando
#######################################
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

#######################################
# Recarregando
#######################################

soma 1 1
  fail: bateria insuficiente
charge 10
  done
show
  bateria: 5
div 6 3
  = 2

#######################################
# Dividindo
#######################################

div 7 0
  fail: divisao por zero
show
  bateria: 3
div 7 2
  = 3.5
div 7 1
  = 7
div 4 2
  fail: bateria insuficiente
```

---
## Raio X

```java
class Calculadora  
+ battery: int
+ maxBattery: int
--
+ charge(value: int): void //recarrega
+ useBattery();            //usa uma unidade de bateria
+ sum(a: float, b: float): float
+ div(a: float, b: float): float
--
+ constructor(batteryMax)
+ getBattery()

class Controller
- calc: Calculadora
--
+ shell(line: String): String //encaminha as perguntas e devolve as respostas
--
+ main() //responsavel pelo loop
```

---
## Resposta

[Java](https://github.com/qxcodepoo/qxcodepoo.github.io/tree/master/assets/calculadora/Controller.java)
