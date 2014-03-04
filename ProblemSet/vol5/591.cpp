// 591 - Box of Bricks

#include <stdio.h>

int main()
{
	int count;
	int stack_number;
	int stacks[50];
    int sum;
    int level;

	count = 0;
	scanf("%d", &stack_number);
	while (stack_number != 0) {

        sum = 0;
		//read input
		for (int i = 0; i < stack_number; i++) {
			scanf("%d", &stacks[i]);
			sum = sum + stacks[i];
		}

		level = sum / stack_number;
		sum = 0;
		for (int i = 0; i < stack_number; i++) {
			if (stacks[i] > level)
				sum = sum + stacks[i] - level;
		}

		//output result
		count++;
		printf("Set #%d\n", count);
		printf("The minimum number of moves is %d.\n", sum);

		scanf("%d", &stack_number);
		if (stack_number != 0) {
			printf("\n");
		}
	}
    
    return 0;
}