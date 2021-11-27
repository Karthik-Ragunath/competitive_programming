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
    static Node preOrder(Node root,int value,Node pass_by_reference,Node checker)
    {
        if(root!=null)
        {
            if(root.item==value)
            {
                pass_by_reference=root;
                checker.item=1;
            }
        }
        if((root.left!=null)&&(checker.item!=1))
        {
            preOrder(root.left,value,pass_by_reference,checker);
        }
        if((root.right!=null)&&(checker.item!=1))
        {
            preOrder(root.right,value,pass_by_reference,checker);
        }
        return pass_by_reference;
    }
    public static void main(String[] args) {
        int number_of_queries;
        Scanner in=new Scanner(System.in);
        number_of_queries=in.nextInt();
        in.nextLine();
        Node root=new Node();
        LinkedList<Node> queue=new LinkedList<Node>();
        Node tempNode=new Node();
        Node lastParentNode=new Node();
        boolean left_set=false;
        boolean right_set=false;
        for(int i=0;i<number_of_queries;i++)
        {
            if((i==0)||((left_set==false)&&(right_set==false)))
            {
                int query_type,data=0;
                String input;
                input=in.nextLine();
                String[] array=input.split(" ");
                query_type=Integer.parseInt(array[0]);
                if(query_type!=3)
                {
                    data=Integer.parseInt(array[1]);
                }
                Node newnode=new Node();
                newnode.item=data;
                newnode.left=null;
                newnode.right=null;
                newnode.parent=null;
                root=newnode;
                queue.add(root);
                lastParentNode=root.parent;
                tempNode=queue.poll();
            }
            else
            {
                int query_type,data=0;
                String input;
                input=in.nextLine();
                String[] array=input.split(" ");
                query_type=Integer.parseInt(array[0]);
                if(query_type!=3)
                {
                    data=Integer.parseInt(array[1]);
                }
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
                        lastParentNode=tempNode.left.parent;
                        left_set=true;
                        right_set=false;
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
                        lastParentNode=tempNode.right.parent;
                        left_set=false;
                        right_set=true;
                        tempNode=queue.poll();
                    }
                }
                if(query_type==2)
                {
                    int LastValueAdded=queue.getLast().item;
                    if(LastValueAdded==data)
                    {
                        queue.removeLast();
                        if(left_set==true)
                        {
                            lastParentNode.left=null;
                            lastParentNode=queue.getLast().parent;
                            if(lastParentNode==null)
                            {
                                right_set=false;
                                left_set=false;
                            }
                            else
                            {
                                right_set=true;
                                left_set=false;
                            }
                            continue;
                        }
                        if(right_set==true)
                        {
                            lastParentNode.right=null;
                            lastParentNode=queue.getLast().parent;
                            if(lastParentNode==null)
                            {
                                right_set=false;
                                left_set=false;
                            }
                            else
                            {
                                right_set=false;
                                left_set=true;
                            }
                            continue;
                        }
                        if(((left_set==false)&&(right_set==false))&&(queue.isEmpty()))
                        {
                            root=new Node();
                            continue;
                        }
                    }
                    else
                    {
                        Node tempo=new Node();
                        Node pass_by_reference=new Node();
                        pass_by_reference.item=0;
                        pass_by_reference.left=null;
                        pass_by_reference.right=null;
                        pass_by_reference.parent=null;
                        Node checker=new Node();
                        checker.item=0;
                        checker.left=null;
                        checker.right=null;
                        checker.parent=null;
                        tempo=preOrder(root,data,pass_by_reference,checker);
                        int swappy;
                        swappy=queue.getLast().item;
                        queue.getLast().item=tempo.item;
                        tempo.item=swappy;
                        queue.removeLast();
                        if(left_set==true)
                        {
                            lastParentNode.left=null;
                            lastParentNode=queue.getLast().parent;
                            if(lastParentNode==null)
                            {
                                left_set=false;
                                right_set=false;
                            }
                            else
                            {
                                left_set=false;
                                right_set=true;
                            }
                            while((tempo.left!=null)||(tempo.right!=null))
                            {
                                int left_value,right_value;
                                Node comparer=new Node();
                                if(tempo.left!=null)
                                {
                                    left_value=tempo.left.item;
                                    if(tempo.right!=null)
                                    {
                                        right_value=tempo.right.item;
                                        if(right_value>left_value)
                                        {
                                            comparer=tempo.right;
                                        }
                                        else
                                        {
                                            comparer=tempo.left;
                                        }
                                    }
                                    else
                                    {
                                        comparer=tempo.left;
                                    }
                                }
                                else
                                {
                                    if(tempo.right!=null)
                                    {
                                        comparer=tempo.right;
                                    }
                                }
                                if(tempo.item>comparer.item)
                                {
                                    break;
                                }
                                else
                                {
                                    swappy=comparer.item;
                                    comparer.item=tempo.item;
                                    tempo.item=swappy;
                                    tempo=comparer;
                                }
                            }
                        }
                        if(right_set==true)
                        {
                            lastParentNode.right=null;
                            lastParentNode=queue.getLast().parent;
                            if(lastParentNode==null)
                            {
                                left_set=false;
                                right_set=false;
                            }
                            else
                            {
                                left_set=true;
                                right_set=false;
                            }
                            while((tempo.left!=null)||(tempo.right!=null))
                            {
                                int left_value,right_value;
                                Node comparer=new Node();
                                if(tempo.left!=null)
                                {
                                    left_value=tempo.left.item;
                                    if(tempo.right!=null)
                                    {
                                        right_value=tempo.right.item;
                                        if(right_value>left_value)
                                        {
                                            comparer=tempo.right;
                                        }
                                        else
                                        {
                                            comparer=tempo.left;
                                        }
                                    }
                                    else
                                    {
                                        comparer=tempo.left;
                                    }
                                }
                                else
                                {
                                    if(tempo.right!=null)
                                    {
                                        comparer=tempo.right;
                                    }
                                }
                                if(tempo.item>comparer.item)
                                {
                                    break;
                                }
                                else
                                {
                                    swappy=comparer.item;
                                    comparer.item=tempo.item;
                                    tempo.item=swappy;
                                    tempo=comparer;
                                }
                            }
                        }
                    }
                }
                if(query_type==3)
                {
                    System.out.println(root.item);
                }
            }
        }
    }
}