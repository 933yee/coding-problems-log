class WordDictionary {
   public:
    struct Node {
        char ch;
        Node* next[26];
        bool end = false;
        Node(char c) {
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
            this->ch = c;
        }
    };
    Node* head;
    WordDictionary() {
        head = new Node('#');
    }

    void addWord(string word) {
        Node* cur = head;
        for (char c : word) {
            if (cur->next[c - 'a'] == NULL) {
                Node* newNode = new Node(c);
                cur->next[c - 'a'] = newNode;
                cur = newNode;
            } else
                cur = cur->next[c - 'a'];
        }
        cur->end = true;
    }

    bool search(string word) {
        queue<Node*> q;
        q.push(head);
        int cnt = 0;
        while (cnt < word.size()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                Node* cur = q.front();
                q.pop();
                if (word[cnt] == '.') {
                    for (int j = 0; j < 26; j++)
                        if (cur->next[j] != NULL)
                            q.push(cur->next[j]);
                } else if (cur->next[word[cnt] - 'a'] != NULL) {
                    q.push(cur->next[word[cnt] - 'a']);
                }
            }
            cnt++;
        }
        while (!q.empty()) {
            if (q.front()->end)
                return true;
            q.pop();
        }
        return false;
    }
};