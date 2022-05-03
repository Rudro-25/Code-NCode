//https://codeforces.com/problemset/problem/1514/D
//MO's Algo (offline)
//

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define BLOCK 550
#define InTheNameOfGod   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);


struct query{
  int l,r,i;
};
query Q[300001];
int ar[300001];
int ans[300001];
int freq[300001],cntFreq[300001];
ll maxFreq=0;
bool comp(query a,query b){
  if(a.l/BLOCK != b.l/BLOCK)
   return a.l/BLOCK < b.l/BLOCK;

   return a.r < b.r;
}
void add(int pos){
  int pref= freq[ar[pos]];
  freq[ar[pos]]++;
  int curF= freq[ar[pos]];

  cntFreq[pref]--;
  cntFreq[curF]++;
  if(curF>maxFreq) maxFreq=curF;
}
void remove(int pos){
  int pref= freq[ar[pos]];
  freq[ar[pos]]--;
  int curF= freq[ar[pos]];

  cntFreq[pref]--;
  cntFreq[curF]++;
  if(maxFreq==pref && !cntFreq[pref]){
    while(!cntFreq[maxFreq]) maxFreq--;
  }
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

         int total= Q[i].r-Q[i].l+1;
         int rem= total-maxFreq;
         if(maxFreq<=(rem+1)) ans[Q[i].i]=1;
         else{
           ans[Q[i].i]= total- 2*rem;
         }
       }

       for(int i=0;i<q;i++)
        cout<<ans[i]<<endl;
    
   }
   return 0;
}
/*

*/
