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
- **[4.0] Comendo, Jogando, Dormindo e tomando banho**
    - Cada operação causa aumento e reduções nos atributos.
    - Nenhum atributo pode passar do máximo ou ir abaixo de 0
- **[4.0] Morrendo**
    - Se algum atributo chegar a 0, o pet morre e nenhuma ação pode ser feita a não ser mostrar os dados.

---

## Exemplo

```bash
#__begin__
#$init energy hungry clean
$init 20 10 15

$show
#Energy Hungry Clean Diamonds Age
E:20/20, H:10/10, C:15/15, D:0, A:0

# play - Brincar 
# diminui 2 na energia, 1 na fome, 3 na limpeza
# aumenta 1 na idade e 1 diamante
$play
$show
E:18/20, H:9/10, C:12/15, D:1, A:1
$play
$show
E:16/20, H:8/10, C:9/15, D:2, A:2

# eat - Comer 
# diminui 1 na energia, 2 na limpeza
# aumenta 4 na fome, 1 na idade
# e pet pode comer o quanto quiser, mas a fome nunca vai ultrapassar o limite maximo
$eat
$show
E:15/20, H:10/10, C:7/15, D:2, A:3

# sleep - Dormir
# diminui 1 na fome
# aumenta energia até o máximo e idade aumenta do número de turnos que o pet dormiu
# no caso anterior atual, ele vai recuperar 5 de energia, então vai dormir 5 turnos
$sleep
$show
E:20/20, H:9/10, C:7/15, D:2, A:8

# clean - tomar banho
# diminui 1 na fome e 3 na energia
# aumenta 2 na idade e limpeza até o máximo
$clean
$show
E:17/20, H:8/10, C:15/15, D:2, A:10

# Para dormir, precisa ter perdido pelo menos 5 unidades de energia
$sleep
fail: nao esta com sono

# Se algum atributo atingir 0, o pet morre e não poderá executar nenhuma ação
$play
$play
$play
$play
$show
E:9/20, H:4/10, C:3/15, D:6, A:14
$play
fail: pet morreu de sujeira
$show
E:7/20, H:3/10, C:0/15, D:7, A:15
$play
fail: pet esta morto
$eat
fail: pet esta morto
$clean
fail: pet esta morto
$sleep
fail: pet esta morto


# Exemplo 2
$init 5 10 10
$play
$play
$play
fail: pet morreu de fraqueza
$play
fail: pet esta morto
$show
E:0/5, H:7/10, C:1/10, D:3, A:3

# Exemplo 3
$init 10 3 10
$play
$play
$play
fail: pet morreu de fome
$play
fail: pet esta morto
$show
E:4/10, H:0/3, C:1/10, D:3, A:3

$end
#__end__
```