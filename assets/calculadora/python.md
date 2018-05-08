---
layout: post
title: "Calculadora em Python"
---

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
    def main():
        c = Controller() 
        print("Digite um comando ou help: ")
        while True:
            line = input("")
            if (line == "") or (line[0] == " "):
                continue
            try:
                print(IO.tab(c.shell(line)))
            except Exception as e:
                print(IO.tab(e.args[0]))


IO.main()

```
