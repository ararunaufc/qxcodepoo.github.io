---
layout: post
title:  "Calculadora"
category: 'Novice' 
introduction: Vamos somar, dividir e lançar excessões.
description:
image: '/assets/calculadora/figura.jpg'
tags:
- base
---

O objetivo dessa atividade é implementar uma calculadora a bateria. Se há bateria, ela executa operações de soma, multiplicação e divisão. É possível também mostrar a quantidade de bateria e recarregar a calculadora. Ela avisa quando está sem bateria e se há tentativa de divisão por 0.

Nessa atividade, você deverá criar três classes. 
- A classe Calculadora que realiza as operações e lança excessões caso a bateria acabe ou haja divisão por 0. A Classe Calculadora não se comunica diretamente com o usuário através de comandos de print. Ela apenas executa cálculos e retorna resultados. 
- A segunda classe é um Controlador que trata as solicitações na forma de perguntas e retorna as respostas.
- A terceira classe é quem faz a interface com o usuário no formato de shell. 

## Run
[](/assets/calculadora/main.html)

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

## Implementação em Python

```python
class Calculadora:
    def __init__(self, bateriaInicial = 2):
        self.bateria = bateriaInicial;
    
    def useBattery(self):
        if self.bateria == 0 :
            raise Exception("fail: Bateria acabou")
        self.bateria -= 1

    def sum(self, a = 0, b = 0):
        self.useBattery()
        return a + b

    def div(self, a = 0, b = 0):
        self.useBattery()
        if b == 0:
            raise Exception("fail: Divisao por zero nao permitida")
        return float(a) / b

    def charge(self, carga = 0):
        self.bateria += carga


# essa classe é o nosso meio de campo, ela recebe as perguntas do frontend,
# encaminha pro backend, e retorna as respostas
class Controller:
    def __init__(self):
        self.calc = Calculadora();

    # a funcao oraculo, recebe perguntas e retorna respostas
    def oracle(self, line = ""):
        ui = line.split(" ")
        cmd = ui[0]

        if cmd == "help":
            return "sum _a _b\ncharge _carga\nshow\ndiv _a _b";
        elif cmd == "sum": # a  b
            return "= " + str(self.calc.sum(float(ui[1]), float(ui[2])))
        elif cmd == "charge":  # carga
            self.calc.charge(float(ui[1]))
        elif(cmd == "show"):
            return "bateria: " + str(self.calc.bateria)
        elif(cmd == "div"):
            return "= " + str(self.calc.div(float(ui[1]), float(ui[2])))
        else:
            return "comando invalido";
        return "done";

# aqui é o nosso frontend, que interage com o usuário
# aqui fazemos nossos prints e inputs
class IO:
    def tab(text = ""):
        return "  " + "\n  ".join(text.split("\n"))

    # recebe um metodo oraculo por parametro
    def shell(oracle):
        print("Digite um comando ou help: ")
        while True:
            line = input("")
            if (line == "") or (line[0] == " "):
                continue
            try:
                print(IO.tab(oracle(line)))
            except Exception as e:
                print(IO.tab(e.args[0]))

cont = Controller();
IO.shell(cont.oracle)
```

## Implementação em Java

```java
package calculadora;

import java.util.Scanner;

public class Calculadora {
	static final int bateriaInicial = 2;
	static final int bateriaMaxima = 5;
	
	int bateria;
	
	public Calculadora() {
		this.bateria = Calculadora.bateriaInicial;
	}
	
	void charge(int value){
		if(value < 0)
			return;
		this.bateria += value;
		if(this.bateria > Calculadora.bateriaMaxima)
			this.bateria = Calculadora.bateriaMaxima;
	}
	void gastarBateria() {
		if(this.bateria == 0)
			throw new RuntimeException("fail: bateria insuficiente");
		this.bateria -= 1;
	}
	
	float soma(float a, float b){
		this.gastarBateria();
		this.bateria -= 1;
		return a + b;
	}
	
	float divisao(float num, float den){
		this.gastarBateria();
		if(den == 0f)
			throw new RuntimeException("fail: divisao por 0");
		return num/den;
	}
	
	public String toString(){
		return "bateria: " + this.bateria;
	}
}


class Controller{
	Calculadora calc;
	
	public Controller() {
		calc = new Calculadora();
	}
	
	//recebe uma string e tenta converter em float
	private float toFloat(String s) {
		return Float.parseFloat(s);
	}
	
	//nossa funcao oraculo que recebe uma pergunta e retorna uma resposta
	public String oracle(String line){
		String ui[] = line.split(" ");

		if(ui[0].equals("help"))
			return "sum _a _b\nshow\ndiv _a _b\ncharge _value";
		else if(ui[0].equals("show"))
			return "" + calc;
		else if(ui[0].equals("charge"))
			calc.charge(Integer.parseInt(ui[1]));
		else if(ui[0].equals("soma"))
			return "= " + calc.soma(toFloat(ui[1]), toFloat(ui[2]));
		else if(ui[0].equals("div"))
			return "= " + calc.divisao(toFloat(ui[1]), toFloat(ui[2]));
		else
			return "comando invalido";
		return "done";
	}
}

class IO {
	//cria um objeto scan para ler strings do teclado
	static Scanner scan = new Scanner(System.in);
	
	//aplica um tab e retorna o texto tabulado com dois espaços
	static private String tab(String text){
		return "  " + String.join("\n  ", text.split("\n"));
	}
	
	public static void main(String[] args) {
		Controller cont = new Controller();
		System.out.println("Digite um comando ou help:");
		while(true){
			String line = scan.nextLine();

			try {
				//se não der problema, faz a pergunta e mostra a resposta
				System.out.println(tab(cont.oracle(line)));
			}catch(Exception e) {
				//se der problema, mostre o erro que deu
				System.out.println(tab(e.getMessage()));
			}
		}
	}
}






```

![](/assets/contato/diagrama.png)
