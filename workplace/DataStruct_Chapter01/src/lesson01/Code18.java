package lesson01;
/*
 * 1.. ���� ���� ȣ�� (int a , int b)
 *   	�� ������ �������.. �Ű������� �޴´�. ���纹��..(�ּҰ� ���� ���� ����)
 * 
 * 2.. ������ ���� ȣ��
 * 		�� �ڹ�, C�� �ش� ����. c++�� �ش�. ������ ���� ȣ���� �ּҰ�. 
 * 
 * ? �׷� �� �迭�� �����Ͱ� �ٲ����? �ּҰ� ������ ���ߴµ�?
 * ��3. ���� ���� ȣ�� :: �迭�� ���ܴ�. (non������Ƽ��� ���ܴ�)
 *		��non-primitive type : String, �迭 .......����
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
