class CompareSet
{
    public:
        bool operator()(const pair< char, int > pair_1, const pair< char, int > pair_2) const
        {
            if(pair_1.second <= pair_2.second)
            {
                return true;
            }
            return false;
        }
};

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map< char, unordered_set< char > > char_mapping;
        unordered_map< char, int > indegree;
        for(auto word: words)
        {
            for(auto ch: word)
            {
                indegree[ch] = 0;
            }
        }
        for(auto iter = words.begin(); iter != words.end(); iter++)
        {
            if(iter + 1 == words.end())
            {
                break;
            }
            auto next_iter = iter + 1;
            for(auto ch_1 = (*iter).begin(), ch_2 = (*next_iter).begin(); ch_1 != (*iter_1).end() and ch_2 (*iter_2).end(); ch_1++, ch_2++)
            {
                int ch_1_val = (int)(*ch_1);
                int ch_2_val = (int)(*ch_2);
                if(ch_1_val == ch_2_val)
                {
                    continue;
                }
                else
                {
                    if(ch_1_val < ch_2_val)
                    {
                        auto find_iter = char_mapping.find(*ch_1);
                        if(find_iter != char_mapping.end())
                        {
                            find_iter -> second.insert(*ch_2);
                        }
                        else
                        {
                            char_mapping.insert(make_pair((*ch_1), unordered_set< char >{*ch_2}));
                        }
                        indegree[(*ch_2)] += 1;
                        auto indegree_find_iter = indegree.find((*ch_1));
                        if(indegree_find_iter == indegree.end())
                        {
                            indegree[(*ch_1)] = 0;
                        }
                    }
                    else
                    {
                        auto find_iter = char_mapping.find(*ch_2);
                        if(find_iter != char_mapping.end())
                        {
                            find_iter -> second.insert(*ch_1);
                        }
                        else
                        {
                            char_mapping.insert(make_pair((*ch_2), unordered_set< char >{*ch_1}));
                        }
                        indegree[(*ch_1)] += 1;
                        auto indegree_find_iter = indegree.find((*ch_2));
                        if(indegree_find_iter == indegree.end())
                        {
                            indegree[(*ch_2)] = 0;
                        }
                    }
                    break;
                }
            }
        }
        set< pair< char, int >, CompareSet > indegree_set(indegree.begin(), indegree.end());
        set< char > visited_nodes;
        vector< char > solution;
        while(not indegree_set.empty())
        {
            while(not indegree_set.empty() and (indegree_set.begin()) -> second == 0)
            {
                char char_to_be_removed = (indegree_set.begin()) -> first;
                visited_nodes.insert(char_to_be_removed);
                solution.push_back(char_to_be_removed);
                indegree_set.erase((indegree_set.begin()));
            }
            for(auto iter = visited_nodes.begin(); iter != visited_nodes.end();)
            {
                char visited_char = *iter;
                auto find_iter = char_mapping.find(visited_char);
                if(find_iter != char_mapping.end())
                {
                    for(char child_char: char_mapping[visited_char])
                    {
                        int indegree_of_child_char = indegree[child_char];
                        auto find_iter = indegree_set.find(make_pair(child_char, indegree_of_child_char));
                        if(find_iter != indegree_set.end())
                        {
                            find_iter -> second -= 1;
                        }
                        indegree[child_char] -= 1;
                    }
                }
            }
        }
    }
};