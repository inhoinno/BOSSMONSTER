package pr_ex_test;

public class Mainclass {
	public static void main(String[] args) {
		double temp = Math.random();
		int chch =(int)(temp * 100) +1;
		chch %= 2;
		
		if(chch ==1){
			System.out.println("��ȣ->���� �ǻ�");
		}
		else{
			System.out.println("����->��ȣ �ǻ�");
		}
		
		
		
	}
}
