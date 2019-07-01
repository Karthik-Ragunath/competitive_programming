import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class PenaltyShootout
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        while(in.hasNext())
        {
            String input = in.next();
            int chefGoals = 0;
            int opponentGoals = 0;
            boolean resultFound = false;
            for(int i = 0; i < 6; i++)
            {
                if(i % 2 == 0)
                {
                    if(input.charAt(i) == '1')
                    {
                        chefGoals += 1;
                    }
                }
                else
                {
                    if(input.charAt(i) == '1')
                    {
                        opponentGoals += 1;
                    }
                }
            }
            if(chefGoals > opponentGoals)
            {
                if(chefGoals - opponentGoals == 3)
                {
                    System.out.println("TEAM-A 6");
                    continue;
                }
            }
            else
            {
                if(opponentGoals - chefGoals == 3)
                {
                    System.out.println("TEAM-B 6");
                    continue;
                }
            }
            for(int i = 6; i < 10; i++)
            {
                if(i == 6)
                {
                    if(input.charAt(i) == '1')
                    {
                        chefGoals += 1;
                        if(chefGoals - opponentGoals >= 3)
                        {
                            System.out.println("TEAM-A 7");
                            resultFound = true;
                            break;
                        }
                    }
                    else
                    {
                        if(opponentGoals - chefGoals >= 2)
                        {
                            System.out.println("TEAM-B 7");
                            resultFound = true;
                            break;
                        }
                    }
                }
                else if(i == 7)
                {
                    if(input.charAt(i) == '1')
                    {
                        opponentGoals += 1;
                        if(opponentGoals - chefGoals >= 2)
                        {
                            System.out.println("TEAM-B 8");
                            resultFound = true;
                            break;
                        }
                    }
                    else
                    {
                        if(chefGoals - opponentGoals >= 2)
                        {
                            System.out.println("TEAM-A 8");
                            resultFound = true;
                            break;
                        }
                    }
                }
                else if(i == 8)
                {
                    if(input.charAt(i) == '1')
                    {
                        chefGoals += 1;
                        if(chefGoals - opponentGoals >= 2)
                        {
                            System.out.println("TEAM-A 9");
                            resultFound = true;
                            break;
                        }
                    }
                    else
                    {
                        if(opponentGoals - chefGoals >= 1)
                        {
                            System.out.println("TEAM-B 9");
                            resultFound = true;
                            break;
                        }
                    }
                }
                else if(i == 9)
                {
                    if(input.charAt(i) == '1')
                    {
                        opponentGoals += 1;
                        if(opponentGoals - chefGoals >= 1)
                        {
                            System.out.println("TEAM-B 10");
                            resultFound = true;
                            break;
                        }
                    }
                    else
                    {
                        if(chefGoals - opponentGoals >= 1)
                        {
                            System.out.println("TEAM-A 10");
                            resultFound = true;
                            break;
                        }
                    }
                }
            }
            if(!resultFound)
            {
                for(int i = 10; i < 20; i++)
                {
                    if(i % 2 == 0)
                    {
                        if(input.charAt(i) == '1')
                        {
                            chefGoals += 1;
                        }
                    }
                    else
                    {
                        if(input.charAt(i) == '1')
                        {
                            opponentGoals += 1;
                        }
                        int endingKick = i + 1;
                        if(chefGoals - opponentGoals >= 1)
                        {
                            System.out.println("TEAM-A " + endingKick);
                            resultFound = true;
                            break;
                        }
                        else if(opponentGoals - chefGoals >= 1)
                        {
                            System.out.println("TEAM-B " + endingKick);
                            resultFound = true;
                            break;
                        }
                    }
                }
                if(!resultFound)
                {
                    System.out.println("TIE");
                }
            }
        }
    }
}
