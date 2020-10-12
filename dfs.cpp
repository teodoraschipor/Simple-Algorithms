#include <iostream>
#include <fstream>
#include <vector>
#define Nmax 100009

using namespace std;

ifstream in("dfs.in");
ofstream out("dfs.out");
vector <int>graph[Nmax];
int Visited[Nmax];

void DFS(int node)
{
    /// We visit it
    Visited[node] = 1;
    int limit = graph[node].size();
    for(int i = 0; i < limit; i++)
    {
        int neighbour = graph[node][i];
        if(Visited[neighbour] == 0)
            DFS(neighbour);
    }
}

int main()
{
    int N, M;
    in >> N >> M;
    int ConnectedComponentsNumber = 0;
    int X, Y;
    for(int i = 0; i < M; i++)
    {
        in >> X >> Y;
        graph[X].push_back(Y);
        graph[Y].push_back(X);
    }
    for(int i = 1; i <= N; i++)
    {
        if(Visited[i] == 0)
        {
            ConnectedComponentsNumber ++;
            DFS(i);
        }
    }
    out << ConnectedComponentsNumber;
    return 0;
}
