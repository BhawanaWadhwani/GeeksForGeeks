#include<bits/stdc++.h>
using namespace std;
#define N 3
void minCashFlowRec(int amount[])
{
    int max_credit=INT_MIN; //one who'll get maximum amt
    int max_debit=INT_MAX; //one who'll give maximum amt
    
    int idx1=0;
    int idx2=0;
    
    for(int i=0;i<N;i++)
    {
        if(amount[i]>max_credit)
        {
            max_credit=amount[i];
            idx1=i;
        }
        if(amount[i]<max_debit)
        {
            max_debit=amount[i];
            idx2=i;
        }
    }
    
    if(amount[idx1]==0 && amount[idx2]==0) //all transactions done
    {
        return;
    }
    
    int mini=min(-amount[idx2], amount[idx1]);
    
    amount[idx1]-=mini;
    amount[idx2]+=mini;
    
    cout<<"Person "<<idx2+1<<" pays "<<mini<<" to "<<idx1+1<<'\n';
    minCashFlowRec(amount);
}
int minCashFlow(int graph[][N])
{
    int amount[N];
    for(int i=0;i<N;i++)
    {
        amount[i]=0;
        for(int j=0;j<N;j++)
        {
            amount[i]-=graph[i][j];
            amount[i]+=graph[j][i];
        }
        //cout<<amount[i]<<" ";
    }
    
    minCashFlowRec(amount); 
}
int main()
{
    // graph[i][j] indicates the amount that person i needs to pay person j 
    
    //cin>>N;
	int graph[N][N] = { {0, 1000, 2000}, 
                        {0, 0, 5000}, 
                        {0, 0, 0},}; 
  
    // Print the solution 
    minCashFlow(graph); 
    return 0; 
} 
