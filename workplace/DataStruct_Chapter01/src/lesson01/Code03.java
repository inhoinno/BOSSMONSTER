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
		
		if( str.equals(input )){ //str == input �̷� ==�����ڴ� ����� �� �����ϴ�. String�� class�̰� ==�����ڴ� primitiveŸ�Ը� ����� �����ϱ� �����Դϴ�.
			System.out.println("Strings match! : ) ");
		} else {
			System.out.println("String doesnt match! :-(");
		}
		System.out.println("�Է��� ���ڿ� Ȯ�� :"+input);
		kb.close();
				
	}

}
