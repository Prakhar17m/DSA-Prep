class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int LeftHeight = maxDepth(root->left);
        int RightHeight = maxDepth(root->right);
        return 1+ max(LeftHeight,RightHeight);
    }
};