//https://www.spoj.com/problems/GOT/
//MO + LCA
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define InTheNameOfGod   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const int maxN = 100005;
const int BLOCK = 450;
 
vector<int> adj[maxN];
int S[maxN],T[maxN],FT[2*maxN];
int nodeF[maxN],eleF[maxN],level[maxN];
int ans[2*maxN],LCA[maxN][21],val[maxN];
int timer;
 
struct query{
  int l,r,c,idx,lca;
};
query Q[2*maxN];
 
bool comp(query a,query b){
  if(a.l/BLOCK != b.l/BLOCK)
   return a.l/BLOCK < b.l/BLOCK;
 
   return a.r < b.r;
}
// bool comp(query a,query b){
//   int x= a.l/BLOCK;
//   int y= b.l/BLOCK;
 
//   if(x!=y) return x<y;
 
//   if(x%2) return a.r<b.r;
//   else return a.r > b.r;
// }
 
void dfs(int node,int par,int lvl){
    level[node]=lvl;
    LCA[node][0]=par;
 
    S[node]=timer;
    FT[timer]=node;
    timer++;
 
    for(int child : adj[node]){
        if(child!=par) dfs(child,node,lvl+1);
    }
 
    T[node]=timer;
    FT[timer]=node;
    timer++;
}
 
void add(int idx){
  int node= FT[idx];
  nodeF[node]++;
 
  if(nodeF[node]==1){
    int c= val[node];
    eleF[c]++;
  }
  else{
    int c=val[node];
    eleF[c]--;
  }
}
 
void remove(int idx){
  int node= FT[idx];
  nodeF[node]--;
 
  if(nodeF[node]==1){
    int c= val[node];
    eleF[c]++;
  }
  else{
    int c=val[node];
    eleF[c]--;
  }
}
void init(int n){
  for(int j=1;j<21;j++){
    for(int i=1;i<=n;i++){
      if(LCA[i][j-1]!=-1) LCA[i][j]=LCA[LCA[i][j-1]][j-1];
    }
  }
}
 
int getLCA(int a,int b){
   if(level[a]>level[b]) swap(a,b);
 
   int d= level[b]-level[a];
   int f=0;
   while(d){
     if(d&1) b=LCA[b][f];
     d>>=1;
     f++;
   }
   if(a==b) return a;
 
   for(int j=20;j>=0;j--){
     if(LCA[a][j] != -1 && (LCA[a][j] != LCA[b][j])){
       a= LCA[a][j],b=LCA[b][j];
     }
   }
   return LCA[a][0];
}
 
int main(){
  InTheNameOfGod
   int t=0,n,q;
   //cin>>Test;
   while(cin>>n){
       cin>>q;
       for(int i=0;i<=n;i++)
         adj[i].clear(),eleF[i]=nodeF[i]=0;
       for(int i=1;i<=q;i++) ans[i]=0;   
 
       for(int i=1;i<=n;i++) cin>>val[i];
       for(ll i=1;i<n;i++){
         int a,b; cin>>a>>b; 
         adj[a].pb(b); adj[b].pb(a);
       }
 
       timer=1;
       memset(LCA,-1, sizeof LCA);
       dfs(1,-1,0);
       init(n);
 
       for(int i=1;i<=q;i++){
         int a,b,c; cin>>a>>b>>c;
 
 
         if(S[a]>S[b]) swap(a,b);
         
         int lca= getLCA(a,b);
 
         Q[i].idx=i,Q[i].c=c; 
 
         //1st type query
         if(a==lca) Q[i].l=S[a],Q[i].r=S[b],Q[i].lca=-1;
         //2nd type query
         else Q[i].l=T[a],Q[i].r=S[b],Q[i].lca=lca;
       }
       sort(Q+1,Q+q+1,comp);
 
       int ML=1,MR=0;
 
       for(int i=1;i<=q;i++){
         int L= Q[i].l;
         int R= Q[i].r;
         int idx= Q[i].idx;
         int c= Q[i].c;
         int lca=Q[i].lca;
 
         while(ML>L) ML--,add(ML);
         while(MR<R) MR++,add(MR);
 
         while(ML<L) remove(ML),ML++;
         while(MR>R) remove(MR),MR--;
 
         if(eleF[c]>0) ans[idx]=1;
         if(lca!=-1 && val[lca]==c) ans[idx]=1;
       }
 
       for(int i=1;i<=q;i++){
         if(ans[i]==1) printf("Find\n\n");
         else printf("NotFind\n\n");
       }
   }
   return 0;
}
/*
5 5
1 2 3 4 5
1 2
1 3
3 4
3 5
 
2 3 4
2 4 3
2 4 5
4 5 1
4 5 3
*/ 
