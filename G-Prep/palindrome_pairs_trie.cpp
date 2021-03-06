#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct HASH
{
    size_t operator()(const pair< int, int > &pair_node) const
    {
        return hash< int >()(pair_node.first ^ (pair_node.second << 32));
    }
};

struct Trie
{
    unordered_map< char, Trie* > children;
    vector< int > uptill;
    vector< int > below;
    vector< int > index_vec;
};

struct Trie_Graph
{
    Trie* root = new Trie;
    void insert_nodes(string word, int index, vector< bool > &is_suffix_palindrome)
    {
        // // cout << "insert index: " << index << " word: " << word << "\n";
        Trie* node = root;
        int string_length = word.length();
        for(int i = 0; i < string_length; i++)
        {
            char character = word[i];
            auto child_finder = node -> children.find(character);
            if(child_finder != node -> children.end())
            {
                node = node -> children[character];
                node -> index_vec.push_back(index);
            }
            else
            {
                Trie* new_node = new Trie();
                node -> children[character] = new_node;
                node = new_node;
                node -> index_vec.push_back(index);
            }
            if(i + 1 < string_length)
            {
                if(is_suffix_palindrome[i + 1])
                {
                    // // cout << "word: " << word << " index: " << i << "\n";
                    node -> below.push_back(index);
                }
            }
        }
        node -> uptill.push_back(index);
        // cout << "----------" << "\n";
    }

    void print_node_children(Trie* node)
    {
        cout << "Node child printing" << "\n";
        for(auto child: node -> children)
        {
            cout << child.first << "\n";
            cout << child.second << "\n";
        }
        cout << "///////////" << "\n";
    }

    void search(string word, int index, vector< bool > &is_suffix_palindrome, unordered_map< int, unordered_set< int > > &solution_vector)
    {
        // cout << "search index: " << index << " word: " << word << "\n";
        Trie* node = root;
        int string_length = word.length();
        int char_index = 0;
        bool match_exists = true;
        for(int i = 0; i < string_length; i++)
        {
            char character = word[i];
            auto child_finder = node -> children.find(character);
            if(child_finder != node -> children.end())
            {
                node = node -> children[character];
                if(i + 1 < string_length)
                {
                    if(is_suffix_palindrome[i + 1])
                    {
                        for(auto uptill_index: node -> uptill)
                        {
                            // solution_vector.insert(make_pair(uptill_index, index));
                            auto find_iter = solution_vector.find(uptill_index);
                            if(find_iter != solution_vector.end())
                            {
                            	find_iter -> second.insert(index);
                            }
                            else
                            {
                            	unordered_set< int > new_set;
                            	new_set.insert(index);
                            	solution_vector.insert(make_pair(uptill_index, new_set));
                            }
                        }
                    }
                }
            }
            else
            {
                match_exists = false;
                break;
            }
        }
        if(match_exists)
        {
            // cout << "came hereeeeeee baby (uptill size): " <<  node -> uptill.size() << "\n";
            // for(vector< int >::iterator iter = node -> uptill.begin(); iter != node -> uptill.end(); iter++)
            // {    
            //     solution_vector.insert(make_pair(*iter, index));
            // }
            for(auto uptill_index: node -> uptill)
            {    
                // solution_vector.insert(make_pair(uptill_index, index));
                auto find_iter = solution_vector.find(uptill_index);
                if(find_iter != solution_vector.end())
                {
                	find_iter -> second.insert(index);
                }
                else
                {
                	unordered_set< int > new_set;
                	new_set.insert(index);
                	solution_vector.insert(make_pair(uptill_index, new_set));
                }
            }
            for(auto below_index: node -> below)
            {
                // solution_vector.insert(make_pair(below_index, index));
                auto find_iter = solution_vector.find(below_index);
                if(find_iter != solution_vector.end())
                {
                	find_iter -> second.insert(index);
                }
                else
                {
                	unordered_set< int > new_set;
                	new_set.insert(index);
                	solution_vector.insert(make_pair(below_index, new_set));
                }
            }
        }
        // cout << "*******" << "\n";
    }
};

