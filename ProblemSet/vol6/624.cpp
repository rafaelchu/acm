// 624 - CD

#include <iostream>

using namespace std;

const int MAX_TRACK = 20;

//find out the maximum sum in tracks
int find_maxsum(int track_no, int track[], int now_track, int sum, bool used_track[])
{
	if (now_track == (track_no - 1))
	{
		if (track[now_track] <= sum)		//use the last track
		{
			used_track[now_track] = true;
			return track[now_track];
		}
		else								//not use the last track
			return 0;
	}
	else if (sum - track[now_track] == 0)   //get the answer
	{
		used_track[now_track] = true;
		return sum;
	}
	else if (sum - track[now_track] < 0)    //not use now_track
	{
		return find_maxsum(track_no, track, now_track + 1, sum, used_track);		
	}
	else
	{
		bool used_track2[MAX_TRACK];
		for (int ci = 0; ci < track_no; ci++)
			used_track2[ci] = used_track[ci];

		//use now_track
		int a = find_maxsum(track_no, track, now_track + 1, sum - track[now_track], used_track);
		used_track[now_track] = true;
		a += track[now_track];

		//not use now_track		
		int b = find_maxsum(track_no, track, now_track + 1, sum, used_track2);
		
		if (a >= b)
		{				
			return a;
		}
		else
		{
			for (int ci = 0; ci < track_no; ci++)
				used_track[ci] = used_track2[ci];			
			return b;
		}
	}
}

int main()
{
	int  track[25];				//durations of the tracks
	int  track_no;				//number of tracks
	int  n;						//a tape with N minutes long
	int  sum;					//maximum sum (not exceed n)
	bool used_track[25];		//tracks used to get maximum sum
	int  ci;

	while (cin >> n)
	{
		//read input
		cin >> track_no;
		for (ci = 0; ci < track_no; ci++)
			cin >> track[ci];
		
		//calculate answer
		for (ci = 0; ci < track_no; ci++)
			used_track[ci] = false;

		sum = find_maxsum(track_no, track, 0, n, used_track);

		//output result
		for (ci = 0; ci < track_no; ci++)
			if (used_track[ci])
				cout << track[ci] << ' ';
		cout << "sum:" << sum << endl;
	}

	return 0;
}

