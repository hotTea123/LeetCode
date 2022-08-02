#include<bits/stdc++.h>
using namespace std;

/*
    循环队列实现的3种方法：
    1.设标志位 2.设置size变量 3.在数组里面预留一位
*/
class MyCircularQueue {
private:
    vector<int> v;
    bool empty;
    int front;
    int rear;
public:
    MyCircularQueue(int k) {
        v = vector<int>(k);
        empty = true;
        front = 0;
        rear = 0;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        v[rear] = value;
        rear = (rear+1) % v.size();
        empty = false;
        return true;
    }
    
    bool deQueue() {
        if(empty)
            return false;
        front = (front+1) % v.size();
        if(front==rear)
            empty = true;
        return true;
    }
    
    int Front() {
        if(empty)
            return -1;
        return v[front];
    }
    
    int Rear() {
        if(empty)
            return -1;
        return v[(rear+v.size()-1)%v.size()];
    }
    
    bool isEmpty() {
        return empty;
    }
    
    bool isFull() {
        return !empty && rear==front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */