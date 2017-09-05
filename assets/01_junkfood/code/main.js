/*
declare function require(name:string);
var readline = require('readline-sync');
function cin(text: string): string{
    return readline.question(text);
}
function cout(text: string){
    return console.log(text);
}
*/
function cin(text) {
    return prompt(text);
}
function cout(text) {
    return alert(text);
}
//################################################//
var Espiral = (function () {
    function Espiral(nome, qtd, preco) {
        if (nome === void 0) { nome = ""; }
        if (qtd === void 0) { qtd = 0; }
        if (preco === void 0) { preco = 0.0; }
        this.nome = nome;
        this.qtd = qtd;
        this.preco = preco;
    }
    Espiral.prototype.toString = function () {
        return "nome: " + this.nome + ", qtd: " + this.qtd + ", preco: " + this.preco;
    };
    return Espiral;
}());
var Machine = (function () {
    function Machine(nespirais, maxProdutos) {
        this.saldo = 0.0;
        this.lucro = 0.0;
        this.espirais = [];
        this.maxProdutos = maxProdutos;
        for (var i = 0; i < nespirais; i++) {
            this.espirais.push(new Espiral());
        }
    }
    Machine.prototype.inserirDin = function (value) {
        this.saldo += value;
    };
    Machine.prototype.getSaldo = function () {
        return this.saldo;
    };
    Machine.prototype.pedirTroco = function () {
        var troco = this.saldo;
        this.saldo = 0;
        return troco;
    };
    Machine.prototype.alterarEspiral = function (indice, nome, qtd, preco) {
        if (indice < 0 || indice >= this.espirais.length)
            return false;
        if (qtd < 0 || qtd > this.maxProdutos)
            return;
        this.espirais[indice] = new Espiral(nome, qtd, preco);
    };
    Machine.prototype.comprar = function (indice) {
        if (indice < 0 || indice >= this.espirais.length)
            return false;
        if (this.saldo < this.espirais[indice].preco)
            return false;
        if (this.espirais[indice].qtd == 0)
            return false;
        this.saldo -= this.espirais[indice].preco;
        this.lucro += this.espirais[indice].preco;
        this.espirais[indice].qtd -= 1;
        return true;
    };
    Machine.prototype.toString = function () {
        var st = "";
        st += "Saldo Cliente: " + this.saldo + "\n";
        st += "Lucro Maquina: " + this.lucro + "\n";
        for (var ind in this.espirais)
            st += "ind: " + ind + ", " + this.espirais[Number(ind)] + "\n";
        return st;
    };
    return Machine;
}());
var Controller = (function () {
    function Controller() {
        this.maquina = new Machine(5, 5);
        this.maquina.alterarEspiral(0, "todinho", 3, 2.00);
        this.maquina.alterarEspiral(1, "biscoito", 1, 5.00);
        this.maquina.alterarEspiral(2, "todinho", 3, 2.50);
        this.maquina.alterarEspiral(3, "picole", 2, 7.50);
        this.maquina.inserirDin(4.00);
        this.maquina.comprar(0);
        this.maquina.comprar(0); //nao deve comprar
    }
    Controller.prototype.openConsole = function () {
        var ui = [""]; //user input
        while (ui[0] != "fim") {
            ui = cin("Digite comando ou help: ").split(" ");
            if (ui[0] == "help") {
                cout("iniciar $qtdEspirais $maxProdutos" + "\n"
                    + "dinheiro $valor" + "\n"
                    + "troco          " + "\n"
                    + "show           " + "\n"
                    + "saldo          " + "\n"
                    + "comprar $indice" + "\n"
                    + "alterar $indice $qtd $preco" + "\n");
            }
            if (ui[0] == "alterar") {
                var result = this.maquina.alterarEspiral(Number(ui[1]), ui[2], Number(ui[3]), Number(ui[4]));
                if (result)
                    cout("Produto alterado");
                else
                    cout("Erro na alteracao");
            }
            if (ui[0] == "iniciar") {
                this.maquina = new Machine(Number(ui[1]), Number(ui[2]));
                cout("" + this.maquina);
            }
            if (ui[0] == "dinheiro") {
                this.maquina.inserirDin(Number(ui[1]));
                cout("Saldo: " + this.maquina.getSaldo());
            }
            if (ui[0] == "saldo") {
                cout("Saldo: " + this.maquina.getSaldo());
            }
            if (ui[0] == "troco") {
                cout("Seu troco é " + this.maquina.pedirTroco());
            }
            if (ui[0] == "show") {
                cout("" + this.maquina);
            }
            if (ui[0] == "comprar") {
                if (this.maquina.comprar(Number(ui[1])))
                    cout("Compra efetuada com sucesso");
                else
                    cout("Erro na compra");
            }
        }
    };
    return Controller;
}());
function main() {
    var controller = new Controller();
    controller.openConsole();
}
main();
//# sourceMappingURL=main.js.map