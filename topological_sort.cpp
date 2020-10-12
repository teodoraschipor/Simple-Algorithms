#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#define Nmax 50003

using namespace std;

ifstream f("sort.in");
ofstream g("sort.out");

vector<int>graph[Nmax];
int Visited[Nmax];
stack<int>STACK;

void DFS(int node)
{
    Visited[node] = 1;
    int limit = graph[node].size();
    for(int i = 0; i < limit; i++)
    {
        int neighbour = graph[node][i];
        if(Visited[neighbour] == 0)
            DFS(neighbour);
    }
	STACK.push(node);
    }

int main()
{
   int n, m;
   f >> n >> m;
   int a, b;
   for(int i = 0; i < m; i ++)
   {
       f >> a >> b;
       graph[a].push_back(b);
   }
   for(int i = 1; i <= n; i++)
   {
       if(Visited[i] == 0)
       {
           DFS(i);
       }
   }
for(int i = 1; i <= n; i ++)
{
	g << STACK.top() << " ";
	STACK.pop();
}
    return 0;
}
