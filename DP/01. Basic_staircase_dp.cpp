//How many ways u can reach nth stair from 0th stair if you can jump 1 or 2 step.

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int mod= 1e9 + 7;
int dp[N];

void pre_cal(){
  dp[1]=1;
  dp[2]=2;

  for(int i=3;i<N;i++){
    dp[i]= dp[i-1]+dp[i-2];
  }
}

int main(){
   int Test=1;
   pre_cal();
   // cin>>Test;
   while(Test--){
       int pos; cin>>pos;
       cout<<dp[pos]<<endl;
   }

   return 0;
}
/*

*/
