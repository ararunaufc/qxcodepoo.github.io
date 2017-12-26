---
layout: post
title:  "Mercantil"
category: 'Expert'
introduction: Sistema de guardar anotações com vários usuários e várias notas.
description: 
image: '/assets/mercantil/figura.jpg'
tags:
- interfaces
- padrão composite
- padrão decorator
---
```
# Parte 1: adicionar produtos mostrando individualmente
# addProd idProd preco descricao
# o idProd deve ser unico
addProd mouse 25.00 mouse gamer
addProd pen32 30.00 pendrive kingston 32Gb
addProd noteL 2500  notebook lenovo

# loja online

addPr veja 3.50
addPr bombril 4.00
addPr rodo 15.00
addPr balde 2.00
addPr limpol 5.00

addEstoque veja 10
addEstoque rodo 5
addEstoque balde 2
addEstoque bombril 1
addEstoque limpol 30

addPacote  rbalde rodo 1 balde 2
addPromo   bombombril bombril 30
addPacote  limp5 limpol 5
addPromo   promolimp5 limp5 20


addEstante veja
addEstante rbalde
addEstante bombombril
addEstante promolimp5

verEstante



```