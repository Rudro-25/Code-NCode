//https://www.spoj.com/problems/RMQSQ/
//0 based
//min in range query
//sqrt(n)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define      ll                  long long
#define      pb                 push_back
#define      mp                 make_pair
#define      all(x)             x.begin(),x.end()
#define      Ceil(x,y)           ((x+y-1)/y)
#define      gcd(a,b)            __gcd(a,b)
#define      lcm(a,b)           (a*b)/gcd(a,b)
#define      InTheNameOfGod      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr ll mod = 1e9 + 7;
const ll N=3e6+5;

void solve(){
   ll n,q;
   cin>>n;
   vector<int> a(n);
   for(ll i=0;i<n;i++) cin>>a[i];

   int len = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks
   vector<int> b (len);
   for(ll i=0;i<len;i++) b[i]=INT_MAX;
   for (int i=0; i<n; ++i)
       b[i / len] = min(b[i/len],a[i]);
   cin>>q;
   while(q--){
      int l, r;
      cin>>l>>r;
      int sum = 0;
      int c_l = l / len,   c_r = r / len;
      int ans=INT_MAX;
      if (c_l == c_r)
          for (int i=l; i<=r; ++i)
              ans=min(ans,a[i]);
      else {
          for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
              ans=min(ans,a[i]);
          for (int i=c_l+1; i<=c_r-1; ++i)
              ans=min(ans,b[i]);
          for (int i=c_r*len; i<=r; ++i)
              ans=min(ans,a[i]);
      }
      cout<<ans<<endl;
   }


}

int main(){
   InTheNameOfGod;
   ll Test=1;
   //cin>>Test;
   while(Test--){
     solve();
    }
  return 0;
}
/*
5 4
1 2 3 4 5
0 2
1 4
2 3
3 3

ans:
6
14
7
4
*/
