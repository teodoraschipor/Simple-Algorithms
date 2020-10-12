#include <iostream>
#include <fstream>
#include <vector>
#define Nmax 50000
#define Infinite 10000000
using namespace std;

///---------FILES----------
ifstream in("dijkstra.in");
ofstream out("dijkstra.out");

///---------DATA TYPE----------
vector < int > Graph1[Nmax];
vector < int > Graph2[Nmax];
int Visited[Nmax], Distance[Nmax], Queue[Nmax];

///---------DIJKSTRA-----------
void DIJKSTRA(int n)
{
    int copy = n;
    int index;
    while( copy != 0 )
    {
        int minimum = Infinite;

        for(int i = 1; i <= n; i++)
            if(!Visited[i] && Distance[i] < minimum)
            {
                minimum = Distance[i];
                index = i;
            }
        Visited[index] = 1;
        int Size = Graph1[index].size();
        for(int i = 0; i < Size; i++)
        {
            int neighbour = Graph1[index][i];
            int cost = Graph2[index][i];
            if(Distance[index] + cost < Distance[neighbour])
                Distance[neighbour] = Distance[index] + cost;
        }
        copy --;
    }
}

int main()
{
    ///----------------READ DATA FROM FILE---------------
    int N, M, A, B, C;
    in >> N >> M;
    for(int i = 0; i < M; i++)
    {
        in >> A >> B >> C;
        Graph1[A].push_back(B);
        Graph2[A].push_back(C);
    }
    for(int i = 2; i <= N; i++)
        Distance[i] = Infinite;

    DIJKSTRA(N);
    for(int i = 2; i <= N; i++)
    {
        if(Distance[i] ==Infinite)
            out << "0 ";
        else
            out << Distance[i]<< " ";
    }
    return 0;
}
