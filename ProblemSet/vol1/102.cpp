// 102 - Ecological Bin Packing.
// Time limit: 3.000 seconds

#include <iostream>
using namespace std;

unsigned int FindSteps(int bin_type, int brown_no[], int green_no[], int clear_no[])
{
	switch (bin_type) {
		case 0 : return brown_no[1] + brown_no[2] + clear_no[0] +  /*BCG*/
							 clear_no[2] + green_no[0] + green_no[1];
		case 1 : return brown_no[1] + brown_no[2] + clear_no[0] +  /*BGC*/
							 clear_no[1] + green_no[0] + green_no[2];
		case 2 : return brown_no[0] + brown_no[2] + clear_no[1] +  /*CBG*/
							 clear_no[2] + green_no[0] + green_no[1];
		case 3 : return brown_no[0] + brown_no[1] + clear_no[1] +  /*CGB*/
							 clear_no[2] + green_no[0] + green_no[2];
		case 4 : return brown_no[0] + brown_no[2] + clear_no[0] +  /*GBC*/
							 clear_no[1] + green_no[1] + green_no[2];
		case 5 : return brown_no[0] + brown_no[1] + clear_no[0] +  /*GCB*/
							 clear_no[2] + green_no[1] + green_no[2];
	}

	return 0xFFFFFFFF;
}

int main()
{
	int brown_no[3];
	int green_no[3];
	int clear_no[3];

	/*read the glass noumber in three bins*/
	while ( cin >> brown_no[0] ) 
	{
		cin >> green_no[0] >> clear_no[0];
		cin >> brown_no[1] >> green_no[1] >> clear_no[1];
		cin >> brown_no[2] >> green_no[2] >> clear_no[2];

		int bin_type = 0;
		unsigned int min_steps = FindSteps(0, brown_no, green_no, clear_no);

		for ( int i = 1; i <= 5; i++ ) {
			unsigned int temp = FindSteps(i, brown_no, green_no, clear_no);
			if (temp < min_steps) {
				bin_type = i;
				min_steps = temp;
			}
		}

		/*output result*/
		switch (bin_type) {
			case 0 : printf("BCG %d\n", min_steps); break;
			case 1 : printf("BGC %d\n", min_steps); break;
			case 2 : printf("CBG %d\n", min_steps); break;
			case 3 : printf("CGB %d\n", min_steps); break;
			case 4 : printf("GBC %d\n", min_steps); break;
			case 5 : printf("GCB %d\n", min_steps); break;
		}
	}

	return 0;
}