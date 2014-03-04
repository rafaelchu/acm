// 272 - TEX Quotes

#include <stdio.h>

int main()
{
	char Temp;
	int Q_count = 0;

	// Read input*
	while ((Temp = getchar()) !=  EOF) {
		if (Temp == '"') {
			Q_count++;
			if (Q_count % 2 == 1)
				printf("%c%c", '`', '`');
			else
				printf("%c%c", '\'','\'');
		}
		else
			printf("%c", Temp);
	};
	
	return 0;
}