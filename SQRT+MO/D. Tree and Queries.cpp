//https://codeforces.com/problemset/problem/375/D
//MO + sqrt decomposition

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
const int maxN = 100001;
const int BLOCK = 600;

vector<int> adj[maxN];
int S[maxN],T[maxN],FT[2*maxN],color[maxN];
int nodeF[maxN],eleF[maxN],FF[maxN];
int ans[maxN],bucket[maxN],n;
int timer;

struct query{
  int l,r,idx,minF;
};
query Q[maxN];

bool comp(query a,query b){
  int x= a.l/BLOCK;
  int y= b.l/BLOCK;

  if(x!=y) return x<y;

  if(x%2) return a.r<b.r;
  else return a.r > b.r;
}

void dfs(int node,int par){
    S[node]=timer;
    FT[timer]=node;
    timer++;

    for(int child : adj[node]){
        if(child!=par) dfs(child,node);
    }

    T[node]=timer;
    FT[timer]=node;
    timer++;
}

int getBlock(int idx){
  return (idx+BLOCK-1)/BLOCK; 
}

void add(int idx){
  int node= FT[idx];
  int colr= color[node];
  nodeF[node]++;

  if(nodeF[node]==2){
    eleF[colr]++;
    FF[eleF[colr]]++;
    bucket[getBlock(eleF[colr])]++;

    FF[eleF[colr]-1]--;
    bucket[getBlock(eleF[colr]-1)]--;
  }
}

void remove(int idx){
  int node= FT[idx];
  int colr= color[node];
  nodeF[node]--;

  if(nodeF[node]==1){
    eleF[colr]--;
    FF[eleF[colr]]++;
    bucket[getBlock(eleF[colr])]++;

    FF[eleF[colr]+1]--;
    bucket[getBlock(eleF[colr]+1)]--;
  }
}

int getAns(int minF,int n){
   int ans=0;

   //for(int i=minF;i<=n;i++) ans+=FF[i];
    int c_l = getBlock(minF), c_r = getBlock(n);
    if (c_l == c_r)
        for (int i=minF; i<=n; ++i)
            ans += FF[i];
    else {
        for (int i=minF, end=c_l*BLOCK; i<=end; ++i)
            ans += FF[i];
        for (int i=c_l+1; i<=c_r-1; ++i)
            ans += bucket[i];
        for (int i=c_r*BLOCK+1; i<=n; ++i)
            ans += FF[i];
    }

   return ans;
}

int main(){
   int Test=1;
   //cin>>Test;
   while(Test--){
       ll n,q; cin>>n>>q;

       for(int i=1;i<=n;i++) cin>>color[i];
       for(ll i=1;i<n;i++){
         int a,b; cin>>a>>b; 
         adj[a].pb(b); adj[b].pb(a);
       }

       timer=1;
       dfs(1,-1);

       for(int i=1;i<=q;i++){
         int val,minF; cin>>val>>minF;
         Q[i].l=S[val];
         Q[i].r=T[val];
         Q[i].idx=i;
         Q[i].minF=minF;
       }
       sort(Q+1,Q+q+1,comp);

       int ML=1,MR=0;

       for(int i=1;i<=q;i++){
         int L= Q[i].l;
         int R= Q[i].r;
         int idx= Q[i].idx;
         int minF= Q[i].minF;

         while(ML>L) ML--,add(ML);
         while(MR<R) MR++,add(MR);

         while(ML<L) remove(ML),ML++;
         while(MR>R) remove(MR),MR--;

         ans[idx]= getAns(minF,n);
       }

       for(int i=1;i<=q;i++)
          cout<<ans[i]<<endl;
   }
   return 0;
}
/*
8 5
1 2 2 3 3 2 3 3
1 2
1 5
2 3
2 4
5 6
5 7
5 8

1 2
1 3
1 4
2 3
5 3

ans:
2 2 1 0 1

4 1
1 2 3 4
1 2
2 3
3 4
1 1

ans:
4
*/
