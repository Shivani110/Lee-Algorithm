#include <bits/stdc++.h>
using namespace std;
#define Rc 10
#define Cc 10

struct Lee_Point
{
	int p;
	int q;
};

struct queue_Nodes
{
	Lee_Point x; 
	int distance; 
};
bool V(int r, int c)
{
	return (r >= 0) && (r < Rc) &&
		(c >= 0) && (c < Cc);
}

int no_of_row[] = {1, 0, -1, 0};
int no_of_col[] = {0, 1, 0, -1};

int Bfs(int M[][Cc], Lee_Point s, Lee_Point d)
{
	if (!M[s.p][s.q] || !M[d.p][d.q])
		return -1;

	bool Visit[Rc][Cc];
	memset(Visit, false, sizeof Visit);
	Visit[s.p][s.q] = true; 
	
	queue<queue_Nodes> N;
	queue_Nodes u = {s, 0};
	N.push(u); 
	while (!N.empty())
	{
		queue_Nodes i = N.front();
		Lee_Point x = i.x;
		if (x.p == d.p && x.q == d.q)
			return i.distance;
		N.pop();

		for (int m = 0; m < 5; m++)
		{
			int r = x.p + no_of_row[m];
			int c = x.q + no_of_col[m];
			
			if (V(r, c) && M[r][c] &&
			!Visit[r][c])
			{
				Visit[r][c] = true;
				queue_Nodes adj_Cells = { {r, c},
									i.distance + 1 };
				N.push(adj_Cells);
			}
		}
	}
	return -1;
}
int main()
{
	int M[Rc][Cc] =
	{{ 1,  -1,  1,  1,  -1,  0,  0,  0,  0,  0},
     { 1,  1,  -1,  1,  0,  0,  0,  0,  0,  -1},
     { -1,  0,  0,  -1,  0,  1,  0,  -1,  0,  1},
     { 1,  0,  -1,  0 , 1,  0,  0,  1,  1,  0},
     { 0,  1,  1,  0,  1,  1,  0,  1,  0,  1},
     { 1,  0,  0,  -1,  0,  1,  1,  0,  0,  1},
     { 1,  -1,  0,  0,  1,  0,  1,  0,  1,  1},
     { 0,  1,  1,  0,  1,  -1,  0,  0,  0,  1},
     { 1,  0,  0,  -1,  1,  0,  0,  1,  0,  0},
     { 1,  1,  0,  1,  1,  0,  0,  -1,  1,  1,}
	 };                    

    Lee_Point s = {0, 0};
	Lee_Point d = {7, 9};

	int distance = Bfs(M, s, d);

	if (distance != -1)
		cout << "The shortest path is " << distance ;
	else
		cout << "The shortest path is not exist ";

	return 0;
}

