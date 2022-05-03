//https://codeforces.com/problemset/problem/86/D
//MO's Algo (offline)
//

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define BLOCK 500
#define InTheNameOfGod   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);


struct query{
  int l,r,i;
};
query Q[200001];
int ar[200001];
ll ans[200001];
int freq[1000001];
ll power=0;
bool comp(query a,query b){
  if(a.l/BLOCK != b.l/BLOCK)
   return a.l/BLOCK < b.l/BLOCK;

   return a.r < b.r;
}
void add(int pos){
  ll cnt= freq[ar[pos]];
  freq[ar[pos]]++;
  power-= cnt*cnt*ar[pos]; cnt++;
  power+= cnt*cnt*ar[pos];
}
void remove(int pos){
  ll cnt= freq[ar[pos]];
  freq[ar[pos]]--;
  power-= cnt*cnt*ar[pos]; cnt--;
  power+= cnt*cnt*ar[pos];
}

int main(){
   InTheNameOfGod
   int Test=1;
   //cin>>Test;
   while(Test--){
       int n,q; cin>>n>>q;
       for(int i=0;i<n;i++) cin>>ar[i];

       for(int i=0;i<q;i++){
         cin>>Q[i].l>>Q[i].r;
         Q[i].i=i; Q[i].l--,Q[i].r--;
       }

       sort(Q,Q+q,comp);

       int ML=0,MR=-1;
       for(int i=0;i<q;i++){
         int L=Q[i].l;
         int R=Q[i].r;

         while(ML>L) ML--,add(ML);
         while(MR<R) MR++,add(MR);

         while(ML<L) remove(ML),ML++;
         while(MR>R) remove(MR),MR--;

         ans[Q[i].i]=power;
       }

       for(int i=0;i<q;i++)
        cout<<ans[i]<<endl;
    
   }
   return 0;
}
/*

*/
