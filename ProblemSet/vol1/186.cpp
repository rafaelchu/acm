// 186 - Trip Routing

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

const long INF = 100000000;

struct route_type
{
	char name[15];
	int start;
	int end;
};

void find_path(int path[][110], int s, int e, int anspath[], int& ans_no)
{
	if (path[s][e] != 0)
	{
		find_path(path, s, path[s][e], anspath, ans_no);
		anspath[ans_no] = path[s][e];
		ans_no++;
		find_path(path, path[s][e], e, anspath, ans_no);
	}
}

int main()
{	
	int  city_no;
	char city[110][25];
	int  route_no;
	route_type route[210];
	long weight[110][110];		//normal path cost
	long sweight[110][110];		//shortest path cost
	int  path[110][110];		//shortest path
	int  ans_no;				
	int  anspath[110];				
	int  report_no;
	char line[200];	
	char sep[] = ",\n";			
	char* word;
	char* digit;
	long dis;
	int  city1;
	int  city2;
	int  i;
	int  j;
	
	//intial
	city_no = 0;
	route_no = 0;
	for (city1 = 0; city1 < 110; city1++)
		for (city2 = 0; city2 < 110; city2++)				
			weight[city1][city2] = INF;
	for (city1 = 0; city1 < 110; city1++)
		weight[city1][city1] = 0;

	//read input 1
	cin.getline(line, 200);
	while (strlen(line) > 0)
	{
		//find cities
		word = strtok(line, sep);
		for (city1 = 0; city1 < city_no; city1++)
			if (strcmp(word, city[city1]) == 0)
				break;
		if (city1 >= city_no)
		{
			strcpy(city[city_no], word);
			city_no++;
		}

		word = strtok(NULL, sep);
		for (city2 = 0; city2 < city_no; city2++)
			if (strcmp(word, city[city2]) == 0)
				break;
		if (city2 >= city_no)
		{
			strcpy(city[city_no], word);
			city_no++;
		}

		//let city1 < city2
		if (city1 > city2)
		{
			int temp = city1;
			city1 = city2;
			city2 = temp;
		}

		//store the route name between two cities
		word = strtok(NULL, sep);
		for (i = 0; i < route_no; i++)
			if ((route[i].start == city1) && (route[i].end == city2))
				 break;
		if (i >= route_no)	//new route			
			route_no++;		

		digit = strtok(NULL, sep);
		dis = atol(digit);
		if (dis < weight[city1][city2])
		{
			//change route
			weight[city1][city2] = dis;
			weight[city2][city1] = dis;
			strcpy(route[i].name, word);
			route[i].start = city1;
			route[i].end   = city2;
		}

		cin.getline(line, 200);
	}

	//calculate allpair shortest path and route
	for (city1 = 0; city1 < city_no; city1++)
		for (city2 = 0; city2 < city_no; city2++)
		{
			path[city1][city2] = 0;
			sweight[city1][city2] = weight[city1][city2];
		}

	for (i = 0; i < city_no; i++)
		for (city1 = 0; city1 < city_no; city1++)
			for (city2 = 0; city2 < city_no; city2++)
				if (sweight[city1][i] + sweight[i][city2] < sweight[city1][city2])
				{
					path[city1][city2] = i;
					sweight[city1][city2] = sweight[city1][i] + sweight[i][city2];
				}

	//read input 2
	report_no = 0;
	while (cin.getline(line, 200))
	{
		report_no++;
		//find cities
		word = strtok(line, sep);
		for (city1 = 0; city1 < city_no; city1++)
			if (strcmp(word, city[city1]) == 0)
				break;
		if (city1 >= city_no)
		{
			strcpy(city[city_no], word);
			city_no++;
		}

		word = strtok(NULL, sep);
		for (city2 = 0; city2 < city_no; city2++)
			if (strcmp(word, city[city2]) == 0)
				break;
		if (city2 >= city_no)
		{
			strcpy(city[city_no], word);
			city_no++;
		}

		//find out answer
		anspath[0] = city1;
		ans_no = 1;		
		find_path(path, city1, city2, anspath, ans_no);
		anspath[ans_no] = city2;
		ans_no++;

		//output result
		if (report_no > 1)
			cout << endl << endl;
		cout << "From                 To                   Route      Miles" << endl;
		cout << "-------------------- -------------------- ---------- -----" << endl;
		for (i = 0; i < ans_no - 1; i++)
		{
			cout << setiosflags(ios::left) << setw(20) << city[anspath[i]] << ' ';
			cout << setw(20) << city[anspath[i+1]] << ' ';			
			for (j = 0; j < route_no; j++)
				if (((route[j].start == anspath[i]) && (route[j].end == anspath[i+1])) || 
					 ((route[j].start == anspath[i+1]) && (route[j].end == anspath[i])))
					 break;
			cout << setw(10) << route[j].name << ' ';
			cout << resetiosflags(ios::left) << setw(5)  << weight[anspath[i]][anspath[i+1]] << endl;
		}
		cout << "                                                     -----" << endl;
		cout << "                                          Total" << setw(11) << sweight[city1][city2] << endl;
	}

	return 0;
}

