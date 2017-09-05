class Operacao {
    constructor(descricao = "", valor = 0) {
        this.descricao = descricao;
        this.valor = valor;
    }
}
class Conta {
    constructor(id = 0) {
        //TODAS as variaveis precisam ser inicializadas, TODAS
        this.id = id;
        this.saldo = 0;
        this.extrato = [];
    }
    saque(value) {
        if (value <= 0)
            return false;
        if (value > this.saldo)
            return false;
        this.saldo -= value;
        this.extrato.push(new Operacao("saque", -value));
        return true;
    }
    deposito(value) {
        if (value < 0)
            return false;
        this.saldo += value;
        this.extrato.push(new Operacao("deposito", value));
        return true;
    }
}
function intUsuario(conta) {
    let op = [""];
    while (op[0] != "fim") {
        op = prompt("Digite comando ou help").split(" ");
        if (op[0] == "help") {
            alert("saldo\n" +
                "extrato\n" +
                "saque $valor\n" +
                "deposito $valor\n" +
                "fim\n");
        }
        if (op[0] == "saldo") {
            alert("Conta " + conta.id +
                ", Saldo: " + conta.saldo);
        }
        if (op[0] == "extrato") {
            //criando uma string para guardar os valores de saída
            let saida = "Extrato: \n";
            //percorrendo todos os valores
            for (let oper of conta.extrato)
                saida += "[" + oper.descricao + ", " + oper.valor + "]\n";
            alert(saida);
        }
        if (op[0] == "saque") {
            if (conta.saque(Number(op[1])))
                alert("ok");
            else
                alert("erro");
        }
    }
}
function inicializar(conta) {
    conta.deposito(50);
    conta.deposito(100);
    conta.saque(30);
    conta.deposito(20);
}
function main() {
    let conta = new Conta();
    inicializar(conta);
    intUsuario(conta);
}
main();
//# sourceMappingURL=main.js.map