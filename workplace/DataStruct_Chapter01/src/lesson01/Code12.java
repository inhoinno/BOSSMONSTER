package lesson01;

import java.util.Scanner;

public class Code12 {
//(���ӵ�!)�ִ����� ���ϴ� �ڵ�
	public static void main(String[] args) {
		System.out.println("go");
		Scanner kb = new Scanner(System.in);
		int n = kb.nextInt();
		int [] data =new int [n];
		
		//-2 3 5 -14 12 3 -9 8 -1 13 2 -5 4
		for(int i=0; i<n; i++){
			data[i] = kb.nextInt();
		}
		kb.close();

		int max =0;
		for(int i=0; i<n; i++){ //i ���ؼ�
			int sum=0;
			for(int j=i; j<n; j++){//j i~j �������ϱ��
				sum += data[j];
				if(sum>max)
					max = sum;
			}
		}
		System.out.println(max);
	}
}
