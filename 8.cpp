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

void in(N*t, vector<int>&a) {

  if (!t) return;

  in(t->l, a);


  a.push_back(t->v);
  in(t->r, a);

}

int h(N*t) {

  return t?1+max(h(t->l), h(t->r)):-1;
}

bool same(N*a, N*b) {
  if (!a||!b) return a==b;


  return same(a->l, b->l)&&same(a->r, b->r);

}

void pr(string s, vector<int>&a) {
  cout<<s<<":";
  for (int x:a) cout<<" "<<x;

  cout<<endl;
}

int main() {
  int a[]={40, 20, 60, 10, 30, 50, 70}, b[]={30, 20, 55, 10, 40, 60, 75};
  N*x=0,*y=0;
  for (int v:a) x=ins(x, v);
    
  
    for (int v:b) y=ins(y, v);
  vector<int>p, q, both, oa, ob;
  in(x, p);
         in(y, q);


  int i=0, j=0;
  while (i<p.size()||j<q.size()) {
        
    if (j==q.size()||(i<p.size()&&p[i]<q[j])) oa.push_back(p[i++]);
            else if (i==p.size()||q[j]<p[i]) ob.push_back(q[j++]);

    else {

      both.push_back(p[i]);
      i++;

      j++;
    }

  }
  pr("Both", both);
  pr("Only A", oa);
  

  pr("Only B", ob);
  cout<<"Height A is "<<h(x)<<", height B is "<<h(y)<<endl;
  cout<<"Same shape:"<<(same(x, y)?"Yes":"No")<<endl;
}
