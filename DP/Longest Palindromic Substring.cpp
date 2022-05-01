//https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        s='0'+s;
        int n=s.size();
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=0;
        for(int i=0;i<=n;i++) dp[0][i]=dp[1][i]=1;
        
        int pos=1,len=1;
        for(int i=2;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(s[j]==s[j-i+1] && dp[i-2][j-1]){
                    pos=j,len=i;
                    dp[i][j]=1;
                }   
            }
        }
        string ans;
        for(int i=pos-len+1;i<=pos;i++) ans+=s[i];
        return ans;
    }
};
