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
## Funcionalidades

- **[1.0 P] Iniciando a calculadora** 
    - Ao iniciar, sua calculadora estará com a bateria vazia.
- **[1.0 P] Mostrar bateria da calculadora**
- **[2.0 P] Recarregar a bateria**
    - Ao recarregar a bateria, deverá ser passado por parâmetro a quantidade de carga. O máximo de carga que a bateria suporta é 5 unidades.
- **[2.0 P] Realizar operações matemáricas**
    - Soma e divisão. Cada operação consome 1 unidade de carga da bateria.
- **[2.0 P] Notificar sobre erros**
    - Se o usuário tentar realizar operações e a bateria estiver com carga 0, deverá ser mostrada uma notificação sobre falta de bateria.
    - Se o resultado da divisão for zero, deve ser notificado o erro.

---
## Exemplos

```bash
#__begin__
#######################################
# Mostrar a bateria da calculadora
#######################################

$show
battery = 0
$charge 3
success
$show
battery = 3
$sum 4 3
= 7.0
$div 8 2
= 4.0
$show
battery = 1
$sum 8 9
= 17.0
$show
battery = 0
$sum 4 3
failure: bateria insuficiente
$charge 10
success
$show
battery = 5


#######################################
# Dividindo
#######################################
$div 6 3
= 2.0
$div 7 0
failure: divisao por zero
$show
battery = 3
$div 7 2
= 3.5
$end
#__end__
```

---
## Raio X

```java
class Calculadora  
+ battery: int
+ maxBattery: int
--
+ charge(value: int): void
+ useBattery(): void
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

[C++](https://github.com/qxcodepoo/qxcodepoo.github.io/tree/master/assets/calculadora/solver.cpp)

[java](https://github.com/qxcodepoo/qxcodepoo.github.io/tree/master/assets/calculadora/Controller.java)

