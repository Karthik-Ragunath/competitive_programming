private static int isPresent(Node root, int val){
/* For your reference
class Node {
		Node left, right;
		int data;
                Node(int newData) {
			left = right = null;
			data = newData;
		}
	}
*/
    if(root!=null)
    {
        if(root.data==val)
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
    if(val<root.data)
    {
         if(isPresent(root.left,val)==1)
         {
             return 1;
         }
         else
         {
             return 0;
         }
    }
    if(val>root.data)
    {
        if(isPresent(root.right,val)==1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}