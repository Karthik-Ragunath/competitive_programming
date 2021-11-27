import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

class CircularWalk
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int numberofPointsInCircle = in.nextInt();
        int startingPoint = in.nextInt();
        int endingPoint = in.nextInt();
        int initialArrayValue = in.nextInt();
        int g = in.nextInt();
        int seed = in.nextInt();
        int p = in.nextInt();
        int[] weightArray = new int[numberofPointsInCircle];
        weightArray[0] = initialArrayValue;
        for (int i=1; i< numberofPointsInCircle; i++)
        {
            weightArray[i] = (weightArray[i - 1] * g + seed) % p;
        }
        Queue<Integer> = new ArrayDeque<Integer>();
        Queue.add(startingPoint);
        while(!Queue.isEmpty())
        {
            int head = Queue.poll()
            
        }
    }
}
