#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        lli ans=INT_MAX,temp=0;
        
        cin>>n>>k;
        lli t2=0;
        lli a[n];
        
        for(int i=0;i<n;i++)cin>>a[i];
        
        sort(a,a+n);
        
        for(int i=0;i<n;i++)
        {
            temp=t2; //remove all previous piles
            t2+=a[i]; 
            for(int j=n-1;j>i;j--)
                if(a[j]-a[i]-k>0)
                    temp+=a[j]-a[i]-k; //remove excess elements
            ans=min(ans,temp);
        }
        cout<<ans<<endl;
    }
	return 0;
}
