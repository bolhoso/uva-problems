import org.junit.Test;
import static org.junit.Assert.*;

/**
 * Test for problem 102. 
 */
public class Problem102Test {
	@Test public void providedInput1 () {
		Main p = new Main();
		long bins[][] = {
			{1, 2, 3}, 
			{4, 5, 6},
			{7, 8, 9}
		};
		
		p.solve (bins);
		assertEquals (p.getBins(), "BCG");
		assertEquals (p.getMovements(), 30);
	}
	
	@Test public void providedInput2 () {
		Main p = new Main();
		long bins[][] = {
			{5, 10, 5},
			{20, 10, 5},
			{10, 20, 10}
		};
		
		p.solve (bins);
		assertEquals (p.getBins(), "CBG");
		assertEquals (p.getMovements(), 50);
	}
	
	@Test public void providedInput3 () {
		Main p = new Main();
		long bins[][] = {
				{2147483648L, 2147483648L, 2147483648L}, 
				{2147483648L, 2147483648L, 2147483648L},
				{2147483648L, 2147483648L, 2147483648L}
		};
		
		p.solve (bins);
		assertEquals (p.getBins(), "BCG");
		assertEquals (p.getMovements(), 12884901888L);
	}
}