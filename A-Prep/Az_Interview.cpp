Q1:
Tree: Binary Tree

     10
   8   12
  7 11 11 14

Output: Tree is BST or not.

class Node
{
    int value;
    Node* left;
    Node* right;
    Node *parent;
    Node(int x) : value(x) {}
};

class Solution
{
    bool is_bst(Node *root, int &max_left, int &max_right)
    {


        if(root)
        {
            if(root -> value <= root -> left or root -> value >= root -> right)
            {
                return false;
            }
            bool is_valid_left = true;
            bool is_valid_right = true;
            if(root -> left)
            {
                is_valid_left = is_bst(root -> left -> value);
            }
            if(root -> right)
            {
                is_valid_right = is_bst(root -> right -> value);
            }
            if(not is_valid_left or not is_valid_right)
            {
                return false;
            }
            return true;
        }
        else
        {
            cout << "Null root" << "\n";
            return false;
        }
        /
        
        if(root)
        {
            is_bool 
            if()
        }
    }
}

// min_left = 0, max_right = 0

class Solution
{
    bool is_bst(Node *root, int max_left, int max_right)
    {
        
        if(root)
        {
            bool is_left_valid = true;
            bool is_right_valid = true;
            if(root -> value < root -> parent -> value)
            {
                if(root -> value >= max_right)
                {
                    return false;
                }
            }
            if(root -> value > root -> parent -> value)
            {
                if(root -> value <= min_left)
                {
                    return false;
                }
            }
            if(root -> left)
            {
                if(root -> value < root -> parent -> value)
                {
                    min_left = root -> value;
                }
                is_left_valid = is_bst(root -> left, max_left, max_right);
            }
            if(root -> right)
            {
                if(root -> value > root -> parent -> value)
                {
                    max_right = root -> value;
                }                
                is_right_valid = is_bst(root -> right, max_left, max_right);
            }

            if(root -> value <= root -> right or root -> value >= root -> left)
            {
                return false;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
}

Q2:
Next Greater Element

Input:
A: [3, 10, 13, 5]

Output:
O: [10, 13, -1, -1]

vector< int > sol_func(vector< int> a)
{
    int len = a.size();
    vector< int > solution;
    for(int i = 0; i < len; i++)
    {
        int sol = -1;
        for(int j = i + 1; j < len; j++)
        {
            if(a[j] > a[i])
            {
                sol = a[j];
                break;
            }
        }
        solution.push_back(sol);
    }
    return solution;
}

[3, 2, 5, 1, 10, 7, 8]

[5, 5, 10, 10, -1 , 8 , -1]

[(3, 0), (2, 1), ]

solution< int > (n)

10 8
map< int, int>
2 - 5
3 - 5
1 - 10
5 - 10
7 - 8
10 - -1
8 - -1



vector< int > sol_func(vector< int > a)
{
    int len = a.size();
    vector< int > solution(len);
    vector< pair< int, int > > temp;
    for(int i = 0; i < len; i++)
    {
        while(not temp.empty() and a[i] > (temp.back()).first)
        {
            solution[(temp.back()).second] = a[i];
            temp.pop_back();
        }
        temp.push_back(make_pair(a[i], i));
    }
    while(not temp.empty())
    {
        solution[(temp.back()).second] = -1;
    }
    return solution;
}