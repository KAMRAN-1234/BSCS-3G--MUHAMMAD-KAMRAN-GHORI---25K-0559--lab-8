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

bool has(N*t, int x) {
  while (t) {
     if (x==t->v) return 1;
   
     t=x<t->v?t->l:t->r;
  }
  return 0;

}

int dep(N*t, int x) {
  int d=0;
    while (t->v!=x) {
    
    t=x<t->v?t->l:t->r;
    d++;
  }

  return d;
}

int main() {
  int a[]={50, 30, 70, 20, 40, 60, 80, 35, 45};
   q[4][2]={{35, 45}, {20, 60}, {30, 35}, {35, 99}};


  N*t=0;

  for (int x:a) t=ins(t, x);
    
        for (auto&w:q) {
    int x=w[0], y=w[1];
    cout<<"("<<x<<", "<<y<<"):";

    if (!has(t, x)||!has(t, y)) {
         cout<<"Employee not found"<<endl;

      continue;
    }
    N*c=t;
    while (!((x<=c->v&&y>=c->v)||(y<=c->v&&x>=c->v))) c=x<c->v?c->l:c->r;
    
    
    cout<<"boss "<<c->v<<", distance "<<dep(t, x)+dep(t, y)-2*dep(t, c->v)<<endl;
  }
}
