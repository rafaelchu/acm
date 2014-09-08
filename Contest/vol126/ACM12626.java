/**
 * 12626 - I love Pizza
 * Time limit: 1.000 seconds
 * 
 * Time  complexity: O(n)
 * Space complexity: O(1)
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


class Main {
	
	public int parseIngredients(String line) {
		// No pizzas can be made.
		if (line.length() <= 0) {
			return 0;
		}
		
		int[] numIngredients = new int[6];	// "MARGIT"
		for (int i = 0; i < numIngredients.length; i++) {
			numIngredients[i] = 0;
		}
		
		// Calculate the count of MARGARITA.
		for (int i = 0; i < line.length(); i++) {
			if (line.charAt(i) == 'M') {
				numIngredients[0]++;
			} else if (line.charAt(i) == 'A') {
				numIngredients[1]++;
			} else if (line.charAt(i) == 'R') {
				numIngredients[2]++;
			} else if (line.charAt(i) == 'G') {
				numIngredients[3]++;
			} else if (line.charAt(i) == 'I') {
				numIngredients[4]++;
			} else if (line.charAt(i) == 'T') {
				numIngredients[5]++;
			}
		}
		
		// 'A' need 3, 'R' need 2.
		numIngredients[1] /= 3;
		numIngredients[2] /= 2;
		
		// Find the smallest value of "MARGIT".
		int pizzas = Integer.MAX_VALUE;
		for (int i = 0; i < numIngredients.length; i++) {
			if (numIngredients[i] < pizzas) {
				pizzas = numIngredients[i];
			}
		}
		
		return pizzas;
	}

	public static void main(String[] args) {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String line;
		int numTest = 0;
		
		// Read number of test cases.
		try {
			line = reader.readLine();
			numTest = Integer.parseInt(line);
		} catch (IOException e) {
		}
		
		for (int i = 0; i < numTest; i++) {
			// Read ingredients.
			try {
				line = reader.readLine();
			} catch (IOException e) {
				line = "";
			}
			
			// Parse ingredients.
			Main acm = new Main();
			int pizzas = acm.parseIngredients(line);
			
			// Output result.
			System.out.println(pizzas);
		}
	}
}
