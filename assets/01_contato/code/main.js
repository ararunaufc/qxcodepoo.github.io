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
var Telefone = (function () {
    function Telefone(id, numero) {
        if (id === void 0) { id = ""; }
        if (numero === void 0) { numero = ""; }
        this.id = id;
        this.numero = numero;
    }
    return Telefone;
}());
var Contato = (function () {
    function Contato(nome, email) {
        if (nome === void 0) { nome = ""; }
        if (email === void 0) { email = ""; }
        this.nome = nome;
        this.email = email;
        this.telefones = [];
    }
    Contato.prototype.toString = function () {
        var st = ("nome: " + this.nome + " email: " + this.email + "\n");
        for (var _i = 0, _a = this.telefones; _i < _a.length; _i++) {
            var fone = _a[_i];
            st += ("\t[id: " + fone.id + " numero: " + fone.numero + "]\n");
        }
        return st;
    };
    Contato.prototype.addFone = function (fone) {
        for (var _i = 0, _a = this.telefones; _i < _a.length; _i++) {
            var elemento = _a[_i];
            if (elemento.id == fone.id)
                return false;
        }
        this.telefones.push(fone);
        return true;
    };
    Contato.prototype.rmFone = function (id) {
        for (var i in this.telefones) {
            if (this.telefones[i].id == id) {
                //remove 1 elemento a partir da posicao i
                this.telefones.splice(Number(i), 1);
                return true;
            }
        }
        return false;
    };
    return Contato;
}());
//realiza a interação com o usuario alterando contado
//retorna as alterações de contato
function commandLine(contato) {
    var op = [""];
    while (op[0] != "fim") {
        op = cin("Digite comando ou help: ").split(" ");
        if (op[0] == "help") {
            cout("iniciar $nome $email" + "\n" +
                "show" + "\n" +
                "addFone $id $numero" + "\n" +
                "rmFone $id" + "\n" +
                "fim" + "\n");
        }
        if (op[0] == "iniciar") {
            contato = new Contato(op[1], op[2]);
            cout("" + contato);
        }
        if (op[0] == "addFone") {
            if (contato.addFone(new Telefone(op[1], op[2])))
                cout("telefone adicionado");
            else
                cout("id ja existe");
        }
        if (op[0] == "rmFone") {
            if (contato.rmFone(op[1]))
                cout("telefone removido");
            else
                cout("id nao existe");
        }
        if (op[0] == "show") {
            cout("Info Contato\n" + contato);
        }
    }
    return contato;
}
//inicializa o contato e retorna o contato inicializado
function inicializar(contato) {
    contato = new Contato("Anibal", "bonitao18@gmail.com");
    contato.addFone(new Telefone("oi", "88"));
    contato.addFone(new Telefone("tim", "85"));
    contato.addFone(new Telefone("casa", "87"));
    contato.rmFone("tim");
    return contato;
}
function main() {
    var contato = new Contato();
    contato = inicializar(contato);
    contato = commandLine(contato);
}
main();
//# sourceMappingURL=main.js.map