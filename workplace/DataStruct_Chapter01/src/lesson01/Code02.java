package lesson01;

import java.util.Scanner; //자동으로 import 해주는 갓-자바
public class Code02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int number = 23;
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Please enter an integer : ");
		int input = keyboard.nextInt();
		if (input == number){
			System.out.println("Numbers match ! :-)");
		} else{
			System.out.println("Numbers do not match! :-(");
		}
		keyboard.close(); //스캐너를 닫아준다. 
	}

}
