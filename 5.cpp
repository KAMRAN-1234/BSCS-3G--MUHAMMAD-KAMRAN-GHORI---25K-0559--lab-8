#include<bits/stdc++.h>
using namespace std;

int l[11], r[11], c[]={0, 5,-3, 4, 6, 2,-2, 9, 3, 1,-1}, best=INT_MIN, cnt;
vector<int>path, bp;

    void go(int u, int sum) {

  sum+=c[u];
    
  
        path.push_back(u);
  if (!l[u]&&!r[u]) {
        cnt++;
    
        if (sum>best) {
      best=sum;

      bp=path;
    }
  }

  if (l[u]) go(l[u], sum);


    if (r[u]) go(r[u], sum);
 
    path.pop_back();
}

int main() {
  int a[]={1, 2, 1, 3, 2, 4, 2, 5, 3, 6, 5, 7, 6, 8, 6, 9, 8, 10};
  string s="LRLRRLLRL";
    
    for (int i=0; i<9; i++) {

    int m=a[2*i], e=a[2*i+1];
         if (s[i]=='L') l[m]=e;


    else r[m]=e;
  }
  go(1, 0);

        cout<<cnt<<" routes"<<endl<<"Best route:";
        
  for (int x:bp) cout<<" "<<x;
  cout<<" with "<<best<<" coins"<<endl;
}
