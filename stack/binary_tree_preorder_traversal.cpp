/*
LeetCode #144
Given the root of a binary tree, return the preorder traversal of its nodes' values.


Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]
Explanation:

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [1,2,4,5,6,7,3,8,9]
Explanation:

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]
*/

/*
    Ý tưởng thuật toán (không cần dùng đến stack)
    - Visit Node giữa.
    - Đệ quy visit nút trái.
    - Đệ quy visit nút phải.
*/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (): left(NULL), right(NULL){}
    TreeNode (int x): val(x), left(NULL), right(NULL){}
    TreeNode (int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

void preorder_traveresal(TreeNode* node){
    if (node == NULL)return;

    cout << node->val << " ";
    preorder_traveresal(node->left);
    preorder_traveresal(node->right);
}

void preorder_traveresal(){
    return;
}
int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode (2);
    TreeNode* c = new TreeNode (3);

    TreeNode* d = new TreeNode (4);
    TreeNode* e = new TreeNode (5);
    TreeNode* f = new TreeNode (6);

    TreeNode* g = new TreeNode (7);
    TreeNode* h = new TreeNode (8);
    TreeNode* j = new TreeNode (9); 

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;
    c->right = h;

    e->left = f;
    e->right = g;
    h->left = j;

    preorder_traveresal(a);
}