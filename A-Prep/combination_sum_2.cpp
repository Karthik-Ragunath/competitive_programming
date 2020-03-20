// https://leetcode.com/problems/combination-sum-ii/submissions/
class Solution 
{
	public:
    	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
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
            int prev = -1;
    		for(int i = candidate_index; i < candidates.size(); i++)
    		{
                if(candidates[i] == prev)
                {
                    continue;
                }
    			current_combo.push_back(candidates[i]);
    			form_combinations(candidates, target - candidates[i], current_combo, solution, i + 1);
    			current_combo.pop_back();
                prev = candidates[i];
    		}
    	}
};