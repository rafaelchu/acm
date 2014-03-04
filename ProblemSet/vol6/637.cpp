// 637 - Booklet Printing

#include <iostream>

using namespace std;

int main()
{
	int n;
	int sheet;
	int page[120];
	int page_index;
	int counter;
	bool forward;		//fill page number forward/backward
	
	//read input
	for (cin >> n; n > 0; cin >> n)
	{
		if (n % 4 == 0)
			sheet = n / 4;
		else
			sheet = n / 4 + 1;

		counter = 1;
		page_index = 1;
		forward = true;
        
		//fill page numbers
		do
		{
			if (counter <= n)		//n is filled or not
				page[page_index] = counter++;
			else 
				page[page_index] = 0;

			if (forward)
				page_index = page_index + 1;
			else
				page_index = page_index - 3;

			if (counter <= n)		//n is filled or not
				page[page_index] = counter++;
			else 
				page[page_index] = 0;

			if (forward)
				page_index = page_index + 3;
			else
				page_index = page_index - 1;

			//forward or backward checking
			if (page_index > sheet * 4)
			{
				forward = false;
				page_index = page_index - 2;
			}
		} while (page_index >= 0);

		//output result
		cout << "Printing order for " << n << " pages:" << endl;
		page_index = 0;
		for (counter = 1; counter <= sheet; counter++)
		{		
			//ouput sheet front
			if (page[page_index] || page[page_index + 1])
			{
				cout << "Sheet " << counter << ", front: ";
				if (page[page_index])
					cout << page[page_index++] << ", ";
				else
				{
					page_index++;
					cout << "Blank" << ", ";					
				}

				if (page[page_index])
					cout << page[page_index++] << endl;
				else
				{
					page_index++;
					cout << "Blank" << endl;
				}
			}
			else
				page_index = page_index + 2;

			//ouput sheet back
			if (page[page_index] || page[page_index + 1])
			{
				cout << "Sheet " << counter << ", back : ";
				if (page[page_index])
					cout << page[page_index++] << ", ";
				else
				{
					page_index++;
					cout << "Blank" << ", ";					
				}

				if (page[page_index])
					cout << page[page_index++] << endl;
				else
				{
					page_index++;
					cout << "Blank" << endl;
				}
			}
			else
				page_index = page_index + 2;
		}
	}
    
    return 0;
}