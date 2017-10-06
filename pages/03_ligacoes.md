---
layout: page
title:  "Serviço de Ligações"
categories: poo
exclude: true
---

![](/assets/03_ligacoes/figura.png)

Vamos criar o módulo que gerencia ligações da nossa agenda telefônica. Ele vai ser capaz de encontrar o número da agenda que corresponde à aquele número, montar nossa lista de contatos mais ligados e histórico de ligações.

## Funcionalidades

- **[1P]** Deverá adicionar, remover e contatos como feito na atividade anterior.
- Utilize as mesmas restrições de não permitir dois nomes de contatos iguais na agenda ou dois telefones iguais no contato.

        >> addContato $nome
        contato adicionado
        ------
        erro | contato já existe

---
- **[1P]** Remover um contatos pelo nome.

        >> rmContato $nome
        contato removido
        ------
        erro | contato não existe

---
- **[1P]** Deverá adicionar telefones ao contato.
- Telefones tem descrição e número.
- **[1P]** Não deve ser possível adicionar dois telefones iguais no mesmo contato.
- **[1E]** O número deverá conter apenas dígitos.


        >> addFone $nome $number $descricao
        ok
        ------
        erro | numero já existe
        erro | numero inválido
        erro | nome não existe

---
- **[1P]** Deverá remover telefones do contato.

        >> rmFone $nome $number
        ok
        ------
        erro | nome nao existe
        erro | number não existe

---
- **[1P]** Mostrar os contatos
- **[1E]** Ordene os contatos pelo nome.

        >> showContatos
        $nome1 [$fone1 $desc1][$fone2 $desc2] ...
        ...

---
- **[1P]** Buscar contatos por substring
- **[1E]** Se o contato tiver qualquer campo que combine com a string pattern de busca,
ele deve ser retornado.

        >> search $pattern
        $nome1 [$fone1 $desc1][$fone2 $desc2] ...
        ...

---
- **[1P]** Inicilize o sistema para que ele já inicie com alguns contatos e telefones.


## Diagrama de Classes

- Métodos Get e Set de atributos básicos omitidos.

![](/assets/03_ligacoes/diagrama.png)
