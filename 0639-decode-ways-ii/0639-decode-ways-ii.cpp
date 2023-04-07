class Solution {
public:
    int m = 1e9 + 7;
    int f(int i,string&s,vector<int>&dp){
        int n = s.size();
        if(i==n)return 1;
        if(i>n || s[i]=='0')return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        int cnt=0;
        
        if(s[i]=='1'){
            cnt = (cnt + f(i+1,s,dp))%m;
            
            if(i+1<n && s[i+1]=='*'){
                for(int k=1;k<=9;k++){
                    cnt = (cnt + f(i+2,s,dp))%m;
                }
            }
            else cnt = (cnt + f(i+2,s,dp))%m;
        }
        
        
        else if(s[i]=='2'){
            cnt = (cnt + f(i+1,s,dp))%m;
            
            if(i+1<n && s[i+1]=='*'){
                for(int k=1;k<=6;k++){
                    cnt = (cnt + f(i+2,s,dp))%m;
                }
            }
            else if(i+1<n && s[i+1]<='6') cnt = (cnt + f(i+2,s,dp))%m;
        }
        
        
        else if(s[i]=='*'){
            
            cnt = (cnt + f(i+1,s,dp))%m;
            
            if(i+1<n && s[i+1]=='*'){
                for(int k=1;k<=9;k++){
                    cnt = (cnt + f(i+2,s,dp))%m;
                }
            }
            else cnt = (cnt + f(i+2,s,dp))%m;
            
            cnt = (cnt + f(i+1,s,dp))%m;
            
            if(i+1<n && s[i+1]=='*'){
                for(int k=1;k<=6;k++){
                    cnt = (cnt + f(i+2,s,dp))%m;
                }
            }
            else if(i+1<n && s[i+1]<='6') cnt = (cnt + f(i+2,s,dp))%m;
        
            
            for(int k=3;k<=9;k++){
                cnt = (cnt+f(i+1,s,dp))%m;
            }
            
        }
        
        
        else{
            cnt = (cnt + f(i+1,s,dp))%m;
        }
        return dp[i] = cnt%m;
        
}
    int numDecodings(string s) {
        
        vector<int>dp(s.size()+1,-1);
        return f(0,s,dp);
    }
};