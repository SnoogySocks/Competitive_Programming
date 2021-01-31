// https://dmoj.ca/problem/ccc19s1
// 4/2020

import java.util.*; 

public class Main{  
	
	public static void main(String args[]){   
		
		Scanner input = new Scanner(System.in);
		
		String line = input.next();
		int h = 0, v = 0;
		
		for(int i = 0; i < line.length(); i++) {
			
			if (line.charAt(i) == 'V') 
				h++;
			else
				v++;
			
			
		}
		
		if(h%2==0) {
			
			if (v%2==0)
				System.out.println("1 2\n3 4");
			else
				System.out.println("3 4\n1 2");
		}
		
		else {
			
			if (v%2==0)
				System.out.println("2 1\n4 3");
			else
				System.out.println("4 3\n2 1");
		}
	}
         
}
