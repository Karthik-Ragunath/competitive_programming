import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

class SnakeCoup
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int testcases = in.nextInt();
        for(int i = 0; i < testcases; i++)
        {
            int numberOfColumns = in.nextInt();
            in.nextLine();
            char[][] input = new char[2][numberOfColumns];
            String input1 = in.nextLine();
            String input2 = in.nextLine();
            input[0] = input1.toCharArray();
            input[1] = input2.toCharArray();
            boolean horizontalLineUsed = false;
            horizontalLineUsed = false;
            int numberOfSoundProofWalls = 0;
            for(int j = 0; j < numberOfColumns; j++)
            {
                if(j == 0 && j == (numberOfColumns - 1))
                {
                    if(input[0][j] == '*' && input[1][j] == '*')
                    {
                        numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                        break;
                    }
                }
                else if(j != (numberOfColumns - 1))
                {
                    if(input[0][j] == '*' && input[1][j] == '*' && input[0][j + 1] == '*' && input[1][j + 1] == '*')
                    {
                        numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                        if(horizontalLineUsed == false)
                        {
                            horizontalLineUsed = true;
                            numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                        }
                    }
                    else if(input[0][j] == '*' && input[1][j] == '*' && input[0][j + 1] == '*')
                    {
                        numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                        if(horizontalLineUsed == false)
                        {
                            horizontalLineUsed = true;
                            numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                        }
                    }
                    else if(input[0][j] == '*' && input[1][j] == '*' && input[1][j + 1] == '*')
                    {
                        numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                        if(horizontalLineUsed == false)
                        {
                            horizontalLineUsed = true;
                            numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                        }
                    }
                    else if(input[0][j] == '*' && input[0][j + 1] == '*' && input[1][j + 1] == '*')
                    {
                        numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                    }
                    else if(input[0][j] == '*' && input[0][j + 1] == '*')
                    {
                        numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                    }
                    else if(input[0][j] == '*' && input[1][j + 1] == '*')
                    {
                        if(horizontalLineUsed == false)
                        {
                            horizontalLineUsed = true;
                            numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                        }
                    }
                    else if(input[1][j] == '*' && input[0][j + 1] == '*' && input[1][j + 1] == '*')
                    {
                        numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                    }
                    else if(input[1][j] == '*' && input[1][j + 1] == '*')
                    {
                        numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                    }
                    else if(input[1][j] == '*' && input[0][j + 1] == '*')
                    {
                        if(horizontalLineUsed == false)
                        {
                            horizontalLineUsed = true;
                            numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                        }
                    }
                }
                else
                {
                    if(input[0][j] == '*' && input[1][j] == '*')
                    {
                        if(horizontalLineUsed == false)
                        {
                            horizontalLineUsed = true;
                            numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                        }
                    }
                }
            }
            System.out.println(numberOfSoundProofWalls);
        }
    }
}
