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
    boolean first=true;
    boolean looped_left;
    boolean looped_right;
    while(queuehead!=null)
    {
        if(first==true)
        {
            Node tempnode=new Node();
            tempnode=queuehead;
            System.out.println(tempnode.data);
            looped_left=false;
            looped_right=false;
            if(queuehead.left!=null)
            {
                queue.left=new Node();
                queue.left=tempnode.left;
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
                    queue.left.left=null;
                    queue.left.right=null;
                    looped_right=true;
                }
                else
                {
                    queue.left.left=new Node();
                    queue.left.left=tempnode.right;
                    queue.left.left.left=null;
                    queue.left.left.right=null;
                    looped_right=true;
                }
            }
            if((looped_left==true)&&(looped_right=true))
            {
                queue=queue.left;
                queuehead=queue;
                queue=queue.left;
            }
            else if(looped_left==true)
            {
                queue=queue.left;
                queuehead=queue;
            }
            else if(looped_right==true)
            {
                queue=queue.left;
                queuehead=queue;
            }
            first=false;
        }
        else
        {
            Node tempnode=new Node();
            tempnode=queuehead;
            System.out.println(tempnode.data);
            looped_left=false;
            looped_right=false;
            if(queuehead.left!=null)
            {
                queue.left=new Node();
                queue.left=tempnode.left;
                    System.out.println("Jo "+queue.left.data);
                queue.left.left=null;
                    
                queue.left.right=null;
                    System.out.println("HI");
                looped_left=true;
                
            }
            if(queuehead.right!=null)
            {
                System.out.println("Hi");
                if(looped_left==false)
                {
                    queue.left=new Node();
                    queue.left=tempnode.right;
                    queue.left.left=null;
                    queue.left.right=null;
                    looped_right=true;
                }
                else
                {
                    queue.left.left=new Node();
                    queue.left.left=tempnode.right;
                        //System.out.println(tempnode.right);
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
}
