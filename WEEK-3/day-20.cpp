/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.
left has a value < node.val, and any descendant of node.right has a value > node.val. 
 Also recall that a preorder traversal displays the value of the node first, then traverses 
 node.left, then traverses node.right.)
*/

class Solution
{
public:
    int idx = 0;
    TreeNode *bstFromPreorder(vector<int> &preorder, int parent_value = INT_MAX)
    {
        if (idx == preorder.size() || preorder[idx] > parent_value)
            return NULL;
        int current_value = preorder[idx++];
        TreeNode *temp = new TreeNode(current_value);
        temp->left = bstFromPreorder(preorder, current_value);
        temp->right = bstFromPreorder(preorder, parent_value);
        return temp;
    }
};