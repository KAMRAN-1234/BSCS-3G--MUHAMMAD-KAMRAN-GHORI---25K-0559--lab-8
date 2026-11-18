#include <bits/stdc++.h>
using namespace std;

struct N {
    int v;
    N *l=0, *r=0;
    N(int x):v(x) {}
};

N* ins(N* t, int x, bool &ok) {
    if (!t) {
        ok=1;
        return new N(x);
    }

    if (x<t->v) t->l=ins(t->l, x, ok);
         else if (x>t->v) t->r=ins(t->r, x, ok);
    return t;
}

void in(N* t, vector<int> &a) {
    if (!t) return;


    in(t->l, a);
        a.push_back(t->v);


    in(t->r, a);
}

void pre(N* t, vector<int> &a) {
    if (!t) return;
    
    a.push_back(t->v);
        pre(t->l, a);

            pre(t->r, a);
}

bool same(N* a, N* b) {
    if (!a || !b) return a == b;

    
    return a->v == b->v && same(a->l, b->l) && same(a->r, b->r);
}

int main() {
    int in1[]={50, 30, 70, 20, 40, 60, 80, 30, 65};

    N* t=0;


    for (int x:in1) {
        bool ok=0;
             t=ins(t, x, ok);

        if (!ok) cout<<"Already issued: "<<x<<"\n";
    }
    vector<int> a, b;
    in(t, a);

    cout<<"Calling list:";

            for (int x:a) cout<<" "<<x;
        pre(t, b);
    cout<<"\nBackup list:";
    
for (int x:b) cout<<" "<<x;
    N* u=0;
    for (int x:b) {
            bool ok;

        u=ins(u, x, ok);
    }
    
    cout<<"\n"<<(same(t, u) ? "Backup is safe":"Backup is wrong")<<"\n";
}