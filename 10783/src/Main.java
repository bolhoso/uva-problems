import java.util.Scanner;

public class Main {
	public static int solve (int a, int b) {
		int s = 0;
		
		// Find the next odd number
		if (a%2 == 0) a++;
		
		// Are they equal? Sum b one more time
		if (a == b) {
			s += a;
		}
		
		// Sum each odd number
		while (a <= b) {
			s+=a;
			a+=2;
		}
		
		return s;
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner (System.in);
		int nofTests = s.nextInt();
		int i = 1;
		while (i <= nofTests) {
			int a = s.nextInt(),
				b = s.nextInt();
			
			System.out.printf ("Case %d: %d\n", i++, Main.solve(a, b));
		}
	}
}

