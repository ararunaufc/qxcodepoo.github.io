import java.util.Scanner;
class Calculadora {
	static final int bateriaInicial = 0;
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
			throw new RuntimeException("failure: bateria insuficiente");
		this.bateria -= 1;
	}
	
	float soma(float a, float b){
		gastarBateria();
		return a + b;
	}
	
	float divisao(float num, float den){
		gastarBateria();
		if(den == 0f)
			throw new RuntimeException("failure: divisao por zero");
		return num/den;
	}
	
	public String toString(){
		return "battery = " + this.bateria;
	}
}


class Controller{
	Calculadora calc;
	static Scanner scan = new Scanner(System.in);
	
	public Controller() {
		calc = new Calculadora();
	}
	
	//nossa funcao shell que recebe uma pergunta e retorna uma resposta
	public String shell(String line){
		String ui[] = line.split(" ");
		String saida = "";
		if(ui[0].equals("help"))
			saida = "soma _a _b; show; div _a _b; charge _value";
		else if(ui[0].equals("show"))
			saida = "" + calc;
		else if(ui[0].equals("charge")){
			calc.charge(Integer.parseInt(ui[1]));
			saida = "success";
		}else if(ui[0].equals("sum")){
			saida = "= " + calc.soma(Float.parseFloat(ui[1]), Float.parseFloat(ui[2]));
		}else if(ui[0].equals("div")){
			saida = "= " + calc.divisao(Float.parseFloat(ui[1]), Float.parseFloat(ui[2]));
		}else
			saida = "failure: comando invalido";
		return saida;
	}

	public static void main(String[] args) {
		Controller cont = new Controller();
		while(true){
			String line = scan.nextLine();
			System.out.println("$" + line);
			if(line.equals("end"))
				break;
			try{
				System.out.println(cont.shell(line));
			}catch(RuntimeException e){
				System.out.println(e.getMessage());
			}
		}
	}
}