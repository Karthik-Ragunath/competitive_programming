import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

class SnakeVsMongooseFinal
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
                    boolean flagship11 = false;
                    boolean flagship2 = false;
                    boolean flagship22 = false;
                    int position1 = 0;
                    int position11 = 0;
                    int position2 = 0;
                    int position22 = 0;
                    for(k = j + 1; k < numberOfColumns; k++)
                    {
                        if(input[0][k] == '*' && (flagship1 == false || flagship11 == false))
                        {
                            if(flagship1 == false)
                            {
                                flagship1 = true;
                                position1 = k;
                            }
                            else
                            {
                                flagship11 = true;
                                position11 = k;
                                break;
                            }
                        }
                    }
                    for(l = j + 1; l < numberOfColumns; l++)
                    {
                        if(input[1][l] == '*' && (flagship2 == false || flagship22 == false))
                        {
                            if(flagship2 == false)
                            {
                                flagship2 = true;
                                position2 = l;
                            }
                            else
                            {
                                flagship22 = true;
                                position22 = l;
                                break;
                            }
                        }
                    }
                    if(position1 < position2)
                    {
                        if(flagship11 == true && position11 < position2)
                        {
                            flagship2 = false;
                            k = position1;
                        }
                        else
                        {
                            k = position1;
                            l = position2;
                        }
                        //System.out.println("1. K: " + k +" L: " + l);
                    }
                    else if(position2 < position1)
                    {
                        if(flagship22 == true && position22 < position1)
                        {
                            flagship1 = false;
                            l = position2;
                        }
                        else
                        {
                            l = position2;
                            k = position1;
                        }
                        //System.out.println("2. K: " + k +" L: " + l);
                    }
                    else
                    {
                        k = position1;
                        l = position2;
                        //System.out.println("3. K: " + k +" L: " + l);
                    }
                    if(flagship1 == true && flagship2 == true)
                    {
                        if(k == l)
                        {
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
                            j = k - 1;
                        }
                        else if(k < l)
                        {
                            boolean verticalLineUsed = false;
                            if(input[0][j] == '*' && input[1][j] == '*' && input[0][k] == '*')
                            {
                                numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                                verticalLineUsed = true;
                                if(horizontalLineUsed == false)
                                {
                                    horizontalLineUsed = true;
                                    numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                                }
                            }
                            else if(input[0][j] == '*' && input[0][k] == '*')
                            {
                                numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                                verticalLineUsed = true;
                            }
                            else if(input[1][j] == '*' && input[0][k] == '*')
                            {
                                if(horizontalLineUsed == false)
                                {
                                    horizontalLineUsed = true;
                                    numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                                }
                            }

                            if(input[0][j] == '*' && input[1][j] == '*' && input[1][l] == '*')
                            {
                                if(verticalLineUsed == false)
                                {
                                    numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                                    verticalLineUsed = true;
                                }
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
                                if(verticalLineUsed == false)
                                {
                                    numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                                    verticalLineUsed = true;
                                }
                            }
                            j = k - 1;
                        }
                        else
                        {
                            boolean verticalLineUsed = false;
                            if(input[0][j] == '*' && input[1][j] == '*' && input[1][l] == '*')
                            {
                                numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                                verticalLineUsed = true;
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
                                    //System.out.print(" " + j);
                                }
                            }
                            else if(input[1][j] == '*' && input[1][l] == '*')
                            {
                                numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                                verticalLineUsed = true;
                            }

                            if(input[0][j] == '*' && input[1][j] == '*' && input[0][k] == '*')
                            {
                                if(verticalLineUsed == false)
                                {
                                    numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                                    verticalLineUsed = true;
                                }
                                if(horizontalLineUsed == false)
                                {
                                    horizontalLineUsed = true;
                                    numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                                }
                            }
                            else if(input[0][j] == '*' && input[0][k] == '*')
                            {
                                if(verticalLineUsed == false)
                                {
                                    numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                                    //System.out.print(" " + j);
                                }
                            }
                            else if(input[1][j] == '*' && input[0][k] == '*')
                            {
                                if(horizontalLineUsed == false)
                                {
                                    horizontalLineUsed = true;
                                    numberOfSoundProofWalls = numberOfSoundProofWalls + 1;
                                }
                            }
                            j = l - 1;
                        }
                        /*
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
                        */
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
