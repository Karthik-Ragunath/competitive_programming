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

	static int[] analysis(ArrayDeque<Node> analyzer,int rows,int columns,int Box_Position,char[][] input,int[][] shortest_path,int target)
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
                System.out.println("Previous Position: "+previous_position);
                System.out.println("Current Position: "+current_position);
                System.out.println("Current Walk: "+current_walk);
                System.out.println("Current Push: "+current_push);
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
									temp_adder.current=next_current_position;
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
										temp_adder.current=next_current_position;
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
							compulsory_adder.current=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							analyzer.add(compulsory_adder);
                            visited[next_current_position]=true;
						}
					}
				}
				else
				{
					int next_current_position=current_position+columns;
					int temp_rows=next_current_position/columns;
					int temp_columns=next_current_position%columns;
					int next_previous_position=current_position;
					int next_walk=current_walk+shortest_path[previous_position][current_position-columns];
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
									temp_adder.current=next_current_position;
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
										temp_adder.current=next_current_position;
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
							compulsory_adder.current=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							analyzer.add(compulsory_adder);
                            visited[next_current_position]=true;
						}
					}
				}
			}
			if((current_row!=rows-1)&&(current_row!=0))
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
									temp_adder.current=next_current_position;
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
										temp_adder.current=next_current_position;
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
							compulsory_adder.current=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							analyzer.add(compulsory_adder);
                            visited[next_current_position]=true;
						}
					}
				}
				else
				{
					int next_current_position=current_position-columns;
					int temp_rows=next_current_position/columns;
					int temp_columns=next_current_position%columns;
					int next_previous_position=current_position;
					int next_walk=current_walk+shortest_path[previous_position][current_position+columns];
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
									temp_adder.current=next_current_position;
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
										temp_adder.current=next_current_position;
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
							compulsory_adder.current=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							analyzer.add(compulsory_adder);
                            visited[next_current_position]=true;
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
									temp_adder.current=next_current_position;
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
										temp_adder.current=next_current_position;
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
							compulsory_adder.current=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							analyzer.add(compulsory_adder);
                            visited[next_current_position]=true;
						}
					}
				}
				else
				{
					int next_current_position=current_position+1;
					int temp_rows=next_current_position/columns;
					int temp_columns=next_current_position%columns;
					int next_previous_position=current_position;
					int next_walk=current_walk+shortest_path[previous_position][current_position-1];
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
									temp_adder.current=next_current_position;
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
										temp_adder.current=next_current_position;
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
							compulsory_adder.current=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							analyzer.add(compulsory_adder);
                            visited[next_current_position]=true;
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
									temp_adder.current=next_current_position;
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
										temp_adder.current=next_current_position;
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
							compulsory_adder.current=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							analyzer.add(compulsory_adder);
                            visited[next_current_position]=true;
						}
					}
				}
				else
				{
					int next_current_position=current_position-1;
					int temp_rows=next_current_position/columns;
					int temp_columns=next_current_position%columns;
					int next_previous_position=current_position;
					int next_walk=current_walk+shortest_path[previous_position][current_position+1];
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
									temp_adder.current=next_current_position;
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
										temp_adder.current=next_current_position;
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
							compulsory_adder.current=next_current_position;
							distance[next_current_position]=next_push;
							distance_walks[next_current_position]=next_walk;
							analyzer.add(compulsory_adder);
                            visited[next_current_position]=true;
						}
					}
				}
			}
		}
        int[] returner=new int[2];
		returner[0]=distance[target];
		returner[1]=distance_walks[target];
        return returner;
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
            System.out.println("shortest distance between two points "+shortest_path[15][23]);

        int Starting_Point=0,Box_Position=0,Target_Point=0;
        int Box_Row=0,Box_Column=0,Starting_Row=0,Starting_Column=0,Target_Row=0,Target_Column=0;
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
            System.out.println("Box Position: "+Box_Position);
            System.out.println("Box Row: "+Box_Row);
            System.out.println("Box Column "+Box_Column);
            System.out.println("Starting Point: "+Starting_Point);
            System.out.println("Starting Row: "+Starting_Row);
            System.out.println("Stsrting Column: "+Starting_Column);
            System.out.println("Target Point: "+Target_Point);
            System.out.println("Target Row: "+Target_Row);
            System.out.println("Target Column: "+Target_Column);
        ArrayDeque<Node> right=new ArrayDeque();
        ArrayDeque<Node> left=new ArrayDeque();
        ArrayDeque<Node> up=new ArrayDeque();
        ArrayDeque<Node> down=new ArrayDeque();

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
        distance_up[0]=rows*columns+1;
        distance_up[1]=rows*columns+1;
       	int[] distance_down=new int[2];
        distance_down[0]=rows*columns+1;
        distance_down[1]=rows*columns+1;
       	int[] distance_left=new int[2];
        distance_left[0]=rows*columns+1;
        distance_left[1]=rows*columns+1;
       	int[] distance_right=new int[2];
        distance_right[0]=rows*columns+1;
        distance_right[1]=rows*columns+1;
       	
       	if(up_flagship==true)
       	{
       		Node new_node=new Node();
       		int temp=Box_Position-columns;
            int now_row=temp/columns;
            int now_column=temp%columns;
            if(input[now_row][now_column]!='#')
            {
                int temp_walks=shortest_path[Starting_Point][temp];
                new_node.walk=temp_walks;
                new_node.prev=temp;
                new_node.current=Box_Position;
                up.add(new_node);
                System.out.println("Up Direction");
                distance_up=new IOI_Pushing_Boxes().analysis(up,rows,columns,Box_Position,input,shortest_path,Target_Point);
                System.out.println();
            }
            else
            {
                System.out.println("Up is #");
            }
        }

		if(down_flagship==true)
		{
			Node new_node=new Node();
       		int temp=Box_Position+columns;
            int now_row=temp/columns;
            int now_column=temp%columns;
            if(input[now_row][now_column]!='#')
            {
                int temp_walks=shortest_path[Starting_Point][temp];
                new_node.walk=temp_walks;
                new_node.prev=temp;
                new_node.current=Box_Position;
                down.add(new_node);
                System.out.println("Down Direction");
                distance_down=new IOI_Pushing_Boxes().analysis(down,rows,columns,Box_Position,input,shortest_path,Target_Point);
                System.out.println();
            }
            else
            {
                System.out.println("Down is #");
            }
		}

		if(right_flagship==true)
		{
            System.out.println("Inside Right");
			Node new_node=new Node();
       		int temp=Box_Position+1;
            int now_row=temp/columns;
            int now_column=temp%columns;
            if(input[now_row][now_column]!='#')
            {
                int temp_walks=shortest_path[Starting_Point][temp];
                new_node.walk=temp_walks;
                new_node.prev=temp;
                new_node.current=Box_Position;
                right.add(new_node);
                System.out.println("Right Direction");
                distance_right=new IOI_Pushing_Boxes().analysis(right,rows,columns,Box_Position,input,shortest_path,Target_Point);
                System.out.println();
            }
            else
            {
                System.out.println("Right is #");
            }
		} 

		if(left_flagship==true)
		{
			Node new_node=new Node();
       		int temp=Box_Position-1;
            int now_row=temp/columns;
            int now_column=temp%columns;
            if(input[now_row][now_column]!='#')
            {
                int temp_walks=shortest_path[Starting_Point][temp];
                new_node.walk=temp_walks;
                new_node.prev=temp;
                new_node.current=Box_Position;
                left.add(new_node);
                System.out.println("Left Direction");
                distance_left=new IOI_Pushing_Boxes().analysis(left,rows,columns,Box_Position,input,shortest_path,Target_Point);
                System.out.println();
            }
            else
            {
                System.out.println("Left is #");
            }
		}
		/*left=1;right=2;up=3;down=4*/
		int temp_min_distance1;
		int temp_min_walk1;
		int temp_min_distance2;
		int temp_min_walk2;

		if(distance_left[0]<distance_right[0])
		{
			temp_min_distance1=distance_left[0];
			temp_min_walk1=distance_left[1];
		}
		else if(distance_left[0]>distance_right[0])
		{
			temp_min_distance1=distance_right[0];
			temp_min_walk1=distance_right[1];
		}
		else
		{
			if(distance_left[1]<distance_right[1])
			{
				temp_min_distance1=distance_left[0];
				temp_min_walk1=distance_left[1];
			}
			else if(distance_left[1]>distance_right[1])
			{
				temp_min_distance1=distance_right[0];
				temp_min_walk1=distance_right[1];
			}
			else
			{
				temp_min_distance1=distance_left[0];
				temp_min_walk1=distance_left[1];
			}
		}
		if(distance_up[0]<distance_down[0])
		{
			temp_min_distance2=distance_up[0];
			temp_min_walk2=distance_up[1];
		}
		else if(distance_up[0]>distance_down[0])
		{
			temp_min_distance2=distance_down[0];
			temp_min_walk2=distance_down[1];
		}
		else
		{
			if(distance_up[1]<distance_down[1])
			{
				temp_min_distance2=distance_up[0];
				temp_min_walk2=distance_down[1];
			}
			else if(distance_up[1]>distance_down[1])
			{
				temp_min_distance2=distance_down[0];
				temp_min_walk2=distance_down[1];
			}
			else
			{
				temp_min_distance2=distance_up[0];
				temp_min_walk2=distance_up[1];
			}
		}
		int distance_answer;
		int walk_answer;
		if(temp_min_distance1<temp_min_distance2)
		{
			distance_answer=temp_min_distance1;
			walk_answer=temp_min_walk1;
		}
		else if(temp_min_distance1>temp_min_distance2)
		{
			distance_answer=temp_min_distance2;
			walk_answer=temp_min_walk2;
		}
		else
		{
			distance_answer=temp_min_distance1;
			if(temp_min_walk1<temp_min_walk2)
			{
				walk_answer=temp_min_walk1;
			}
			else if(temp_min_walk1>temp_min_walk2)
			{
				walk_answer=temp_min_walk2;
			}
			else
			{
				walk_answer=temp_min_walk1;
			}
		}
		System.out.println(distance_answer+" "+walk_answer);
	}
}