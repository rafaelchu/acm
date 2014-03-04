// 324 - Factorial Frequencies

#include <iostream>
#include <iomanip>
#include "string.h"
#include "stdlib.h"

using namespace std;

const int SZ = 1200;		

class verylong
{
private:
	char vlstr[SZ];									//digit
	int  vlen;											//length of digit
	verylong multdigit(const int) const;
	verylong mult10(const verylong) const;
	void reverse(char s[SZ]);						
   void change(unsigned long in_integer, char s[]);		

public:
	verylong() : vlen(0)					//constructor
	{
		vlstr[0]='\0';
	}
	verylong(const char s[SZ])			//constructor for string
	{
		vlen = (int)strlen(s);
		strcpy(vlstr,s);
	}
	verylong(const unsigned long n)	//constructor fot long int
	{
		change(n, vlstr);		
		vlen = (int)strlen(vlstr);
	}

	//operator
	verylong add(const verylong);
	verylong mult(const verylong);

	void set(const char s[SZ])		
	{		
		vlen = (int)strlen(s);
		strcpy(vlstr,s);
		reverse(vlstr);				
	}
	void get(char s[])				
	{
		strcpy(s, vlstr);
		reverse(s);
	}	
};

verylong verylong::add(const verylong v)
{
	char temp[SZ];
	int cj;
	int maxlen = (vlen > v.vlen) ? vlen : v.vlen;	
	int carry = 0;												

	for (cj = 0; cj < maxlen; cj++)
	{
		int d1 = (cj > vlen - 1)   ? 0 : vlstr[cj]   - '0';
		int d2 = (cj > v.vlen - 1) ? 0 : v.vlstr[cj] - '0';
		int digitsum = d1 + d2 + carry;

		if (digitsum >= 10)
		{
			digitsum -= 10;
			carry = 1;
		}
		else
			carry = 0;
		temp[cj] = digitsum + '0';
	}

	if (carry == 1)
		temp[cj++] = '1';
	temp[cj] = '\0';					

	return verylong(temp);
}

verylong verylong::mult(const verylong v)
{
	verylong pprod;
	verylong tempsum;

	for (int cj = 0; cj < v.vlen; cj++)
	{
		int digit = v.vlstr[cj] - '0';		
		pprod = multdigit(digit);
		for (int ck = 0; ck < cj; ck++)
			pprod = mult10(pprod);
		tempsum = tempsum.add(pprod);
	}

	return tempsum;
}

verylong verylong::mult10(const verylong v) const
{
	char temp[SZ];

	for (int cj = v.vlen - 1; cj >= 0; cj--)
		temp[cj+1] = v.vlstr[cj];
	temp[0] = '0';
	temp[v.vlen+1] = '\0';

	return verylong(temp);
}

verylong verylong::multdigit(const int d2) const
{
	char temp[SZ];	
	int carry = 0;
	int cj;

	for (cj = 0; cj < vlen; cj++)
	{
		int d1 = vlstr[cj] - '0';
		int digitprod = d1 * d2;		
		digitprod += carry;

		if (digitprod >= 10)
		{
			carry = digitprod / 10;
			digitprod -= carry * 10;
		}
		else
			carry = 0;

		temp[cj]= digitprod + '0';
	}

	if (carry != 0)
		temp[cj++] = carry + '0';
	temp[cj] = '\0';

	return verylong(temp);
}

void verylong::reverse(char s[])
{
	char temp[SZ];
	int len;	
	int oldptr;
	int newptr;

	len = (int)strlen(s);
	oldptr = len - 1;	
	for (newptr = 0; newptr < len; newptr++)
		temp[newptr] = s[oldptr--];
	temp[newptr] = '\0';
	strcpy(s, temp);
}

void verylong::change(unsigned long in_integer, char s[])
{		
	unsigned long temp_r;	
	int index;

	index = -1;	
	while (in_integer >= 10)
	{
		temp_r = in_integer % 10;		
		in_integer = in_integer / 10;		
		s[++index] = temp_r + '0';
	}
	
	s[++index] = in_integer + '0';	
	s[++index] = '\0';
}

int main()
{
	char ans[502][SZ];		//result from 0! to 500!
	verylong fact = 1;
	int digitno[10];
	int n;
	int cj;

	//initialize
	ans[0][0] = '1';
	ans[0][1] = '\0';
	ans[1][0] = '1';
	ans[1][1] = '\0';
	for (cj = 2; cj < 502; cj++)
	{
		fact = fact.mult(cj);
		fact.get(ans[cj]);
	}
	
	//read input
	while (true)
	{
		cin >> n;
		if (n == 0)	
			break;

		//output result
		for (cj = 0; cj < 10; cj++)
			digitno[cj] = 0;
		for (cj = 0; cj < strlen(ans[n]); cj++)
			digitno[ans[n][cj] - '0']++;

		cout << n << "! --" << endl;
		for (cj = 0; cj <= 4; cj++)
		{
			cout << setw(4) << '(' << cj << ')';
			cout << setw(4) << digitno[cj];
		}
		cout << endl;

		for (; cj <= 9; cj++)
		{
			cout << setw(4) << '(' << cj << ')';
			cout << setw(4) << digitno[cj];
		}
		cout << endl;
	}
	
	return 0;
}
