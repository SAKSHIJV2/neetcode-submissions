class ListNode {
public:
    int key;
    int val;
    ListNode* prev;
    ListNode* next;

    ListNode(int k, int v)
    {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
public:
    int cap;
    unordered_map<int,ListNode*> mp;
    ListNode *head;
    ListNode *tail;
    LRUCache(int capacity) {
        cap=capacity;
        head=new ListNode(-1,-1);
        tail=new ListNode(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void remove(ListNode *node){
        ListNode *prevNode=node->prev;
        ListNode *nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    void insert(ListNode *node){
        ListNode *first=head->next;
        head->next=node;
        node->prev=head;
        first->prev=node;
        node->next=first;       
    }
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        ListNode *node=mp[key];
        remove(node);
        insert(node);
        return node->val;
    }    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            remove(mp[key]);
            delete mp[key];
            mp.erase(key);
        }
        ListNode *node=new ListNode(key,value);
        mp[key]=node;
        insert(node);
        if(mp.size() > cap)
        {
            ListNode* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};
