package lesson01;

public class Code10_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for(int n=100000; n<=1940713; n++){
			boolean isPrime =true;
			for(int i =2; i*i <=n && isPrime; i++){
				if(n%i ==0) isPrime =false;
			}
			if(isPrime)
				System.out.println(n);
		}
	}

}
