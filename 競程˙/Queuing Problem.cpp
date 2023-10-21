#include <bits/stdc++.h>
using namespace std;

int n, m;
struct node {
    node() {}
    node(int v) { val = v; }
    int val, backof;
    node* next = nullptr;
    node* prev = nullptr;
};
vector<node*> head(1000005), back(1000005), nodes(1000005);
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        node* dummy = new node(0);
        dummy->next = new node(i);
        dummy->next->backof = i;
        dummy->next->prev = dummy;
        head[i] = dummy;
        back[i] = dummy->next;
        nodes[i] = dummy->next;
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b == c) continue;
        if (a == 0) {
            node* cur1 = nodes[b];
            node* cur2 = nodes[c];

            cur1->prev->next = cur1->next;
            if (cur1->next)
                cur1->next->prev = cur1->prev;
            else {
                cur1->prev->backof = cur1->backof;
                back[cur1->backof] = cur1->prev;
            }

            cur1->next = cur2->next;
            if (cur2->next)
                cur2->next->prev = cur1;
            else {
                back[cur2->backof] = cur1;
                cur1->backof = cur2->backof;
            }

            cur2->next = cur1;
            cur1->prev = cur2;
        } else {
            node* cur1 = head[b]->next;
            if (cur1 != nullptr) {
                node* cur2 = back[c];
                cur2->next = cur1;
                cur1->prev = cur2;
                back[b]->backof = c;
                back[c] = back[b];
                back[b] = head[b];
                head[b]->next = nullptr;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        node* cur = head[i]->next;
        cout << "#" << i << ":";
        while (cur) {
            cout << " " << cur->val;
            cur = cur->next;
        }
        cout << '\n';
    }
}