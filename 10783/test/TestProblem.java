import org.junit.Test;
import static org.junit.Assert.*;

public class TestProblem {
	@Test public void baseTests() {
		assertEquals(1+3+5, Main.solve (1, 5));
		assertEquals(3+5, Main.solve (3, 5));
	}
	
	@Test public void testLimits () {
		assertEquals(2500, Main.solve (0, 100));
		assertEquals(2, Main.solve (1, 1));
		assertEquals(0, Main.solve (100, 100));
		assertEquals(0, Main.solve (0, 0));
	}

}

