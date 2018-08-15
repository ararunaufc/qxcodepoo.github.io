import java.util.Scanner;
class Calculadora {
	static final int bateriaInicial = 2;
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
	boolean gastarBateria() {
		if(this.bateria == 0){
			System.out.print("  fail: bateria insuficiente. ");
			return false;
		}
		this.bateria -= 1;
		return true;
	}
	
	float soma(float a, float b){
		if(!gastarBateria())
			return 0.0f;
		return a + b;
	}
	
	float divisao(float num, float den){
		if(!gastarBateria())
			return 0.0f;
		if(den == 0f){
			System.out.print("  fail: divisão por 0. ");
			return 0.0f;
		}
		return num/den;
	}
	
	public String toString(){
		return "bateria: " + this.bateria;
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

		if(ui[0].equals("help"))
			return "sum _a _b\nshow\ndiv _a _b\ncharge _value";
		else if(ui[0].equals("show"))
			return "" + calc;
		else if(ui[0].equals("charge"))
			calc.charge(Integer.parseInt(ui[1]));
		else if(ui[0].equals("sum"))
			return "= " + calc.soma(Float.parseFloat(ui[1]), Float.parseFloat(ui[2]));
		else if(ui[0].equals("div"))
			return "= " + calc.divisao(Float.parseFloat(ui[1]), Float.parseFloat(ui[2]));
		else
			return "comando invalido";
		return "done";
	}

	public static void main(String[] args) {
		Controller cont = new Controller();
		System.out.println("Digite um comando ou help:");
		while(true){
			String line = scan.nextLine();
			String answer = cont.shell(line);
			System.out.println("  " + answer);
		}
	}

}