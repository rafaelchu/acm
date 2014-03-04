// 628 - Passwords

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int  word_no;
	char dictionary[100][260];
	int  rule_no;
	char rule[260];
	int  zero_no;

	int i, j, k;

	//read input
	while(scanf("%d", &word_no) == 1) {
		//initial
		zero_no = 0;

		//read words
		for (i = 0; i < word_no; i++)
			scanf("%s", dictionary[i]);
		printf("--\n");

		//read rules
		scanf("%d", &rule_no);
		for (i = 0; i < rule_no; i++) {
			scanf("%s", &rule);

			for (i = 0; i < strlen(rule); i++)
				if (rule[i] == '0')
					zero_no++;

			//output result
			for (k = 0; k < word_no; k++)
				for (i = 0; i < pow(10, zero_no); i++) {
					int temp = i;
					int temp2 = zero_no;
					for (j = 0; j < strlen(rule); j++)
						if (rule[j] == '0') {
							int temp3 = temp / (int) pow(10, temp2 - 1);
							printf("%d", temp3);
							if (temp >= (int) pow(10, temp2 - 1))
								temp = temp - temp3 * (int) pow(10, temp2 - 1);
							temp2--;
						}
						else
							printf("%s", dictionary[k]);
					printf("\n");
				}
		}
	}
    
    return 0;
}