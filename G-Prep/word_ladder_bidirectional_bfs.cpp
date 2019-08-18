class Solution 
{
	public:
    	int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    	{
            bool end_word_present = false;
            for(int i = 0; i < wordList.size(); i++)
            {
                if(wordList[i] == endWord)
                {
                    end_word_present = true;
                    break;
                }
            }
            if(not end_word_present)
            {
                return 0;
            }
            
    		unordered_map< string, vector< string > > generic_dicts;
        	for(int i = 0; i < wordList.size(); i++)
        	{
        		int word_length = wordList[i].length();
        		for(int j = 0; j < word_length; j++)
        		{
        			auto find_iter = generic_dicts.find(wordList[i].substr(0, j) + '*' + wordList[i].substr(j + 1, word_length - (j  + 1)));
        			if(find_iter != generic_dicts.end())
        			{
        				find_iter -> second.push_back(wordList[i]);
        			}
        			else
        			{
        				generic_dicts.insert(make_pair(wordList[i].substr(0, j) + '*' + wordList[i].substr(j + 1, word_length - (j  + 1)), vector< string >{wordList[i]}));
        			}
        		}
        	}
    		queue< string > bfs_forward;
    		queue< string > bfs_backward;
    		unordered_map< string, bool > forward_bfs_visited;
    		unordered_map< string, bool > backward_bfs_visited;
    		unordered_map< string, int > forward_bfs_level;
    		unordered_map< string, int > backward_bfs_level;
    		bfs_forward.push(beginWord);
    		bfs_backward.push(endWord);
    		forward_bfs_visited[beginWord] = true;
    		backward_bfs_visited[endWord] = true;
    		forward_bfs_level[beginWord] = 1;
    		backward_bfs_level[endWord] = 1;
    		int solution = 0;
    		while(not bfs_forward.empty() and not bfs_backward.empty())
    		{
                if(not bfs_forward.empty())
                {
                    string f_head = bfs_forward.front();
                    bfs_forward.pop();
                    int f_head_level = forward_bfs_level[f_head];
                    if(backward_bfs_visited[beginWord])
                    {
                        // cout << "debug2" << "\n";
                        solution = backward_bfs_level[beginWord];
                        break;
                    }
                    if(backward_bfs_visited[f_head])
                    {
                        // cout << "debug3" << "\n";
                        solution = forward_bfs_level[f_head] + backward_bfs_level[f_head] - 1;
                        break;
                    }

                    int f_head_length = f_head.length();
                    for(int i = 0; i < f_head_length; i++)
                    {
                        string generic_string = f_head.substr(0, i) + '*' + f_head.substr(i + 1, f_head_length - (i  + 1));
                        // cout << "generic_string_f: " << generic_string << "\n";
                        for(auto forward_iter = generic_dicts[generic_string].begin(); forward_iter != generic_dicts[generic_string].end(); forward_iter++)
                        {
                            if(not forward_bfs_visited[*forward_iter])
                            {
                                // cout << "f_push: " << *forward_iter << " val: " << (f_head_level + 1) << "\n";
                                bfs_forward.push(*forward_iter);
                                forward_bfs_visited[*forward_iter] = true;
                                forward_bfs_level[*forward_iter] = f_head_level + 1;
                            }
                        }
                    }
                }
                
                if(not bfs_backward.empty())
                {
                    string b_head = bfs_backward.front();
                    bfs_backward.pop();
                    int b_head_level = backward_bfs_level[b_head];
                    if(forward_bfs_visited[endWord])
                    {
                        // cout << "debug1" << "\n";
                        solution = forward_bfs_level[endWord];
                        break;
                    }
                    if(forward_bfs_visited[b_head])
                    {
                        // cout << "debug4" << "\n";
                        solution = forward_bfs_level[b_head] + backward_bfs_level[b_head] - 1;
                        break;
                    }

                    int b_head_length = b_head.length();
                    for(int i = 0; i < b_head_length; i++)
                    {
                        string generic_string = b_head.substr(0, i) + '*' + b_head.substr(i + 1, b_head_length - (i  + 1));
                        // cout << "generic_string_b: " << generic_string << "\n";
                        for(auto g_dict_val: generic_dicts[generic_string])
                        {
                            if(not backward_bfs_visited[g_dict_val])
                            {
                                // cout << "b_push: " << g_dict_val << " val: " << (b_head_level + 1) << "\n";
                                bfs_backward.push(g_dict_val);
                                backward_bfs_visited[g_dict_val] = true;
                                backward_bfs_level[g_dict_val] = b_head_level + 1;
                            }
                        }
                    }
                }
                // cout << "=======" << "\n";
    		}
    		return solution;
    	}
};