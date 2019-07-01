import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

class SameSnake
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int numberOfInputs = in.nextInt();
        for(int i = 0; i < numberOfInputs; i++)
        {
            int[] snake1 = new int[4];
            int[] snake2 = new int[4];
            boolean xVariationSnake1 = true;
            boolean xVariationSnake2 = true;
            for(int j = 0; j < 4; j++)
            {
                snake1[j] = in.nextInt();
                if(j == 2)
                {
                    if(snake1[0] == snake1[j])
                    {
                        xVariationSnake1 = false;
                    }
                }
            }
            for(int k = 0; k < 4; k++)
            {
                snake2[k] = in.nextInt();
                if(k == 2)
                {
                    if(snake2[0] == snake2[k])
                    {
                        xVariationSnake2 = false;
                    }
                }
            }
            boolean solution = false;
            if(xVariationSnake1 == xVariationSnake2)
            {
                if(xVariationSnake1 == true)
                {
                    if(snake1[0] < snake1[2])
                    {
                        if(snake2[0] >= snake1[0] && snake2[0] <= snake1[2])
                        {
                            solution = true;
                        }
                        else if(snake2[2] >= snake1[0] && snake2[2] <= snake1[2])
                        {
                            solution = true;
                        }
                    }
                    else
                    {
                        if(snake2[0] >= snake1[2] && snake2[0] <= snake1[0])
                        {
                            solution = true;
                        }
                        else if(snake2[2] >= snake1[2] && snake2[2] <= snake1[0])
                        {
                            solution = true;
                        }
                    }
                }
                else
                {
                    if(snake1[1] < snake1[3])
                    {
                        if(snake2[1] >= snake1[1] && snake2[1] <= snake1[3])
                        {
                            solution = true;
                        }
                        else if(snake2[3] >= snake1[1] && snake2[3] <= snake1[3])
                        {
                            solution = true;
                        }
                    }
                    else
                    {
                        if(snake2[1] >= snake1[3] && snake2[1] <= snake1[1])
                        {
                            solution = true;
                        }
                        else if(snake2[3] >= snake1[3] && snake2[3] <= snake1[1])
                        {
                            solution = true;
                        }
                    }
                }
            }
            else
            {
                solution = true;
                if(xVariationSnake1 == true)
                {
                    if(snake1[0] < snake1[2])
                    {
                        if(snake2[0] > snake1[0] && snake2[0] < snake1[2])
                        {
                            solution = false;
                        }
                        else if (snake2[2] > snake1[0] && snake2[2] < snake1[2])
                        {
                            solution = false;
                        }
                    }
                    else
                    {
                        if(snake2[0] > snake1[2] && snake2[0] < snake1[0])
                        {
                            solution = false;
                        }
                        else if (snake2[2] > snake1[2] && snake2[2] < snake1[0])
                        {
                            solution = false;
                        }
                    }
                }
                else
                {
                    if(snake1[1] < snake1[3])
                    {
                        if(snake2[1] > snake1[1] && snake2[1] < snake1[3])
                        {
                            solution = false;
                        }
                        else if (snake2[3] > snake1[1] && snake2[3] < snake1[3])
                        {
                            solution = false;
                        }
                    }
                    else
                    {
                        if(snake2[1] > snake1[3] && snake2[1] < snake1[1])
                        {
                            solution = false;
                        }
                        else if (snake2[3] > snake1[3] && snake2[3] < snake1[1])
                        {
                            solution = false;
                        }
                    }
                }
            }
            if (solution == true)
            {
                System.out.println("YES");
            }
            else
            {
                System.out.println("NO");
            }
        }
    }
}
