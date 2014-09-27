/**
 * 11069 - A Graph Problem
 * Time limit: 3.000 seconds
 * 
 * Time  complexity: O(n)
 * Space complexity: O(n)
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


class Main {
	static final int MAX_NODES = 76;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int[] answer = new int[MAX_NODES];
		
		answer[0] = 1;
		answer[1] = 2;
		answer[2] = 2;
		for (int i = 3; i < MAX_NODES; i++) {
			answer[i] = answer[i-2] + answer[i-3];
		}
		
		// Read input
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String line;
		int n;
		
		do {
			n = 0;
			try {
				line = reader.readLine();
				if (line != null && line.length() > 0) {
					n = Integer.parseInt(line);					
				}
			} catch (IOException e) {
			}		

			// Write output.
			if (n >= 1 && n <= MAX_NODES) {
				System.out.println(answer[n-1]);
			}
		} while (n >= 1) ;
	}
}
