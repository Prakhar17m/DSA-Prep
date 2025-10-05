class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        if (root == nullptr) {
            return arr;
        }
        arr.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        arr.insert(arr.end(), left.begin(), left.end());
        vector<int> right = preorderTraversal(root->right);
        arr.insert(arr.end(), right.begin(), right.end());
        return arr;
    }
};
