//https://www.codechef.com/problems/JAIN
//simple bitmasking

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=4e4+1;
const int mod=1e9+7;
ll F[32];

int main(){
   int Test=1;
   cin>>Test;
   while(Test--){
       ll n; cin>>n;
       for(ll i=0;i<32;i++) F[i]=0;

       for(ll i=1;i<=n;i++){
         string st; cin>>st;
         ll mask=0;
         for(char ch : st){
           if(ch == 'a') mask|=(1LL<<0);
           if(ch == 'e') mask|=(1LL<<1);
           if(ch == 'i') mask|=(1LL<<2);
           if(ch == 'o') mask|=(1LL<<3);
           if(ch == 'u') mask|=(1LL<<4);
         }
         F[mask]++;
         //cout<<mask<<endl;
       }
       ll res=0;
       for(ll i=1 ;i<32;i++){
         for(ll j=i+1;j<32;j++){
           if((i|j)==31){
             res+= (F[i]*F[j]);
             //cout<<i<<' '<<j<<endl;
           } 
         }
       }
       res+= (F[31]*(F[31]-1))/2;

       cout<<res<<endl;
   }
   return 0;
}
/*

*/
