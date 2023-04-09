class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1,n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }
        for(int i=n-1;i>=ind && ind!=-1;i--){
            if(nums[ind]<nums[i]){
                swap(nums[ind],nums[i]);
                break;
            }
        }
       
        reverse(nums.begin() + ind+1,nums.end());
    }
};