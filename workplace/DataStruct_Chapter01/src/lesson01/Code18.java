package lesson01;
/*
 * 1.. 값에 의한 호출 (int a , int b)
 *   	ㄴ 원본에 영향없음.. 매개변수로 받는다. 복사복사..(주소값 참조 전혀 없음)
 * 
 * 2.. 참조에 의한 호출
 * 		ㄴ 자바, C는 해당 없음. c++만 해당. 참조에 의한 호출은 주소값. 
 * 
 * ? 그럼 왜 배열의 데이터가 바뀌었냐? 주소값 참조도 안했는데?
 * ㄴ3. 값에 의한 호출 :: 배열은 예외다. (non프리미티브는 예외다)
 *		ㄴnon-primitive type : String, 배열 .......등등등
 *			primitive : byte, short, int,  char,boolean, double 
 * 
 * */

import java.util.Scanner;

public class Code18 {
	
	public static void bubblesort(int [] data){
		for(int i = data.length-1 ; i>0; i--){
			for(int j =0; j<i; j++){
				if(data[j] > data[j+1]){
					int tmp = data[j];
					data[j] = data[j+1];
					data[j+1] = tmp;
				}
			}
			
		}
		System.out.println("Bubble Sorted");
		return ;
	
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner kb = new Scanner(System.in);
		System.out.println("Getting Length ...");
		int n =  kb.nextInt();
		int [] data = new int [n];
		for(int i=0; i<n; i++) data[i]=kb.nextInt();
		kb.close();
		bubblesort(data);
		for(int i=0; i< data.length; i++)
			System.out.print (data[i]+" ");
		
				

	}

}
