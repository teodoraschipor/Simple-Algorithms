#include <iostream>
#include <fstream>
#include <vector>
#define Nmax 100006
using namespace std;

int Visited[Nmax], Queue[Nmax], Distance[Nmax];
vector <int> graph[Nmax]; //array of lists
ifstream in("bfs.in");
ofstream out("bfs.out");


int main()
{
    int N, M, S;
    in>>N>>M>>S;
    Visited[S]=1;
    int x, y;
    for(int i = 0; i < M; i++)
    {
        in>>x>>y;
        graph[x].push_back(y);
    }
    for(int i = 1; i <= N; i++)
        Distance[i]=-1;
    Distance[S]=0;
    Queue[1]=S;
    int left, right;
    left = right = 1;
    while(left <= right)
    {
        int index = Queue[left]; //first element (with the smallest distance)
        int limit = graph[index].size();
        for(int i = 0; i < limit; i++)
        {
            int neighbour = graph[index][i];
            if(!Visited[neighbour])
            {
                Distance[neighbour] = Distance[index] + 1;
                Visited[neighbour] = 1;
                Queue[++right] = neighbour;
            }
        }
        left++; //delete the first element from Queue
    }
    for(int i = 1; i <= N; i++)
    {
        out<<Distance[i]<<"  ";
    }
    return 0;
}
