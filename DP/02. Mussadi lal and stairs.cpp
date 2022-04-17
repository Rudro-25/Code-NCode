//How many ways u can reach nth stair from 0th stair if you can jump 1 or 2 or 3 step.
//https://www.codechef.com/problems/JAM11

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 1e6 + 5;
ll mod= 1e9 + 7;
ll dp[N];

void pre_cal(){
  dp[1]=1;
  dp[2]=2;
  dp[3]=4;

  for(int i=4;i<N;i++){
    dp[i]= (dp[i-1]+dp[i-2]+dp[i-3])% mod;
  }
}

int main(){
   int Test=1;
   pre_cal();
   cin>>Test;
   while(Test--){
       int pos; cin>>pos;
       cout<<dp[pos]<<endl;
   }

   return 0;
}
/*

*/
