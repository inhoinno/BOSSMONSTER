package lesson01;

import java.util.Scanner; //�ڵ����� import ���ִ� ��-�ڹ�
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
		keyboard.close(); //��ĳ�ʸ� �ݾ��ش�. 
	}

}
