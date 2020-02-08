//$ create f 
//$ add f 2 3
//$ add f -1 1
//$ add f 5 0
//$ add f 2 1
//$ calc f 2
//23
//$ print f
//f(x) = +2x3+1x1+5x0
//$ create g
//$ add g 4 5
//$ add g -2 3
//$ add g 1 2
//$ add g 2 3
//$ print g
//g(x) = +4x5+1x2
//$ exit
package lesson4;

import java.util.Scanner;

public class MypolinomialApp {
	//여러개의 다항식 보관
	private Polynomial [] polys = new Polynomial [100];
	private int n =0;
	private Scanner kb = new Scanner (System.in); 
	public MypolinomialApp(){
		
	}
	public void processComand(){
		while(true){
			System.out.print("$ ");
			String command  = kb.next();
			if (command.equals("create"))
				handleCreate();
			else if (command.equals("add"))
				handleAdd();
			else if (command.equals("calc"))
				handleCalc();
			else if (command.equals("print"))
				handlePrint();
			else if (command.equals("exit"))
				break;
		}
	}
	public void handleCreate(){
		char name = kb.next().charAt(0);
		Polynomial p = new Polynomial(name);
		polys[n++] = p;
	}
	public void handleAdd(){
		char name = kb.next().charAt(0);
		int coef = kb.nextInt();
		int expo = kb.nextInt();
		int index = find(name);
		if(index <0){
			System.out.println("No such polynomial");
			return;
		}
		polys[index].addTerm(coef, expo);
		
	}
	private void handleCalc(){
		char name = kb.next().charAt(0);
		int index = find(name);
		int x  = kb.nextInt();
		if(index < 0 ){
			System.out.println("No such polynomial");
		}
		System.out.println(polys[index].calc(x));
	}
	private void handlePrint(){
		char name = kb.next().charAt(0);
		int index = find(name);
		if(index < 0 ){
			System.out.println("No such polynomial");
			return;
		}
		System.out.println( polys[index].toString());
		
	}
	private int find(char name){
		for(int i =0; i<n; i++)
			if(polys[i].name==name)
				return i;
		return 0;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MypolinomialApp app = new MypolinomialApp();
		app.processComand();

	}

}
