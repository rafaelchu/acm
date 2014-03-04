// 593 - MBone

#include <iostream>
#include <string.h>

using namespace std;

const long INF = 200000000;

struct host_type
{
	long island;
	long addr;
};

struct tunnel_type
{
	long s_island;
	long threshold;
	char e_island[30];
};

struct packet_type
{
	long addr;
	long id;
	long ttl;
};

struct group_type
{
	long addr;
	long host_no;
	host_type host[60];
};

int main()
{
	long net_no;
	long island_no;
	char island_name[15][30];
	long island_path[15][15];
	long host_no;
	host_type host[60];
	long tunnel_no;
	tunnel_type tunnel[110];
	long packet_no;
	packet_type packet[1010];
	long group_no;
	group_type group[30];

	long no;
	char act;
	long addr;
	long g_addr;
	long i;
	long j;
	long k;

	net_no = 0;

	//read island input
	cin >> island_no;
	while (island_no > 0)
	{
		//initial
		net_no++;
		for (i = 0; i < island_no; i ++)
			for (j = 0; j < island_no; j++)
				island_path[i][j] = INF;
		for (i = 0; i < island_no; i++)
			island_path[i][i] = 0;
		host_no = 0;
		tunnel_no = 0;
		packet_no = 0;
		group_no = 0;

		//read island description
		for (i = 0; i < island_no; i++)
		{
			cin >> island_name[i];
			cin >> no;
			
			for (j = 0; j < no; j++)
			{
				cin >> act;
				if (act == 'H')		//Host
				{
					host[host_no].island = i; 
					cin >> host[host_no].addr;
					host_no++;
				}
				else				//Tunnel
				{
					tunnel[tunnel_no].s_island = i;
					cin >> tunnel[tunnel_no].threshold;
					cin >> tunnel[tunnel_no].e_island;
					tunnel_no++;
				}
			}
		}

		//calculate threshold between islands
		for (i = 0; i < tunnel_no; i ++)
		{
			for (j = 0; j < island_no; j++)
				if (strcmp(tunnel[i].e_island, island_name[j]) == 0)
					break;

			island_path[tunnel[i].s_island][j] = tunnel[i].threshold;
		}

		//calculate the shortest path between islands
		for (k = 0; k < island_no; k++)
			for (i = 0; i < island_no; i++)
				for (j = 0; j < island_no; j++)
					if (island_path[i][k] + island_path[k][j] < island_path[i][j])
						island_path[i][j] = island_path[i][k] + island_path[k][j]; 

		//read activity input
		cin >> no;
		for (i = 0; i < no; i++)
		{
			cin >> act >> addr >> g_addr;

			//get addr's host
			for (j = 0; j < host_no; j++)
				if (host[j].addr == addr)
					break;

			//get g_addr's group
			for (k = 0; k < group_no; k++)
				if (group[k].addr == g_addr)
					break;

			if (act == 'J')			//Join a group
			{
				if (k < group_no)
				{
					group[k].host[group[k].host_no] = host[j];
					group[k].host_no++;
				}
				else
				{
					group[group_no].addr = g_addr;
					group[group_no].host[0] = host[j];
					group[group_no].host_no = 1;
					group_no++;
				}
			}
			else if (act == 'L')	//Leave a group
			{
				//remove host
				for (j = 0; j < group[k].host_no; j++)
					if (group[k].host[j].addr == addr)
						break;
				for (; j < group[k].host_no - 1; j++)
					group[k].host[j] = group[k].host[j+1];
				group[k].host_no--;

				//check group removing
				if (group[k].host_no == 0)
				{
					for (j = k; j < group_no - 1; j++)
						group[j] = group[j+1];
					group_no--;
				}
			}
			else					//Send a packet to a group
			{
				long id;
				long ttl;

				cin >> id >> ttl;

				//send packet
				int l;
				for (l = 0; l < group[k].host_no; l++)
				{
					packet[packet_no].addr = group[k].host[l].addr;
					packet[packet_no].id = id;						

					if (island_path[host[j].island][group[k].host[l].island] <= ttl)
					{
						packet[packet_no].ttl = ttl - island_path[host[j].island][group[k].host[l].island];
						packet_no++;
					}
				}
			}
		}

		//sort packets
		for (i = 0; i < packet_no - 1; i++)
		{
			long min = i;

			for (j = i + 1; j < packet_no; j++)
				if (packet[j].addr < packet[min].addr)
					min = j;
				else if ((packet[j].addr == packet[min].addr) &&
				         (packet[j].id < packet[min].id))
					min = j;
			
			packet_type temp = packet[i];
			packet[i] = packet[min];
			packet[min] = temp;
		}

		//output reslut
		if (net_no > 1)
			cout << endl;
		cout << "Network #" << net_no << endl;
		for (i = 0; i < packet_no; i++)
			cout << packet[i].addr << ' ' << packet[i].id << ' ' << packet[i].ttl << endl;


		cin >> island_no;
	}

	return 0;
}