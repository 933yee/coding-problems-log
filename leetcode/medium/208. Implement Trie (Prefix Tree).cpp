class Trie {
   public:
    struct TrieNode {
        TrieNode* next[26];
        bool end = false;
        TrieNode(char c) {
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    };
    TrieNode* head;
    Trie() {
        head = new TrieNode('#');
    }

    void insert(string word) {
        TrieNode* cur = head;
        for (char c : word) {
            if (cur->next[c - 'a'] == NULL) {
                TrieNode* newTrieNode = new TrieNode(c);
                cur->next[c - 'a'] = newTrieNode;
                cur = newTrieNode;
            } else
                cur = cur->next[c - 'a'];
        }
        cur->end = true;
    }

    bool search(string word) {
        TrieNode* cur = head;
        for (char c : word) {
            if (cur->next[c - 'a'] == NULL) {
                return false;
            } else
                cur = cur->next[c - 'a'];
        }
        return cur->end;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = head;
        for (char c : prefix) {
            if (cur->next[c - 'a'] == NULL) {
                return false;
            } else
                cur = cur->next[c - 'a'];
        }
        return true;
    }
};