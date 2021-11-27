import java.io.*;
import java.lang.*;
import java.util.*;

class ArrayDeque_Example{
	public static void main(String[] args){
		Deque<Integer> deque=new ArrayDeque<Integer>();
		deque.add(123);
		deque.add(765);
		deque.add(32);
		deque.poll();
		System.out.println(deque.peek());
	}
}