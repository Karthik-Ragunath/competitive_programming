/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/
    

Node InsertNth(Node head, int data, int position) {
    Node node=new Node();
    Node nodecutter=new Node();
    if(head==null)
    {
        node.data=data;
        node.next=null;
        head=node;
        //System.out.println("Hi");
        return head;
    }
    else
    {
        if(position==0)
        {
            //System.out.println("You");
            node.data=data;
            node.next=head;
            head=node;
            return head;
        }
        node=head;
        for(int i=0;i<position-1;i++)
        {
            node=node.next;
            if(node.next==null)
            {
                break;
            }
        }
        nodecutter=node.next;
        node.next=new Node();
        node.next.data=data;
        node.next.next=nodecutter;
        return head;
    }
   // This is a "method-only" submission. 
    // You only need to complete this method. 
}
