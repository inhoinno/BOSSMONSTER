package lesson01;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

//��ȭ��ȣ��? 
public class Code19 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//String filename = "input.txt";
		
		String [] names = new String [1000];
		String [] calls = new String[1000];
		int heads =0;
		Scanner InFile;
		
		try{
			InFile = new Scanner(new File("input.txt"));
			while( InFile.hasNext() ){ //������ ������ true �ٳ�����or ������end of file false return 
				//detect end file
				names[heads] = InFile.next(); calls[heads++] =InFile.next();
			}
			InFile.close();
		} catch (FileNotFoundException e){
			System.out.println("No file. ");
			return;
		}
		//���Ϸ� ���� �о��
		//������ �������� ���� ĳġexception handling
		for (int i =0; i<heads;  i++){
			System.out.println("name :" + names[i]+" Pnumber :"+ calls[i]);
		}
		

	}

}
