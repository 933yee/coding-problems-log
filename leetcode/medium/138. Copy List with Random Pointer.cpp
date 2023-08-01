class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node*, int> mp;
        vector<Node*> v;

        Node* cur = head;
        for (int i = 0; cur; i++) {
            Node* created = new Node(cur->val);
            v.push_back(created);
            mp[cur] = i;
            cur = cur->next;
        }
        cur = head;
        for (int i = 0; cur; i++) {
            if (i != 0)
                v[i - 1]->next = v[i];

            if (cur->random)
                v[i]->random = v[mp[cur->random]];
            else
                v[i]->random = nullptr;
            cur = cur->next;
        }
        v[v.size() - 1]->next = nullptr;
        return v[0];
    }
};