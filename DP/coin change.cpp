//https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        for(int i=0;i<=amount;i++) dp[i]=1e8;
        dp[0]=0;
        for(int i=0;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                int baki=j-coins[i];
                if(baki>=0) dp[j]=min(dp[j],dp[baki]+1);
            }
        }
        if(dp[amount]==1e8) dp[amount]=-1;
        
        return dp[amount];
    }
};
