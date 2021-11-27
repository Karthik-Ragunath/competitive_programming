/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/

    static LinkedListNode removeNodes(LinkedListNode list, int x) {
        LinkedListNode head=list;
        boolean flagship=false;
        while(head!=null)
        {
            System.out.println(head.val);
            if(flagship==false)
            {
                if(head.val>x)
                {
                    head=head.next;
                    list=list.next;
                }
                else
                {
                    //head=head.next;
                    flagship=true;
                }
            }
            else
            {
                if(head.next!=null)
                {
                    if(head.next.val>x)
                    {
                        head.next=head.next.next;
                    }
                    else
                    {
                        head=head.next;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return list;
    }

