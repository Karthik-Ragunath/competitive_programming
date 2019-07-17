/*
 * Complete the function below.
 */

    static long countX(String[] steps) {
        int length=steps.length;
        int[][] matrix=new int[length][2];
        for(int i=0;i<length;i++)
        {
            String[] splitter=steps[i].split(" ");
            matrix[i][0]=Integer.parseInt(splitter[0]);
            matrix[i][1]=Integer.parseInt(splitter[1]);
        }
        int row_max=0;
        int column_max=0;
        for(int i=0;i<length;i++)
        {
            if(matrix[i][0]>row_max)
            {
                row_max=matrix[i][0];
            }
            if(matrix[i][1]>column_max)
            {
                column_max=matrix[i][1];
            }
        }
        int[][] new_matrix=new int[row_max][column_max];
        for(int i=0;i<length;i++)
        {
            int temp_row=matrix[i][0];
            int temp_column=matrix[i][1];
            int row_counter=temp_row;
            int column_counter=temp_column;
            for(int k=(row_max-1);row_counter>0;k--)
            {
                for(int j=0;j<column_counter;j++)
                {
                    new_matrix[k][j]=new_matrix[k][j]+1;
                }
                row_counter=row_counter-1;
            }
        }
        long ans_counter=0;
        for(int i=0;i<row_max;i++)
        {
            for(int j=0;j<column_max;j++)
            {
                if(new_matrix[i][j]==length)
                {
                    ans_counter=ans_counter+1;
                }
            }
        }
        return ans_counter;
    }

