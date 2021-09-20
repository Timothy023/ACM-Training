#include<bits/stdc++.h>
using namespace std;
map<int,int> file;
class Node{
public:
    map<string, Node*> son;
    set<int> sonv;
    int dt;
    int ma;
    int s;
    Node *fa;
    Node(Node* f){
        fa = f;
        s = -1;
    }
};
Node *root;
string s;
void dfs(Node* p, Node *fa, int op, int val){
    string tmp; char c;
    while((c = getchar() != '/') && c != '\n') tmp.push_back(c);
    if(s.empty()) return;
    
    if(!p->son.count(s)) p->son[s] = new Node(p);
    p->son[s]->s = max(p->son[s]->s, p->s);
}
int main(){
    root = new Node(nullptr);
    char ch[10], c;
    while(scanf("%s", ch) != -1){
        Node *ptr = root;
        while((c = getchar()) != '/');
        if(ch[0] == 'g'){
            int ma1 = 0, ma2 = 0;
            while(1){
                s.clear();
                while((c = getchar()) != '/' && c != '\n') s.push_back(c);
                if(ptr->s != -1) ma1 = max(ma1, ptr->s);
                if(ptr->s == -1 && ptr->dt != 0) ma1 = max(ma1, ptr->dt);
                if(s.empty()){
                    ma2 = ma1;
                    break;
                }
                if(!ptr->son.count(s)){
                    ptr->son[s] = new Node(ptr);
                }
                ptr->son[s]->dt = ptr->dt;
                ptr->son[s]->s = max(ptr->son[s]->s, ptr->s);
                if(c == '\n'){
                    ma2 = max(ptr->ma, ptr->s);
                    if(ptr->s == -1) ma2 = max(ma2, ptr->dt);
                    break;
                }
                ptr = ptr->son[s];
            }
            cout << ma1 << " " << ma2 << "\n";
        }
        if(ch[0] == 'd'){

        }
        if(ch[0] == 's'){
            
        }
    }
}