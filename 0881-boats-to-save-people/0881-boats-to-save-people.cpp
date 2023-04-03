class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        int l=0,h=n-1,cnt=0;
        while(l<=h){
            if(people[l]+people[h]<=limit){
                l++;
                h--;
            }
            else h--;
        cnt++;
        }
        return cnt;
    }
};