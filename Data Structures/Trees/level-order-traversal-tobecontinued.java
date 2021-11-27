/* 
class Node 
{
    int data;
    Node left;
    Node right;
} 
*/
void LevelOrder(Node root)
{
    Node queue=new Node();
    Node queuehead=new Node();
    queue.data=root.data;
    queue.left=null;
    queue.right=null;
    queuehead=root;
    while(queuehead!=null)
    {
        //System.out.println("Hi :"+queuehead.left.data+" "+queuehead.right.data);
        Node tempnode=new Node();
        tempnode=queuehead;
        System.out.println(tempnode.data);
        boolean looped_left=false;
        boolean looped_right=false;
        if(queuehead.left!=null)
        {
            queue.left=new Node();
            queue.left=tempnode.left;
                //System.out.println(queue.left.data);
            queue.left.left=null;
            queue.left.right=null;
            looped_left=true;
        }
        if(queuehead.right!=null)
        {
            if(looped_left==false)
            {
                queue.left=new Node();
                queue.left=tempnode.right;
                    System.out.println(queue.left.data);
                queue.left.left=null;
                queue.left.right=null;
                looped_right=true;
            }
            else
            {
                queue.left.left=new Node();
                queue.left.left=tempnode.right;
                    System.out.println(queue.left.left.data);
                queue.left.left.left=null;
                queue.left.left.right=null;
                looped_right=true;
            }
        }
        if((looped_right==true)&&(looped_left==true))
        {
            queue=queue.left;
            queue=queue.left;
        }
        else if(looped_left==true)
        {
            queue=queue.left;
        }
        else if(looped_right==true)
        {
            queue=queue.left;
        }
        queuehead=queuehead.left;
    }
}
