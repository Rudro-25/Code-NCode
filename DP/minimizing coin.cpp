//https://cses.fi/problemset/task/1634

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N= 1e6+5;
ll dp[N];
int main(){
   int Test=1;
   //cin>>Test;
   while(Test--){
       for(ll i=0;i<N;i++) dp[i]=1e9;
       dp[0]=0;
       ll n,target; cin>>n>>target;
       ll coin[n];
       for(ll i=0;i<n;i++) cin>>coin[i];
       for(ll i=1;i<=target;i++){
         for(ll j=0;j<n;j++){
           ll baki= i-coin[j];
           if(baki>=0) dp[i]=min(dp[i],dp[baki]+1);
         }
       }
       if(dp[target]==1e9) dp[target]=-1;
       cout<<dp[target]<<endl;
   }
   return 0;
}
/*

*/
