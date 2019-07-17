/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as  
  class Node {
     int data;
     Node next;
  }
*/
    // This is a "method-only" submission. 
    // You only need to complete this method. 
Node Reverse(Node head) {
    Node currnode=new Node();
    Node prevnode=new Node();
    Node printernode=new Node();
    int flagship=0;
    if(head==null)
    {
        return null;
    }
    currnode=head;
    while(true)
    {
        if(flagship==0)
        {
            flagship=1;
            printernode.next=null;
            printernode.data=currnode.data;
            prevnode=printernode;
            if(currnode.next!=null)
            {
                currnode=currnode.next;
                printernode=new Node();
            }
            else
            {
                break;
            }
        }
        else
        {
            printernode.next=prevnode;
            printernode.data=currnode.data;
            prevnode=printernode;
            if(currnode.next!=null)
            {
                currnode=currnode.next;
                printernode=new Node();
            }
            else
            {
                break;
            }
        }
    }
    printernode=prevnode;
    return printernode;

}
