class AVLNode
{
    public:
        int key;
        int duplicates;
        AVLNode *left;
        AVLNode *right;
        int height;
        int size;
        AVLNode(int x) : key(x), left(NULL), right(NULL), height(1), duplicates(1), size(1) {} 
};

class Solution 
{
    public:
        void print_vec(vector< int > &vec)
        {
            int vec_size = vec.size();
            for(int i = 0; i < vec_size; i++)
            {
                cout << vec[i] << " ";
            }
            cout << "\n";
        }

        int get_size(AVLNode *avl_node)
        {
            if(not avl_node)
            {
                return 0;
            }
            return avl_node -> size;
        }

        int get_height(AVLNode *avl_node)
        {
            if(not avl_node)
            {
                return 0;
            }
            return avl_node -> height;
        }

        void update_node(AVLNode *A)
        {
            A -> height = max(get_height(A -> left), get_height(A -> right)) + 1;
            A -> size = get_size(A -> left) + get_size(A -> right) + A -> duplicates;
            return;
        }

        AVLNode* rotate_right(AVLNode *A)
        {
            AVLNode *B = A -> left;
            // cout << "before right rotate: " << A -> key << " " << B -> key << " " << A -> left -> key << " A height: " << A -> height << " B Height: " << B -> height << "\n";
            AVLNode *B_right = B -> right;
            A -> left = B_right;
            B -> right = A;
            update_node(A);
            update_node(B);
            // cout << "right rotate: " << B -> right -> key << " A height: " << A -> height << " B Height: " << B -> height << "\n";
            return B;
        }

        AVLNode* rotate_left(AVLNode *A)
        {
            AVLNode *B = A -> right;
            // cout << "before left rotate: " << A -> key << " " << B -> key << " " << A -> right -> key << " A height: " << A -> height << " B Height: " << B -> height << "\n";
            AVLNode *B_left = B -> left;
            A -> right = B_left;
            B -> left = A;
            update_node(A);
            update_node(B);
            // cout << "left rotate: " << B -> left -> key << " A height: " << A -> height << " B Height: " << B -> height << "\n";
            return B;
        }

        AVLNode* insert_avl_node(int key_to_be_inserted, AVLNode* head, int &smaller_values)
        {
            if(head != NULL)
            {
                if(key_to_be_inserted > head -> key)
                {
                    smaller_values += (((not head -> left) ? 0 : head -> left -> size) + head -> duplicates);
                    head -> right = insert_avl_node(key_to_be_inserted, head -> right, smaller_values);
                }
                else if(key_to_be_inserted < head -> key)
                {
                    head -> left = insert_avl_node(key_to_be_inserted, head -> left, smaller_values);
                }
                else
                {
                    head -> duplicates += 1;
                    smaller_values += (not head -> left) ? 0 : head -> left -> size;
                    head -> size += 1;
                    return head;
                }
            }
            else
            {
                AVLNode *new_node = new AVLNode(key_to_be_inserted);
                return new_node;
            }

            int height_left = (not head -> left) ? 0 : head -> left -> height;
            int height_right = (not head -> right) ? 0 : head -> right -> height;
            int difference = height_right - height_left;
            // cout << "Key: " << head -> key << " Difference: " << difference << "\n";
            // update_node(head);
            if(difference <= -2)
            {
                // left left case
                if(head -> left -> key > key_to_be_inserted)
                {
                    return rotate_right(head); // Updation happens within rotatation func
                }
                // left right case
                else if(head -> left -> key < key_to_be_inserted)
                {
                    head -> left = rotate_left(head -> left);
                    return rotate_right(head); // Updation happens within rotatation func
                }
            }
            else if(difference >= 2)
            {
                // right right case
                if(head -> right -> key < key_to_be_inserted)
                {
                    return rotate_left(head); // Updation happens within rotatation func
                }
                // right left case
                else if(head -> right -> key > key_to_be_inserted)
                {
                    head -> right = rotate_right(head -> right);
                    return rotate_left(head); // Updation happens within rotatation func
                }
            }
            else
            {
                update_node(head); // Update node only needs to happen for non inverted items since for inverted items anyway update_node occurs
            }
            return head;
        }

        vector<int> countSmaller(vector<int>& nums) 
        {
            vector< int > solution_vec(nums.size());
            if(nums.empty())
            {
                return solution_vec;
            }
            int nums_size = nums.size();
            AVLNode *avl_node_head = new AVLNode(nums[nums_size - 1]);
            for(int i = nums_size - 2; i >= 0; i--)
            {
                // cout << "Head Val: " << avl_node_head -> key << "\n";
                int number_of_smaller_vals = 0;
                avl_node_head = insert_avl_node(nums[i], avl_node_head, number_of_smaller_vals);
                solution_vec[i] = number_of_smaller_vals;
            }
            return solution_vec;
        }
};