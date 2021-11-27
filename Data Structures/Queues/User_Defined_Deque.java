import java.io.*;
import java.lang.*;
import java.util.*;

class Node{
	int walk=0;
	int push=0;
}
class User_Defined_Deque{
	public static void main(String[] args){
		Deque<Node> queue=new ArrayDeque();
		Node new_node=new Node();
		new_node.walk=98;
		new_node.push=120;
		queue.add(new_node);
		Node old_node=new Node();
		old_node.walk=67;
		old_node.push=576;
		queue.add(old_node);
		Node temp=new Node();
		temp.walk=68;
		temp.push=678;
		queue.add(temp);
		Node tempo=new Node();
		tempo.walk=67;
		tempo.push=576;
		int size=queue.size();
		System.out.println(size);
		Iterator<Node> iterator=queue.iterator();
		while(iterator.hasNext())
		{
			Node temporary=iterator.next();
			/*int temp_walk=temporary.walk;
			int temp_push=temporary.push;
			System.out.println(temp_walk);
			System.out.println(temp_push);*/

			System.out.println(temporary.walk);
			System.out.println(temporary.push);
		}
		if(queue.contains(tempo))
		{
			System.out.println("True");
		}
		else
		{
			System.out.println("False");
		}
	}
}