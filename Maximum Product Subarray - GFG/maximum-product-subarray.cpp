//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long ans=INT_MIN,mx=1,mn=1;
	    for(int i=0;i<n;i++){
	        if(arr[i]<0)swap(mn,mx);
	        if(arr[i]==0){
	            mn=1;
	            mx=1;
	        }
	        long long el = arr[i];
	        mx = max(mx*el,el);
	        mn = min(mn*el,el);
	        ans= max(mx,ans);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends