// https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
class StackNode
{
	public:
		int last_index;
		bool is_rotten;
		char character;
		int initial_index;
};
class Solution 
{
	public:
    	vector<string> maxNumOfSubstrings(string s) 
    	{
        	int s_len = s.length();
        	unordered_map< char, int > char_hash;
        	for(int i = 0; i < s_len; i++)
        	{
        		auto find_iter = char_hash.find(s[i]);
        		int initial_val;
        		if(find_iter != char_hash.end())
        		{
		    		initial_val = (find_iter -> second).second;
		    		char_hash.erase(find_iter);
        		}
        		else
        		{
        			initial_val = i;
        		}
        		char_hash.insert(make_pair(s[i], make_pair(initial_val, i)));
        	}
        	stack< StackNode > stack_nodes;
        	vector< string > solution;
        	set< char > visited;
        	// for(auto map_pair: char_hash)
        	// {
        	// 	StackNode* stack_node = new StackNode;
        	// 	stack_node -> last_index = map_pair.second;
        	// 	stack_node -> is_rotten = false;
        	// 	stack_node -> character = map_pair.first;
        	// }
        	for(int i = 0; i < s_len; i++)
        	{
        		char current_char = s[i];
        		int last_index = char_hash[current_char] -> second.second;
        		if(stack_nodes.empty())
        		{
        			if(last_index == i)
        			{
        				string char_string = string(1, current_char);
        				solution.push_back(char_string);
        			}
        			else
        			{
        				StackNode* stack_node = new StackNode;
        				stack_node -> last_index = last_index;
        				stack_node -> is_rotten = false;
        				stack_node -> character = current_char;
        				stack_node -> initial_val = char_hash[s[i]] -> second.first;
        				stack_nodes.push(stack_node);
        			}
        		}
        		else
        		{
        			bool is_rotten = false;
        			while(not stack_nodes.empty() and (stack_nodes.top()) -> last_index < last_index)
        			{
        				auto stack_node = stack_nodes.top();
        				stack_nodes.pop();
        			}
        			if(not stack_nodes.empty())
        			{
        				auto stack_node = stack_nodes.top();
        				if(stack_node -> character == current_char)
        				{
        					if(char_hash[current_char] -> second.second == i)
        					{
        						if(stack_node -> is_rotten == false)
        						{
	        						int local_initial_value = stack_node -> initial_val;
	        						int final_val = i;
	        						int difference = final_val - initial_val;
	        					}
        					}
        					else
        					{
        						continue;
        					}
        				}
        				else
        				{
        					if(char_hash[current_char] -> second.first < i)
        					{
        						auto stack_node = stack_nodes.top();
        						stack_nodes.pop();
        						stack_node -> initial_val = min(stack_node -> initial_val, char_hash[current_char] -> second.first);
        						stack_nodes.push(stack_node);
        					}
        					else
        					{

        					}
        				}
        			}
        			else
        			{

        			}
        		}
        	}
    	}
};