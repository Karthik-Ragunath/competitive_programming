// https://leetcode.com/problems/partition-labels/
class Solution 
{
	public:
    	vector<int> partitionLabels(string S) 
    	{
        	unordered_map< char, int > max_index_of_char;
        	for(int i = 0; i < S.length(); i++)
        	{
        		max_index_of_char[S[i]] = i;
        	}
            cout << max_index_of_char['a'] << "\n";
        	// int start = 0;
        	// vector< string > solution;
        	int length = 0;
        	int max_current_partition_index = max_index_of_char[S[0]];
        	vector< int > solution_sizes;
        	for(int i = 0; i < S.length(); i++)
        	{
        		length += 1;
        		if(i == max_current_partition_index)
        		{
        			// solution.push_back(S.substr(start, length));
        			// start = i + 1;
        			solution_sizes.push_back(length);
        			length = 0;
                    if(i != (S.length() - 1))
                    {
                        max_current_partition_index = max_index_of_char[S[i + 1]];
                    }
        		}
        		else
        		{
        			if(max_index_of_char[S[i]] <= max_current_partition_index)
        			{
        				continue;
        			}
        			else
        			{
        				max_current_partition_index = max_index_of_char[S[i]];
        				continue;
        			}
        		}
        	}
        	if(length > 0)
        	{
        		// solution.push_back(S.substr(start, length));
        		solution_sizes.push_back(length);
        	}
        	return solution_sizes;	
    	}
};