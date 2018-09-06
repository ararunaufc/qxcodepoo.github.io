---
layout: post
title:  "Tamagotchi - Seu Pet Virtual"
category: 'Novice' 
introduction: Comida, limpeza, energia e diversão.
description:
image: '/assets/tamagotchi/figura.jpg'
tags:
- base
---

Você deve implementar um simulador de bichinho virtual. Ele poderá comer, brincar, dormir e tomar banho.
E eventualmente morrerá, se você não cuidar bem dele.

---

## Funcionalidades
Seu sistema deverá:

- **[3.0] Inicializar**
    - passando saciedade, energia e limpeza máximas do pet.
    - Todos os níveis devem ser iniciados no máximo na criação do pet.
    - Os outros atributos diamantes, que ele vai ganhar jogando e idade, ambos iniciando em 0.
- **[4.0] Comendo, Jogando, Dormindo**
- **[4.0] Morrento**

---

## Exemplo

```bash
#__begin__
#$init energy hungry clean
$init 20 10 15

$show
#Energy Hungry Clean Diamonds Age
E:20/20, H:10/10 C:15/15, D:0, A:0

# play - Brincar 
# diminui 2 na energia, 1 na fome, 3 na limpeza
# aumenta 1 na idade e 1 diamante
$play
$show
E:18/20, H:9/10, C:12/15, D:1, A:1
$play
$show
E:16/20, H:8/10, C:9/15, D:1, A:2

# eat - Comer 
# diminui 1 na energia, 2 na limpeza
# aumenta 4 na fome, 1 na idade
# e pet pode comer o quanto quiser, mas a fome nunca vai ultrapassar o limite maximo
$eat
$show
E:15/20, H:10/10, C:7/15, D:1, A:3

# sleep - Dormir
# diminui 1 na fome
# aumenta energia até o máximo e idade aumenta do número de turnos que o pet dormiu
# no caso anterior atual, ele vai recuperar 5 de energia, então vai dormir 5 turnos
$sleep
$show
E:20/20, H:9/10, C:7/15, D:1, A:8

# clean - tomar banho
# diminui 1 na fome e 3 na energia
# aumenta 2 na idade e limpeza até o máximo
$clean
$show
E:17/20, H:8/10, C:15/15, D:1, A:10

# Para dormir, precisa ter perdido pelo menos 5 unidades de energia
$sleep
fail: nao esta com sono

# Se algum atributo atingir 0, o pet morre e não poderá executar nenhuma ação
$play
$play
$play
$play
$show

$play
fail: pet morreu de sujeira com 15 turnos de idade
$eat
fail: pet esta morto
$clean
fail: pet esta morto
$sleep
fail: pet esta morto

#__end__
```