class Solution 
{
    public:
        vector< bool > rolling_hash(string word)
        {
            vector< bool > is_index_palindrome;
            int hash_modulo = 103;
            is_index_palindrome.push_back(true);
            if(word.length() == 1)
            {
                return is_index_palindrome;
            }
            int first_pointer = word[0] % hash_modulo;
            int second_pointer = word[1] % hash_modulo;
            int string_length = word.length();
            for(int i = 1; i < string_length; i++)
            {
                // // cout << "first pointer: " << first_pointer << " second_pointer: " << second_pointer << "\n";
                if(first_pointer == second_pointer)
                {
                    int first_half_length = (i + 1) / 2;
                    int second_half_length = i + 1 - first_half_length;
                    bool is_palindrome = true;
                    for(int k = 0, j = i; k < first_half_length; k++, j--)
                    {
                        if(word[k] != word[j])
                        {
                            is_palindrome = false;
                            break;
                        }
                    }
                    if(is_palindrome)
                    {
                        is_index_palindrome.push_back(true);
                    }
                    else
                    {
                        is_index_palindrome.push_back(false);
                    }
                }
                else
                {
                    is_index_palindrome.push_back(false);
                }
                if(i + 1 < string_length)
                {
                    if(i % 2 == 0)
                    {
                        first_pointer += (word[(i + 1) / 2] % hash_modulo);
                        second_pointer += (word[(i + 1)] % hash_modulo);
                        first_pointer = (first_pointer + hash_modulo) % hash_modulo;
                        second_pointer = (second_pointer + hash_modulo) % hash_modulo;
                    }
                    else
                    {
                        second_pointer = second_pointer - (word[(i + 1) / 2] % hash_modulo) + (word[i + 1] % hash_modulo);
                        second_pointer = ((second_pointer + hash_modulo) % hash_modulo);
                    }
                }
            }
            return is_index_palindrome;
        }

        void print_suffix_palindromes(vector< string > &words)
        {
            int words_size = words.size();
            for(int i = 0; i < words_size; i++)
            {
                string rev_string(words[i]);
                reverse(rev_string.begin(), rev_string.end());
                auto palindromic_suffixes = rolling_hash(rev_string);
                int palindromic_suffixes_length = palindromic_suffixes.size();
                for(int j = palindromic_suffixes_length - 1, k = 0; j >= 0; j--, k++)
                {
                    cout << "string: " << i + 1 << " suffix string: " << words[i].substr(j, k + 1) << " is a " << ((palindromic_suffixes[k] == true) ? "true" : "false") << "\n";
                }
                cout << "----------" << "\n";
            }
        }

        void print_palindromic_pairs(vector< vector< int > > &palindrome_pairs)
        {
        	cout << "size of solution: " << palindrome_pairs.size() << "\n";
		    for(auto outer_vec: palindrome_pairs)
		    {
		        cout << "-------solution-------" << "\n";
		        for(auto inner_vec: outer_vec)
		        {
		            cout << inner_vec << "\n";
		        }
		    }
		}

