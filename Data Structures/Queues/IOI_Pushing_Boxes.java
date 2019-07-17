import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Node
{
	int walk=0;
	int push=0;
	int prev=0;
	int current=0;
}

class IOI_Pushing_Boxes{

	static int[] analysis(ArrayDeque<Node> analyzer,int rows,int columns,int Box_Position,char[][] input,int[] shortest_path)
	{
		boolean[] visited=new boolean[rows*columns];
		visited[Box_Position]=true;
		int[] distance=new int[rows*columns];
		int[] distance_walks=new int[rows*columns];
		while(!(analyzer.isEmpty()))
		{
			boolean up_flag=false;
			boolean down_flag=false;
			boolean right_flag=false;
			boolean left_flag=false;
			Node temp_node=new Node();
			temp_node=analyzer.poll();
			int previous_position=temp_node.prev;
			int current_position=temp_node.current;
			int current_walk=temp_node.walk;
			int current_push=temp_node.push;
			int difference=current_position-previous_position;
			if(difference==1)
			{
				right_flag=true;
			}
			else if(difference==-1)
			{
				left_flag=true;
			}
			else if(difference>1)
			{
				down_flag=true;
			}
			else
			{
				up_flag=true;
			}
			int current_row=current_position/columns;
			int current_column=current_position%columns;
			if((current_row!=0)&&(current_row!=rows-1))
			{
				if(down_flag==true)
				{
					int next_walk=current_walk;
					int next_current_position=current_position+columns;
					int temp_rows=next_current_position/columns;
					int temp_columns=next_current_position%columns;
					int next_previous_position=current_position;
					int next_push=current_push+1;
					if(input[temp_rows][temp_columns]!='#')
					{
						if(visited[next_current_position]==true)
						{
							int temporary=distance[next_current_position];
							if(next_push<temporary)
							{
								distance[next_current_position]=next_push;
								distance_walks[next_current_position]=next_walk;
								Iterator<Node> iterator=analyzer.iterator();
								boolean breaker_flagship=false;
								while(iterator.hasNext())
								{
									Node temp_iterator=iterator.next();
									int temp_position=temp_iterator.current;
									if(temp_position==next_current_position)
									{
										temp_iterator.walk=next_walk;
										temp_iterator.push=next_push;
										temp_iterator.current=next_current_position;
										temp_iterator.prev=next_previous_position;
										breaker_flagship=true;
										break;
									}
								}
								if(breaker_flagship==false)
								{
									Node temp_adder=new Node();
									temp_adder.walk=next_walk;
									temp_adder.push=next_push;
									temp_adder.prev=next_previous_position;
									temp_adder.next=next_current_position;
									analyzer.add(temp_adder);
								}
							}
							else if(next_push==temporary)
							{
								int temporary_walk=distance_walks[next_current_position];
								if(next_walk<temporary)
								{
									distance_walks[next_current_position]=next_walk;
									Iterator<Node> iterator=analyzer.iterator();
									boolean breaker_flagship=false;
									while(iterator.hasNext())
									{
										Node temp_iterator=iterator.next();
										int temp_position=temp_iterator.current;
										if(temp_position==next_current_position)
										{
											temp_iterator.walk=next_walk;
											temp_iterator.push=next_push;
											temp_iterator.current=next_current_position;
											temp_iterator.prev=next_previous_position;
											breaker_flagship=true;
											break;
										}
									}
									if(breaker_flagship==false)
									{
										Node temp_adder=new Node();
										temp_adder.walk=next_walk;
										temp_adder.push=next_push;
										temp_adder.prev=next_previous_position;
										temp_adder.next=next_current_position;
										analyzer.add(temp_adder);
									}
								}	
							}
						}
						else
						{
							Node compulsory_adder=new Node();
							compulsory_adder.walk=next_walk;
							compulsory_adder.push=next_push;
							compulsory_adder.prev=next_previous_position;
							compulsory_adder.next=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							amalyzer.add(compulsory_adder);
						}
					}
				}
				else
				{
					int next_current_position=current_position+columns;
					int temp_rows=next_current_position/columns;
					int temp_columns=next_current_position%columns;
					int next_previous_position=current_position;
					int next_walk=current_walk+shortest_distance[previous_position][current_position-columns];
					int next_push=current_push+1;
					if(input[temp_rows][temp_columns]!='#')
					{
						if(visited[next_current_position]==true)
						{
							int temporary=distance[next_current_position];
							if(next_push<temporary)
							{
								distance[next_current_position]=next_push;
								distance_walks[next_current_position]=next_walk;
								Iterator<Node> iterator=analyzer.iterator();
								boolean breaker_flagship=false;
								while(iterator.hasNext())
								{
									Node temp_iterator=iterator.next();
									int temp_position=temp_iterator.current;
									if(temp_position==next_current_position)
									{
										temp_iterator.walk=next_walk;
										temp_iterator.push=next_push;
										temp_iterator.current=next_current_position;
										temp_iterator.prev=next_previous_position;
										breaker_flagship=true;
										break;
									}
								}
								if(breaker_flagship==false)
								{
									Node temp_adder=new Node();
									temp_adder.walk=next_walk;
									temp_adder.push=next_push;
									temp_adder.prev=next_previous_position;
									temp_adder.next=next_current_position;
									analyzer.add(temp_adder);
								}
							}
							else if(next_push==temporary)
							{
								int temporary_walk=distance_walks[next_current_position];
								if(next_walk<temporary)
								{
									distance_walks[next_current_position]=next_walk;
									Iterator<Node> iterator=analyzer.iterator();
									boolean breaker_flagship=false;
									while(iterator.hasNext())
									{
										Node temp_iterator=iterator.next();
										int temp_position=temp_iterator.current;
										if(temp_position==next_current_position)
										{
											temp_iterator.walk=next_walk;
											temp_iterator.push=next_push;
											temp_iterator.current=next_current_position;
											temp_iterator.prev=next_previous_position;
											breaker_flagship=true;
											break;
										}
									}
									if(breaker_flagship==false)
									{
										Node temp_adder=new Node();
										temp_adder.walk=next_walk;
										temp_adder.push=next_push;
										temp_adder.prev=next_previous_position;
										temp_adder.next=next_current_position;
										analyzer.add(temp_adder);
									}
								}	
							}
						}
						else
						{
							Node compulsory_adder=new Node();
							compulsory_adder.walk=next_walk;
							compulsory_adder.push=next_push;
							compulsory_adder.prev=next_previous_position;
							compulsory_adder.next=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							amalyzer.add(compulsory_adder);
						}
					}
				}
			}
			if((current_row!=rows-1)&&(current_rows!=0))
			{
				if(up_flag==true)
				{
					int next_walk=current_walk;
					int next_current_position=current_position-columns;
					int temp_rows=next_current_position/columns;
					int temp_columns=next_current_position%columns;
					int next_previous_position=current_position;
					int next_push=current_push+1;
					if(input[temp_rows][temp_columns]!='#')
					{
						if(visited[next_current_position]==true)
						{
							int temporary=distance[next_current_position];
							if(next_push<temporary)
							{
								distance[next_current_position]=next_push;
								distance_walks[next_current_position]=next_walk;
								Iterator<Node> iterator=analyzer.iterator();
								boolean breaker_flagship=false;
								while(iterator.hasNext())
								{
									Node temp_iterator=iterator.next();
									int temp_position=temp_iterator.current;
									if(temp_position==next_current_position)
									{
										temp_iterator.walk=next_walk;
										temp_iterator.push=next_push;
										temp_iterator.current=next_current_position;
										temp_iterator.prev=next_previous_position;
										breaker_flagship=true;
										break;
									}
								}
								if(breaker_flagship==false)
								{
									Node temp_adder=new Node();
									temp_adder.walk=next_walk;
									temp_adder.push=next_push;
									temp_adder.prev=next_previous_position;
									temp_adder.next=next_current_position;
									analyzer.add(temp_adder);
								}
							}
							else if(next_push==temporary)
							{
								int temporary_walk=distance_walks[next_current_position];
								if(next_walk<temporary)
								{
									distance_walks[next_current_position]=next_walk;
									Iterator<Node> iterator=analyzer.iterator();
									boolean breaker_flagship=false;
									while(iterator.hasNext())
									{
										Node temp_iterator=iterator.next();
										int temp_position=temp_iterator.current;
										if(temp_position==next_current_position)
										{
											temp_iterator.walk=next_walk;
											temp_iterator.push=next_push;
											temp_iterator.current=next_current_position;
											temp_iterator.prev=next_previous_position;
											breaker_flagship=true;
											break;
										}
									}
									if(breaker_flagship==false)
									{
										Node temp_adder=new Node();
										temp_adder.walk=next_walk;
										temp_adder.push=next_push;
										temp_adder.prev=next_previous_position;
										temp_adder.next=next_current_position;
										analyzer.add(temp_adder);
									}
								}	
							}
						}
						else
						{
							Node compulsory_adder=new Node();
							compulsory_adder.walk=next_walk;
							compulsory_adder.push=next_push;
							compulsory_adder.prev=next_previous_position;
							compulsory_adder.next=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							amalyzer.add(compulsory_adder);
						}
					}
				}
				else
				{
					int next_current_position=current_position-columns;
					int temp_rows=next_current_position/columns;
					int temp_columns=next_current_position%columns;
					int next_previous_position=current_position;
					int next_walk=current_walk+shortest_distance[previous_position][current_position+columns];
					int next_push=current_push+1;
					if(input[temp_rows][temp_columns]!='#')
					{
						if(visited[next_current_position]==true)
						{
							int temporary=distance[next_current_position];
							if(next_push<temporary)
							{
								distance[next_current_position]=next_push;
								distance_walks[next_current_position]=next_walk;
								Iterator<Node> iterator=analyzer.iterator();
								boolean breaker_flagship=false;
								while(iterator.hasNext())
								{
									Node temp_iterator=iterator.next();
									int temp_position=temp_iterator.current;
									if(temp_position==next_current_position)
									{
										temp_iterator.walk=next_walk;
										temp_iterator.push=next_push;
										temp_iterator.current=next_current_position;
										temp_iterator.prev=next_previous_position;
										breaker_flagship=true;
										break;
									}
								}
								if(breaker_flagship==false)
								{
									Node temp_adder=new Node();
									temp_adder.walk=next_walk;
									temp_adder.push=next_push;
									temp_adder.prev=next_previous_position;
									temp_adder.next=next_current_position;
									analyzer.add(temp_adder);
								}
							}
							else if(next_push==temporary)
							{
								int temporary_walk=distance_walks[next_current_position];
								if(next_walk<temporary)
								{
									distance_walks[next_current_position]=next_walk;
									Iterator<Node> iterator=analyzer.iterator();
									boolean breaker_flagship=false;
									while(iterator.hasNext())
									{
										Node temp_iterator=iterator.next();
										int temp_position=temp_iterator.current;
										if(temp_position==next_current_position)
										{
											temp_iterator.walk=next_walk;
											temp_iterator.push=next_push;
											temp_iterator.current=next_current_position;
											temp_iterator.prev=next_previous_position;
											breaker_flagship=true;
											break;
										}
									}
									if(breaker_flagship==false)
									{
										Node temp_adder=new Node();
										temp_adder.walk=next_walk;
										temp_adder.push=next_push;
										temp_adder.prev=next_previous_position;
										temp_adder.next=next_current_position;
										analyzer.add(temp_adder);
									}
								}	
							}
						}
						else
						{
							Node compulsory_adder=new Node();
							compulsory_adder.walk=next_walk;
							compulsory_adder.push=next_push;
							compulsory_adder.prev=next_previous_position;
							compulsory_adder.next=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							amalyzer.add(compulsory_adder);
						}
					}
				}	
			}
			if((current_column!=0)&&(current_column!=columns-1))
			{
				if(right_flag==true)
				{
					int next_walk=current_walk;
					int next_current_position=current_position+1;
					int temp_rows=next_current_position/columns;
					int temp_columns=next_current_position%columns;
					int next_previous_position=current_position;
					int next_push=current_push+1;
					if(input[temp_rows][temp_columns]!='#')
					{
						if(visited[next_current_position]==true)
						{
							int temporary=distance[next_current_position];
							if(next_push<temporary)
							{
								distance[next_current_position]=next_push;
								distance_walks[next_current_position]=next_walk;
								Iterator<Node> iterator=analyzer.iterator();
								boolean breaker_flagship=false;
								while(iterator.hasNext())
								{
									Node temp_iterator=iterator.next();
									int temp_position=temp_iterator.current;
									if(temp_position==next_current_position)
									{
										temp_iterator.walk=next_walk;
										temp_iterator.push=next_push;
										temp_iterator.current=next_current_position;
										temp_iterator.prev=next_previous_position;
										breaker_flagship=true;
										break;
									}
								}
								if(breaker_flagship==false)
								{
									Node temp_adder=new Node();
									temp_adder.walk=next_walk;
									temp_adder.push=next_push;
									temp_adder.prev=next_previous_position;
									temp_adder.next=next_current_position;
									analyzer.add(temp_adder);
								}
							}
							else if(next_push==temporary)
							{
								int temporary_walk=distance_walks[next_current_position];
								if(next_walk<temporary)
								{
									distance_walks[next_current_position]=next_walk;
									Iterator<Node> iterator=analyzer.iterator();
									boolean breaker_flagship=false;
									while(iterator.hasNext())
									{
										Node temp_iterator=iterator.next();
										int temp_position=temp_iterator.current;
										if(temp_position==next_current_position)
										{
											temp_iterator.walk=next_walk;
											temp_iterator.push=next_push;
											temp_iterator.current=next_current_position;
											temp_iterator.prev=next_previous_position;
											breaker_flagship=true;
											break;
										}
									}
									if(breaker_flagship==false)
									{
										Node temp_adder=new Node();
										temp_adder.walk=next_walk;
										temp_adder.push=next_push;
										temp_adder.prev=next_previous_position;
										temp_adder.next=next_current_position;
										analyzer.add(temp_adder);
									}
								}	
							}
						}
						else
						{
							Node compulsory_adder=new Node();
							compulsory_adder.walk=next_walk;
							compulsory_adder.push=next_push;
							compulsory_adder.prev=next_previous_position;
							compulsory_adder.next=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							amalyzer.add(compulsory_adder);
						}
					}
				}
				else
				{
					int next_current_position=current_position+1;
					int temp_rows=next_current_position/columns;
					int temp_columns=next_current_position%columns;
					int next_previous_position=current_position;
					int next_walk=current_walk+shortest_distance[previous_position][current_position-1];
					int next_push=current_push+1;
					if(input[temp_rows][temp_columns]!='#')
					{
						if(visited[next_current_position]==true)
						{
							int temporary=distance[next_current_position];
							if(next_push<temporary)
							{
								distance[next_current_position]=next_push;
								distance_walks[next_current_position]=next_walk;
								Iterator<Node> iterator=analyzer.iterator();
								boolean breaker_flagship=false;
								while(iterator.hasNext())
								{
									Node temp_iterator=iterator.next();
									int temp_position=temp_iterator.current;
									if(temp_position==next_current_position)
									{
										temp_iterator.walk=next_walk;
										temp_iterator.push=next_push;
										temp_iterator.current=next_current_position;
										temp_iterator.prev=next_previous_position;
										breaker_flagship=true;
										break;
									}
								}
								if(breaker_flagship==false)
								{
									Node temp_adder=new Node();
									temp_adder.walk=next_walk;
									temp_adder.push=next_push;
									temp_adder.prev=next_previous_position;
									temp_adder.next=next_current_position;
									analyzer.add(temp_adder);
								}
							}
							else if(next_push==temporary)
							{
								int temporary_walk=distance_walks[next_current_position];
								if(next_walk<temporary)
								{
									distance_walks[next_current_position]=next_walk;
									Iterator<Node> iterator=analyzer.iterator();
									boolean breaker_flagship=false;
									while(iterator.hasNext())
									{
										Node temp_iterator=iterator.next();
										int temp_position=temp_iterator.current;
										if(temp_position==next_current_position)
										{
											temp_iterator.walk=next_walk;
											temp_iterator.push=next_push;
											temp_iterator.current=next_current_position;
											temp_iterator.prev=next_previous_position;
											breaker_flagship=true;
											break;
										}
									}
									if(breaker_flagship==false)
									{
										Node temp_adder=new Node();
										temp_adder.walk=next_walk;
										temp_adder.push=next_push;
										temp_adder.prev=next_previous_position;
										temp_adder.next=next_current_position;
										analyzer.add(temp_adder);
									}
								}	
							}
						}
						else
						{
							Node compulsory_adder=new Node();
							compulsory_adder.walk=next_walk;
							compulsory_adder.push=next_push;
							compulsory_adder.prev=next_previous_position;
							compulsory_adder.next=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							amalyzer.add(compulsory_adder);
						}
					}
				}
			}
			if((current_column!=columns-1)&&(current_column!=0))
			{
				if(left_flag==true)
				{
					int next_walk=current_walk;
					int next_current_position=current_position-1;
					int temp_rows=next_current_position/columns;
					int temp_columns=next_current_position%columns;
					int next_previous_position=current_position;
					int next_push=current_push+1;
					if(input[temp_rows][temp_columns]!='#')
					{
						if(visited[next_current_position]==true)
						{
							int temporary=distance[next_current_position];
							if(next_push<temporary)
							{
								distance[next_current_position]=next_push;
								distance_walks[next_current_position]=next_walk;
								Iterator<Node> iterator=analyzer.iterator();
								boolean breaker_flagship=false;
								while(iterator.hasNext())
								{
									Node temp_iterator=iterator.next();
									int temp_position=temp_iterator.current;
									if(temp_position==next_current_position)
									{
										temp_iterator.walk=next_walk;
										temp_iterator.push=next_push;
										temp_iterator.current=next_current_position;
										temp_iterator.prev=next_previous_position;
										breaker_flagship=true;
										break;
									}
								}
								if(breaker_flagship==false)
								{
									Node temp_adder=new Node();
									temp_adder.walk=next_walk;
									temp_adder.push=next_push;
									temp_adder.prev=next_previous_position;
									temp_adder.next=next_current_position;
									analyzer.add(temp_adder);
								}
							}
							else if(next_push==temporary)
							{
								int temporary_walk=distance_walks[next_current_position];
								if(next_walk<temporary)
								{
									distance_walks[next_current_position]=next_walk;
									Iterator<Node> iterator=analyzer.iterator();
									boolean breaker_flagship=false;
									while(iterator.hasNext())
									{
										Node temp_iterator=iterator.next();
										int temp_position=temp_iterator.current;
										if(temp_position==next_current_position)
										{
											temp_iterator.walk=next_walk;
											temp_iterator.push=next_push;
											temp_iterator.current=next_current_position;
											temp_iterator.prev=next_previous_position;
											breaker_flagship=true;
											break;
										}
									}
									if(breaker_flagship==false)
									{
										Node temp_adder=new Node();
										temp_adder.walk=next_walk;
										temp_adder.push=next_push;
										temp_adder.prev=next_previous_position;
										temp_adder.next=next_current_position;
										analyzer.add(temp_adder);
									}
								}	
							}
						}
						else
						{
							Node compulsory_adder=new Node();
							compulsory_adder.walk=next_walk;
							compulsory_adder.push=next_push;
							compulsory_adder.prev=next_previous_position;
							compulsory_adder.next=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							amalyzer.add(compulsory_adder);
						}
					}
				}
				else
				{
					int next_current_position=current_position-1;
					int temp_rows=next_current_position/columns;
					int temp_columns=next_current_position%columns;
					int next_previous_position=current_position;
					int next_walk=current_walk+shortest_distance[previous_position][current_position+1];
					int next_push=current_push+1;
					if(input[temp_rows][temp_columns]!='#')
					{
						if(visited[next_current_position]==true)
						{
							int temporary=distance[next_current_position];
							if(next_push<temporary)
							{
								distance[next_current_position]=next_push;
								distance_walks[next_current_position]=next_walk;
								Iterator<Node> iterator=analyzer.iterator();
								boolean breaker_flagship=false;
								while(iterator.hasNext())
								{
									Node temp_iterator=iterator.next();
									int temp_position=temp_iterator.current;
									if(temp_position==next_current_position)
									{
										temp_iterator.walk=next_walk;
										temp_iterator.push=next_push;
										temp_iterator.current=next_current_position;
										temp_iterator.prev=next_previous_position;
										breaker_flagship=true;
										break;
									}
								}
								if(breaker_flagship==false)
								{
									Node temp_adder=new Node();
									temp_adder.walk=next_walk;
									temp_adder.push=next_push;
									temp_adder.prev=next_previous_position;
									temp_adder.next=next_current_position;
									analyzer.add(temp_adder);
								}
							}
							else if(next_push==temporary)
							{
								int temporary_walk=distance_walks[next_current_position];
								if(next_walk<temporary)
								{
									distance_walks[next_current_position]=next_walk;
									Iterator<Node> iterator=analyzer.iterator();
									boolean breaker_flagship=false;
									while(iterator.hasNext())
									{
										Node temp_iterator=iterator.next();
										int temp_position=temp_iterator.current;
										if(temp_position==next_current_position)
										{
											temp_iterator.walk=next_walk;
											temp_iterator.push=next_push;
											temp_iterator.current=next_current_position;
											temp_iterator.prev=next_previous_position;
											breaker_flagship=true;
											break;
										}
									}
									if(breaker_flagship==false)
									{
										Node temp_adder=new Node();
										temp_adder.walk=next_walk;
										temp_adder.push=next_push;
										temp_adder.prev=next_previous_position;
										temp_adder.next=next_current_position;
										analyzer.add(temp_adder);
									}
								}	
							}
						}
						else
						{
							Node compulsory_adder=new Node();
							compulsory_adder.walk=next_walk;
							compulsory_adder.push=next_push;
							compulsory_adder.prev=next_previous_position;
							compulsory_adder.next=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							amalyzer.add(compulsory_adder);
						}
					}
				}
			}
		}
	}

