class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int ans=1;
        set<int>st;
        for(auto ch:s){
            if(st.find(ch)!=st.end()){
                st.clear();
                ans++;
            }
            st.insert(ch);
}
        return ans;
        
    }
};