//KMP-pattern search
//https://www.spoj.com/problems/ADAPET/

#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
using namespace std;

#define ll long long int
#define pb push_back
#define      InTheNameOfGod     ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 5e5+5;
const int mod=1e9+7;
char s[N];
ll lps[N];
//LPS[i]= longest matched (prefix from start and suffix of ith position).

int main(){
   InTheNameOfGod
   int Test=1;
   scanf("%d",&Test);
   while(Test--){
       ll k;
       scanf("%s %lld",s,&k);
       int n= strlen(s);
        lps[0]=0;
        for(int i=1,k=0;i<n;i++){
          while(k>0 && s[k]!=s[i])
            k=lps[k-1];
          if(s[i]==s[k]) k++;
          lps[i]=k;
          //cout<<k<<' ';
        }
       printf("%lld\n",n+(n-lps[n-1])*(k-1));
   }
   return 0;
}
/*
2
na
banananobano
6
foobar
foo
9
foobarfoo
barfoobarfoobarfoobarfoobarfoo

ans: 
2
4

3
9
15
21
*/