	static int[] shortest(ArrayList<Integer>[] vector,ArrayList<Integer>[] vector_index,int starting_position,int rows,int columns)
	{
		Deque<Integer> short_queue=new ArrayDeque<Integer>();
		int[] distance=new int[rows*columns];
		boolean[] visited=new boolean[rows*columns];
		visited[starting_position]=true;
		short_queue.add(starting_position);
		while(!(short_queue.isEmpty()))
		{
			int current=short_queue.poll();
			for(int i=0;i<vector[current].size();i++)
			{
				int now=vector[current].get(i);
				if(now==current)
				{
					continue;
				}
				if(visited[now]==true)
				{
					int temp=distance[current]+vector_index[current].get(i);
					if(temp<distance[now])
					{
						distance[now]=temp;
						if(!(short_queue.contains(now)))
						{
							short_queue.add(now);
						}
					}
				}
				else
				{
					distance[now]=distance[current]+vector_index[current].get(i);
					visited[now]=true;
					short_queue.add(now);
				}
			}
		}
		return distance;
	}

	public static void main(String[] args){
		int rows,columns;
		Scanner in=new Scanner(System.in);
		rows=in.nextInt();
		columns=in.nextInt();
		in.nextLine();
		String[] input_string=new String[rows];
		char[][] input=new char[rows][columns];
		for(int i=0;i<rows;i++)
		{
			input_string[i]=in.nextLine();
			input[i]=input_string[i].toCharArray();
		}
		ArrayList<Integer>[] vector=new ArrayList[rows*columns];
		ArrayList<Integer>[] vector_index=new ArrayList[rows*columns];
		for(int i=0;i<rows*columns;i++)
		{
			vector[i]=new ArrayList<Integer>();
			vector_index[i]=new ArrayList<Integer>();
		}
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<columns;j++)
			{
				if(input[i][j]=='#')
				{
					continue;
				}
				int index=i*columns+j;
				for(int k=j,count=0;k<columns;k++,count++)
				{
					if(input[i][k]=='#')
					{
						break;
					}
					vector[index].add(i*columns+k);
					vector_index[index].add(count);
				}
				for(int k=j,count=0;k>=0;k--,count++)
				{
					if(input[i][k]=='#')
					{
						break;
					}
					vector[index].add(i*columns+k);
					vector_index[index].add(count);
				}
				for(int k=i,count=0;k<rows;k++,count++)
				{
					if(input[k][j]=='#')
					{
						break;
					}
					vector[index].add(k*columns+j);
					vector_index[index].add(count);
				}
				for(int k=i,count=0;k>=0;k--,count++)
				{
					if(input[k][j]=='#')
					{
						break;
					}
					vector[index].add(k*columns+j);
					vector_index[index].add(count);
				}
			}
		}
		int[][] shortest_path=new int[rows*columns][rows*columns];
		for(int i=0;i<rows*columns;i++)
		{
			shortest_path[i]=new IOI_Pushing_Boxes().shortest(vector,vector_index,i,rows,columns);
		}
        /*for(int i=0;i<rows*columns;i++)
        {
            for(int j=0;j<rows*columns;j++)
            {
                System.out.print(shortest_path[i][j]+" ");
            }
            System.out.println();
        }*/
            //System.out.println(shortest_path[5][27]);
        int Starting_Point,Box_Position,Target_Point;
        int Box_Row,Box_Column,Starting_Row,Starting_Column,Target_Row,Target_Column;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(input[i][j]=='B')
                {
                    Box_Position=i*columns+j;
                    Box_Row=i;
                    Box_Column=j;
                }
                if(input[i][j]=='S')
                {
                    Starting_Point=i*columns+j;
                    Starting_Row=i;
                    Starting_Column=j;
                }
                if(input[i][j]=='T')
                {
                    Target_Point=i*columns+j;
                    Target_Row=i;
                    Target_Column=j;
                }
            }
        }

        Deque<Node> right=new ArrayDeque<Node>();
        Deque<Node> left=new ArrayDeque<Node>();
        Deque<Node> up=new ArrayDeque<Node>();
        Deque<Node> down=new ArrayDeque<Node>();

        boolean left_flagship=true;
        boolean right_flagship=true;
        boolean up_flagship=true;
        boolean down_flagship=true;

        if(Box_Row==0)
       	{
       		up_flagship=false;
       	}
       	if(Box_Row==(rows-1))
       	{
       		down_flagship=false;
       	}
       	if(Box_Column==0)
       	{
       		left_flagship=false;
       	}
       	if(Box_Column==(columns-1))
       	{
       		right_flagship=false;
       	}

       	int[] distance_up=new int[2];
       	int[] distance_down=new int[2];
       	int[] distance_left=new int[2];
       	int[] distance_right=new int[2];
       	
       	if(up_flagship==true)
       	{
       		Node new_node=new Node();
       		int temp=Box_Position-columns;
       		int temp_walks=shortest_path[Starting_Point][temp];
       		new_node.walks=temp_walks;
       		new_node.prev=temp;
       		new_node.current=Box_Position;
       		up.add(new_node);
       		distance_up=new IOI_Pushing_Boxes().analysis(up,rows,columns,Box_Position,input,shortest_path);
       	}

		if(down_flagship==true)
		{
			Node new_node=new Node();
       		int temp=Box_Position+columns;
       		int temp_walks=shortest_path[Starting_Point][temp];
       		new_node.walks=temp_walks;
       		new_node.prev=temp;
       		new_node.current=Box_Position;
       		down.add(new_node);
       		distance_down=new IOI_Pushing_Boxes().analysis(down,rows,columns,Box_Position,input,shortest_path);	
		}

		if(right_flagship==true)
		{
			Node new_node=new Node();
       		int temp=Box_Position+1;
       		int temp_walks=shortest_path[Starting_Point][temp];
       		new_node.walks=temp_walks;
       		new_node.prev=temp;
       		new_node.current=Box_Position;
       		right.add(new_node);
       		distance_right=new IOI_Pushing_Boxes().analysis(right,rows,columns,Box_Position,input,shortest_path);	
		} 

		if(left_flagship==true)
		{
			Node new_node=new Node();
       		int temp=Box_Position-1;
       		int temp_walks=shortest_path[Starting_Point][temp];
       		new_node.walks=temp_walks;
       		new_node.prev=temp;
       		new_node.current=Box_Position;
       		left.add(new_node);
       		distance_left=new IOI_Pushing_Boxes().analysis(left,rows,columns,Box_Position,input,shortest_path);	
		}      
	}
}