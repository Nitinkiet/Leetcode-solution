//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution

{   

    public:

    void booleanMatrix(vector<vector<int> > &m)

    {

        int n1=m.size();

        int n2=m[0].size();

        int row[n1],col[n2];

        for(int i=0;i<n1;i++)

        {

            for(int j=0;j<n2;j++)

            {

                if(m[i][j]==1)

                {

                    row[i]=1;

                    col[j]=1;

                }

            }

        }

        for(int i=0;i<n1;i++)

        {

            for(int j=0;j<n2;j++)

            {

                if(row[i]==1||col[j]==1)

                {

                    m[i][j]=1;

                }

            }

        }

    }

};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends