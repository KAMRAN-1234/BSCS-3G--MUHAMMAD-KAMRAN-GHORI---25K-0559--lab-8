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

int main() {
  int a[]={45, 20, 60, 10, 30, 50, 70, 25, 35};
  q[]={35, 55, 5, 70};


  N*t=0;

  for (int x:a) t=ins(t, x);

  for (int x:q) {
    N*c=t;

        int cnt=0, sm=-1, bg=-1;
    bool f=0;

    while (c) {
      cnt++;

      if (x==c->v) {
        f=1;
        break;
      }
      if (x<c->v) {

        bg=c->v;
        c=c->l;
      } else {

        sm=c->v;
        c=c->r;
      }
    }

    cout<<x<<":";


    if (f) cout<<"Found, "<<cnt<<" compared."<<endl;

    else {
      cout<<"Not found, "<<cnt<<" compared, smaller ";


      if (sm<0) cout<<"None";
        else cout<<sm;
      cout<<", bigger ";

        if (bg<0) cout<<"None";
      else cout<<bg;

      cout<<"."<<endl;
    }
  }

}
