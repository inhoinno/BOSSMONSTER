package lesson01;

import java.util.Scanner;

public class Code03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str = "Hello,_World!";
		String input =null;
		Scanner kb = new Scanner(System.in);
		System.out.print("Please type a string : ");
		input = kb.next(); //scanf("%s" , ..)
		
		if( str.equals(input )){ //str == input 이런 ==연산자는 사용할 수 없습니다. String은 class이고 ==연산자는 primitive타입만 사용이 가능하기 때문입니다.
			System.out.println("Strings match! : ) ");
		} else {
			System.out.println("String doesnt match! :-(");
		}
		System.out.println("입력한 문자열 확인 :"+input);
		kb.close();
				
	}

}
