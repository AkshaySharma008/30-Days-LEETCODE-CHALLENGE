/*
 Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree

          1
         / \
        2   3
       / \     
      4   5    

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them. 
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;           //diameter
        DFS(root,d);
        return d;
    }
    
    int DFS(TreeNode* root, int& d){
        if (!root) return 0;
        int l = DFS(root->left,d);     //calculate depth of each branch
        int r = DFS(root->right,d);
        d = max(d, l+r);         //calculate d with the current node as the anchor, retain maximum
        return max(l,r)+1;       //pass the max depth from this node up the tree to calculate d at parent nodes
    }
};