```bash
#__case inicializar
# O comando "$in" insere uma pessoa no carro.
# O comando "$out" retira uma pessoa do carro".
# O comando "$show" mostra o estado do carro.
# Deve ser emitido um erro caso não seja possível inserir ou retirar uma pessoa.
$show
pass: 0, gas: 0, km: 0
$in
$in
$show
pass: 2, gas: 0, km: 0
$in
fail: limite de pessoas atingido
$show
pass: 2, gas: 0, km: 0
$out
$out
$out
fail: nao ha ninguem no carro
$show
pass: 0, gas: 0, km: 0
$end
```
```bash
#__case abastecer
$fuel 25
$show
pass: 0, gas: 10, km: 0

#__case dirigir vazio
$drive 10
fail: nao ha ninguem no carro

#__case dirigir
$in
$drive 10
$show
pass: 1, gas: 9, km: 10
$drive 70
$show
pass: 1, gas: 2, km: 80

#__case para longe
$drive 50
fail: gasolina insuficiente
$end
#__end__
```
