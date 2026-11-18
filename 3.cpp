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

N*delmin(N*t, int&m) {
  if (!t->l) {


    m=t->v;
    return t->r;
  }

    t->l=delmin(t->l, m);
  return t;
}

int k, rep;

N*del(N*t, int x) {
  if (!t) return t;
        if (x<t->v) {


    t->l=del(t->l, x);

    return t;
  }

  if (x>t->v) {
      t->r=del(t->r, x);

    return t;

  }
  if (!t->l&&!t->r) {
    k=0;

        return 0;

  }

  if (!t->l||!t->r) {
    k=1;

    return t->l?t->l:t->r;
  }
  k=2;
  int m;

  t->r=delmin(t->r, m);
         t->v=m;

  rep=m;


  return t;
}

void pre(N*t) {
  if (!t) return;


  cout<<" "<<t->v;
  pre(t->l);


  pre(t->r);
}

int h(N*t) {

  return t?1+max(h(t->l), h(t->r)):-1;
}

int main() {
  int a[]={50, 30, 70, 20, 40, 60, 80, 35, 45, 65};
    d[]={20, 70, 30, 50, 99};
    c[3]={0, 0, 0};

  N*t=0;
  for (int x:a) t=ins(t, x);
        for (int x:d) {

    k=-1;

    t=del(t, x);
    cout<<x<<" ";

    if (k<0) cout<<"Code not found"<<endl;
    else {
      c[k]++;
      if (k==0) cout<<"no sub-branch"<<endl;
       else if (k==1) cout<<"one sub-branch"<<endl;
      
      
       else cout<<"two sub-branches, replaced by "<<rep<<endl;
    }
  }
  cout<<"Remaining:";
  pre(t);

  cout<<endl<<"Height "<<h(t)<<endl<<"Kinds:none "<<c[0]<<", one "<<c[1]<<", two "<<c[2]<<endl;
}
