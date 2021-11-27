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

Node Delete(Node head, int position) {
    Node node=new Node();
    if(position==0)
    {
        node=head.next;
        head=node;
        return head;
    }
    node=head;
    for(int i=0;i<position-1;i++)
    {
        node=node.next;
    }
    node.next=node.next.next;
    return head;
    
  // Complete this method

}

