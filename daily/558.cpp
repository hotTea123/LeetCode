#include<bits/stdc++.h>
using namespace std;

/*
    常规树上的递归题目，唯一需要注意的一点是当下面四个节点经过计算后发现都是叶子节点且值一致
  的时候需要进行合并操作。
    时间复杂度O(n)，空间复杂度O(logn)，主要为递归的开销
*/

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1->isLeaf){
            if(!quadTree1->val)
                return quadTree2;
            return quadTree1;
        }
        if(quadTree2->isLeaf){
            if(!quadTree2->val)
                return quadTree1;
            return quadTree2;
        }
        quadTree1->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        quadTree1->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        quadTree1->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        quadTree1->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if(quadTree1->topLeft->isLeaf && quadTree1->topRight->isLeaf && quadTree1->bottomRight->isLeaf && quadTree1->bottomLeft->isLeaf){
            bool flag = quadTree1->topLeft->val;
            if(quadTree1->topRight->val == flag && quadTree1->bottomLeft->val == flag && quadTree1->bottomRight->val == flag)
                return new Node(true, flag);
        }
        return quadTree1;
    }
};