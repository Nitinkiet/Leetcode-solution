class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long k) {
        int n = s.size(),m=p.size();
        vector<int>ans;
        sort(p.begin(),p.end());
        for(auto x:s){
           long long l = 0,h=m-1,mid;
            while(l<=h){
                mid = l + (h-l)/2;
                if((long long)x*p[mid]>=k)h=mid-1;
                else l = mid+1;
            }
            ans.push_back(m-l);
        }
        
        return ans;
    }
};