class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int>arr(26);
        for(int i=0;i<26;i++){
            arr[i] = i+1;
        }
        int j=0;
        for(int i=0;i<chars.size();i++){
            arr[chars[i]-'a']=vals[j];
            j++;
        }
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<s.size();i++){
            sum += arr[s[i]-'a'];
            if(sum<0)sum=0;
        maxi = max(sum,maxi);
        }
        return maxi;
    }
};