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

show
  bateria = 2
soma 4 3
  = 7
sub 16 8
  = 8
mult 2 6
  = 12
div 8 2
  = 4
show
  bateria = 1
soma 8 9
  = 17
show
  bateria = 0
soma 4 3
  bateria insuficiente

#######################################
# Recarregando
#######################################

soma 1 1
  fail: bateria insuficiente
charge 10
  done
show
  bateria = 5
div 6 3
  = 2

#######################################
# Dividindo
#######################################

div 7 0
  fail: divisao por zero
show
  bateria = 3
div 7 2
  = 3.5
end
###END
```

---
## Raio X

```java
class Calculadora  
+ battery: int
+ maxBattery: int
--
+ charge(value: int): void
+ soma(a: float, b: float): float
+ sub(a: float, b: float): float
+ mult(a: float, b: float): float
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
