class Comparator
{
    public:
        bool operator()(const int val_1, const int val_2)
        {
            if(val_1 > val_2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

class Solution {
public:
    int summit(vector< int > &vec)
    {
        int sum = 0;
        for(auto val: vec)
        {
            sum += val;
        }
        return sum;
    }
    int connectSticks(vector<int>& sticks) {
        sort(sticks.begin(), sticks.end());
        // int local_max = sticks[0];
        // int global_max = 0;
        // vector< int > local_vals;
        // for(int i = 1; i < sticks.size(); i++)
        // {
        //     local_max += sticks[i];
        //     global_max += local_max;
        //     local_vals.push_back(local_max);
        //     cout << sticks[i] << " " << local_max << " " << global_max << "\n";
        // }
        // int sol = summit(local_vals);
        // cout << "sol: " << sol << "\n";
        // if(sticks.size() == 1)
        // {
        //     global_max = local_max;
        // }
        // return global_max;
        priority_queue< int, vector< int > , Comparator > pq(sticks.begin(), sticks.end());
        cout << pq.size() << " " << sticks[0] << "\n";
        if(pq.size() <= 0)
        {
            return 0;
        }
        int solution = 0;
        while(pq.size() > 1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            solution += (x + y);
            pq.push(x + y);
        }
        return solution;
        
    }
};