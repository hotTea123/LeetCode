struct Node {
    int val;
    Node *next, *pre;
    Node(int x) : val(x), next(nullptr), pre(nullptr) {}
};

/*
    使用循环双链表实现双端队列
*/
class MyCircularDeque {
private:
    Node* head;
    int len;
    int maxlen;
public:
    MyCircularDeque(int k) {
        len = 0;
        maxlen = k;
    }
    
    bool insertFront(int value) {
        if(len == 0){
            head = new Node(value);
            head->next = head;
            head->pre = head;
        }else if(len == maxlen){
            return false;
        }else{
            Node* p = new Node(value);
            p->pre = head->pre;
            p->pre->next = p;
            p->next = head;
            head->pre = p;
            head = p;
        }
        ++len;
        return true;
    }
    
    bool insertLast(int value) {
        if(len == 0){
            head = new Node(value);
            head->next = head;
            head->pre = head;
        }else if(len == maxlen){
            return false;
        }else{
            Node* p = new Node(value);
            p->pre = head->pre;
            p->pre->next = p;
            p->next = head;
            head->pre = p;
        }
        ++len;
        return true;
    }
    
    bool deleteFront() {
        if(len == 0)
            return false;
        Node* p = head;
        head = p->next;
        head->pre = p->pre;
        p->pre->next = head;
        delete p;
        --len;
        return true;
    }
    
    bool deleteLast() {
        if(len == 0)
            return false;
        Node* p = head->pre;
        p->pre->next = head;
        head->pre = p->pre;
        delete p;
        --len;
        return true;
    }
    
    int getFront() {
        if(len == 0)
            return -1;
        return head->val;
    }
    
    int getRear() {
        if(len == 0)
            return -1;
        return head->pre->val;
    }
    
    bool isEmpty() {
        if(len == 0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(len == maxlen)
            return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */