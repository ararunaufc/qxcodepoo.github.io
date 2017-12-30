"use strict";

class Calculadora {
    constructor(bateriaInicial = 2) {
        this.bateria = bateriaInicial;
    }

    useBattery(){
        if (this.bateria == 0)
            throw new Error("fail: Bateria acabou");
        this.bateria -= 1;
    }

    sum(a = 0, b = 0) {
        this.useBattery();
        return a + b;
    }
    div(a = 0, b = 0){
        this.useBattery();
        if (b == 0)
            throw new Error("fail: Divisao por zero nao permitida");
        return (a / b);    
    }

    charge(carga) {
        this.bateria += carga;
    }
}

class Controller {
    constructor() {
        this.calc = new Calculadora();
    }

    execQuery(line = "") {
        let ui = line.split(" ");
        let cmd = ui[0];

        if (cmd == "help")
            return "sum _a _b\ncharge _carga\nshow\ndiv _a _b";
        else if (cmd == "sum")
            return "= " + this.calc.sum(Number(ui[1]), Number(ui[2]));
        else if (cmd == "charge")
            this.calc.charge(Number(ui[1]));
        else if (cmd == "div")
            return "= " + this.calc.div(Number(ui[1]), Number(ui[2]));
        else if (cmd == "show")
            return "bateria: " + this.calc.bateria;
        else
            return "comando invalido";
        return "done";
    }
}

/* //instalar o readline para usar entrada de dados via terminal
//npm install readline-sync
var readline = require('readline-sync');
readline.setDefaultOptions({ keepWhitespace: true });

class IO {
    static input(text = "") {
        return readline.question(text);
    }
    static print(text = "") {
        return console.log(text);
    }
    //recebe um texto e retorna o texto com um tab de 2 espacos
    static tab(text, prefix = "  ") {
        return prefix + text.split("\n").join("\n" + prefix);
    }

    static shell(execQuery) {
        IO.print("Digite um comando ou help:");
        while (true) {
            let line = IO.input("");
            try {
                IO.print(IO.tab(execQuery(line)));
            } catch (e) {
                IO.print(IO.tab(e.message));
            }
        }
    }
}

let cont = new Controller();
IO.shell(x => cont.execQuery(x)); */

let cont = new Controller();
function rprocess(line) {
    let result = "";
    try {
        result = cont.execQuery(line);
    } catch (e) {
        result = e.message;
    }
    return result;
}

function site(process) {
    var tab = function (text, prefix) {
        if (prefix === void 0) { prefix = "__"; }
        return prefix + text.split("\n").join("<br/>" + prefix);
    };
    var label = document.createElement("label");
    label.innerHTML = "Input: ";
    var input = document.createElement("input");
    input.style.width = "80%";
    input.setAttribute('type', 'text');
    var idiv = document.createElement("div");
    var exec = function () {
        idiv.innerHTML = input.value + "<br/>" +
            tab(process(input.value)) + "<br/><hr>" + idiv.innerHTML;
        input.value = "";
    };
    input.addEventListener("keyup", function (event) {
        event.preventDefault();
        if (event.keyCode === 13)
            exec();
    });
    document.body.appendChild(label);
    document.body.appendChild(input);
    document.getElementsByTagName('body')[0].appendChild(idiv);
}
site(rprocess);
