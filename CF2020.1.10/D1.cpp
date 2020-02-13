#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int s = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * f;
}
struct node {
    node *ch[2];
}*root;
inline node* newnode() {
    node *ret = new node;
    ret -> ch[0] = ret -> ch[1] = NULL;
    return ret;
}
inline void init() {
    root = new node;
    root -> ch[0] = root -> ch[1] = NULL;
}
int bit[31];
inline void ins(int x) {
    node *rt = root;
    for(int i = 30; i >= 0; --i) {
        bool d = x & bit[i];
        if(rt -> ch[d] == NULL) rt -> ch[d] = newnode();
        rt = rt -> ch[d];
    }
}
inline int query(node *rt, int dep) {
    if(rt == NULL) return 0;
    if(dep < 0) return 0;
    int ret = 0;
    if(rt -> ch[0] && rt -> ch[1]) {
        ret = min(query(rt -> ch[0], dep - 1), query(rt -> ch[1], dep - 1));
        return ret | bit[dep];
    }
    if(rt -> ch[0]) return query(rt -> ch[0], dep - 1);
    if(rt -> ch[1]) return query(rt -> ch[1], dep - 1);
    return ret;
}
int n;
int main() {
    for(int i = 0; i < 30; ++i) bit[i] = 1 << i;
    int s;
    init();
    n = read();
    for(int i = 1; i <= n; ++i) {
        s = read();
        ins(s);
    }
    cout << query(root, 30) << endl;
}