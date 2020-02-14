#include <bits/stdc++.h>
using namespace std;


struct node {
    node* nxt[26];
    node* fail;
    int id;
    node() {
        fail = NULL; id = -1;
        for (int i = 0; i < 26; ++i)
            nxt[i] = NULL;
    }
};

class AC_Machine {
    public:
        void init() {
            root = new node[1];
            emp = new node[1];
        }
        int get_id(node *x) { return x->id; }
        node *get_root() { return root; }
        node *get_nxt(node *x, int k) { return x->nxt[k]; }
        node *get_fail(node *x) { return x->fail; }
        void insert(char *c, int id) {
            int len = strlen(c);
            node *now = root;
            for (int i = 0; i < len; ++i) {
                int x = c[i] - 'a';
                if ((now->nxt[x]) == NULL)
                    now->nxt[x] = new node[1];
                now = now->nxt[x];
            }
            now->id = id;
        }
        void build() {
            node *now;
            queue <node *> q;
            root->fail = emp;
            for (int i = 0; i < 26; ++i)
                emp->nxt[i] = root;
            q.push(root);
            while (!q.empty()) {
                now = q.front(); q.pop();
                for (int i = 0; i < 26; ++i) {
                    if ((now->nxt[i]) == NULL) {
                        now->nxt[i] = now->fail->nxt[i];
                    } else {
                        now->nxt[i]->fail = now->fail->nxt[i];
                        q.push(now->nxt[i]);
                    }
                }
            }
        }
    private:
        node *root, *emp;
        void clean(node *ro) {
            for (int i = 0; i < 26; ++i)
                if (ro->nxt[i] != NULL)
                    clean(ro->nxt[i]);
            delete ro;
        }
}t;

int n, ans, sum[200];
char ch[200][100];
char s[1000005];

void init() {
    t.init(); ans = 0;
    memset(sum, 0,sizeof(sum));
}

void solve() {
    scanf ("%s", s);
    int len = strlen(s);
    node *now = t.get_root();
    for (int i = 0; i < len; ++i) {
        int x = s[i] - 'a';
        now = t.get_nxt(now, x);
        for (node *j = now;j != t.get_root(); j = t.get_fail(j)) {
            x = t.get_id(j);
            if (x != -1) sum[x]++;
        }
    }
}

int main () {
    while (~scanf ("%d", &n) && n) { 
        init();
        for (int i = 1; i <= n; ++i) {
            scanf ("%s", ch[i]);
            t.insert(ch[i], i);
        }
        t.build();
        solve();
        for (int i = 1; i <= n; ++i) 
            ans = max(ans, sum[i]);
        printf ("%d\n", ans);
        for (int i = 1; i <= n; ++i)
            if (sum[i] == ans)
                printf ("%s\n", ch[i]);
    }
    return 0;
}