import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

class FightTheMonsters
{
   public static void main(String[] args)
   {
      Scanner in = new Scanner(System.in);
      int numberOfMonsters;
      int blasterPower;
      int seconds;
      numberOfMonsters = in.nextInt();
      blasterPower = in.nextInt();
      seconds = in.nextInt();
      int[] monsterPowerLevel = new int[numberOfMonsters];
      for (int i = 0; i < numberOfMonsters; i++)
      {
         monsterPowerLevel[i] = in.nextInt();
      }
      Arrays.sort(monsterPowerLevel);
      int monsterIndex = 0;
      int numberOfMonsterKilled = 0;
      int timeLeft = seconds;
      while(true)
      {
         int timeTaken = monsterPowerLevel[monsterIndex] / blasterPower;
         if (monsterPowerLevel[monsterIndex] % blasterPower != 0)
         {
            timeTaken = timeTaken + 1;
         }
         timeLeft = timeLeft - timeTaken;
         if (timeLeft < 0)
         {
            break;
         }
         else
         {
            numberOfMonsterKilled = numberOfMonsterKilled + 1;
            monsterIndex = monsterIndex + 1;
         }
      }
      System.out.println(numberOfMonsterKilled);
   }
}
