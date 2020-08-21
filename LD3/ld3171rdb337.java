import java.util.Random; 
import java.util.Scanner; 

public class ld3171rdb337 { 

	public static void main(String[] args) { 

	int K, i;
	int C = 0;
	int A[]= new int [30]; 
	Scanner sc = new Scanner(System.in); 
	System.out.println("Marks Fomins IRDBD01 171RDB337"); 
	System.out.print("K="); 
	if (sc.hasNextInt()) 
		K = sc.nextInt(); 
	else { 
		System.out.println("input-output error"); 
		sc.close(); 
	return; 
	} 
	sc.close(); 
	do { 
	Random r = new Random(); 
	for (i=0; i<A.length; i++) { 
		A[i] = r.nextInt(11);
	}while(K<=0)
	 {
		for (i=0; i < A.length; i++) {
			A[i] = i % (K + 1);
		}
	}

		System.out.println("A:"); 
	for (i=0; i<A.length; i++) { 
		System.out.printf("%d\t", A[i]); 
	if ((i+1)%10==0 && i>0)
		System.out.println(); 
	}
	
	int nextPos= 0;
	i=0;
		for (i=0; i<A.length; i++) {
		if (A[i]==0) {
			C++;
			;
		}else {
			A[nextPos]=A[i];
			nextPos++;
		}
		i=nextPos;
			for (i=nextPos; i<A.length; i++) {
		}
			i++;
		}
	}
	
	while (i<30);{
		System.out.println("\nA:"); 
		i++;
		if ((i==9)||(i==19))
			System.out.println(); 
	}
	}	
	
}