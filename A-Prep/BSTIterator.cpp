/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator 
{
    public:
        vector< int > inorder_traversal;
        int current_index = 0;
    
        void traverse_inorder(TreeNode* root)
        {
            if(root)
            {
                traverse_inorder(root -> left);
                inorder_traversal.push_back(root -> val);
                traverse_inorder(root -> right);
            }
            return;
        }
        BSTIterator(TreeNode* root) 
        {
            traverse_inorder(root);
        }
        
        /** @return the next smallest number */
        int next() 
        {
            return inorder_traversal[current_index++];
        }
        
        /** @return whether we have a next smallest number */
        bool hasNext() 
        {
            if(current_index < inorder_traversal.size())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */