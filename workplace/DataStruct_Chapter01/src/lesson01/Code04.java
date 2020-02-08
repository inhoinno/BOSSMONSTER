package lesson01;

import java.util.Scanner;

public class Code04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String name = null;
		int age;
		String gender;
		
		Scanner kb = new Scanner(System.in);
		System.out.print("Please type your name and your gender(male/female) : ");
		
		name = kb.next();
		age = kb.nextInt();
		gender = kb.next();
		
		if(gender.equals("male"))
			System.out.println(name + ", you are " + age +"-year-old, Man");
		else if (gender.equals("female"))
			System.out.println(name + ", you are "+ age +"-year-old Woman");
		else
			System.out.println("Hmm...... Interesting.");
		kb.close();
	}
	

}
