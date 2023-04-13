class Solution {
public:
    bool validateStackSequences(vector<int>& p1, vector<int>& p2) {
       
        int j=0,k=0;
        for(int i=0;i<p1.size();i++){
            p1[k] = p1[i];
            k++;
            while(k>0 && p1[k-1]==p2[j]){
                k--;
                j++;
            }
        }
        return k==0;
    }
};