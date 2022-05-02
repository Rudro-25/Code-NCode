//https://codeforces.com/problemset/problem/118/D

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod=1e8;

ll dp[101][101][11][11],limit_k1,limit_k2;
ll getAns(ll n1,ll n2,ll k1,ll k2){

   if((n1+n2)==0) return 1;
   if(dp[n1][n2][k1][k2]!=-1) return dp[n1][n2][k1][k2];
   
   ll x=0;
   //fill f
   if(n1 && k1) x=getAns(n1-1,n2,k1-1,limit_k2);
   ll y=0;
   //fill h
   if(n2 && k2) y=getAns(n1,n2-1,limit_k1,k2-1);

   return dp[n1][n2][k1][k2]= (x+y)%mod;

}

int main(){
   int Test=1;
   //cin>>Test;
   while(Test--){
       memset(dp,-1,sizeof dp);
       ll n1,n2; cin>>n1>>n2>>limit_k1>>limit_k2;

       ll ans= getAns(n1,n2,limit_k1,limit_k2);

       cout<<ans<<endl;
       
   }
   return 0;
}
/*

*/
