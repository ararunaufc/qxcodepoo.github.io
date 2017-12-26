---
layout: post
title:  "Calculadora"
category: 'Novice' 
introduction: Vamos somar, dividir e lançar excessões.
description:
image: '/assets/calculadora/figura.png'
tags:
- base
---

O objetivo dessa atividade é implementar uma calculadora a bateria. Se há bateria, ela executa operações de soma, multiplicação e divisão. É possível também mostrar a quantidade de bateria e recarregar a calculadora. Ela avisa quando está sem bateria e se há tentativa de divisão por 0.

Nessa atividade, você deverá criar duas classes. A classe Calculadora que realiza as operações e lança excessões caso a bateria acabe ou haja divisão por 0. A Classe Calculadora não se comunica diretamente com o usuário através de comandos de print. Ela apenas executa cálculos e retorna resultados. A segunda classe é um Controlador que trata os comandos do usuário encaminhando à Calculadora e devolvendo as respostas.

## Funcionalidades
Seu sistema deverá:

- Iniciar a calculadora. 
    - Ao iniciar, sua calculadora terá bateria para efetuar duas operações matemáticas.
- Mostrar a bateria da calculadora.
- Recarregar a bateria passando como parametro a quantidade de carga.
    - O máximo de carga que a bateria suporta é cinco unidades.
- Realizar operações de soma.

```
show
  bateria: 2
soma 4 3
  = 7
show
  bateria: 1
soma 8 9
  = 17 
show
  bateria: 0
```

- Se não houver mais bateria, notifique o usuário, lançando uma excessão.
- Efetue operações de divisão. 
    - Se houver divisão por 0, notifique o usuario.

```
soma 1 1
  fail: bateria insuficiente
charge 10
  done
show
  bateria: 5
div 6 3
  = 2
div 7 0
  fail: divisao por zero
show
  bateria: 3
```

### Just for Fun

- Guarde variáveis para utilizar nas operações de soma e divisão.
- Lance excessão caso o usuário tente efetuar uma operação com uma variável que não foi definida.
- Definir variáveis não gasta bateria.

```
set a 2
  done
set b 1
soma 5 a
  = 7
div a b
  = 0.5
soma c b
  fail: var c nao definida
```

## Diagrama de Classes
@sq@sq@s2@s2@s@@s1@s2@@s3@s4


```typescript
class Calculadora {
    bateria: number;
    useBattery(){
        if(this.bateria == 0)
            throw new Error("fail: Bateria acabou");
        this.bateria -= 1;
    }
    charge(carga: number){
        this.bateria += carga;
    }
}


class Controller{
    calc: Calculadora;
    process(line: string): string{
        let ui = line.split(" ");
        let cmd = ui[0];
        if(cmd == "sum")//a  b
            return "" + this.calc.sum(Number(ui[1]), Number(ui[2]));
        else if(cmd == "charge")//carga
            this.calc.charge(Number(ui[1]));
        else if(cmd == "show")
            return "" + this.calc.bateria;
        else
            return "comando invalido";
        return "done";
    }

    static shell(){
        poo.print("Digite um comando ou help: ");
        while(true){
            let line = poo.getline("");
            try{
                let result = this.process(line);
                poo.print(result);
            }catch(e){
                poo.print(e.message);
            }
        }
    }
}

let cont = new Controller();
poo.shell();
```

![](/assets/contato/diagrama.png)
