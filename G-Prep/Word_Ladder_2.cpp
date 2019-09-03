class Solution {
public:
    void dfs(string current_word, string end_word, unordered_map< string, vector< string > > &generic_dicts, unordered_map< int, vector< vector< string > > > &solution_dict, int current_len, vector< string > &temp_vec, int &min_transformations, unordered_map< string, int > &distance_map)
    {
        if(min_transformations == -1 or current_len <= min_transformations)
        {
            temp_vec.push_back(current_word);
            if(current_word == end_word)
            {
                cout << "current len: " << current_len << "\n";
                auto find_iter = solution_dict.find(current_len);
                if(find_iter != solution_dict.end())
                {
                    find_iter -> second.push_back(temp_vec);
                }
                else
                {
                    vector< vector< string > > temp_2d_vec;
                    temp_2d_vec.push_back(temp_vec);
                    solution_dict.insert(make_pair(current_len, temp_2d_vec));
                }
                min_transformations = current_len;
                temp_vec.pop_back();
                return;
            }
            int current_word_length = current_word.length();
            unordered_set< string > local_visited_set;
            for(int i = 0; i < current_word_length; i++)
            {
                string key = current_word.substr(0, i) + '*' + current_word.substr(i + 1, (current_word_length - (i + 1)));
                for(auto iter = generic_dicts[key].begin(); iter != generic_dicts[key].end(); iter++)
                {
                    if(local_visited_set.find(*iter) == local_visited_set.end())
                    {
                        auto find_iter = distance_map.find(*iter);
                        if(find_iter != distance_map.end())
                        {
                            if((current_len + 1) <= distance_map[*iter])
                            {
                                distance_map[*iter] = current_len + 1;
                                dfs(*iter, end_word, generic_dicts, solution_dict, current_len + 1, temp_vec, min_transformations, distance_map);
                            }
                        }
                        else
                        {
                            distance_map[*iter] = current_len + 1;
                            dfs(*iter, end_word, generic_dicts, solution_dict, current_len + 1, temp_vec, min_transformations, distance_map);
                        }
                        local_visited_set.insert(*iter);
                    }
                }
            }
            temp_vec.pop_back();
        }
        return;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
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
            return vector< vector< string > >{};
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
        unordered_map< int, vector< vector< string > > > solution_dict;
        unordered_map< string, int > distance_map;
        distance_map[beginWord] = 1;
        int min_transformations = -1;
        vector< string > temp_vec;
        dfs(beginWord, endWord, generic_dicts, solution_dict, 1, temp_vec, min_transformations, distance_map);
        // cout << "milestone1" << "\n";
        if(min_transformations != -1)
        {
            auto iter = solution_dict.find(min_transformations);
            return iter -> second;
        }
        else
        {
            return vector< vector< string > >{};
        }
    }
};