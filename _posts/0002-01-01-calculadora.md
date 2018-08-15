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


---
## [Run](/assets/calculadora/main.html)


---
## Funcionalidades

<<<<<<< HEAD
- **[0 P] Iniciando a calculadora** 
    - Ao iniciar, sua calculadora terá bateria para efetuar duas operações matemáticas
- **[0 P] Mostrar bateria da calculadora**
- **[0 P] Recarregar a bateria**
    - Ao recarregar a bateria, deverá ser passado por parâmetro a quantidade de carga. O máximo de carga que a bateria suporta é 5 unidades.
- **[0 P] Realizar operações matemáricas**
    - Soma, subtração, divisão e multiplicação. Cada operação consome 1 unidade de carga da bateria.
- **[0 P] Notificar sobre falta de bateria**
    - Se o usuário tentar realizar operações e a bateria estiver com carga 0, deverá ser mostrada uma notificação sobre falta de bateria.
    
---

## Exemplos

```python
#######################################
# Mostrar a bateria da calculadora
#######################################

=======
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
>>>>>>> 6cd2e58ed5c474da71bcfeeba4937c0086fe3b7f
show
  bateria: 2

#######################################
# Recarregar a bateria
#######################################

charge 10
  done
show
  bateria: 5

#######################################
# Realizar operações matemáricas
#######################################

soma 4 3
  = 7
sub 16 8
  = 8
mult 2 6
  = 12
div 8 2
  = 4
show
  bateria: 1

#######################################
# Notificar sobre falta de bateria
#######################################

show
  bateria: 0

<<<<<<< HEAD
soma 4 3
  bateria insuficiente

=======
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
>>>>>>> 6cd2e58ed5c474da71bcfeeba4937c0086fe3b7f
```

---
## Raio X

```java
class Calculadora  
+ battery: int
+ maxBattery: int
--
<<<<<<< HEAD
+ charge(value: int): void
+ soma(a: float, b: float): float
+ sub(a: float, b: float): float
+ mult(a: float, b: float): float
=======
+ charge(value: int): void //recarrega
+ useBattery();            //usa uma unidade de bateria
+ sum(a: float, b: float): float
>>>>>>> 6cd2e58ed5c474da71bcfeeba4937c0086fe3b7f
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
