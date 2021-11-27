/*  
   class Node
      public  int frequency; // the frequency of this tree
       public  char data;
       public  Node left, right;
    
*/ 

void decode(String S ,Node root)
{
    String returnable="";
    Node temp=root;
    int length=S.length();
    char[] chararray=S.toCharArray();
    for(int i=0;i<length;i++)
    {
        if(chararray[i]=='1')
        {
            temp=temp.right;
            if((temp.right==null)&&(temp.left==null))
            {
                returnable=returnable+temp.data;
                temp=root;
            }
        }
        else
        {
            temp=temp.left;
            if((temp.right==null)&&(temp.left==null))
            {
                returnable=returnable+temp.data;
                temp=root;
            }
        }
    }
    System.out.println(returnable);
    return;
}
