// 140 - Bandwidth

#include <iostream>
#include <string.h>
#include <stdlib.h>


const int INF = 100;

int find_max(int no, long node[], bool path[][26])
{
    int bandwidth;
    int i;
    int j;
    int k;
    
    //initial
    bandwidth = 0;
    
    for (i = 0; i < no; i++)
        for (j = 0; j < 26; j++)
            if (path[node[i]][j])
            {
                for (k = 0; k < no; k++)
                    if (node[k] == j)
                        break;
                k = k - i;
                if (k > bandwidth)
                    bandwidth = k;
            }
    
    return bandwidth;        
}


int main()
{
	bool path[26][26];
	int  no;				
	bool used[26];			
	long node[10];			
	int  ans;				
	long ans_node[10];		
	int  bandwidth;
	long bound[10];			
	char sep[] = ";\n";
	char* token;
	char line[200];
	long i;
	long j;
	long k;

	//initial
	bound[0] = 1;
	for (i = 1; i <= 8; i++)
		bound[i] = bound[i-1] * i;
	for (i = 2; i <= 8; i++)
		bound[i] = bound[i] / 2;

	//read input
	std::cin.getline(line, 200);
	while (strcmp(line, "#") != 0)
	{
		//initial
		for (i = 0; i < 26; i++)
			for (j = 0; j < 26; j++)
				path[i][j] = false;
		for (i = 0; i < 26; i++)
			used[i] = false;
		ans = INF;

		token = strtok(line, sep);
		while (token)
		{
			used[token[0]-'A'] = true;
			for (i = 2; i < strlen(token); i++)
			{
				path[token[0]-'A'][token[i]-'A'] = true;
				path[token[i]-'A'][token[0]-'A'] = true;
				used[token[i]-'A'] = true;
			}

			token = strtok(NULL, sep);
		}

		no = 0;
		for (i = 0; i < 26; i++)
		{
			if (used[i])
				node[no++] = i;
		}

		for (i = 0; i < bound[no]; i++)
		{
			bandwidth = find_max(no, node, path);
			if ((bandwidth < ans) && (bandwidth != 0))
			{
				ans = bandwidth;
				for (j = 0; j < no; j++)
					ans_node[j] = node[j];
			}

			for (j = no - 2; j > 0; j--) 
				if (node[j] < node[j + 1])
					break;

			for (k = no - 1; node[j] > node[k]; k--);
			long temp = node[j];
			node[j] = node[k];
			node[k] = temp;

			j = j + 1;
			k = no - 1;
			while (j < k)
			{
				temp = node[j];
				node[j] = node[k];
				node[k] = temp;

				j++;
				k--;
			}
		}

		//output result
		for (i = 0; i < no; i++)
			std::cout << static_cast<char>(ans_node[i] + 'A') << ' ';
		std::cout << "-> " << ans << "\n";

		std::cin.getline(line, 200);
	}

	return 0;
}