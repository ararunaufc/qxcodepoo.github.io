```bash
#__case iniciar mostrar e recarregar
# O comando "$init M" inicia uma calculadora com carga inicial 0 e bateria máxima M.
# O comando "$show" mostra o estado da bateria
# O comando "$charge V" recarrega a bateria de V
$init 5
$show
battery = 0
$charge 3
$show
battery = 3
$charge 1
$show
battery = 4
$charge 2
$show
battery = 5
$init 4
$charge 2
$show
battery = 2
$charge 3
$show
battery = 4
$end
```
```bash
#__case somando
# O comando "$sum V1 V2" soma e mostra o resultado da soma. Para isso ele precisa gastar uma unidade de bateria. Caso não exista bateria suficiente informe.
$init 2
$charge 2
$sum 4 3
7
$show
battery = 1
$sum 2 3
5
$sum -4 -1
fail: bateria insuficiente
$charge 1
$sum -4 -2
-6
$show
battery = 0
$end
```
```bash
#__case dividindo
# O comando "$div A B" consome uma unidade de bateria e apresenta o resultado da divisão inteira entre os números inteiros A e B. Se B for 0 ou não houver bateria, informe os erros. Tentar dividir por 0 consome uma unidade de bateria.
$init 3
$charge 3
$div 6 3
2
$div 7 0
fail: divisao por zero
$show
battery = 1
$div 7 2
3
$div 10 2
fail: bateria insuficiente
$end
```
