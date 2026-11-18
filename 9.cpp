#include<bits/stdc++.h>
using namespace std;

struct N {
  int v;
  N*l=0,*r=0;
  N(int x):v(x) {}
};

N*ins(N*t, int x) {
  if (!t) return new N(x);

  if (x<t->v) t->l=ins(t->l, x);

  else t->r=ins(t->r, x);
  return t;
}

int seen;

void go(N*t, int lo, int hi, vector<int>&a) {
  if (!t) return;
  seen++;

  if (t->v>lo) go(t->l, lo, hi, a);

  if (t->v>=lo&&t->v<=hi) a.push_back(t->v);
    
  if (t->v<hi) go(t->r, lo, hi, a);
}

int main() {
  int a[]={500, 300, 800, 200, 400, 700, 900, 100, 250, 350, 450, 600}, n=12;
  N*t=0;
  for (int x:a) t=ins(t, x);
     int q[2][2]={{350, 700}, {610, 650}};
  
     for (auto&w:q) {
    
    vector<int>r;
        
    seen=0;
    go(t, w[0], w[1], r);
            cout<<"For range "<<w[0]<<" to "<<w[1]<<":";
    if (r.empty()) cout<<"no amounts";
    for (int i=0; i<r.size(); i++) {
        
        if (i) cout<<" ";
      cout<<r[i];
    }
     cout<<", count "<<r.size()<<", looked at "<<seen<<" of "<<n<<" nodes"<<endl;
  }
}
