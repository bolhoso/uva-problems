public class OddSum {
	public static int solve (int a, int b) {
		int s = 0;
		if (a%2 == 0) {
			a++;
		} else if (a == b) {
			s += a;
		}
		while (a <= b) {
			s+=a;
			a+=2;
		}
		
		return s;
	}
	
	public static void main(String[] args) {

	}
}

