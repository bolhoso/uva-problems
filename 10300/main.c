#include <stdio.h>

int main () {
	int tests = 0;
	scanf ("%d\n", &tests);

	while (tests > 0) {
		long budget = 0;
		int farmers;
		scanf ("%d\n", &farmers);

		int curr_farmer = 0;
		for (curr_farmer = 0; curr_farmer < farmers; curr_farmer++) {
			int size, nof_animals, env_friend;
			char dummy;
			scanf ("%d %d %d%c", &size, &nof_animals, &env_friend, &dummy);

			budget += size * env_friend;
		}

		printf ("%ld\n", budget);
		tests--;
	}

	return 0;
}
