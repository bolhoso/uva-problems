import org.junit.Test;
import static org.junit.Assert.*;

public class TestProblem {
	@Test public void baseTests() {
		assertEquals(1+3+5, OddSum.solve (1, 5));
		assertEquals(3+5, OddSum.solve (3, 5));
	}
	
	@Test public void testLimits () {
		assertEquals(2500, OddSum.solve (1, 100));
		assertEquals(2, OddSum.solve (1, 1));
		assertEquals(0, OddSum.solve (100, 100));
	}
}

