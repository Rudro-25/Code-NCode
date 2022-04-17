//How many ways u can reach nth stair from 0th stair if you can jump 1 or 2 or 3 step.
//https://www.codechef.com/problems/JAM11

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 1e6 + 5;
ll mod= 1e9 + 7;
ll dp[N];

ll stairs(ll pos){
  if(dp[pos]) return dp[pos];
  if(pos==1 || pos==2) return dp[pos]=pos;
  if(pos==3) return dp[pos]=4;

  dp[pos]= (stairs(pos-1) + stairs(pos-2) + stairs(pos-3))%mod;

  return dp[pos];
}

int main(){
   int Test=1;
   stairs(100000);
   cin>>Test;
   while(Test--){
       int pos; cin>>pos;
       cout<<dp[pos]<<endl;
   }

   return 0;
}
/*

*/
