/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]
Explanation:

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,6,7,5,2,9,8,3,1]
Explanation:

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]

*/
/*
    Ý tưởng thuật toán
    Sử dụng đệ quy
    - Đệ quy hết nhánh con bên trái
    - Đệ quy hết nhánh con bên phải
    - Visit chính nó
*/
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode () : left(NULL), right(NULL){}
    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
    TreeNode (int x, TreeNode* a, TreeNode* b) : val(x), left(a), right(b){}
};

void visit (TreeNode* node){
    cout << node->val << " ";
}

void postorder_traversal(TreeNode* node){
    if (node == NULL)return;
    
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    visit(node);
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

    postorder_traversal(a);
}