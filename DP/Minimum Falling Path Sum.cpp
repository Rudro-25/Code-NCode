//https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size(),m=matrix[0].size();
        int ans[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans[i][j]=1e8;
        int answer=1e9;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(i){
                    for(int k=j-1;k<=j+1;k++){
                        if(k>=0 && k<matrix[i].size()){
                            ans[i][j]=min(ans[i][j],ans[i-1][k]+matrix[i][j]);
                        }
                    }
                }
                else{
                    ans[i][j]= matrix[i][j];
                }
                if(i==matrix.size()-1) answer=min(answer,ans[i][j]);
            }
        }
        return answer;
    }
};