        vector<vector<int>> palindromePairs(vector<string>& words) 
        {
            // print_suffix_palindromes(words);
             int words_vec_length = words.size();
             // cout << "mile_stone 2: " << words_vec_length << "\n";
             
            unordered_map< int, unordered_set< int > > solution_vector;

            Trie_Graph* trie_graph = new Trie_Graph;
            vector< int > empty_string_indices;
            vector< int > induvidual_palindromic_string_indices;
            for(int i = 0; i < words_vec_length; i++)
            {
                string word = words[i];
                if(word == "")
                {
                	empty_string_indices.push_back(i);
                	continue;
                }
                // cout << "index: " << i << " word: " << word << "\n";
                auto palindromic_prefixes = rolling_hash(word);
                if(palindromic_prefixes[word.length() - 1] == true)
                {
                	induvidual_palindromic_string_indices.push_back(i);
                }
                string rev_word(word); //copy string
                reverse(rev_word.begin(), rev_word.end());
                // cout << "rev word: " << rev_word << "\n";
                vector< bool > palindromic_prefixes_inversed(palindromic_prefixes);
                reverse(palindromic_prefixes_inversed.begin(), palindromic_prefixes_inversed.end());
                trie_graph -> search(rev_word, i, palindromic_prefixes_inversed, solution_vector);
                auto palindromic_suffixes_inversed = rolling_hash(rev_word);
                vector< bool > palindromic_suffixes(palindromic_suffixes_inversed);
                reverse(palindromic_suffixes.begin(), palindromic_suffixes.end());
                trie_graph -> insert_nodes(word, i, palindromic_suffixes);
            }

            trie_graph = new Trie_Graph;
            for(int i = words_vec_length - 1; i >= 0; i--)
            {
                string word = words[i];
                if(word == "")
                {
                	continue;
                }
                auto palindromic_prefixes = rolling_hash(word);
                string rev_word(word); //copy string
                reverse(rev_word.begin(), rev_word.end());
                vector< bool > palindromic_prefixes_inversed(palindromic_prefixes);
                reverse(palindromic_prefixes_inversed.begin(), palindromic_prefixes_inversed.end());
                trie_graph -> search(rev_word, i, palindromic_prefixes_inversed, solution_vector);
                auto palindromic_suffixes_inversed = rolling_hash(rev_word);
                vector< bool > palindromic_suffixes(palindromic_suffixes_inversed);
                reverse(palindromic_suffixes.begin(), palindromic_suffixes.end());
                trie_graph -> insert_nodes(word, i, palindromic_suffixes);
            }

            if(!empty_string_indices.empty() && !induvidual_palindromic_string_indices.empty())
            {
            	for(auto empty_index: empty_string_indices)
            	{
            		for(auto induvidual_palindromic_string_index: induvidual_palindromic_string_indices)
            		{
            			// cout << "Induvidual: " << induvidual_palindromic_string_index << " empty: " << empty_index << "\n";
            			// solution_vector.insert(make_pair(empty_index, induvidual_palindromic_string_index));
            			// solution_vector.insert(make_pair(induvidual_palindromic_string_index, empty_index));
            			auto find_iter = solution_vector.find(empty_index);
		                if(find_iter != solution_vector.end())
		                {
		                	find_iter -> second.insert(induvidual_palindromic_string_index);
		                }
		                else
		                {
		                	unordered_set< int > new_set;
		                	new_set.insert(induvidual_palindromic_string_index);
		                	solution_vector.insert(make_pair(empty_index, new_set));
		                }

		                auto find_iter_modified = solution_vector.find(induvidual_palindromic_string_index);
		                if(find_iter_modified != solution_vector.end())
		                {
		                	find_iter_modified -> second.insert(empty_index);
		                }
		                else
		                {
		                	unordered_set< int > new_set;
		                	new_set.insert(empty_index);
		                	solution_vector.insert(make_pair(induvidual_palindromic_string_index, new_set));
		                }
            		}
            	}
            }

            vector< vector< int > > palindromic_pairs;
            for(auto map_iter = solution_vector.begin(); map_iter != solution_vector.end(); map_iter++)
            {
                // int index_1 = map_iter -> first;
                // int index_2 = map_iter -> second;
                // vector< int > pair_vec;
                // pair_vec.push_back(index_1);
                // pair_vec.push_back(index_2);
                // palindromic_pairs.push_back(pair_vec);
                int index_1 = map_iter -> first;
                for(auto set_iter = map_iter -> second.begin(); set_iter != map_iter -> second.end(); set_iter++)
                {
                	vector< int > pair_vec;
                	pair_vec.push_back(index_1);
                	pair_vec.push_back(*set_iter);
                	palindromic_pairs.push_back(pair_vec);
                }
            }
            return palindromic_pairs;
        }
};

int main()
{
    Solution solution;
    vector< string > words;
    words.push_back("cbd");
    words.push_back("aadbc");
    words.push_back("bdaa");
    // solution.print_suffix_palindromes(words);
    // cout << "mile stone 1" << "\n";
    vector< vector< int > > palindrome_pairs;
    palindrome_pairs = solution.palindromePairs(words);
    // solution.print_palindromic_pairs(palindrome_pairs);

    /* Testing
    Trie_Graph* trie_graph = new Trie_Graph;
    vector< bool > test;
    test.push_back(0);
    test.push_back(0);
    test.push_back(1);
    trie_graph -> insert_nodes("bat", 0, test);
    trie_graph -> insert_nodes("tab", 0, test);
	*/

    return 0;
}