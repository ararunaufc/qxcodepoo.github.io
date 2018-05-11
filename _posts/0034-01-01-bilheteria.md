---
layout: post
title: "Bilheteria"
category: 'Adept'
introduction: 
description: Fazer vendas usando papel e caneta é coisa do passado. Você foi contratado para modernizar a bilheteria do seu bairro e trazer ela pro século XXI
image: '/assets/bilheteria/figura.jpg'
tags:
- agregação
- manager
- template
---

Você deve desenvolver um sistema para gerenciar as vendas de uma bilheteria de shows

---

## Requisitos

- Cadastrar uma pessoa pelo nome.
    - nome da pessoa é único
    - pessoa deve ter nome, idade e pode ou não ser estudante
- Mostrar todos os clientes

```
# addPessoa _nome _idade _estudante
addPessoa steve 32 nao
  done
addPessoa tony 43 sim
  done
addPessoa steve 24 sim
  fail: pessoa steve ja existe
showP
  [steve, 32, nao],
  [tony, 43, sim]

```

- Cadastrar evento pelo nome.
    - Assim como pessoa, nome do evento é único
    - Um evento pode ter vários setores
- Cadastrar setor pelo nome.
    - Setor tem nome e preço
    - Setores do MESMO EVENTO não podem ter o mesmo nome
- Mostrar evento e setores de um evento cadastrados

```
# addEvento _nome
addEvento orappa
  done
#addSetor _nome-evento _nome _preco
addSetor orappa front 70
  done
addSetor orappa pista 35
  done
showE
  [orappa]
showS orappa
  [front],
  [pista]

```

- Realizar venda
    - Uma venda deve ter pessoa, evento, setor e preco
    - O atributo preco da venda será obtido através do atributo preco do setor
    - O identificador único da venda é o nome do cliente(Pessoa)
    - Se o cliente for menor de 2 anos, não paga
    - Se o cliente tiver até 12 anos ou for estudante, paga meia
    - O valor da venda deve ser contabilizado em um caixa
- Mostrar vendas realizadas e o valor atual em caixa

```
#vender _Pessoa _Evento _Setor
vender tony orappa front
  done
vender steve orappa camarote
  fail: setor camarote nao existe

#showV
showV
  [tony, orappa, front, 35]

#showC
showC
  R$ 35.00
```
