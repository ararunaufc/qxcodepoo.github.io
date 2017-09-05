---
layout: page
title:  "JunkFood Machine"
categories: poo
exclude: true
---
## Máquina de Vender JunkFood

![Máquina de vender](/pages/01_junkfood/figura.png)

O objetivo dessa atividade é implementar uma classe responsável por uma máquina de vender JunkFood. Na máquina existem várias espirais. Uma espiral contém uma certa quantidade de produtos do mesmo tipo e mesmo preço. O usuário coloca o dinheiro, compra o produto e recebe o troco.

[**Execute o projeto**](/pages/01_junkfood/code/pagina.html)

## Funcionalidades

Essa classe deverá ser capaz de:

* **[1.0 P]** Receber dinheiro do usuário.

```
>> dinheiro $valor
sucesso/erro
```

---
* **[1.0 P]** Mostrar o saldo da máquina

```
>> saldo
$saldo Reais
```

---
* **[1.0 P]** Pedir troco, zerando o saldo da máquina

```
>> troco
voce retirou $valor Reais
```

---
* **[1.0 P]** Iniciar a máquina definindo o número de espirais e a quantidade máxima de produtos em uma espiral.
    * Se já houver uma máquina, então apague tudo e inicie uma nova máquina.

```
>> iniciar $qtdEspirais $maxProdutos
ok
```

---
* **[1.0 P]** Pemitir que o admin possa alterar o nome, a quantidade e o valor de um produto na espiral.
    * **[2.0 E]** Cheque se índice, qtd e valor são válidos e se nome não é vazio.

```
>> alterar $ind $nome $qtd $valor
ok
erro | indice invalido
erro | qtd maior que o permitido
```

---
* **[1.0 P]** Permitir que o cliente possa pedir um produto de uma espiral.
    * **[1.0 E]** Verifique se existe o produto e se o valor do pagamento é suficiente.
    * Mostre o nome do produto que ele pediu.

```
>> comprar $ind
ok | você comprou um $nome
erro | produto nao existe
erro | valor insuficiente
```

---
* **[1.0 P]** Permitir que o admin possa visualizar o status completo da máquina
    * saldo cliente.
    * lucro total.
    * conteúdo de cada espiral.

```
>> show
saldo: $saldo
lucro: $lucro
ind 0: nome: $nome, qtd: $qtd, valor: $value
ind 1: nome: $nome, qtd: $qtd, valor: $value
...
```

---
* **[1.0 P]** Faça um código de inicialização para o sistema já iniciar com alguns produtos nas espirais.


## Dica

- Faça primeiro a classe Espiral. Garanta que existe um construtor default seja sem parâmetros ou com todos os parametros com valores default.
- No contrutor da class Maquina receba a quantidade de espirais. Para iniciar o vetor de espirais você pode fazer um laço inserindo qtd Espirais no vetor.

- Exemplo Typescript

```typescript
class Espiral{
    constructor(
        public nome : string = "", 
        public qtd : number = 0, 
        public preco : number = 0.0
    ){}
}

class Machine{
    saldo : number;
    lucro : number;
    maxProdutos : number;
    espirais : Espiral[];

    constructor(nespirais : number, maxProdutos : number){
        this.saldo = 0.0;
        this.lucro = 0.0;
        this.maxProdutos = maxProdutos;
        this.espirais = [];

        for(let i = 0; i < nespirais; i++){
            this.espirais.push(new Espiral());
        }
    }
}
```

- Exemplo c++

```c++
//c++
class Espiral{
    //atributos
    Espiral(){
        //inicializacao
    }
}

class Maquina{
    std::vector<Espiral> espirais;
    //outros atributos
public:
    Maquina(int nespirais){
        for(int i = 0; i < nespirais; i++)
            espirais.push_back(Espiral());
    }
}
```


## Diagrama
![](/pages/01_junkfood/diagrama.png)
