/*
    
class Node {
    int data;
    Node left;
    Node right;
}
*/
int height(Node root)
{
    int height=0;
    Node pass_by_reference=new Node();
    pass_by_reference.data=0;
    pass_by_reference.left=null;
    pass_by_reference.right=null;
    int maximum=recurse(root,height,pass_by_reference);  
    return maximum;
}
int recurse(Node root,int height,Node pass_by_reference)
{
    if((root.left==null)&&(root.right==null))
    {
        if(height>pass_by_reference.data)
        {
            pass_by_reference.data=height;
        }
    }
    if(root.left!=null)
    {
        recurse(root.left,height+1,pass_by_reference);
    }
    if(root.right!=null)
    {
        recurse(root.right,height+1,pass_by_reference);
    }
    return pass_by_reference.data;
}
