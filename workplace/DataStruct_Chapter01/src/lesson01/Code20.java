package lesson01;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

//��ȭ��ȣ��? 
public class Code20 {

	
	static	String [] names = new String [1000];
	static	String [] calls = new String[1000];
	static	int heads =0;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//String filename = "input.txt";
		
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
			System.exit(9);
		}
		//���Ϸ� ���� �о��
		//������ �������� ���� ĳġexception handling
		for (int i =0; i<heads;  i++){
			System.out.println("name | " + names[i]+" , "+ calls[i]);
		}
		bubblesort();
		System.out.println("-------------------");
		for (int i =0; i<heads;  i++){
			System.out.println("name | " + names[i]+" , "+ calls[i]);
		}

	}
	
	public static void bubblesort(){
		for(int i = heads -1; i>0 ; i--){
			for(int j=0; j<i; j++){
				if(names[j].compareTo(names[j+1])>0){ //if names[j] > names[j+1] then 1, = 0 , < -1
					// .compareToignoreCase() is ��ҹ��� ����
					String tmp = names[j];
					names[j] = names[j+1];
					names[j+1] = tmp;
					
					tmp = calls[j];
					calls[j] = calls[j+1];
					calls[j+1] = tmp;
				}
			}
		}
		
	}
}
