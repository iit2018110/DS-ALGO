int findPlatform(int arr[], int dep[], int n)
{
	sort(arr,arr+n);
	sort(dep,dep+n);
	
	int i=0,j=0;
	int platform = 0, maxplatform=0;
	while(i < n and j < n) {
	    if(arr[i] <= dep[j]) platform++, i++;
	    else platform--, j++;
	    
	    maxplatform = max(maxplatform,platform);
	}
	
	return maxplatform;
}