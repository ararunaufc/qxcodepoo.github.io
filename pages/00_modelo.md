---
layout: page
title:  "Modelo de Atividade"
categories: poo
exclude: true
---

![](/assets/00_modelo/figura.png)

Aqui vai a motivação e a descrição geral do que o sistema a ser desenvolvido se propõe a resolver.

- Para a figura de capa:
    - Use a figura de capa com o nome figura.png dentro da pasta assets
    - Pegue uma figura qualquer que represente o trabalho.
    - Se não estiver na proporção 16x9, utilize um software como o **gthumb** para cropar a figura para proporção correta.
    - Redimensione para a resolução padrão de 360x180. No linux o comando abaixo redimensiona para a resolução de 360x180.

```
convert -resize 360x180 sua_figura figura.png
```

## Habilidades

Aqui vai a lista de técnicas a serem desenvolvidas ou aprendidas para atividade.
- Ordenação
- Referência circular
- Retorno de referência nula
- Controlador
- Sistema de logn
- Etc

## Execute online
Se você tiver implementado em js, crie copia a página run e coloque o main.js para ser carregado na página padrão. Use a figura padrão.

[![](/assets/images/run.png)](/assets/00_modelo/run.html)

## Video explicativo

Se houver vídeo explicativo ele vai através do link embeebed do youtube. Escolha o tamanho para ser 320 por 180 do player.

<iframe width="320" height="180" src="https://www.youtube.com/embed/ggOdp0Eh7fc" frameborder="0" allowfullscreen></iframe>

## Funcionalidades

- **[1.0 P]** Iniciar Sistema.
    - Inicia o sistema com uma certa quantidade de dinheiro.
    - Apaga todos os registros de transações que existam.

```
>> iniciar $valor
sistema iniciado com $valor
```

---
- **[1.0 P]** Adicionar transação.
    - Uma transação tem um nome de cliente e um valor numérico.
    - Um valor negativo indica que essa pessoa pegou um empréstimo de Ptolomeu.
    - Um valor positivo indica que ela deu o dinheiro para Ptolomeu, seja quitando uma dívida ou fazendo um investimento.
    - Cada transação deve receber do sistema um identificador numérico crescente.
    - A primeira transação tem id 0. A segundo tem id 1 e etc.
    - **[1.0 E]** Ptolomeu não pode emprestar dinheiro se não tiver dinheiro suficiente.

```
>> addTran $nome $valor
ok | transacao $id adicionada
erro | não há dinheiro suficiente para empréstimo.
```

---
- **[1.0 P]** Mostrar transações.
    - Mostre todas as transações

```
>> showTran
Lista de transações:
$id $nome $valor
$id $nome $valor
...
```

---
- **[1.0 P]** Remover uma transação.    
    - As vezes os clientes se arrependem e desistem após fazer as transações. Ptolomeu então precisa apagar a transação do histórico.
    - Dado o id, apague a transação correspondente.

```
>> rmTran $id
ok | transação removida
erro | transação não encontrada
```

---
- **[1.0 P]** Mostrar cliente.
    - Mostra todas as transações de um cliente.
    - Mostra o saldo do cliente no final

```
>> showCli $nome
Lista de transações de $nome:
$id $nome $valor
$id $nome $valor
...
Saldo: $saldo
```

---
- **[1.0 P]** Fazer balanço do sistema.
    - Soma todas as operações.

```
>> balanco
Balanco: $balanco
```

---
- **[2.0 E]** Contar clientes.
    - Conta quantos clientes diferentes existem no sistema.

```
>> contarCli
Existem $qtd clientes diferentes no sistema.
```

---
- **[1.0 P]** Inicialize o sistema com valores válidos.

## Pontuação
Os valores dos pontos podem ser estabelecidos aqui ao invés de no bloco de funcionalidades. A soma deve ser 10 pontos. P representa ponto normal, E representa ponto extra. Os alunos só podem ganhar os extra se fizerem todos os normais. Você pode fazer7P + 3E ou 8P + 2E ou como proferir. 

```
[ ][1.0 P] addContato
[ ][1.0 P] rmContato
[ ][1.0 P] addFone
[ ][1.0 P] rmFone
[ ][1.0 P] mostrar Contatos
[ ][2.0 P] busca por padrão
[ ][1.0 P] inicialização do sistema
[ ]     Total pontos

[ ][0.5 E] favoritar
[ ][0.5 E] desfavoritar
[ ][1.0 E] mostrar favoritos
[ ][1.0 E] mostrar contatos ordenados
[ ]        Total Extras
```

## Orientações
- Se houverem orientações de como o projeto deve ser desenvolvido em cada linguagem, elas devem vir aqui.

## Diagrama de Classes
- Gets, Sets e toString omitidos.

![](/assets/01_agiota/diagrama.png)