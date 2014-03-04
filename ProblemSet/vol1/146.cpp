// 146 - ID Codes

#include <stdio.h>
#include <string.h>

int main()
{
	char Word[50];
	int  Word_len;
	char Temp;

	int J;
	int K;

	/*Read input*/
	for (scanf("%s", Word); Word[0] != '#'; scanf("%s", Word)) {
		Word_len = strlen(Word);

		/*Find successor*/
		for (J = Word_len - 1; J > 0;) {
			if (Word[J - 1] >= Word[J])
				J--;
			else {
				for (K = Word_len - 1; K >= J - 1; K--)
					if (Word[K] > Word[J - 1])
						break;

				Temp = Word[J - 1];
				Word[J - 1] = Word[K];
				Word[K] = Temp;

				break;
			}
		}

		/*Output result*/
		if (J != 0) {
			for (K = 0; K <= J - 1; K++)
				printf("%c", Word[K]);
			for (K = Word_len - 1; K >= J; K--)
				printf("%c", Word[K]);
			printf("\n");
		}
		else
			printf("No Successor\n");
	}
    
    return 0;
}