// using the height function 
class Solution {
public:
    int diameter =0;
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int x = maxDepth(root->left);
        int y = maxDepth(root->right);
        diameter = max(diameter,x+y);
        return 1+ max(x,y);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return diameter;
    }
};