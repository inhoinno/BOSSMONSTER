package lesson01;

public class Code06 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub	
		int [] grades = new int [5]; //define Max = 5 
		//new int [Max]
		//assign some values to the array
		grades[0]= 100;
		grades[1] = 76;
		grades[2] = 92;
		grades[3] = 95;
		grades[4] =14;
		//print out each value
		for(int i=0; i<grades.length; i++ ){
			System.out.println("Grade " +(i+1)+ ": "+grades[i]);
		}
		
	}

}
