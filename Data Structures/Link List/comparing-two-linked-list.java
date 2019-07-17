/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/
int CompareLists(Node headA, Node headB) {
    Node node1=new Node();
    Node node2=new Node();
    node1=headA;
    node2=headB;
    boolean compare=true;
    while((node1!=null)&&(node2!=null))
    {
        if(node1.data!=node2.data)
        {
            compare=false;
            break;
        }
        node1=node1.next;
        node2=node2.next;
    }
    if((node1==null)&&(node2==null)&&(compare==true))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    // This is a "method-only" submission. 
    // You only need to complete this method 
  
}
