#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
///-------FILES-------
ifstream in("apm.in");
ofstream out("apm.out");

int rank[200003], father[200003];

int findFather(int x)
{
	if (father[x] == x)
		return x;
	else return findFather(father[x]);
}

vector < pair<int, int> > tree;
priority_queue < pair < int, pair <int, int> > > myHeap;


int main()
{
    int n, m, c, cost, EdgesNumber;
	in >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
		rank[i] = 1;
	}

	for (int i = 1; i <= m; i++)
	{
		int x, y;
		in >> x >> y >> c;
		myHeap.push(make_pair((-1)* c, make_pair(x, y)));
	}

	cost = 0;
	EdgesNumber = 0;

	while (myHeap.empty() == 0 && EdgesNumber < m - 1)
	{
		pair <int, pair<int, int> > Min = myHeap.top();
		myHeap.pop();
		int x = Min.second.first;
		int y = Min.second.second;
		int f1 = findFather(x);
		int f2 = findFather(y);

		if (f1 != f2)
		{
		    cost = cost + (-1) * Min.first;
			EdgesNumber++;
			if (rank[f1] < rank[f2])
			{
				father[f1] = f2;
				rank[f2] += rank[f1];
			}
			else
			{
				father[f2] = f1;
				rank[f1] += rank[f2];
			}

			tree.push_back(make_pair(x,y));
		}
	}

	out << cost << '\n';
	out << EdgesNumber << '\n';
	for(int i = 0; i < EdgesNumber; i++)
        out << tree[i].first << " " << tree[i].second << '\n';

	return 0;
}
