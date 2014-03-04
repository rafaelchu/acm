// 630 - Anagrams (II)

#include <stdio.h>
#include <string.h>

struct WordTable {
    char origin[22];
    char sorted[22];
};

void SelectionSort(char word[], int count)
{
	int smallest;
	char temp;

	for (int j = 0; j < count - 1; j++) {
		smallest = j;
		for (int k = j + 1; k < count; k++)
			if (word[k] < word[smallest])
				smallest = k;

		temp = word[j];
		word[j] = word[smallest];
		word[smallest] = temp;
	}
}

void SubMain(void)
{
	int n;
	char word[25];
	struct WordTable word_table[1010];
	char result[1010][25];
	int result_count;
	char temp_word[25];

    // read input
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", word_table[i].origin);
		strcpy(word_table[i].sorted, word_table[i].origin);
		SelectionSort(word_table[i].sorted, strlen(word_table[i].sorted));
	}

	for (scanf("%s", word); strcmp(word, "END"); scanf("%s", word)) {
		// initial
		result_count = 0;
		strcpy(temp_word, word);
		SelectionSort(temp_word, strlen(temp_word));

		// find sutible answer
		for (int i = 0; i < n; i++) {
			if (strcmp(temp_word, word_table[i].sorted) == 0) {
				// check dublicate
                int j;
				for (j = 0; j < result_count; j++) {
					if (strcmp(word_table[i].origin, result[j]) == 0)
						break;
				}
				if (j == result_count)
					strcpy(result[result_count++], word_table[i].origin);
			}
		}

		// output result
		printf("Anagrams for: %s\n", word);
		if (result_count > 0)
			for (int i = 0; i < result_count; i++)
				printf("%3d) %s\n", i + 1, result[i]);
		else
			printf("No anagrams for: %s\n", word);
	}
}

int main()
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		SubMain();
		printf("\n");
	}
	SubMain();
    
    return 0;
}