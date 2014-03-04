// 588 - Video Surveillance

#include <stdio.h>

const int MAXPOINTS = 100;

int solvable(int n, int px[], int py[])
{
	int i,j;

	//check invisible
	for(i = 0; i < n; i++)
		for(j = i % 2; j < n; j += 2)	
			if(px[i] == px[i+1])		//vertical line
			{
				if(px[i] < px[j] && py[i] > py[i+1] && py[j] < py[j+1]) 
					return 0;
			}
			else						//horizontal line
			{
				if(py[i] > py[j] && px[i] > px[i+1] && px[j] < px[j+1]) 
					return 0;
			}

	return 1;
}

int main()
{
    int n;
    int px[MAXPOINTS+1];
    int py[MAXPOINTS+1];
	int caseno = 1;
    
    //read input
	while(scanf("%d",&n) && n != 0)
    {
        // read input
		for(int i = 0; i < n; i++) 
			scanf("%d %d",px+i,py+i);
		px[n] = px[0];
		py[n] = py[0];

        //output result
		printf("Floor #%d\n",caseno++);
		
		if(solvable(n, px, py))
			printf("Surveillance is possible.\n\n");
		else
			printf("Surveillance is impossible.\n\n");
    }

	return 0;
}
