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

# loja online

 #addPr idProd preco
addPr veja 3.50
addPr bombril 4.00
addPr rodo 15.00
addPr balde 2.00
addPr limpol 5.00

addPacote  pacbalde rodo balde balde
addPromo   bombombril bombril 30
addPacote  paclimpeza limpol veja bombombril
addPromo   promolimpeza paclimpeza 20

 #addEst idProd qtd
addEstoque veja 10
addEstoque rodo 5
addEstoque balde 2
addEstoque limpol 50
addEstoque bombril 10

addEstante bombril bombombril pacbalde promolimpeza

comprar bombril

verEstante



```



Item (Produto, ItemDesc, Pacote)
Class ItemEstoque
    Produto
    qtd
Estoque
    List<ItemEstoque>
Estante
    List<Item>