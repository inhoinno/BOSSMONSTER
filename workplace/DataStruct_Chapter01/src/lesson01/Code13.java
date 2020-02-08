package lesson01;

import java.util.Scanner;

public class Code13 {
//n개의 음이아닌 한자리 정수를 입력받아 배열에 저장.
//이들중 1개 이상의 연속된 정수들을 합하여(자리수대로 맞추어) 얻을 수 있는 소수들 중에서 최대값을 구하여라
/*1 9 4 0 7 1 3 6 2 3
 * sudo 
 * int box(int [] data)
 * 1. for(int i =0; i< n ; i++){
 * 		int dnum= data[i];
 * 		for(int j = i ; j< n ; j++){
 * 			if (dnum >max && dnum is Prime?)
 * 				then max = dnum
 * 			else 
 * 				dnum = dnum * 10 + data[j]
 * } j
 * } i
 * return max;
 * 
 * sudo 
 * boolean IsPrime(int a){
 * for(i = 2; i<=sqrt(a); i++){
 *  if a % i == 0 then return false;
 *  }
 *  return true; 
 * }
 * 
 * 
 * 
 * */
	/*
	 * 이 코드의 문제점. 
	 * 1. 1을 소수로 판단 할 경우를 놓치기 쉽고(잡아줘야하고)
	 * 2. Integer Overflow . (ex배열 크기 20 막 이럴때 (자리수를 늘려가며)정수형 범위를 넘어가는 경우*/
	
	public static int Max_Prime_box(int [] data){
		int max =0;
		for(int i =0; i< data.length; i++){
			int dnum = data[i];
			for(int j = i+1; j<data.length; j++){
				if(dnum > max && IsPrime(dnum))
					max = dnum; 
				dnum = dnum*10 + data[j];
			}
		}
		return max;
	}
	public static boolean IsPrime(int T){
		double a = (double)T;
		for(int i =2 ;  i<=(int)Math.sqrt(a); i++){
			if(T % i == 0)
				return false;
		}
		if(T != 1) return true;
		else return false;
			
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("go");
		Scanner kb = new Scanner(System.in);
		int n = kb.nextInt();
		int [] data= new int [n];
		for(int i=0; i<n; i++)
			data[i] = kb.nextInt();
		kb.close();	//set Data
		int k = Max_Prime_box(data);
		if(k >0)
			System.out.println(k);
		else System.out.println("No Prime Number");
		System.out.println(IsPrime(k));
	}

}
