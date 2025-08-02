/*
LeetCode #141
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.
 

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
*/

/*
    Ý tưởng thuật toán
    - Khởi tạo một vòng lặp, chạy cho đến khi ListNode trỏ đến null.
    - Kiểm tra ListNode current đã có chưa.
    - (Nếu có) Trả về true.
    - (Nếu không) Thêm nó vào bảng băm unordered_set.
    - current <- current.next.
    
*/

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    // ListNode(int x) : val(x), next(NULL) {}

    ListNode(int x){
        val = x;
        next = NULL;
    }
};


bool has_cycle (ListNode* head){
    ListNode* current = head;
    unordered_set <ListNode*> visited;

    while (current != nullptr){
        if (visited.find(current) != visited.end()){
            return true;
        }
        
        visited.insert(current);
        current = current->next;
    }
    
    return false;
}

int main(){
    ListNode* a = new ListNode (3);
    ListNode* b = new ListNode (2);
    ListNode* c = new ListNode (0);
    ListNode* d = new ListNode (-4);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;

    vector <ListNode*> array_node;
    array_node.push_back(a);
    array_node.push_back(b);
    array_node.push_back(c);
    array_node.push_back(d);
 
    bool result = has_cycle (a);
    cout << result;
    delete(a, b, c, d);
    return 0;
}