class Solution {
public:
    bool validateStackSequences(vector<int>& p1, vector<int>& p2) {
        stack<int>st;
        int j=0;
        for(int i=0;i<p1.size();i++){
            st.push(p1[i]);
            while(!st.empty() && st.top()==p2[j])
            { j++;
              st.pop();
            }
        }
       
        return st.size()==0;
    }
};