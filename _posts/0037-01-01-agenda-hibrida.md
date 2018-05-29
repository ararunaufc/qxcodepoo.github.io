---
layout: post
title: "Agenda Híbrida"
category: 'Adept'
introduction: 'Sua agenda telefônica agora será um aplicativo híbrido para guardar contatos e anotações'
description: 'Utilize polimorfismo para tentar adicionar essa funcionalidade' 
image: '/assets/agenda-hibrida/figura.jpg'
tags:
- agregação
- manager
- template
- herança
---

```
  # adicionava o contato e vários telefones ao contato
  # se o contato ja existir, apenas adicione os novos telefones

addContato joao tim:4323 oi:8775
  done

rmContato joao
  done

addContato joao tim:4323 oi:8775
  done

lacont
  - C joao [0:tim:4323][1:oi:8775]

  #rmFone _idContato _idFone
rmFone joao 0
  done

addContato dani recado:324
lacont
  - dani C [0:recado:324]
  - joao C [1:oi:8775]


  #fav _idContato
fav dani
  done

lacont
  @ C dani [0:recado:324]
  - C joao [1:oi:8775]

lafav
  @ C dani [0:recado:324]

  # adiciona uma nova nota ou dá um append na nota antiga

addNote mercantil ovo chiclete fandangos
  done

addNote mercantil pao

la
  @ C dani [0:recado:324]
  - C joao [1:oi:8775]
  + N mercantil (ovo chiclete fandangos pao)

addCont xuxa claro:99
  done

la
  @ C dani [0:recado:324]
  - C joao [1:oi:8775]
  - N mercantil (ovo chiclete fandangos pao)
  - C xuxa [0:claro:99]

fav mercantil
  done

lafav
  @ C dani [0:recado:324]
  @ N mercantil (ovo chiclete fandangos pao)

laNote
  @ N mercantil (ovo chiclete fandangos pao)

addPass bb 123456
  done

la
  - P bb ******
  @ C dani [0:recado:324]
  - C joao [1:oi:8775]
  - N mercantil (ovo chiclete fandangos pao)
  - C xuxa [0:claro:99]

setMasterPass chichele
  done

show bb chichele
  - P bb 123456

```

## Raio X

```java
abstract class Entry{
    id: string
    favorited: bool
    ---
    setId(value: string): void
    getId(): string
    isFavorited(): bool
    setFavorited(value:bool): void
}

class Agenda{
    - entries: Entry[]
    - favorites: Entry[]
    ---
    addEntry(Entry entry)
    rmEntry(id: String)  //desfavorita se preciso e remove a entrada
    getEntries(): Entry[] //retorna todas as entradas
    getFavorites(): Entry[] //retorna todos os favoritos
    setFavorited(idEntry: string, value: bool)
}

//opcao 1 - heranca - opção ruim - muito acoplamento
class MasterAgenda extends Agenda{
    getContatos(): Contato[]
    getNotas(): Note[]
    getAllPass(): Pass[]
    addNote(note: Note)
    addCont(contato: Contato)
    addPass(pass: Pass)
}

//opcao 2 - Agregação - opção melhor de boa #sucesso
class MasterAgenda{
    - agenda: Agenda
    - senhaMestra: string

    MasterAgenda(agenda) //recebe a agenda (agregacao)
    getContatos(): Contato[]
    getNotas(): Note[]
    getAllPass(): Pass[]
    addNote(note: Note)
    addCont(contato: Contato)
    addPass(pass: Pass)
    setMasterPass(pass: string)
}

class Fone{
    id: string
    number: string
}

class Contato extends Entry{
    fones: Fone[]
    addFone(fone: Fone)
    rmFone(id)
}

class Note extends Entry {
    text: string
}

class Controller {
    agenda: Agenda
    master: MasterAgenda
    
    public Controller{
        agenda = new Agenda();
        master = new MasterAgenda(agenda); //utilizando 
    }
}

```





