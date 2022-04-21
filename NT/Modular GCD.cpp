//https://www.codechef.com/problems/GCDMOD

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define      ll                 long long
#define      pb                 push_back
#define      mp                 make_pair
#define      all(x)             x.begin(),x.end()
#define      Ceil(x,y)          ((x+y-1)/y)
#define      gcd(a,b)           __gcd(a,b)
#define      lcm(a,b)           (a*b)/gcd(a,b)
#define      InTheNameOfGod     ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll modpow(ll a,ll b,ll m){ll ans=1;while(b){if(b&1)ans=((ans%m)*(a%m))%m;b/=2;a=((a%m)*(a%m))%m;}return ans;}
constexpr ll mod = 1e9 + 7;
const ll N=3e6+5;

ll find_ans(ll a,ll b,ll n){
  if(a==b){
    return (modpow(a,n,mod)+modpow(b,n,mod))%mod;
  }
  ll dif= a-b,ans=1; 
  for(ll i=1;i*i<=dif;i++){
    if(dif%i==0){
      ll val= (modpow(a,n,i)+modpow(b,n,i))%i;
      if(val==0) ans=max(ans,i);
      val= (modpow(a,n,dif/i)+modpow(b,n,dif/i))%(dif/i);
      if(val==0) ans=max(ans,dif/i);
    }
  }
  return ans%mod;
}

void solve(){
   ll a,b,n; cin>>a>>b>>n;
   cout<<find_ans(a,b,n)<<endl;
}

int main(){
   InTheNameOfGod;
   ll Test=1;
   cin>>Test;
   while(Test--){
     solve();
    }
  return 0;
}

