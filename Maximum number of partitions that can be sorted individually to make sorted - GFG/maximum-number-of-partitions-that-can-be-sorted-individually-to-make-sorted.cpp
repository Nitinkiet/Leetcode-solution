//{ Driver Code Starts

// CPP program to find Maximum number of partitions
// such that we can get a sorted array.
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum partitions.
int maxPartitions(int arr[], int n);


// Driver code
int main()
{
	int t,n;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout << maxPartitions(arr, n)<<endl;
    }

	return 0;
}

// } Driver Code Ends


int maxPartitions(int arr[], int n)
{
    int maxi=0,cnt=0;
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
        if(maxi==i)cnt++;
    }
    return cnt;
    
}