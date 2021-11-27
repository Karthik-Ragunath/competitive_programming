/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/
Node Insert(Node head,int data) {
    Node node=new Node();
    if(head==null)
    {
        node.data=data;
        node.next=null;
        return node;
    }
    else
    {
        node=head;
        while(node.next!=null)
        {
            node=node.next;
        }
        node.next=new Node();
        node.next.data=data;
        node.next.next=null;
        return head;
    }
// This is a "method-only" submission. 
// You only need to complete this method. 
}
