class Comparator
{
	public:
		bool operator()(const pair< string, int > pair_1, const pair< string, int > pair_2) const
		{
			if(pair_1.second < pair_2.second)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};


class Trie
{
	public:
		unordered_map< char, Trie* > children_graph;
		int count;
		string word;
		Trie(int x): count(x) {}
};

class TrieGraph
{
	public:
		Trie* root = new Trie(0);
		void insert(string word)
		{
			Trie *node = root;
			for(auto ch: word)
			{
				auto find_iter = node -> children_graph.find(ch);
				if(find_iter != node -> children_graph.end())
				{
					node = find_iter -> second;
				}
				else
				{
					Trie* new_node = new Trie(0);
					node -> children_graph.insert(make_pair(ch, new_node));
					node = node -> children_graph[ch];
				}
			}
			node -> count += 1;
			node -> word = word;
		}

		// void perform_dfs(Trie* node, string &solution, int &max_val)
		// {
		// 	if(node -> count != 0 and node -> count > max_val)
		// 	{
		// 		solution = node -> word;
		// 	}
		// 	for(auto iter = node -> children_graph.begin(); iter != node -> children_graph.end(); iter++)
		// 	{
		// 		perform_dfs(node -> second, solution, max_val);
		// 	}
		// }

		// void dfs(map< string, int > &word_count, string &solution, int &max_val)
		// {
		// 	Trie *node = root;
		// 	perform_dfs(node, solution, max_val);
		// }

		void perform_dfs(Trie* node, set< pair< string, int >, Comparator > &word_pair_set, int k)
		{
			if(node -> count != 0 and node -> count > (word_pair_set.begin()) -> second)
			{
				if(word_pair_set.size() == k)
				{
					word_pair_set.erase(word_pair_set.begin());
					word_pair_set.insert(make_pair(node -> word, node -> count));
				}
				else
				{
					word_pair_set.insert(make_pair(node -> word, node -> count));
				}
			}
			for(auto iter = node -> children_graph.begin(); iter != node -> children_graph.end(); iter++)
			{
				perform_dfs(iter -> second, word_pair_set, k);
			}
		}

		void dfs(set< pair< string, int >, Comparator > &word_pair_set, int k)
		{
			Trie *node = root;
			perform_dfs(node, word_pair_set, k);
		}
};

class Solution 
{
	public:
    	vector<string> topKFrequent(vector<string>& words, int k) 
    	{
        	TrieGraph* trie_graph = new TrieGraph;
        	for(auto word: words)
        	{
        		trie_graph -> insert(word);
        	}
        	set< pair< string, int >, Comparator > word_pair_set;
        	trie_graph -> dfs(word_pair_set, k);
        	vector< string > solution;
        	for(auto rit = word_pair_set.rbegin(); rit != word_pair_set.rend(); rit++)
        	{
        		solution.push_back(rit -> first);
        	}
        	// vector< string > solution{word_pair_set.rbegin(), word_pair_set.rend()};
        	return solution;
    	}
};