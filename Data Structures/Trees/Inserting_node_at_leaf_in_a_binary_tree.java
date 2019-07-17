 /* Node is defined as :
 class Node 
    int data;
    Node left;
    Node right;
    
    */

static Node Insert(Node root,int value)
{
    Queue<Node> queue=new LinkedList<Node>();
    if(root==null)
    {
        root=new Node();
        root.data=value;
        root.left=null;
        root.right=null;
        return root;
    }
    queue.add(root);
    while(!(queue.isEmpty()))
    {
        Node tempNode=queue.poll();
        if(tempNode.left!=null)
        {
            queue.add(tempNode.left);
        }
        else
        {
            tempNode.left=new Node();
            tempNode.left.data=value;
            tempNode.left.left=null;
            tempNode.left.right=null;
            break;
        }
        if(tempNode.right!=null)
        {
            queue.add(tempNode.right);
        }
        else
        {
            tempNode.right=new Node();
            tempNode.right.data=value;
            tempNode.right.left=null;
            tempNode.right.right=null;
            break;
        }
    }
    return root;
}


