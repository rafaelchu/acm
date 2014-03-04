// 166 - Making Change

#include <stdio.h>
#include <stdlib.h>

class scheme 
{
public:
	int gcount[6];

	scheme();
	int operator == (scheme &) const;
};

scheme::scheme() 
{
	for (int i=0; i<6; i++) 
		gcount[i]=0;
}

int scheme::operator ==(scheme &s) const 
{
	for (int i=0; i<6; i++) 
		if (gcount[i]!=s.gcount[i]) 
			return 0;

	return 1;
}

class queueentry 
{
public:
	scheme s;
	queueentry *next;

	queueentry(scheme &s1) 
	{ 
		s = s1; 
		next=NULL; 
	};
};

class queue 
{
public:
	queueentry *first;
	queueentry *last;

	//constructor
	queue() 
	{ 
		first = last = (queueentry *)NULL; 
	};

	//check queue is empty
	int IsEmpty() 
	{ 
		return first == NULL; 
	};

	//add a new entry
	void Put(scheme &s) 
	{
		if (first) 
			last=last->next=new queueentry(s);
		else 
			first=last=new queueentry(s); 
	}

	//get an entry
	scheme Get(void) 
	{ 
		scheme ret=first->s; 
		queueentry *keep=first;

		first=first->next;
		delete keep;
		return ret; 
	}

	//delete all entries
	void Flush(void) 
	{ 
		while(first) 
			Get(); 
	};
};

int limit[6];
int values[6] = { 5, 10, 20, 50, 100, 200 };


void find(int target) 
{
	queue q;
	scheme s;
	int found=0, i, value, total, changetot;

	q.Put(s);
	total = 0;
	for (i=0; i<6; i++)
		total += values[i]*limit[i];
	while (!found && !q.IsEmpty()) 
	{
		s = q.Get();
		value = 0; 
		for (i=0; i<6; i++) 
			value += values[i]*s.gcount[i];
		changetot = 0; 
		for (i=0; i<6; i++)
			if (s.gcount[i]<0) 
				changetot -= values[i]*s.gcount[i];

		if (value==target) 
		{
			value = 0; 
			for (i=0; i<6; i++) 
				value += abs(s.gcount[i]);
			printf("%3d\n", value);
			fflush(stdout);
			q.Flush();
			return;
		}

		if (changetot>total || changetot>200) 
			continue;
		for (i=5; i>=0; i--) 
		{
			if (s.gcount[i]==0) 
			{
				s.gcount[i]=1;
				if (s.gcount[i]<=limit[i]) 
					q.Put(s);
				s.gcount[i]=-1;
				q.Put(s);
				s.gcount[i]=0;
			} 
			else 
			{
				if (s.gcount[i]>0) 
					s.gcount[i]++;
				else 
					s.gcount[i]--;

				if (s.gcount[i]<=limit[i]) 
					q.Put(s);
				break;
			}
		}
	}

	printf("No valid scheme!\n");
	fflush(stdout);
	q.Flush();
}

int main() 
{
	float v;

	while ((scanf("%d %d %d %d %d %d", &limit[0], &limit[1], &limit[2],
          &limit[3], &limit[4], &limit[5])==6) &&
         (limit[0]||limit[1]||limit[2]||limit[3]||limit[4]||limit[5])) 
	{
		scanf("%f", &v);
		find((int)(v*100.0+0.5));
	}

	return 0;
}

