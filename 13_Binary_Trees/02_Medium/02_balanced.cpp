/*
110. Balanced Binary Tree
Easy

Given a binary tree, determine if it is heigh-balanced.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true

Constraints:
    The number of nodes in the tree is in the range [0, 5000].
    -104 <= Node.val <= 10^4
*/

// BRUTE FORCE APPROACH
bool isBalancedBrute(TreeNode* root) {
        if (!root)
            return true;

        int ld = depth(root->left);
        int rd = depth(root->right);

        if (abs(ld - rd) <= 1 && isBalancedBrute(root->left) && isBalancedBrute(root->right))
            return true;
        else
            return false;
    }

int depth(TreeNode* root){
    if(!root)return 0;

    int ld = depth(root->left);
    int rd = depth(root->right);

    return max(ld,rd) + 1;
}

// OPTIMAL APPROACH
bool isBalanced(TreeNode* root) { 
	return postorder(root) != -1; 
}

int postorder(TreeNode* root) {
    if (!root)
        return 0;

    int ld = postorder(root->left);
    int rd = postorder(root->right);

    if (abs(ld - rd) > 1 || ld == -1 || rd == -1)
        return -1;

    return max(ld, rd) + 1;
}
