#include<bits/stdc++.h>
using namespace std;

int l[100], r[100], bad, anc;


void check(int u, int lo, int la, int hi, int ha) {
  if (!u||bad) return;
    
        if (lo&&u<=lo) {

         bad=u;
    
     anc=la;
    return;
  }
  
  
        if (hi&&u>=hi) {
bad=u;
        anc=ha;
    return;
  }
  check(l[u], lo, la, u, u);
 
  check(r[u], u, u, hi, ha);
}

void solve(vector<int>p, vector<int>c, string s) {
  memset(l, 0, sizeof l);
    
    memset(r, 0, sizeof r);
  bad=anc=0;
  for (int i=0; i<p.size(); i++) {
      if (s[i]=='L') l[p[i]]=c[i];

    else r[p[i]]=c[i];
  }

  check(p[0], 0, 0, 0, 0);

  if (!bad) cout<<"Valid"<<endl;
        else cout<<"Invalid, first wrong ID "<<bad<<", it disagrees with "<<anc<<endl;
}

int main() {

  cout<<"Tree 1:";

  solve({20, 20, 10, 10, 30}, {10, 30, 5, 25, 35}, "LRLRR");
        
  cout<<"Tree 2:";
  
  solve({40, 40, 20, 60, 60}, {20, 60, 30, 50, 70}, "LRRLR");
}
