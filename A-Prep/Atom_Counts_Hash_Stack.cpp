class Solution 
{
	public:
    	string countOfAtoms(string formula) 
    	{
    		stack< char > bracket_stack;
    		map< char, int > solution_map;
    		int string_length = formula.size();
     		for(int i = 0; i < string_length; i++)
     		{
     			if(formula[i] != ')' and formula[i] != '(')
     			{
     				if(isdigit(formula[i]))
     				{
     					int start = i, end = i;
     					for(int j = start + 1; j < string_length; i++)
     					{
     						if(not isdigit(formula[j]))
     						{
     							break;
     						}
   							end = j;
     					}
     					int length = end - start + 1;
     					string sub_string = formula.substr(start, length);
     					int int_value = atoi(sub_string.c_str());
     					if(bracket_stack.empty() or (not bracket_stack.empty() and bracket_stack.top() != '('))
     					{
     						char top_char = bracket_stack.top();
     						solution_map[top_char] += int_value;
     					}
     					else
     					{
     						
     					}
     					i = end;
     				}
     			}
     		}   
    	}
};