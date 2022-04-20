#include<bits/stdc++.h>
using namespace std;

#define      gcd(a,b)           __gcd(a,b)
#define      InTheNameOfGod     ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

int main(){
  InTheNameOfGod;
   int Test=1;
   cin>>Test;
   while(Test--){
       int n,q; cin>>n>>q;
       int a[n+5],pre_gcd[n+2],suf_gcd[n+2];
       pre_gcd[0]=suf_gcd[n+1]=0;
       for(int i=1;i<=n;i++){
         cin>>a[i];
         pre_gcd[i]= gcd(pre_gcd[i-1],a[i]);
       }

       for(int i=n;i>0;i--){
         suf_gcd[i]= gcd(suf_gcd[i+1],a[i]);
       }

       while(q--){
         int l,r; cin>>l>>r;
         cout<<gcd(pre_gcd[l-1],suf_gcd[r+1])<<endl;;
       }
    

       
   }
   return 0;
}
/*

*/
