class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
         int n1=nums1.size(),n2=nums2.size();
        map<int,int>mp;
        for(int i=0;i<n1;i++)mp[nums1[i]]++;
        for(int i=0;i<n2;i++)mp[nums2[i]]++;

        int mn1=10,mn2=10;

        for(int i=0;i<n1;i++){
            mn1 = min(mn1,nums1[i]);
        }
        for(int i=0;i<n2;i++){
            mn2 = min(mn2,nums2[i]);
        }
        for(auto x:mp){
            if(x.second==2)return x.first;
        }
        if(mn2<mn1)swap(mn2,mn1);
        return mn1*10 + mn2;
    }
};