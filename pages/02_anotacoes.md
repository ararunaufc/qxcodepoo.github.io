---
layout: page
title:  "Serviço de Anotações"
categories: poo
exclude: true
---

![](/assets/02_anotacoes/figura.png)

O objetivo dessa atividade é criar um pequeno serviço de anotações. O sistema
terá vários usuários que vão logar utilizando login e senha. Cada usuário pode
armazenar notas de texto contendo título e texto.

## Vídeo Explicativo

<iframe width="320" height="180" src="https://www.youtube.com/embed/ggOdp0Eh7fc" frameborder="0" allowfullscreen></iframe>

## Funcionalidades

- **[1.0 P]** Criar usuário passando username e password.
    - Usernames devem ser únicos no sistema.

```
>> addUser $username $password
ok | usuario criado
erro | username já existe
```
---

- **[1.0 P]** Mostrar os usuários do sistema.

```
>> showUsers
$username1
$username2
...
```

----

- **[2.0 P]** Logar e deslogar na conta de um usuário.

```
>> login $username $senha
ok
erro | username não existe
erro | senha inválida

>> logout
ok
erro | nenhum usuário logado
```

---
- **[1.0 P]** Mudar password.

```
>> changePass $oldpass $newpass
ok
erro | password errado
erro | ninguém logado
```

---
- **[1.0 P]** Adicionar uma nota com título e texto.
- **[2.0 E]** Título deve ter uma palavra, mas o texto pode conter várias palavras.
    - Não deve ser possível inserir duas notas com o mesmo título para o mesmo usuário.

```
>> addNote $titulo $texto
ok
erro | ninguem logado
erro | titulo ja existe
```

---
- **[1.0 E]** Apagar uma nota dado o título.

```
>> rmNote $titulo
ok
erro | nota não encontrada
erro | ninguém logado
```

---
- **[1.0 P]** Mostrar notas

```
>> showNotes
$titulo1 $texto1
$titulo2 $texto2
...
```

---
- **[1.0 P]** Inicialize seu sistema com alguns usuários e algumas notas.

---

## Pontuação

```
[ ][1.0 P] addUser
[ ][1.0 P] showUsers
[ ][1.0 P] login
[ ][1.0 P] logout
[ ][1.0 P] changePass
[ ][1.0 P] addNote
[ ][1.0 P] showNotes
[ ][1.0 P] inicialização do sistema
[ ]     Total pontos

[ ][2.0 E] título deve ter uma palavra e o texto várias
[ ][1.0 E] apagar nota por título
[ ]        Total Extras
```

# Diagrama de Classes
![](/assets/02_anotacoes/diagrama.png)
