/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/
    // This is a "method-only" submission. 
    // You only need to complete this method. 

void ReversePrint(Node head) {
    Node currnode=new Node();
    Node prevnode=new Node();
    Node printernode=new Node();
    int flagship=0;
    if(head==null)
    {
        return;
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
    while(printernode!=null)
    {
        System.out.println(printernode.data);
        printernode=printernode.next;
    }
  // This is a "method-only" submission. 
  // You only need to complete this method. 

}
