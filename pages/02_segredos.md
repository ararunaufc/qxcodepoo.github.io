---
layout: page
title:  "Serviço de Segredos"
categories: poo
exclude: true
---

![](/assets/02_segredos/figura.png)

Lindobergue tinha um "amor" "apaixonado" por Veridiana. Depois de levar o fora incontáveis vezes sem nenhuma explicação, ele começou a desconfiar que Veridiana guardava um terrível segredo.

Ela era uma menina meiga, recatada e discreta, que só aceitava em suas redes sociais amigos íntimos e sempre postava no face com restrição de acesso à quem não era seu amigo. Algo de errado não estava certo. Lindobergue ficou paranóico e botou na cabeça que o problema não era ele, era ela!

Então Lindoberg teve uma ideia terrível e criou um plano maligno. Uma risada malvada, daquelas de filme de terror,  ecoou pelo corredor do bloco 1 da UFC de Quixadá. Lindoberg decidiu criar um serviço de guardar segredos com login e senha para usar na UFC de Quixadá. Ele iria sortear ingressos para o cinema do Pinheiro, as pessoas iriam se cadastrar no seu sistema e Lindo poderia saber de todos os seus de seus colegas. Huhurararah.

Mas como ele fez a disciplina de ética, ele decidiu pelo menos que nem ele mesmo teria acesso às senhas dos usuários. O esquema de senhas seria implementado no formato Zero Knoledge. Depois de armazenadas, as senhas não podem ser recuperadas ou lidas, apenas verificadas ou substituídas. Se alguém perder a senha, perderá o usuário.

A última parte do plano era inventar um tal de Spotted VSF Quixadá, para poder postar anonimamente as revelações comprometedoras de seus piores inimigos. Huhurararararararararararaaaaaaaaa.

---

![](/assets/02_segredos/figura2.png)

O objetivo dessa atividade é criar um pequeno serviço de guardar segredos de Lindoberg. O sistema terá vários usuários que vão logar utilizando login e senha. Cada usuário pode armazenar um único segredo. As senhas podem ser verificadas ou alteradas, nunca obtidas.

O objetivo da ativade é trabalhar:

- Esquema de login (variável de referência que guarda o usuário corrente).
- Ordenação (como ordenar um vetor utilizando múltiplos critérios).
- Controle de acesso (importância de definir variáveis como privadas) e métodos get e set. Quando utilizar métodos get e set.
- Geração de números aleatórios.
- O método toString para sobrescrever o como objetos são transformados em string.
- Pegar uma frase inteira em uma única String.
- Uso de variáveis constantes;

O usuário se cadastra com login e senha. Depois de logado ele pode alterar senha e registrar seu segredo. O usuario só pode ver ser próprio segredo. O Administrador pode ver o segredo de todos.

## Execute Online
[![](/assets/images/run.png)](/assets/02_segredos/code/pagina.html)

## Funcionalidades
O sistema deve:

- **[1.0 P]** Ao ser inicado adicionar o usuário admin.
    - o login deve ser admin e a senha admin.
    - se já houver algo no sistema, apague todos os dados.

```
>> iniciar
sistema iniciado
```
---
- **[1.0 P]** Criar usuário passando username e password.
    - _usernames devem ser únicos no sistema.

```
>> addUser _username _password
ok | usuario criado
erro | _username já existe
```
---

- **[2.0 P]** Logar e deslogar na conta de um usuário.
    - O admin também é um usuário.

```
>> login _username _password
ok
erro | username não existe
erro | senha inválida

>> logout
ok
erro | nenhum usuário logado
```
---

- **[1.0 P]** Mostrar os usuários do sistema.
    - Mostre os usuário ordenados por nome.
    - Qualquer usuário pode ver os usuários do sistema

```
>> showUsernames
$username1
$username2
...
```

---
- **[1.0 P]** Mudar password.
    - O usuário precisa estar logado para mudar seu password.

```
>> changePass _oldpass _newpass
ok
erro | password errado
erro | ninguém logado
```

---
- **[1.0 P]** Remover conta de usuário.
    - O usuário precisa estar logado para remover a conta.

```
>> rmConta _password
ok
erro | password errado
erro | ninguém logado
```

---
- **[1.0 P]** Anotar o segredo informando um nível de gravidade e o texto.
    - O nível de gravidade informa o quão comprometedor e terrível é o segredo. Deve ser um inteiro entre 1 e 10.
    - O texto pode conter várias palavras e não pode ser vazio.
    - Cada usuário tem um único segredo.
    - O usuário admin também pode ter um segredo.

```
>> setSegredo _nivel _segredo
ok
erro | ninguem logado
erro | nivel invalido
```

---
- **[1.0 P]** Mostrar informações.
    - O usuário só pode ver suas próprias informações.

```
>> show
Nome: _username [_nivel _segredo]
erro | ninguem logado
...
```

---
- **[1.0 P]** Mostrar todos os usuários e segredos.
    - Só o admin pode rodar esse comando.
    - Mostre ordenado por nível, ou seja, os usuários com
    segredos mais terríveis aparecem primeiro.

```
>> showAll
Nome: _username [_nivel _segredo]
Nome: _username [_nivel _segredo]
Nome: _username [_nivel _segredo]
erro | ninguem logado
erro | login não é admin
...
```
---
- **[1.0 P]** Sortear usuário.
    - Sorteie um usuário do sistema. O admin também pode ser sorteado.

```
>> sortear
usuario _username sortedo
```

---
- **[1.0 P]** Inicialize seu sistema com alguns usuários e segredos faça alguns testes.

---

## Pontuação

```
[ ][1.0 P] iniciar
[ ][1.0 P] addUser
[ ][0.5 P] login
[ ][0.5 P] logout
[ ][1.0 P] showUsenames
[ ][0.5 P] changePass
[ ][0.5 P] rmAccount
[ ][1.0 P] setSegredo
[ ][0.5 P] show
[ ][1.0 P] showAll
[ ][0.5 P] sortear
[ ][1.0 P] inicialização e testes
[ ]     Total pontos
```

## Orientações

- No construtor da classe Segredo o único parâmetro será o texto.
- Na classe Segredo, faça o setNivel só aceitar valores válidos entre 1 e 10.
- Crie minNivel = 1 e maxNivel = 10 como constantes.
- Usuario não terá método set username. O nome só poderá ser atribuído no processo de criação do objeto.
- Usuário não terá get ou set password. O password só poderá ser alterado através do changePassword, ou verificado através do matchPassword.
- No setNivel e setTexto de segredo, valide os parâmetros. Se o nível estiver fora dos limite, mude para o mínimo. Se o texto estiver vazio, coloque como "Escreva o seu segredo".


## Diagrama de Classes

No diagrama são omitidos construtores, métodos get e set e toString(). Crie os gets, sets dos atributos e toString das classes.

![](/assets/02_segredos/diagrama.png)
