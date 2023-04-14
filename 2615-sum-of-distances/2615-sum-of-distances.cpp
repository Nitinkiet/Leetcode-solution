class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,long long> leftSum,rightSum,countL,countR;
        vector<long long> arr(nums.size(),0);
        
        for(int i=0; i<nums.size(); i++){
            rightSum[nums[i]] += i; 
            countR[nums[i]]++; 
        }
        
        for(int i=0; i<nums.size(); i++)
        {    
         rightSum[nums[i]] -= i;
         countR[nums[i]]--;      

        arr[i] = abs(leftSum[nums[i]] - (1L*countL[nums[i]])*i) 
                  + abs(rightSum[nums[i]] - (1L*countR[nums[i]])*i);

         leftSum[nums[i]] += i; 
         countL[nums[i]]++; 
        }
        return arr;    
    }
};