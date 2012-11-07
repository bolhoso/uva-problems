import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main {
	private long movements;
	private int solution;
	
	// TODO: jeito tosko
	private static final int orders[][] = {
		{0, 2, 1}, // BCG
		{0, 1, 2}, // BGC
		{2, 0, 1}, // CBG
		{2, 1, 0}, // CGB
		{1, 0, 2}, // GBC
		{1, 2, 0}  // GCB
	};
	private static final char bins[] = {'B', 'G', 'C'};

	enum Bottles {
		BROWN, GREEN, CLEAR
	}
	
	private long calcMoves (long bins[][], int comb) {
		long sum = 0;
		
		
		for (int pColor = 0; pColor < bins.length; pColor++) {
			for (int bin = 0; bin < bins.length; bin++) {
				if (pColor != bin) { 
					int id = orders[comb][pColor];
					long i = bins[bin][id];
					sum += i;
				}
			}
		}

		return sum;
	}
	
	public void solve (long bins[][]) {
		int smallestIdx = 0;
		long minMovs = Long.MAX_VALUE;
		for (int i = 0; i < orders.length; i++) {
			long nofMoves = calcMoves (bins, i);
				
			if (nofMoves < minMovs) {
				smallestIdx = i;
				minMovs     = nofMoves;
			}
		}
		
		this.solution  = smallestIdx;
		this.movements = minMovs;
	}

	public String getBins () {
		StringBuffer sb = new StringBuffer();
		sb.append (bins[orders[this.solution][0]]);
		sb.append (bins[orders[this.solution][1]]); 
		sb.append (bins[orders[this.solution][2]]); 
		
		return sb.toString();
	}
	
	public long getMovements() {
		return this.movements;
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(new BufferedInputStream(System.in));
		Main p = new Main();

		while (scanner.hasNext()) {
			long bins[][]= {
					{scanner.nextLong(), scanner.nextLong(), scanner.nextLong()},
					{scanner.nextLong(), scanner.nextLong(), scanner.nextLong()},
					{scanner.nextLong(), scanner.nextLong(), scanner.nextLong()}
			};
				
			p.solve(bins);
			System.out.printf ("%s %d\n", p.getBins(), p.getMovements());
		}
	}
}
