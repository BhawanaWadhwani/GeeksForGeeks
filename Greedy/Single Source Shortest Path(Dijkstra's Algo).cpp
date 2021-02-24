// Prims takes min dist from each vertex to all other connecting vertices
// whereas Dijkstra takes the vertex with min distance from source

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <queue>
#include <utility>
using namespace std;

#define ppi pair<int, int>
vector<pair<int, int> > adj[1001];
int n_vertices;

void sssp()
{
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;
    int src = 0;

    vector<int> dist(n_vertices + 1, 100000);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int a = pq.top().second;
        pq.pop();

        for (auto i = adj[a].begin(); i != adj[a].end(); i++)
        {
            int b = (*i).first;
            int w = (*i).second;

            if (dist[a] + w < dist[b])
            {
                dist[b] = w + dist[a];
                pq.push(make_pair(dist[b], b));
            }
        }
    }

    for (int i = 0; i <= n_vertices; i++)
    {
        cout << i<<" : "<<dist[i] << "\n";
    }
    cout << '\n';
}
int main()
{
    int n, m;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    n_vertices = n - 1; //0 to n

    printf("Enter number of edges : ");
    scanf("%d", &m);

    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
    }

    int a, b, w;
    printf("Enter sides and weight : ");
    while (m--)
    {
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }

    sssp();

    return 0;
}

//example - 
// 9 vertices
// 14 edges
// 0 1 4
// 0 7 8
// 1 7 11
// 1 2 8
// 7 8 7
// 7 6 1
// 2 8 2
// 8 6 6
// 2 5 4
// 6 5 2
// 2 3 7
// 3 5 14
// 3 4 9
// 5 4 10

//op - 0 4 12 19 21 11 9 8 14 
