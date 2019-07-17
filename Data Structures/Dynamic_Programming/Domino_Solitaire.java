import java.io.*;
import java.math.*;
import java.lang.*;
import java.util.*;
class Domino_Solitaire{
    public static void main(String[] args){
        int number_of_tiles;
        Scanner in=new Scanner(System.in);
        number_of_tiles=in.nextInt();
        int[][] input=new int[2][number_of_tiles];
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<number_of_tiles;j++)
            {
                input[i][j]=in.nextInt();
                //System.out.println(input[i][j]);
            }
        }
        if(number_of_tiles==1)
        {
            int answer=(Math.abs(input[0][0]-input[1][0]));
            System.out.println(answer);
            return;
        }
        int[] answer=new int[number_of_tiles];
        answer[0]=Math.abs(input[0][0]-input[1][0]);
        answer[1]=Math.max((answer[0]+(Math.abs(input[0][1]-input[1][1]))),((Math.abs(input[0][0]-input[0][1]))+(Math.abs(input[1][0]-input[1][1]))));
        for(int i=2;i<number_of_tiles;i++)
        {
            answer[i]=Math.max((answer[i-1]+((Math.abs(input[0][i]-input[1][i])))),(answer[i-2]+((Math.abs(input[0][i-1]-input[0][i])))+((Math.abs(input[1][i-1]-input[1][i])))));
        }
        int real_answer=answer[number_of_tiles-1];
        System.out.println(real_answer);
    }
}