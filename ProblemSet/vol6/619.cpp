// 619 - Numerically Speaking

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

class BigNum 
{
	int digit[100];

public:
	BigNum();
	BigNum(char *); // for numeric string

	void mult_by_int(int factor);
	void divide_by_int(int dividend, int &remainder);
	void add_bignum(BigNum &);
	void del_one();
	void print();
	int is_nonzero();
};

// initialize to 0
BigNum::BigNum() 
{
	for (int i = 0; i < 100; i++) 
		digit[i] = 0;
}

// set from a numeric string (most-to-least in significance).
BigNum::BigNum(char *str) 
{
	int i, j;

	for (i=0; i<100; i++)
		digit[i] = 0;

	j = strlen(str) - 1;
	i = 0;
	while (j >= 0) 
	{
		digit[i] = str[j] - '0';
		j--;
		i++;
	}
}

void BigNum::mult_by_int(int factor) {

	int carry = 0;

	for (int i=0; i<100; i++) 
	{
		carry += digit[i] * factor;
		digit[i] = carry % 10;
		carry /= 10;
	}
}

void BigNum::divide_by_int(int dividend, int &remainder) 
{
	int i = 99;

	remainder = 0;
	while (digit[i] == 0)
		i--;
	while (i >= 0) 
	{
		remainder = remainder * 10 + digit[i];
		digit[i] = 0;
		if (dividend <= remainder) {
			digit[i] = remainder / dividend;
			remainder %= dividend;
		}
		i--;
	}
}

void BigNum::add_bignum(BigNum &other) 
{
	int carry = 0;

	for (int i=0; i<100; i++) 
	{
		carry += digit[i] + other.digit[i];
		digit[i] = carry % 10;
		carry /= 10;
	}
}

//assume the result is positive or 0.
void BigNum::del_one()
{
	int i;

	digit[0]--;

	if (digit[0] < 0)
	{			
		for (i = 1; i < 100; i++)
			if (digit[i] > 0)
				break;

		digit[i]--;
		for (i = i - 1; i > 0; i--)
			digit[i] = digit[i] + 9;

		digit[0] = digit[0] + 10;
	}
}


void BigNum::print() 
{
	int i = 99;

	while (digit[i] == 0 && i >= 0) 
		i--;

	while (i >= 0) 
	{
		putchar('0' + digit[i]);

		if (i && !(i % 3))
			putchar(',');
		i--;
	}
}

int BigNum::is_nonzero() 
{
	int i;

	for (i=0; i<100; i++) 
	{
		if (digit[i]) 
			return 1;
	}

	return 0;
}

void convertNumToWord(BigNum num, char word[]) 
{
	int char_no = 0;
	int remainder;

	/* write out the word in least-to-most significance */
	while (num.is_nonzero()) 
	{
		num.divide_by_int(26, remainder);
		if (remainder == 0)
		{
			num.del_one();
			remainder = 26;
		}
		word[char_no++] = remainder + 'a' - 1;
	}

	word[char_no] = 0;

	/* reverse the word */
	char *a = word, *b = word + char_no - 1;
	while (a < b) 
	{
		char c = *a;
		*a = *b;
		*b = c;
		a++; b--;
	}
}

BigNum convertWordToNum(char word[]) 
{
	BigNum num, tmp;
	int char_no;

	char_no = 0;
	while (word[char_no]) 
	{
		num.mult_by_int(26);
		tmp = "1";
		tmp.mult_by_int(word[char_no] - 'a' + 1);
		num.add_bignum(tmp);
		char_no++;
	}

	return num;
}

int main() 
{
	char input[100];

    //read input
	while (scanf("%s", input), strcmp(input, "*")) 
	{
		BigNum num;
		if (isdigit(input[0])) 
		{
			num = BigNum(input);
			char word[100];
			convertNumToWord(num, word);
			printf("%-22s", word);
		} 
		else 
		{
			num = convertWordToNum(input);
			printf("%-22s", input);
		}

        //output result
		num.print();

		printf("\n");
	}

	return 0;
}