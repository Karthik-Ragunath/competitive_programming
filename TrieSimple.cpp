class Trie
{
    set< string > lexicographical_strings;
    unordered_map< char, Trie*> trie_graph;
};

class Solution {
    public:

        vector<vector<string>> suggestedProducts(vector<string> &A, string searchWord) {

            Trie *root = new Trie();
            for(auto suggested_product: A)
            {
                Trie *trie = root;
                for(auto suggested_char: suggested_product)
                {
                    auto search_iter = (trie -> trie_graph).find(suggested_char);
                    if(search_iter != trie -> trie_graph.end())
                    {
                        trie = search_iter;
                        trie -> lexicographical_strings.insert(suggested_product)
                    }
                    else
                    {
                        Trie *new_node = new Trie();
                        trie -> trie_graph.insert(make_pair(suggested_char, new_node));
                        new_node -> lexicographical_strings.insert(suggested_product);
                    }
                }
            }

            Trie *trie = root;
            vector< vector< string > > twod_list(search_word.length());
            int j = 0;
            for(auto search_char: search_word)
            {
                vector< string > internal_list;
                auto search_iter = (trie -> trie_graph.find(search_char));
                if(search_iter != trie -> trie_graph.end())
                {
                    trie = trie -> trie_graph[search_char];
                    int i = 0;
                    for(auto suggested_word: trie -> lexicographical_strings)
                    {
                        if(i < 3)
                        {
                            internal_list.push_back(suggested_word);
                        }
                    }
                }
                twod_list[j] = internal_list;
                j++;
            }

            return twod_list;
        }
};

/*
 vector<vector<string>> suggestedProducts(vector<string>& A, string searchWord) {
        auto it = A.begin();
        sort(it, A.end());
        vector<vector<string>> res;
        string cur = "";
        for (char c : searchWord) {
            cur += c;
            vector<string> suggested;
            it = lower_bound(it, A.end(), cur);
            for (int i = 0; i < 3 && it + i != A.end(); i++) {
                string& s = *(it + i);
                if (s.find(cur)) break;
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        return res;
    }
*/