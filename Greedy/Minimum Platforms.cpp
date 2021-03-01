int findPlatform(int arr[], int dep[], int n)
{
	sort(arr, arr+n); //not given arrival and dep time is same (or in pair)
	sort(dep, dep+n);
	
	int c=1;
	int res=0;
	int end=dep[0];
	int i=1, j=0;
	int platforms=1;
	
	while(i<n && j<n)
	{
	    if(arr[i]<=dep[j]) //add a platform if arrival time is less than departure time 
	    {
	        i++;
	        platforms++;
	    }
	    else if(arr[i]>dep[j]) //arrival time is more therefore we can remove a platform 
	    { 
	        j++;
	        platforms--;
	    }
	    res=max(res, platforms);
	}
	return res;
}
