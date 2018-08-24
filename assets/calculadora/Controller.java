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
			System.out.print("fail: bateria insuficiente");
			return false;
		}
		this.bateria -= 1;
		return true;
	}
	
	boolean soma(float a, float b, Float result){
		if(!gastarBateria())
			return false;
		result = a + b;
		return true;
	}
	
	boolean divisao(float num, float den, Float result){
		if(!gastarBateria())
			return false;
		if(den == 0f){
			System.out.print("fail: divisao por zero");
			return false;
		}
		result = num/den;
		return true;
	}
	
	public String toString(){
		return "bateria = " + this.bateria;
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
			saida = "done";
		}else if(ui[0].equals("soma")){
			Float result = new Float(0.0);
			if(calc.soma(Float.parseFloat(ui[1]), Float.parseFloat(ui[2]), result))
				saida = ": " + result;
		}else if(ui[0].equals("div")){
			Float result = new Float(0.0);
			if(calc.divisao(Float.parseFloat(ui[1]), Float.parseFloat(ui[2]), result))
				saida = "= " + result;
		}else
			saida = "comando invalido";
		return saida;
	}

	public static void main(String[] args) {
		Controller cont = new Controller();
		System.out.println("Digite um comando ou help:");
		while(true){
			String line = scan.nextLine();
			System.out.println(line);
			if(line.equals("end"))
				break;
			System.out.print("  ");
			System.out.println(cont.shell(line));
		}
	}

}