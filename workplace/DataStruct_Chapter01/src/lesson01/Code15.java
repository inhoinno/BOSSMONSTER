package lesson01;

import java.util.Scanner;

//����ڷ� ���� n�� �Է� �ް�
// �ϳ��� �Է� �� �� ���� ������������ �����Ͽ� ����϶�

public class Code15 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner kb = new Scanner(System.in);
		System.out.println("Getting Length ...");
		int n =  kb.nextInt();
		int [] data = new int [n];
	
		
		for(int i =0; i<n; i++){
			System.out.println("Getting number from you ....");
			int tmp = kb.nextInt();
			int j=i-1; // 456 + 1 -> 1 4 5 6 
			while(j>=0 &&data[j]>tmp){
				data[j+1] = data[j];
				j--;
			}
			data[j+1] =tmp;
			System.out.println("Sorted as you Ordered. :-)");
			for(int k=0; k<n; k++) System.out.print(data[k] + " ");
			System.out.println();
		}//main for
		kb.close();
	}

}
