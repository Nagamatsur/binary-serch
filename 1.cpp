#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
 
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> p(n+1);
  p[0]=0;
  rep(i,n) cin>>p[i+1];
  
  
  vector<int> q((n+1)*(n+1));
  rep(i,n+1){
    rep(j,n+1){
      q[i*(n+1)+j]=p[i]+p[j];
    }
  }
  sort(q.begin(),q.end());
  //rep(i,(int)q.size()) cout<<q[i]<<endl;
  
  int ans=0;
  rep(i,(int)q.size()){
    if(q[i]>m) continue;
    int left = -1;
    int right = (int)q.size();
    while (right-left > 1) {
        int mid = (right+left)/2;
        //cout<<q[i]+q[left]<<endl;
        if(q[i]+q[mid] <= m){ left = mid; }//cout<<q[left]<<" true "<<q[i]+q[left]<<endl;}
        else right = mid;
    }
    if(q[i]+q[left]>ans) ans=q[i]+q[left];
    //cout<<"ans="<<ans<<endl;
  }
  cout<<ans<<endl;
  return 0;
}
