#include<bits/stdc++.h>
using namespace std;

void solve(char name, vector<int>p, vector<int>c, string s) {
  int l[20]={}, r[20]={}, ex[20]={};
  for (int i=0; i<p.size(); i++) {
        
    if (s[i]=='L') l[p[i]]=c[i];
            
        else r[p[i]]=c[i];
    ex[p[i]]=ex[c[i]]=1;
  }


  bool full=1, neat=1, seen=0;
 
     vector<int>f;
    
     for (int i=1; i<20; i++) {
            if (ex[i]&&(l[i]>0)!=(r[i]>0)) {
         full=0;
        f.push_back(i);

    }
  }
  queue<int>q;

  q.push(1);
  while (!q.empty()) {

    int u=q.front();
    q.pop();
    if (!u) seen=1;

    else {
      if (seen) neat=0;

      q.push(l[u]);
      q.push(r[u]);
    }
  }
  cout<<name<<":Full "<<(full?"Yes":"No")<<", Neat "<<(neat?"Yes":"No")<<", free pass";

         if (f.empty()) cout<<" None";

     for (int x:f) cout<<" "<<x;
  cout<<endl;
}

int main() {

  solve('B', {1, 1, 2, 2, 3}, {2, 3, 4, 5, 6}, "LRLRL");
  solve('C', {1, 1, 3, 3}, {2, 3, 6, 7}, "LRLR");
  solve('D', {1, 1, 2, 2, 3}, {2, 3, 4, 5, 7}, "LRLRR");
}
