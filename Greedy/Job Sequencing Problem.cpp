bool compare(Job a, Job b)
{
    if(a.profit==b.profit)
    return a.dead<b.dead;
    return a.profit>b.profit;
}

class Solution 
{
  public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int m=n; //m Jobs .. here m=n
        sort(arr, arr+m, compare);
        // your code here
        vector<int>ans;
        int profit=0;

        bool slots[n];
        for(int i=0;i<n;i++)
        {
            slots[i]=false;
        }
        // for(int i=0;i<m;i++)
        // {
        //     cout<<arr[i].id<<" "<<arr[i].dead<<" "<<arr[i].profit<<'\n';
        //}
        int count=0;
        for(int i=0;i<m;i++)
        {
            int last_day=arr[i].dead;
            for(int j=min(n-1,last_day-1);j>=0;j--)
            {
                if(slots[j]==false)
                {
                    slots[j]=true;
                    count++;
                    profit+=arr[i].profit;
                    if(count==n)
                    {
                        ans.push_back(n);
                        ans.push_back(profit);
                        return ans;
                    }
                    break;
                }
            }
        }
        
        ans.push_back(count);
        ans.push_back(profit);
        return ans;
        
    } 
};
