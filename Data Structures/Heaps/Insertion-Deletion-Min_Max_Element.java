import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;
import java.lang.*;

class Node
{
    int item;
    Node left;
    Node right;
    Node parent;
}

public class Solution {
    public static void main(String[] args) {
        int number_of_queries;
        Scanner in=new Scanner(System.in);
        number_of_queries=in.nextInt();
        Node root=new Node();
        Queue<Node> queue=new LinkedList<Node>();
        Node tempNode=new Node();
        for(int i=0;i<number_of_queries;i++)
        {
            if(i==0)
            {
                int query_type,data;
                query_type=in.nextInt();
                data=in.nextInt();
                Node newnode=new Node();
                newnode.item=data;
                newnode.left=null;
                newnode.right=null;
                newnode.parent=null;
                root=newnode;
                queue.add(root);
                tempNode=queue.poll();
            }
            else
            {
                int query_type,data;
                query_type=in.nextInt();
                data=in.nextInt();
                if(query_type==1)
                {
                    if(tempNode.left==null)
                    {
                        tempNode.left=new Node();
                        tempNode.left.item=data;
                        tempNode.left.left=null;
                        tempNode.left.right=null;
                        tempNode.left.parent=tempNode;
                        Node temporary=new Node();
                        temporary=tempNode.left;
                        while(temporary.parent!=null)
                        {
                            if(temporary.parent.item>temporary.item)
                            {
                                break;
                            }
                            else
                            {
                                int swapper;
                                swapper=temporary.item;
                                temporary.item=temporary.parent.item;
                                temporary.parent.item=swapper;
                                temporary=temporary.parent;
                            }
                        }
                        queue.add(tempNode.left);
                        continue;
                    }
                    if(tempNode.right==null)
                    {
                        tempNode.right=new Node();
                        tempNode.right.item=data;
                        tempNode.right.left=null;
                        tempNode.right.right=null;
                        tempNode.right.parent=tempNode;
                        Node temporary=new Node();
                        temporary=tempNode.right;
                        while(temporary.parent!=null)
                        {
                            if(temporary.parent.item>temporary.item)
                            {
                                break;
                            }
                            else
                            {
                                int swapper;
                                swapper=temporary.item;
                                temporary.item=temporary.parent.item;
                                temporary.parent.item=swapper;
                                temporary=temporary.parent;
                            }
                        }
                        queue.add(tempNode.right);
                        tempNode=queue.poll();
                    }
                }
                
                
            }