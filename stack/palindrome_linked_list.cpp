/*
LeetCode (#234) - Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

Follow up: Could you do it in O(n) time and O(1) space?

*/
/*
    Ý tưởng thuật toán
    - Two Pointers
    - Stack

*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : next(NULL){}
    ListNode(int x) : val(x), next(NULL){}
    ListNode(int x, ListNode* a) : val(x), next(a){}
};

int main(){ 

}