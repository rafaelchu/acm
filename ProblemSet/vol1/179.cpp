// 179 - Code Breaking

#include <string.h>
#include <iostream>

using namespace std;

//�ˬdk�ȬO�_���T
bool check_k(long start, long k, char sort_p[], char sort_c1[])
{
	long min_p;
	long min_c1;
	char temp;
	long i;
	long j;

	for (i = start; i < k; i++)
	{

		min_p = i;
		min_c1 = i;
		for (j = i + 1; j < k; j++)
		{
			if (sort_p[j] < sort_p[min_p])
				min_p = j;
			if (sort_c1[j] < sort_c1[min_c1])
				min_c1 = j;
		}

		//swap
		temp = sort_p[i];
		sort_p[i] = sort_p[min_p];
		sort_p[min_p] = temp;
		temp = sort_c1[i];
		sort_c1[i] = sort_c1[min_c1];
		sort_c1[min_c1] = temp;

		//�ˬd�O�_���۵�
		if (sort_p[i] != sort_c1[i])
			return false;				//k�Ȥ���
	}

	return true;	
}

//��X�ӥi�઺�ƦC
bool find_per(long k, long now, long& len, char plain[], char cry1[], bool used[], long per[])
{
	bool ans;
	int i;
	int j;
	int j2;

	if (now == k)		//���ͤF�@�ӥ��T��per
		return true;
	else
	{
		for (i = 0; i < k; i++)
			if ((plain[now] == cry1[i]) && (!used[i]))
			{
				//�ˬd���᪺�O���O�ŦX
				ans = true;
				j = now + k;
				j2 = i + k;				
				while ((j < len) && (j2 < len))
				{
					if (plain[j] != cry1[j2])
					{
						ans = false;
						break;
					}
					j = j + k;
					j2 = j2 + k;
				}

				//���᪺�]�ŦX
				if (ans)
				{
					per[now] = i;
					used[i] = true;
					ans = find_per(k, now + 1, len, plain, cry1, used, per);
					if (ans)
						return true;
					used[i] = false;
				}
			}
	}

	return false;
}


int main()
{
	long len;
	char plain[100];
	char cry1[100];
	long len_c2;
	char cry2[100];
	char sort_p[100];
	char sort_c1[100];
	long per[100];		//�ƦC
	bool used[100];
	long k;
	long i;
	long j;

	//read input
	cin.getline(plain, 100);
	while (strcmp(plain, "#") != 0)
	{
		cin.getline(cry1, 100);
		cin.getline(cry2, 100);

		//initial
		len = strlen(plain);
		len_c2 = strlen(cry2);
		for (i = 0; i < 100; i++)
			used[i] = false;

		//��X��k��
		strcpy(sort_p, plain);
		strcpy(sort_c1, cry1);
		for (k = 1; k <= len; k++)
			if (check_k(0, k, sort_p, sort_c1))
			{
				//��X��k�϶����ƦC���ˬd�o�ӱƦC�O�_�i��
				bool ans = find_per(k, 0, len, plain, cry1, used, per);

				if (ans)
					break;
			}

		//output result
		if (k <= len)
		{
			for (i = 0; i < len_c2; i = i + k)
				for (j = 0; j < k; j++)
				{
					if (i+per[j] < len_c2)
						cout << cry2[i+per[j]];
					else
						cout << '?';	//�W�L���ץ�?��
				}
			cout << endl;
		}
		else
			cout << cry2 << endl;

		cin.getline(plain, 100);
	}

	return 0;
}