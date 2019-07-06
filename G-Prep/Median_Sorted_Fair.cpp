class Solution 
{
  public:
     double return_solution(vector< int > &nums1, vector< int > &nums2, int length_1, int length_2, int min_length, int max_length, bool is_even)
     {
          double solution = -1;
          int left_half_len = (length_1 + length_2 + 1) / 2;
          while(min_length <= max_length)
          {
              int mid_index = min_length + (max_length - min_length) / 2;
              int index_to_look_at = left_half_len - mid_index;
              if(mid_index > 0 && nums2[mid_index - 1] > nums1[index_to_look_at])
              {
                  max_length = mid_index - 1;
              }
              else if(mid_index < length_2 && nums1[index_to_look_at - 1] > nums2[mid_index])
              {
                  min_length = mid_index + 1;
              }
              else
              {
                  int left_half_last_value = mid_index == 0 ? nums1[index_to_look_at - 1] : index_to_look_at == 0 ? nums2[mid_index - 1] : max(nums2[mid_index - 1], nums1[index_to_look_at - 1]);
                  solution = (double)left_half_last_value;
                  cout << "mile stone1 " << left_half_last_value << "\n";
                  if(!is_even)
                  {
                      return solution;
                  }
                  int right_half_first_value = mid_index == length_2 ? nums1[index_to_look_at] : index_to_look_at == length_1 ? nums2[mid_index] : min(nums2[mid_index], nums1[index_to_look_at]);
                  solution = (solution + (double(right_half_first_value))) / 2;
                  return solution;
              }
          }
           return solution;
     }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int length_1 = nums1.size();
        int length_2 = nums2.size();
        bool is_even = false;
        if((length_1 + length_2) % 2 == 0)
        {
            is_even = true;
        }
        bool is_num2_min = false;
        int min_length, max_length;
        if(length_1 >= length_2)
        {
            min_length = 0;
            max_length = length_2;
            is_num2_min = true;
        }
        else
        {
            min_length = 0;
            max_length = length_1;
            is_num2_min = false;
        }
        double solution = -1;
        if(is_num2_min)
        {
            solution = return_solution(nums1, nums2, length_1, length_2, min_length, max_length, is_even);
        }
        else
        {
            solution = return_solution(nums2, nums1, length_2, length_1, min_length, max_length, is_even);
        }
        return solution;
    }
};