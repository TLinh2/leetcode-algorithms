/*
LeetCode #94
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,2,6,5,7,1,3,9,8]

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]
*/


/*
    Ý tưởng thuật toán (stack)
    - Chạy từ đỉnh cây.
    - (Nếu node != NULL) Push vào stack.
    - Đệ quy chạy đến node.left.
    - (Nếu node == NULL) (Đã hết node).
    - In ra node lúc này.
    - Stack.pop() node.
    - Đệ quy chạy đến node.right.
*/
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode () : left(NULL), right(NULL){}
    TreeNode (int x) : val(x), left(NULL), right(NULL){}
    TreeNode (int x, TreeNode* a, TreeNode* b) : val(x), left(a), right(b){}
};


// Cách 1: Giải bằng đệ quy
// void get_val_node (TreeNode* node){
//     if (node == NULL) return;
//     cout << node->val;
//     return;
// }

// void inorder_traversal(TreeNode* root){
//     if (root == NULL){
//         return;
//     }

//     inorder_traversal(root->left);
//     cout << root->val << " ";
//     inorder_traversal(root->right);    
// }

// Cách 2: Dùng stack
stack <TreeNode*> node_stack;

void inorder_traversal_stack (TreeNode* node){
    if (node == NULL)return;
    node_stack.push(node);
    inorder_traversal_stack(node->left);

    cout << node_stack.top()->val << " ";
    node_stack.pop();
    inorder_traversal_stack(node->right);
}

int main(){

    TreeNode* a = new TreeNode (1);
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

    inorder_traversal_stack(a);
}