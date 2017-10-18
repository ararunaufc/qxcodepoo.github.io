"use strict";
/* declare function require(name: string): any;
var readline = require('readline-sync');
function cin(text: string): string{
    return readline.question(text);
}
function cout(text: string){
    return console.log(text);
} */
function cin(text = "") {
    let saida = prompt(text);
    if (saida)
        return saida;
    return "";
}
function cout(text) {
    alert(text);
}
class Segredo {
    constructor(nivel = Segredo.minNivel, texto = "Escreva seu segredo") {
        this._nivel = 0;
        this._texto = "";
        this.texto = texto;
        this.nivel = nivel;
    }
    get nivel() {
        return this._nivel;
    }
    set nivel(value) {
        if ((value < Segredo.minNivel) || (value > Segredo.maxNivel)) {
            cout("nivel deve ser entre " + Segredo.minNivel + " e " + Segredo.maxNivel + "\n");
            return;
        }
        this._nivel = value;
    }
    get texto() {
        return this._texto;
    }
    set texto(value) {
        if (value == "")
            cout("Segredo não pode ser vazio");
        this._texto = value;
    }
    toString() {
        return "[Nivel: " + this.nivel + ", Texto: " + this.texto + "]";
    }
}
Segredo.minNivel = 1;
Segredo.maxNivel = 10;
class Usuario {
    constructor(username = "", password = "") {
        this._isAdmin = false;
        this._segredo = new Segredo();
        this._username = username;
        this._password = password;
    }
    get username() {
        return this._username;
    }
    changePassword(oldPass, newPass) {
        if (this._password != oldPass)
            return false;
        this._password = newPass;
        return true;
    }
    matchPassword(password) {
        return (password == this._password);
    }
    get isAdmin() {
        return this._isAdmin;
    }
    set isAdmin(value) {
        this._isAdmin = value;
    }
    set segredo(value) {
        this._segredo = value;
    }
    get segredo() {
        return this._segredo;
    }
    toString() {
        return "Nome: " + this._username + "\nSegredo: " + this._segredo;
    }
}
class Sistema {
    constructor() {
        this._usuarios = [];
        this._usuarios.push(new Usuario("admin", "admin"));
    }
    addUser(usuario) {
        for (let elem of this._usuarios)
            if (elem.username == usuario.username)
                return false;
        this._usuarios.push(usuario);
        return true;
    }
    rmUser(username) {
        for (let ind in this._usuarios)
            if (this._usuarios[ind].username == username) {
                this._usuarios.splice(Number(ind), 1);
                return true;
            }
        return true;
    }
    getUser(username, password) {
        for (let elem of this._usuarios)
            if (elem.username == username && elem.matchPassword(password))
                return elem;
        return undefined;
    }
    getUsernames() {
        //let comp = function(one: string, two: string):
        let usernames = [];
        for (let elem of this._usuarios)
            usernames.push(elem.username);
        usernames.sort();
        return usernames;
    }
    sortear() {
        let ind = Math.floor(Math.random() * this._usuarios.length);
        return this._usuarios[ind].username;
    }
    toString() {
        let comp = (a, b) => {
            return -(a.segredo.nivel - b.segredo.nivel);
        };
        this._usuarios.sort(comp);
        let st = "Sistema ordenado por nivel:" + "\n";
        for (let elem of this._usuarios)
            st += elem + "\n";
        return st;
    }
}
function commandLine(sistema) {
    let usuario = undefined;
    let ui = [""];
    while (ui[0] != "fim") {
        ui = cin("Digite comando ou help: ").split(" ");
        if (ui[0] == "help") {
            cout("\nCOMANDOS GERAIS" + "\n\n" +
                "iniciar" + "\n" +
                "addUser _username _password" + "\n" +
                "showUsernames" + "\n" +
                "login _username _password" + "\n" +
                "sortear" + "\n" +
                "\nCOMANDOS LOGADO" + "\n\n" +
                "logout" + "\n" +
                "rmAccount _password" + "\n" +
                "show" + "\n" +
                "setSegredo _nivel _segredo" + "\n" +
                "changePass _oldPass _newPass" + "\n" +
                "showAll" + "\n");
        }
        else if (ui[0] == "iniciar") {
            sistema = new Sistema();
            cout("Sistema iniciado");
        }
        else if (ui[0] == "addUser") {
            cout((sistema.addUser(new Usuario(ui[1], ui[2])) ?
                "sucesso\n" : "username ja existe\n"));
        }
        else if (ui[0] == "showUsernames") {
            cout("Usernames\n" + sistema.getUsernames().join("\n"));
        }
        else if (ui[0] == "login") {
            usuario = sistema.getUser(ui[1], ui[2]);
            cout((usuario ? "Sucesso" : "Erro") + "\n");
        }
        else if (ui[0] == "sortear") {
            cout("Sorteado: " + sistema.sortear() + "\n");
        }
        else if (usuario == undefined) {
            cout("ninguem logado");
            continue;
        }
        else if (ui[0] == "logout") {
            usuario = undefined;
            cout("Logout efetuado\n");
        }
        else if (ui[0] == "rmAccount") {
            if (usuario.matchPassword(ui[1])) {
                sistema.rmUser(usuario.username);
                cout("Usuario removido\n");
            }
            else {
                cout("password invalido\n");
            }
        }
        else if (ui[0] == "show") {
            cout("" + usuario);
        }
        else if (ui[0] == "setSegredo") {
            usuario.segredo.texto = ui.slice(2).join(" ");
            usuario.segredo.nivel = Number(ui[1]);
            cout("segredo salvo");
        }
        else if (ui[0] == "changePass") {
            cout((usuario.changePassword(ui[1], ui[2])) ?
                "sucesso\n" : "erro\n");
        }
        else if (ui[0] == "rmAccount") {
            if (!usuario.matchPassword(ui[1]))
                continue;
            sistema.rmUser(usuario.username);
        }
        else if (ui[0] == "showAll") {
            cout((usuario.username == "admin") ?
                ("" + sistema) : ("Usuario nao autorizado"));
        }
    }
    return sistema;
}
function inicializar(sistema) {
    cout("" + sistema.addUser(new Usuario("mario", "pmario")));
    cout("" + sistema.addUser(new Usuario("ivo", "pivo")));
    cout("" + !sistema.addUser(new Usuario("mario", "armario")));
    let mario = sistema.getUser("mario", "pmario");
    cout("" + !mario);
    if (mario)
        mario.segredo = new Segredo(4, "assaltei a geladeira de madrugada");
    let user2 = sistema.getUser("mario", "naosei"); //senha errada
    cout("" + !user2);
    let ivo = sistema.getUser("ivo", "pivo");
    if (ivo)
        ivo.segredo = new Segredo(3, "comi doce E fruta no RU");
    let admin = sistema.getUser("admin", "admin");
    if (admin)
        admin.segredo = new Segredo(1, "eu reprovei em etica");
    return sistema;
}
let sistema = new Sistema();
sistema = inicializar(sistema);
sistema = commandLine(sistema);
