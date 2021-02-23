#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ppi;
vector<pair<int, int>> adj[1001];
int n_vertices;

void prim()
{
	priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
	int src = 0;

	vector<int> key(n_vertices + 1, 100000);
	vector<int> par(n_vertices + 1, -1);
	vector<bool> inSet(n_vertices + 1, false);

	pq.push(make_pair(0, src));
	key[src] = 0;

	while (!pq.empty())
	{
		int a = pq.top().second;
		pq.pop();
		inSet[a] = true;

		for (auto i = adj[a].begin(); i != adj[a].end(); i++) // look for all elements connected to the node
		{
			int b = (*i).first;
			int w = (*i).second;

			if (inSet[b] == false && key[b] > w) //if a node is already traversed it's inSet[]=true...Therefore, we'll check if inset[]==false pr true and if the weight is less update the weight
			{
				key[b] = w;
				pq.push(make_pair(key[b], b));
				par[b] = a;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= n_vertices; ++i)
	{
		cout << par[i] << " " << i << '\n';
	}
	cout << '\n';
	for (int i = 0; i <= n_vertices; i++)
	{
		sum += key[i];
		cout << key[i] << " ";
	}
	cout << '\n';
	cout << "Total sum - " << sum;
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

	prim();

	return 0;
}
