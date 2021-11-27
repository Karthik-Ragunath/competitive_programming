import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

class SnakeCoupMongoose
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
                    if(input[0][j] == '.' && input[1][j] == '.')
                    {
                        continue;
                    }
                    int k;
                    int l;
                    boolean flagship1 = false;
                    boolean flagship2 = false;
                    for(k = j + 1; k < numberOfColumns; k++)
                    {
                        if(input[0][k] == '*')
                        {
                            flagship1 = true;
                            break;
                        }
                    }
                    for(l = j + 1; l < numberOfColumns; l++)
                    {
                        if(input[1][l] == '*')
                        {
                            flagship2= true;
                            break;
                        }
                    }
                    if(flagship1 == true && flagship2 == true)
                    {
                        //System.out.println(k);
                        if(input[0][j] == '*' && input[1][j] == '*' && input[0][k] == '*' && input[1][l] == '*')
                        {
                            numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                            if(horizontalLineUsed == false)
                            {
                                horizontalLineUsed = true;
                                numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                            }
                        }
                        else if(input[0][j] == '*' && input[0][k] == '*' && input[1][l] == '*')
                        {
                            numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                            if(horizontalLineUsed == false)
                            {
                                horizontalLineUsed = true;
                                numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                            }
                        }
                        else if(input[1][j] == '*' && input[0][k] == '*' && input[1][l] == '*')
                        {
                            numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                            if(horizontalLineUsed == false)
                            {
                                horizontalLineUsed = true;
                                numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                            }
                        }
                        if(k < l)
                        {
                            j = k - 1;
                        }
                        else
                        {
                            j = l - 1;
                        }
                        continue;
                    }
                    else if (flagship1 == true)
                    {
                        if(input[0][j] == '*' && input[1][j] == '*' && input[0][k] == '*')
                        {
                            numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                            if(horizontalLineUsed == false)
                            {
                                horizontalLineUsed = true;
                                numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                            }
                        }
                        else if(input[0][j] == '*' && input[0][k] == '*')
                        {
                            numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                        }
                        else if(input[1][j] == '*' && input[0][k] == '*')
                        {
                            if(horizontalLineUsed == false)
                            {
                                horizontalLineUsed = true;
                                numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                            }
                        }
                        j = k - 1;
                    }
                    else if(flagship2 == true)
                    {
                        if(input[0][j] == '*' && input[1][j] == '*' && input[1][l] == '*')
                        {
                            numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                            if(horizontalLineUsed == false)
                            {
                                horizontalLineUsed = true;
                                numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                            }
                        }
                        else if(input[0][j] == '*' && input[1][l] == '*')
                        {
                            if(horizontalLineUsed == false)
                            {
                                horizontalLineUsed = true;
                                numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                            }
                        }
                        else if(input[1][j] == '*' && input[1][l] == '*')
                        {
                            numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                        }
                        j = l - 1;
                    }
                    else
                    {
                        if(input[0][j] == '*' && input[1][j] == '*')
                        {
                            if(horizontalLineUsed == false)
                            {
                                horizontalLineUsed = true;
                                numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                                break;
                            }
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
