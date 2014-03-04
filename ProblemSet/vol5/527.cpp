// 527 - The partition of a cake

#include <iostream>

using namespace std;

struct p_type {
   double x;
   double y;
};

//Check lines are cross or not ( 0 < x < 1000, 0 < y < 1000)
bool line_inter(p_type line1[], p_type line2[], p_type& point) {

   double a1,a2, b1,b2;

   a1 = ( line1[0].y - line1[1].y );
   a2 = ( line2[0].y - line2[1].y );
   b1 = ( line1[1].x - line1[0].x );
   b2 = ( line2[1].x - line2[0].x );

   if ( a1*b2 - a2*b1 == 0 )
      return false;

   double c1, c2;
   double x1, y1;

   c1 = line1[0].x * line1[1].y - line1[1].x * line1[0].y;
   c2 = line2[0].x * line2[1].y - line2[1].x * line2[0].y;

   x1 = (b1*c2-b2*c1) / (a1*b2 - a2*b1);
   y1 = (a1*c2-a2*c1) / (a2*b1 - a1*b2);

   point.x = x1;
   point.y = y1;

   if ((x1 > 0) && (x1 < 1000) && (y1 > 0) && (y1 < 1000))
      return true;
   else
      return false;
}

//Find out how many regions
long find_region(long line_no, p_type line[][2]) {
   long p_no;
   p_type point[40];
   long ans;
   long i;
   long j;
   long k;


   //initial
   ans = 1;

   for (i = 0; i < line_no; i++) {
      ans++;

      p_no = 0;
      for (j = 0; j < i; j++)
         if (line_inter(line[j], line[i], point[p_no])) {
            for (k = 0; k < p_no; k++)
               if ((point[k].x == point[p_no].x) && (point[k].y == point[p_no].y))
                  break;

            if (k >= p_no)
               p_no++;
         }

      ans = ans + p_no;
   }

   return ans;
}

int submain() {
   long n;
   long line_no;
   p_type line[10][2];
   long ans;
   long i;
   long j;

   line_no = 0;

   //read input
   cin >> n;
   for (i = 0; i < n; i++) {
      cin >> line[line_no][0].x >> line[line_no][0].y >> line[line_no][1].x >> line[line_no][1].y;

      for (j = 0; j < line_no; j++)
         if ((line[j][0].x == line[line_no][0].x) && (line[j][0].y == line[line_no][0].y)
             && (line[j][1].x == line[line_no][1].x) && (line[j][1].y == line[line_no][1].y))
             break;
         else if ((line[j][1].x == line[line_no][0].x) && (line[j][1].y == line[line_no][0].y)
             && (line[j][0].x == line[line_no][1].x) && (line[j][0].y == line[line_no][1].y))
             break;

      if (j >= line_no)
         line_no++;
   }

   //find answer
   ans = find_region(line_no, line);

   //output result
   cout << ans << endl;

   return 0;
}

int main() {
   long n;
   long i;

   cin >> n;
   for (i = 0; i < n - 1; i++)   {
      submain();
      cout << endl;
   }
   submain();

   return 0;
}
