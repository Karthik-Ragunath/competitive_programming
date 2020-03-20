// https://leetcode.com/problems/combination-sum/
class Solution 
{
	public:
    	vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    	{
        	sort(candidates.begin(), candidates.end());
            vector< int > current_combo;
            vector< vector< int > > solution;
            form_combinations(candidates, target, current_combo, solution, 0);
        	return solution;
    	}

    	void form_combinations(vector< int > &candidates, int target, vector< int > &current_combo, vector< vector< int > > &solution, int candidate_index)
    	{
    		if(target == 0)
    		{
                // cout << "target reached" << "\n";
    			solution.push_back(current_combo);
    		}
    		else if(target < 0)
    		{
    			return;
    		}
    		for(int i = candidate_index; i < candidates.size(); i++)
    		{
    			current_combo.push_back(candidates[i]);
    			form_combinations(candidates, target - candidates[i], current_combo, solution, i);
    			current_combo.pop_back();
    		}
    	}
};