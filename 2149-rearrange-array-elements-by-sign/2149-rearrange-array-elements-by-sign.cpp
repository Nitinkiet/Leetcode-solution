class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        for(auto x:nums){
            if(x<0)neg.push_back(x);
            else pos.push_back(x);
        }
        int j=0;
        for(int i=0;i<nums.size()-1;i+=2){
            nums[i] = pos[j];
            j++;
        }
         
         int k=0;
        for(int i=1;i<nums.size();i+=2){
            nums[i] = neg[k];
            k++;
        }
        return nums;
    }
};