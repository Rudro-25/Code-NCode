//https://www.spoj.com/problems/TDKPRIME/

#include<bits/stdc++.h>
using namespace std;
#define      InTheNameOfGod     ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N = 9e7 + 1;
bool isPrime[N];
vector<int> PrimeList;
void sieve(int n){
    isPrime[0]=isPrime[1]= false;
    for(int i=2;i*i<n;i++){
      if(!isPrime[i]){
        for(int j=i*i;j<n;j+=i){
          isPrime[j]=true;
        }
      }
    }

    for(int i=2;i<n;i++){
      if(!isPrime[i]) PrimeList.push_back(i);
    }
}

int main(){
  InTheNameOfGod;
   sieve(N);
   //cout<<PrimeList.size()<<endl;
   int Test;
   cin>>Test;
   while(Test--){
      int n; cin>>n;
      cout<<PrimeList[n-1]<<endl;
   }
   return 0;
}
/*

*/
