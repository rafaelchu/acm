import java.util.Scanner;

public class Main {

	static int calculate_count(int number) {
		int count = 1;
		while (number > 1) {
			if (number % 2 != 0)
				number = number * 3 + 1;
			else
				number = number / 2;
			count++;
		}

		return count;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int val1;
		int val2;

		Scanner sc = new Scanner(System.in);
		while (sc.hasNextInt()) {
			val1 = sc.nextInt();
			val2 = sc.nextInt();

			int max_count = 0;
			if (val1 <= val2) {
				for (int i = val1; i <= val2; i++) {
					int count = calculate_count(i);
					if (count > max_count)
						max_count = count;
				}
			} else {
				for (int i = val2; i <= val1; i++) {
					int count = calculate_count(i);
					if (count > max_count)
						max_count = count;
				}
			}

			System.out
					.println(String.format("%d %d %d", val1, val2, max_count));
		}
	}
}
