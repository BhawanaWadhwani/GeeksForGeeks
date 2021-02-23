#include <bits/stdc++.h>
using namespace std;
//#define int long long

int nodes, edges;
vector<pair<int, pair<int,int>>>p; //weight, src, destination
int par[10001]; 

int rank1(int node)
{
    if(par[node]==-1)
    return node;
    
    return par[node]=rank1(par[node]);
}
void union_fun(int a, int b)
{
    par[a]=b;
}

int krushkal()
{
    int min_cost=0;
    
    for(int i=0;i<edges;i++)
    {
        int weight=p[i].first;
        int src=rank1(p[i].second.first);
        int des=rank1(p[i].second.second);
       
        if(src!=des) //if par same then they are already connected else we'll connect them
        {
            min_cost+=weight;
            union_fun(src,des);
        }
    }
    return min_cost;
}
signed main()
{
    cin>>nodes>>edges;
    for(int i=1;i<=nodes;i++)
    {
        par[i]=-1;
    }

    int src,des,w;
    
    for(int i=0;i<edges;i++)
    {
        cin>>src>>des>>w;
        p.push_back(make_pair(w,make_pair(src,des)));
    }

    
    sort(p.begin(),p.end()); //will sort according to weight
	// for(int i=0;i<edges;i++)
    // {
	// 	cout<<p[i].first<<" "<<p[i].second.first<<" "<<p[i].second.second<<'\n';
	// }
    
    int price=krushkal();
	cout<<price;
}
