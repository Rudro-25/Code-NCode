//insert/search only

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N= 2e5+5;
const int SIZE=26;
struct node{
  bool endOfWord;
  int cnt;
  node* TR[SIZE];
};

node* getNode(){
  node* n=new node;
  n->endOfWord=false;
  n->cnt=0;

  for(int i=0;i<SIZE;i++){
    n->TR[i]=NULL;
  }
  return n;
}

void insert(node *root,string st){
  node *tempRoot = root;
  tempRoot->cnt++;

  for(int i=0;i<st.size();i++){
    int index=st[i]-'a';

    if(tempRoot->TR[index] == NULL){
      tempRoot->TR[index]=getNode();
    }
    tempRoot= tempRoot->TR[index];
    tempRoot->cnt++;
  }
  tempRoot->endOfWord=true;
}

int search(node *root,string st){
  node *tempRoot = root;
  for(int i=0;i<st.size();i++){
    int index= st[i]-'a';

    if(tempRoot->TR[index] == NULL){
      return false;
    }
    tempRoot= tempRoot->TR[index];
  }

  return tempRoot->cnt;
}

int main(){
   node *root = getNode();

   int n,q,code;
   string st;
   cin>>n>>q;
   for(ll i=0;i<n;i++){
       cin>>st;
       insert(root,st);
   }

   for(ll i=0;i<q;i++){
       cin>>st;
       cout<<search(root,st)<<endl;
   }

   return 0;
}
/*
12 6
bulldog
dog
dogged
doggedly
doggerel
dogma
dogmatic
dogmatism
dogs
catastroph
catastroph
doctor

cat
dog
dogg
doctrinography
dogge

ans:
1
0
*/
