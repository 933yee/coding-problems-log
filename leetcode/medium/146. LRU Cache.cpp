struct node {
    node* next = NULL;
    node* prev = NULL;
    int val, key;
    node(int val, int key) {
        this->val = val;
        this->key = key;
    }
};

class LRUCache {
    node *head, *back;
    unordered_map<int, node*> mp;
    int limit, size = 0;

   public:
    LRUCache(int capacity) {
        head = new node(-1, -1);
        back = head;
        limit = capacity;
    }

    int get(int key) {
        if (mp.count(key)) {
            if (mp[key] != back) {
                mp[key]->prev->next = mp[key]->next;
                mp[key]->next->prev = mp[key]->prev;
                back->next = mp[key];
                mp[key]->prev = back;
                mp[key]->next = NULL;
                back = mp[key];
            }
            return mp[key]->val;
        } else
            return -1;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            if (mp[key] != back) {
                mp[key]->prev->next = mp[key]->next;
                mp[key]->next->prev = mp[key]->prev;
                back->next = mp[key];
                mp[key]->prev = back;
                mp[key]->next = NULL;
                back = mp[key];
            }
            mp[key]->val = value;
        } else if (size < limit) {
            size++;
            node* newNode = new node(value, key);
            mp[key] = newNode;
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        } else {
            node* tmp = head->next;
            if (head->next == back) {
                back = head;
                head->next = NULL;
            } else {
                head->next = head->next->next;
                head->next->prev = head;
            }
            mp.erase(tmp->key);
            delete tmp;

            node* newNode = new node(value, key);
            mp[key] = newNode;
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        }
    }
};