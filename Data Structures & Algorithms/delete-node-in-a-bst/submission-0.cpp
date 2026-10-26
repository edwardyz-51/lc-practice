class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            // Case 1: no left child
            if (!root->left) {
                return root->right;
            }

            // Case 2: no right child
            if (!root->right) {
                return root->left;
            }

            // Case 3: two children
            TreeNode* curr = root->right;

            // Find inorder successor
            while (curr->left) {
                curr = curr->left;
            }

            root->val = curr->val;
            root->right = deleteNode(root->right, curr->val);
        }

        return root;
    }
};