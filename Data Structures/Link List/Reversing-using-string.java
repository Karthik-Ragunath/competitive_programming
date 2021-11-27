  Node node = new Node();
    node = head;
    String ans = "";String ans1 = "";
    String[] newans=new String[45];
    int i=0;
    while(node!=null)
        {
        ans = ans + node.data;
        newans[i]=String.valueOf(node.data);
        i++;
        node = node.next;
    }
    ans1 = new StringBuffer(ans).reverse().toString();
    int length=i-1;
    //int length = ans1.length();
    /*for(int i =0 ; i<length ; i++)
    System.out.println(ans1.charAt(i));*/
    
    while(length>=0)
    {
        System.out.println(newans[length]);
        length=length-1;
    }
        
}