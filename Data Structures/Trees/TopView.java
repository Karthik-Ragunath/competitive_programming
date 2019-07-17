/*
class Node
{
    int data;
    Node left;
    Node right;
}
*/
void top_view(Node root)
{
    recurse_left(root);
    recurse_right(root.right);
}
void recurse_left(Node root)
{
    if(root.left!=null)
    {
        recurse_left(root.left);
    }
    System.out.print(root.data+" ");
    return;
}
void recurse_right(Node root)
{
    System.out.print(root.data+" ");
    if(root.right!=null)
    {
        recurse_right(root.right);
    }
    return;
}