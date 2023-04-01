//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSquares(int m, int n, vector<vector<int>> &matrix) {
        int sum=0;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                
                    if(matrix[i][j]==1)
                    matrix[i][j]=min(matrix[i-1][j-1],min(matrix[i][j-1],matrix[i-1][j]))+1;
                
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum+=matrix[i][j];
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.countSquares(N, M, matrix) << endl;
    }
    return 0;
}
// } Driver Code Ends