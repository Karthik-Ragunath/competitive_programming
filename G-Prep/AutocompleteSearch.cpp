class TrieNode
{
	public:
		Trie *root = new Trie(0);
		Trie *search_node = new Trie(0);
		void insert(string word, bool is_new_sequence)
		{
			Trie *node = root;
			int word_length = word.length();
			for(int i = 0; i < word_length; i++)
			{
				char cur_char = word[i];
				auto find_iter = node.trie_children.find(cur_char);
				if(find_iter != node.trie_children.end())
				{
					node = find_iter -> second;
				}
				else
				{
					Trie *temp_node = new Trie(0);
					node.trie_children.insert(make_pair(cur_char, temp_node));
					node = temp_node;
				}

				if(i == word_length - 1)
				{
					node.count += 1;
					node.word = word;
				}
			}
		}

		void dfs_lookup(string s, bool should_initialize, map< string, int > &sorted_lookup_map, Trie *dfs_node)
		{
			if(should_initialize)
			{
				dfs_node = root;
				should_initialize = false;
				char starting_char = s[0];
				auto find_iter = dfs_node.trie_children.find(starting_char);
				if(find_iter != dfs_node.end())
				{
					dfs_node = root[starting_char];
				}
			}
			for(auto key_val_iter: dfs_node.trie_children)
			{
				if(key_val_iter -> second.count != 0)
				{
					sorted_lookup_map.insert(make_pair(key_val_iter.second.word, key_val_iter.second.count));
					dfs_lookup(s, should_initialize, sorted_lookup_map, dfs_node -> second);
				}
			}
		}

		void search(string word, bool is_new_sequence, map< string, int > &sorted_lookup_map)
		{
			if(is_new_sequence)
			{
				search_node = root;
				is_new_sequence = false;
				Trie *dfs_node = new Trie(0);
				dfs_lookup(word, true, sorted_lookup_map, dfs_node);
			}
			int word_length = word.length();
			for(int i = 0; i < word_length; i++)
			{
				char cur_char = word[i];
				if(cur_char == '#')
				{
					search_node.count += 1;
					search_node.word = word;
				}
				auto find_iter = search_node.trie_children.find(cur_char);
				if(find_iter != search_node.trie_children.end())
				{
					search_node = find_iter -> second;
				}
				else
				{
					Trie *temp_node = new Trie(0);
					search.trie_children.insert(make_pair(cur_char, temp_node));
					search_node = temp_node;
				}
				vector< string > solution;
				for(auto iter = sorted_lookup_map.begin(); iter != sorted_lookup_map.end();)
				{
					string mapped_word = sorted_lookup_map -> first;
					if(mapped_word[i] == cur_char)
					{
						iter++;
						if(solution.size() < 3)
						{
							solution.push_back(mapped_word);
						}
					}
					else
					{
						iter = sorted_lookup_map.erase(iter);
					}
				}
			}
			return solution;
		}
}

class Trie
{
	public:
		unordered_map< char, TrieNode* > trie_children;
		int count;
		string word;
		Trie(int x) : count(x) {}
}

class AutocompleteSystem 
{
public:

    AutocompleteSystem(vector<string>& sentences, vector<int>& times) 
    {
    		    
    }
    
    vector<string> input(char c) {
        
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */