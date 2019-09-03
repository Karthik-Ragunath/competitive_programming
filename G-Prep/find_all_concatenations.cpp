class Trie
{
	public:
		unordered_map< char, Trie* > trie_map;
		int ending_index;
		Trie() : ending_index(-1) {}
};

class TrieGraph
{
	public:
		Trie *root = new Trie();
		void insert(string word)
		{

		}

		bool search(string word)
		{

		}
};

class CompareNodes
{
	public:
		bool operator(const string &string_1, const string &string_2) const
		{
			return string_1.length() < string_2.length();
		}
};

class Solution 
{
	public:
    	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    	{
        	sort(words.begin(), words.end(), CompareNodes());
        	TrieGraph *trie_graph = new TrieGraph();
        	for(int i = 0; i < words; i++)
        	{
        		bool is_concatenated_string = search(word);
        		
        	}
    	}
};