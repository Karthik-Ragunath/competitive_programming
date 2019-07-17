import java.io.*;
import java.util.*;

public class Solution {
    /*
 * Complete the function below.
 */
    class Pass_By_Reference
    {
        int reference_variable;
    }
    int maximum_steps(int n,int k,int maximum,Pass_By_Reference reference,int step_count)
    {
        if(maximum==k)
        {
            return 0;
        }
        if(step_count==(n+1))
        {
            if(maximum>reference.reference_variable)
            {
                reference.reference_variable=maximum;
                return 1;
            }
        }
        else
        {
            new Solution().maximum_steps(n,k,(maximum+step_count),reference,(step_count+1));
            new Solution().maximum_steps(n,k,maximum,reference,(step_count+1));
        }
        return reference.reference_variable;
    }

    static int maxStep(int n, int k) {
        Pass_By_Reference reference=new Solution().new Pass_By_Reference();
        reference.reference_variable=0;
        int max=0;
        int step_count=1;
        int answer=new Solution().maximum_steps(n,k,max,reference,step_count);
        return answer;
    }



    public static void main(String[] args) {
        int max_ans,number_of_steps,prohibitted_step;
        Scanner in=new Scanner(System.in);
        number_of_steps=in.nextInt();
        prohibitted_step=in.nextInt();
        max_ans=new Solution().maxStep(number_of_steps,prohibitted_step);
        System.out.println(max_ans);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}