//Matrix_Exponentiation
//https://www.spoj.com/problems/MPOW/

#include<bits/stdc++.h>
using namespace std;
#define   ll               long long
#define   InTheNameOfGod   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const ll N = 105;
const ll mod = 1e9 + 7;
int ar[N][N],I[N][N];

void mul(int A[][N],int B[][N], int dim){
  ll res[dim+1][dim+1];

  for(ll i=1;i<=dim;i++){
    for(ll j=1;j<=dim;j++){
      res[i][j]=0;
      for(ll k=1;k<=dim;k++){
        res[i][j] = (res[i][j]%mod + (A[i][k]%mod * B[k][j]%mod)%mod) %mod;
      }
    }
  }

  for(ll i=1;i<=dim;i++){
    for(ll j=1;j<=dim;j++){
      A[i][j]=res[i][j]%mod;
    }
  }
}

void power(int A[][N],int dim, int n){
    for(ll i=1;i<=dim;i++){
      for(ll j=1;j<=dim;j++){
        if(i==j) I[i][j]=1;
        else I[i][j]=0;
      }
    }

    //for(ll i=1;i<=n;i++) mul(I, A, dim);
    while(n){
      if(n%2) mul(I,A,dim),n--;
      else mul(A,A,dim), n/=2;
    }
    
    for(ll i=1;i<=dim;i++){
      for(ll j=1;j<=dim;j++){
        A[i][j] = I[i][j];
      }
    }
}

void printMat(int A[][N],int dim){
  for(ll i=1;i<=dim;i++){
    for(ll j=1;j<=dim;j++){
      cout<<A[i][j]<<' ';
    }
    cout<<endl;
  }
}

int main(){
  InTheNameOfGod;

   int Test=1;  
   cin>>Test;
   while(Test--){
      int dim,n; cin>>dim>>n;
      for(ll i=1;i<=dim;i++){
        for(ll j=1;j<=dim;j++){
          cin>>ar[i][j];
        }
      }

      power(ar,dim,n);
      printMat(ar,dim);

   }
   return 0;
}
/*

*/
