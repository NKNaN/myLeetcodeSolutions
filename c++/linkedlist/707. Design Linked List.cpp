class MyLinkedList {
public:
    int size;
    struct Node {
        Node* next = nullptr;
        Node* prev = nullptr;
        int val;
    };
    Node* head;
    Node* tail; // PREVIOUS NODE OF TAIL

    MyLinkedList() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    int get(int index) {
        if (index >= size) {
            return -1;
        }
        Node* cur = head;
        while (index >= 0) {
            cur = cur->next;
            --index;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node* tmp = new Node();
        tmp->val = val;
        Node* hnn = head->next;
        head->next = tmp;
        tmp->next = hnn;
        hnn->prev = tmp;
        tmp->prev = head;
        ++size;
        return;
    }
    
    void addAtTail(int val) {
        Node* tmp = new Node();
        tmp->val = val;
        Node* tnn = tail->prev;
        tail->prev = tmp;
        tmp->prev = tnn;
        tnn->next = tmp;
        tmp->next = tail;
        ++size;
        return;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        if (index == size) {
            return addAtTail(val);
        }
        Node* cur = head;
        while (index > 0) { // previous node of the index-th node
            cur = cur->next;
            --index;
        }
        Node* tmp = new Node();
        tmp->val = val;
        Node* pnn = cur->next;
        cur->next = tmp;
        tmp->next = pnn;
        pnn->prev = tmp;
        tmp->prev = cur;
        ++size;
        return;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) {
            return;
        }
        Node* cur = head;
        while (index > 0) { // previous node of the index-th node
            cur = cur->next;
            --index;
        }
        Node* tmp = cur->next;
        cur->next = tmp->next;
        tmp->next->prev = cur;
        delete tmp;
        --size;
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */