package ld4171rdb337;
import java.util.Random;
import java.util.Scanner;

public class ld4171rdb337 {

 public static void main(String[] args) {
  String ch = "n";
  int j = 0, i;
  System.out.println("Marks Fomins RDBD013 171RDB337");
  
  double A[][] = {
     {0.5, 0.5, 0.5, 0.5, 0.5},
     {0, 1, 0, 1, 1},
     {0.5, 1, 0.5, 0.5, 0},
     {0, 0.5, 0, 0.5, 0},
     {1, 1, 1, 1, 1},
     {0, 0, 0, 0.5, 0.5},
     {0, 0.5, 0, 0, 1}};
  
System.out.println("Aizpildīt masīvu ar patvaļīgiem skaitļiem (y/n)? ");
 
	Scanner sc = new Scanner(System.in);

	if (sc.hasNext()) {
		ch = sc.next();
	}
	else {
		System.out.println("input-output error");
		sc.close();
		return;
	}
	sc.close();

	Random rnd = new Random();
	if (ch.equals("Y") || ch.equals("y")) {
		for (i=0; i<7; i++) {
			for (j=0; j<5; j++) {
				A[i][j] = rnd.nextInt(3);
			if (A[i][j]== 2.0) {
				A[i][j] = 0.5;
			 }
			}
		}
	}
	else
		if (!ch.equals("N") && !ch.equals("n")) {
			System.out.println("input-output error");
			return;
		}

	for (i=0; i<7; i++) {
		for (j=0; j<5; j++)
			System.out.print(A[i][j] + "\t");
		System.out.println();
	}
	System.out.print("results: ");
	int s=0;
	for (i=0; i<7; i++) {
		for (j=0; j<5; j++) {
			if (A[i][j] == 1.0) 
				s++; 
		}
		if (s>=3) 
			System.out.print((i+1) + " ");
		s=0;
	}
 	}
	}