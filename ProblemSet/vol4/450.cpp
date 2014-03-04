// 450 - Little Black Book

#include <iostream>
#include "string.h"
#include "stdlib.h"

using namespace std;

struct person_type
{
	char title[50];
	char fname[100];
	char lname[100];
	char address[200];
	char hphone[20];
	char wphone[20];
	char mailbox[20];
};

struct dep_type
{
	char name[100];
	struct person_type person[1000];
	int person_no;
};

int supercmp(char a[], char b[])
{
	int type;
	int lena = strlen(a);
	int lenb = strlen(b);
	int i;
	
	for (i = 0; i < lena; i++)
	{
		if (i >= lenb)
			break;
        
		if (a[i] <= 'Z')
		{
			if (b[i] <= 'Z')
			{
				if (a[i] > b[i])		//a and b are capitalized.
				{
					type = 1;
					break;
				}
				else if (a[i] < b[i])
				{
					type = -1;
					break;
				}
			}
			else
			{
				if ((a[i] +32) > b[i])	//a is capitalized, b is uncapitalized.
				{
					type = 1;
					break;
				}
				else if ((a[i] +32) <= b[i])
				{
					type = -1;
					break;
				}
			}
		}
		else
		{
			if (b[i] <= 'Z')
			{
				if (a[i] >= (b[i] + 32))	//a is uncapitalized, b is capitalized
				{
					type = 1;
					break;
				}
				else if (a[i] < (b[i] + 32))
				{
					type = -1;
					break;
				}
			}
			else
			{
				if (a[i] > b[i])			//a and b are uncapitalized
				{
					type = 1;
					break;
				}
				else if (a[i] < b[i])
				{
					type = -1;
					break;
				}
			}
		}
	}
    
	//Length of same part is same.
	if ((i >= lena) || (i >= lenb))		
	{
		if (lena > lenb)
			type = 1;
		else if (lena == lenb)
			type = 0;
		else
			type = -1;
	}
    
	return type;
}

//reach end of input
bool check_over(char temp[])
{
	int len;
	int i;
    
	len = strlen(temp);
    
	if (len == 0)
		return true;
	else
	{
		for (i = 0; i < len; i++)
			if (temp[i] != ' ')
				break;
		if (i == len)
			return true;
	}
    
	return false;
}

void str_low(char a[], char b[])
{
	int len = strlen(a);
	int i;
    
	for (i = 0; i < len; i++)
	{
		if (a[i] <= 'Z')
			b[i] = a[i] + 32;
		else
			b[i] = a[i];
	}
	b[i] = '\0';
}

int main()
{
	struct dep_type dep[15];
	int dep_no;
	int dep_index[15];
	char temp[1000];
	char seps[] = ",\n";
	char *token;
	int i;
	int j;
    
	//initial
	for (i = 0; i < 12; i++)
	{
		dep[i].person_no = 0;
		dep_index[i] = 0;
	}
    
	//read input
	cin.getline(temp, 1000);
	dep_no = atoi(temp);
	for (i = 0; i < dep_no; i++)
	{
		cin.getline(dep[i].name, 100);
		while (cin.getline(temp, 1000))
		{
			if (check_over(temp))
				break;
			
			//convert input data format.
			token = strtok(temp, seps);
			strcpy(dep[i].person[dep[i].person_no].title, token);
			token = strtok(NULL, seps);
			strcpy(dep[i].person[dep[i].person_no].fname, token);
			token = strtok(NULL, seps);
			strcpy(dep[i].person[dep[i].person_no].lname, token);
			token = strtok(NULL, seps);
			strcpy(dep[i].person[dep[i].person_no].address, token);
			token = strtok(NULL, seps);
			strcpy(dep[i].person[dep[i].person_no].hphone, token);
			token = strtok(NULL, seps);
			strcpy(dep[i].person[dep[i].person_no].wphone, token);
			token = strtok(NULL, seps);
			strcpy(dep[i].person[dep[i].person_no].mailbox, token);
			dep[i].person_no++;
		}
	}
    
	//Print output a lname order.
	int min;
	while (true)
	{
		//Find first compared dep.
		for (i = 0; i < dep_no; i++)
			if (dep_index[i] < dep[i].person_no)
				break;
		if (i == dep_no)		//End of test.
			break;
        
		//Find minimum value.
		min = i;
		for (j = i + 1; j < dep_no; j++)
		{
			if (dep_index[j] < dep[j].person_no)
			{
				if (supercmp(dep[j].person[dep_index[j]].lname,
                             dep[min].person[dep_index[min]].lname) < 0)
					min = j;
			}
		}
        
		//print output
		cout << "----------------------------------------" << endl;
		cout << dep[min].person[dep_index[min]].title << ' ' << dep[min].person[dep_index[min]].fname << ' ' << dep[min].person[dep_index[min]].lname << endl;
		cout << dep[min].person[dep_index[min]].address << endl;
		cout << "Department: " << dep[min].name << endl;
		cout << "Home Phone: " << dep[min].person[dep_index[min]].hphone << endl;
		cout << "Work Phone: " << dep[min].person[dep_index[min]].wphone << endl;
		cout << "Campus Box: " << dep[min].person[dep_index[min]].mailbox << endl;
		dep_index[min]++;
	}
    
	return 0;
}