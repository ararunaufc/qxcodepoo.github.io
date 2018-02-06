 Vamos modelar o controle de pagamento de uma empresa privada de ensino.

 Existem 3 categorias: "prof", "sta", "terc" representando
 respectivamente professores, servidores tecnico administrativos e
 terceirizados.

 Todos são funcionarios da empresa, porém só Professores e STA são
 servidores públicos.

 O coração do trabalho é o uso de herança para modelar as relações e
 a lógica de negócios. Para não influenciar na forma como você vai
 escolher modelar suas entidades vamos utilizar uma "artimanha" para
 trabalhar a passagem dos dados. A classe Tudao é uma classe "gambi"
 que contém os dados das três categorias. Em professor, você só
 vai usar os dados de nome e classe. Em Sta você vai usar os dados
 de nome e nível. Em terceirizado você vai usar nome e insalubridade.

 A lógica de negócios para o cálculo do salário é o seguinte.
 Salário = SalarioBase + DivisaoNosLucros + Diarias

 Salário Base:
 	Professores: A "classe" é um char que pode ser A, B, C, D ou E.
 		O salario dos classes A, B, C, D, E é espectivamente 4000, 6000,
 		9000, 12000 e 15000 reais.

 	STA: O "nível" é um int entre 1 e 30.
		O salario é calculado como 1000 + 100 * nivel;

	Terceirizado: Insalubridade é um boolean que define as condições de trabalho.
		O salário é 600 sem insalubridade e 800 com insalubridade.

 DivisãoNosLucros
 	Se a empresa lucrar 10000 reais e tiver 5 funcionarios, cada um ganhará 2000.

 Diárias
 	Apenas Servidores(Professores e Stas) podem solicitar diarias.
 	Cada diária solicitada adiciona 100 reais no salário.
 	Professores podem solicitar até 3 diárias.
 	Stas podem solicitar 1 diária.
