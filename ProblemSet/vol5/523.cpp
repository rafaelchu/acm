// 523- Minimum Transport Cost

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

const long CITYSIZE = 200;
const long INF = 1000000000;

void find_path(long path[][CITYSIZE], long s, long e) {
   if (path[s][e] == -1)
      return;

   find_path(path, s, path[s][e]);
   cout << "-->" << path[s][e] + 1;
   find_path(path, path[s][e], e);
}

int submain() {
   long case_no;
   long n;
   long graph[CITYSIZE][CITYSIZE];
   long tax[CITYSIZE];
   long path[CITYSIZE][CITYSIZE];
   long sc;
   long ec;
   char line[10000];
   char sep[] = " \n";
   char* token;
   long i;
   long j;
   long k;

   //read input
   cin.getline(line, 10000);
   n = 0;

   token = strtok(line, sep);
   while (token) {
      graph[0][n] = atol(token);

      if (graph[0][n] == -1)
         graph[0][n] = INF;

      n++;
      token = strtok(NULL, sep);
   }

   for (i = 1; i < n; i++) {
      cin.getline(line, 10000);

      token = strtok(line, sep);
      for (j = 0; j < n; j++) {
         graph[i][j] = atol(token);

         if (graph[i][j] == -1)
            graph[i][j] = INF;

         token = strtok(NULL, sep);
      }
   }

   cin.getline(line, 10000);
   token = strtok(line, sep);
   for (i = 0; i < n; i++) {
      tax[i] = atol(token);
      token = strtok(NULL, sep);
   }

   //initial
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
         path[i][j] = -1;
   case_no = 0;

   //find shortest path
   for (k = 0; k < n; k++)
      for (i = 0; i < n; i++)
         for (j = 0; j < n; j++)
            if (graph[i][k] + graph[k][j] + tax[k] < graph[i][j]) {
               graph[i][j] = graph[i][k] + graph[k][j] + tax[k];
               path[i][j] = k;
            }

   //read cargo
   while (cin.getline(line, 10000)) {
      if (strlen(line) == 0)
         break;

      case_no++;
      sscanf(line, "%ld %ld", &sc, &ec);

      //output result
      if (case_no > 1)
         cout << endl;
      cout << "From " << sc << " to " << ec << " :" << endl;
      cout << "Path: " << sc;
      find_path(path, sc-1, ec-1);
      cout << "-->" << ec << endl;
      cout << "Total cost : " << graph[sc-1][ec-1] << endl;
   }

   return 0;
}

int main() {
   long n;
   long i;
   char line[100];

   cin.getline(line, 100);
   n = atol(line);
   cin.getline(line, 100);
   for (i = 0; i < n - 1; i++) {
      submain();
      cout << endl;
   }
   submain();
}