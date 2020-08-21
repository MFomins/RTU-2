import java.util.Scanner;

public class Ld5117rdb337 {
    public static void main(String[] args) {
        int A[][]=new int [10][10];
        int i, j, k ,c;

        System.out.println("Marks Fomins 13.gr. 171rdb337");
        System.out.print("Uzdevuma numurs (1 vai 2): ");
        Scanner sc = new Scanner((System.in));

        if (sc.hasNextInt())
            k=sc.nextInt();
        else{
            System.out.println("input-output error");
            sc.close();
            return;
        }
        sc.close();
        if (k!=2 && k!=1){
            System.out.println("input-output error");
            return;
        }

        switch (k){
            case 1: c = 1;
			for (j=0; j<=9; j++)
			    for (i=9-j; i>=7-j; i--) 
			         if (i>=0) {
			            A[i][j] = c; c=c+1;

                            }
                    break;
            case 2: for (j=0; j<=9; j++)
		         for (i=9-j; i<=9; i++)
		             A[i][j] = i+j-8;
                    break;
        }

        for (i=0;i<10;i++){
            for (j=0;j<10;j++)
                System.out.print(A[i][j] + "\t");
            System.out.println();
        }
    }
}
