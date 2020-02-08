package lesson01;

import java.util.Arrays;

public class Code10 {
	static boolean isPrime =false;
	static boolean notPrime =true;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n = 1000000;
		boolean [] check = new boolean [n];
		Arrays.fill(check, isPrime);
		for(int num=2; num <n ; num++){ //num은 대상 수
			if(check[num-1] == notPrime)
				continue;
			for(int i=2; i*i<=num; i++){
				if(num % i == 0){ //나누어 떨어지는 수 라면
					for(int j=1; j*num<=n; j++){
						check[j*num -1 ] = notPrime;
					}
					break;
				}
			}
		}
		for(int i=0; check.length > i; i++){
			if(check[i] == isPrime)
				System.out.println((i+1));
		}

	}

}
