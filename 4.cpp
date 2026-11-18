#include<bits/stdc++.h>
using namespace std;

int l[11], r[11], p[11], d[11];

void pr(int x) {
  if (x) cout<<x;

  else cout<<"None";
}

int main() {
  int a[]={1, 2, 1, 3, 2, 4, 2, 5, 3, 6, 5, 7, 6, 8, 6, 9, 8, 10};
  string s="LRLRRLLRL";
  for (int i=0; i<9; i++) {
    int m=a[2*i], e=a[2*i+1];
    if (s[i]=='L') l[m]=e;
    else r[m]=e;
    p[e]=m;

  }
  vector<vector<int>>lv;
  queue<int>q;
  q.push(1);
  while (!q.empty()) {

    int u=q.front();
    q.pop();
    if (u!=1) d[u]=d[p[u]]+1;

    if (d[u]==lv.size()) lv.push_back({});

    lv[d[u]].push_back(u);
    
    
    if (l[u]) q.push(l[u]);
            
        if (r[u]) q.push(r[u]);
  }
  for (int i=0; i<lv.size(); i++) {
    cout<<"Level "<<i<<":";

            for (int x:lv[i]) cout<<" "<<x;
    cout<<endl;
  }
 
  cout<<"Height "<<lv.size()-1<<endl<<"No one under them:";
  for (int i=1; i<=10; i++)
       if (!l[i]&&!r[i]) cout<<" "<<i;
  
  
       cout<<endl;

  int w[]={10, 5};
  for (int x:w) {
  
    vector<int>c;


    for (int u=x; u; u=p[u]) c.push_back(u);
         reverse(c.begin(), c.end());

    cout<<"For "<<x<<":chain";
            for (int u:c) cout<<" "<<u;


    int g=0;    


        if (p[x]) g=l[p[x]]==x?r[p[x]]:l[p[x]];

    cout<<", colleague ";
    
        pr(g);
    cout<<endl;

  }
}
