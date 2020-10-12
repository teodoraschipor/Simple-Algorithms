#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include  <limitits.h>
#define Nmax 50005
#define Infinite INT_MAX
using namespace std;

ifstream f("dijkstra.in");
ofstream g("dijkstra.out");

struct edge
{
    int cost;
    int destination;
};

vector <edge> graph[Nmax];
priority_queue < pair<int,int> > HEAP;
int dist[Nmax],visited[Nmax];

void Dijkstra()
{
    while(HEAP.empty() == 0)
    {
        pair <int,int> a = HEAP.top();
        HEAP.pop();
        int nod = a.second;
        int costI = -a.first;
        if(visited[nod] == 0)
        {
            visited[nod] = 1;
            dist[nod] = costI;
            int limit = graph[nod].size();
            for(int i = 0; i < limit; i++)
            {
                int neighbour = graph[nod][i].destination;
            int cost = graph[nod][i].cost;
                if(cost + costI < dist[neighbour])
                {
                    dist[neighbour] = cost + costI;
                    HEAP.push( make_pair ((-1) * dist[neighbour], neighbour));
                }
            }
        }
    }
}

int main()
{
    int m, n, x, y, c;
    edge A;
    f >> n >> m;
    for(int i = 0; i < m; i++)
    {
        f >> x >> y >> c;
        A.cost = c;
        A.destination = y;
        graph[x].push_back(A);

    }

    for(int i = 2; i <= Nmax; i++)
        dist[i]=Infinite;
    HEAP.push(make_pair(0,1));
    Dijkstra();
    for(int i = 2; i <= n; i++)
        if(dist[i] != Infinite)
            g << dist[i] << " ";
        else
            g << "0 ";

    return 0;
}
