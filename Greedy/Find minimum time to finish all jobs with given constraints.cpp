
#include <bits/stdc++.h>
using namespace std;


//--------------------------------------- 
#define int         long long
#define double      long double
#define pb          push_back
#define pf          push_front
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
#define x           first
#define y           second
#define endl        '\n'
#define sz(x)	    (int)(x).size()
#define ull       unsigned long long
//-------------------------------------------

//------------------------------------------------
#define fo(i,l,u)   for(i=l;i<u;i++)
#define rfo(i,l,u)  for(i=l;i>=u;i--)
#define allfo(s)    for(auto it=(s).begin();it!=(s).end();it++)
#define _init(b)     memset(b,-1,sizeof(b))
#define _init0(b)     memset(b,0,sizeof(b))
#define MOD         1000000007
#define hell        998244353
#define output(x) cout << (x ? "YES" : "NO")<<endl;
#define Output(x) cout << (x ? "Yes" : "No")<<endl;
//------------------------------------------------



//-----------------------------------------
#define MOD2 (998244353)
#define MOD3 (1000000009)
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18) 
 
 
 
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
ifstream cinn("in.txt");ofstream coutt("out.txt");
int poww(const int &a,int b,const int &m=MOD){if(b==0)return 1;int x=poww(a,b/2,m);x=x*x%m;if(b&1)x=x*a%m;return x;} 

//---------------------------------------------------------------------------------------


int gcd(int a, int b) {if(a>b)swap(a,b) ;  if (a == 0)  return b; return gcd(b % a, a); }  
int rint(int  l , int r){return rand()%(r-l+1) + l ;}
 
const int N = 1e5+5;
#define int long long
bool possible(vector<int>jobs, int n, int k,int mid)
{
     int time_=0;
     int count=1;
     
     for(int i=0;i<n;i++)
     {
          if(time_+jobs[i]<=mid)
          {
               time_+=jobs[i];
          }
          else
          {
               time_=jobs[i];
               count++;
          }
     }
     return count<=k;
}

void solve(vector<int>jobs, int n, int k, int t)
{
     int total=0;
     int maxi=INT_MIN;
     for(int i=0;i<n;i++)
     {
          total+=jobs[i];
          maxi=max(maxi,jobs[i]);
     }
     
     //1,2,3,4,..., mid,mid+1,....total
     //cout<<total<<'\n';
     int l=0,r=total;
     int ans=total;
     
     while(l<=r)
     {
          int mid=l+(r-l)/2; //mid is the value at which we check possible or not
          
          if(mid>=maxi && possible(jobs, n, k, mid)) //if possible at mid
          { 
               ans=min(ans, mid);
               r=mid-1;
               //cout<<l<<" "<<r<<" "<<mid<<"\n";
          }
          else
          {
               l=mid+1;
          }
     }
     
     cout<<ans*t;
}

signed main()
{
     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     int n;
     cin>>n;
     vector<int>jobs(n);
     for(int i=0;i<n;i++)
     {
          cin>>jobs[i];
     }
     int k,t;
     cin>>k>>t;
     solve(jobs, n, k, t);
	//#ifndef ONLINE_JUDGE
  //freopen("f.txt", "r", stdin);
   //freopen("f1.txt", "w", stdout);
	//#endif
   
}
