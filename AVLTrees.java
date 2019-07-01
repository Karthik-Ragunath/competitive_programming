/* Class node is defined as :
 class Node
    int val;   //Value
    int ht;      //Height
    Node left;   //Left child
    Node right;   //Right child

*/

static Node insert(Node root,int val)
 {
    if (val < root.val)
    {
        if (root.left != null)
        {
             insert(root.left, val);
             int difference = root.left.ht - root.right.ht;
             int realDifference = Math.abs(difference);
             if(realDifference > 1)
             {
                 if (root.left.ht > root.right.ht)
                 {
                     if(root.left.left.ht > root.left.right.ht)
                     {
                        Node tempNode = new Node();
                        tempNode = root;
                        tempNode.left = root.left.right;
                        root.left.right = tempNode;
                        root = tempNode;
                     }
                 }
             }
        }
        else
        {
            root.left = Node();
            root.left = val;
            if(root.right == null)
            {
                root.ht = root.ht + 1;
            }
        }
    }
    else if (val > root.val)
    {
        if (root.right != null)
        {
             insert(root.right, val);
        }
        else
        {
            root.right = Node();
            root.right = val;
            if(root.left == null)
            {
                root.ht = root.ht + 1;
            }
        }
    }
 }
