package lesson01;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

//전화번호부? 
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
			while( InFile.hasNext() ){ //읽을게 있으면 true 다끝나서or 없으면end of file false return 
				//detect end file
				names[heads] = InFile.next(); calls[heads++] =InFile.next();
			}
			InFile.close();
		} catch (FileNotFoundException e){
			System.out.println("No file. ");
			return;
		}
		//파일로 부터 읽어옴
		//파일이 없을때에 에러 캐치exception handling
		for (int i =0; i<heads;  i++){
			System.out.println("name :" + names[i]+" Pnumber :"+ calls[i]);
		}
		

	}

}
