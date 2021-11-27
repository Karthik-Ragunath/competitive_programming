import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;


class SkiNode
{
    int index;
    int value;
}

public class DeepSkiingDFS implements Runnable
{
        public static void DFS(int rows, int columns, int[][] grid, boolean[][] visited, int index, int xIndex, int yIndex, int[][] values)
    {
        visited[xIndex][yIndex] = true;
        if(xIndex + 1 < rows)
        {
            if(!visited[xIndex + 1][yIndex] && (values[xIndex + 1][yIndex] <= values[xIndex][yIndex]))
            {
                int indexNew = (xIndex + 1) * columns + yIndex;
                DFS(rows, columns, grid, visited, indexNew, (xIndex + 1), yIndex, values);
            }
        }
        if(xIndex - 1 >= 0)
        {
            if(!visited[xIndex - 1][yIndex] && (values[xIndex - 1][yIndex] <= values[xIndex][yIndex]))
            {
                int indexNew = (xIndex - 1) * columns + yIndex;
                DFS(rows, columns, grid, visited, indexNew, (xIndex - 1), yIndex, values);
            }
        }
        if(yIndex + 1 < columns)
        {
            if(!visited[xIndex][yIndex + 1] && (values[xIndex][yIndex + 1] <= values[xIndex][yIndex]))
            {
                int indexNew = xIndex * columns + (yIndex + 1);
                DFS(rows, columns, grid, visited, indexNew, xIndex, (yIndex + 1), values);
            }
        }
        if(yIndex - 1 >= 0)
        {
            if(!visited[xIndex][yIndex - 1] && (values[xIndex][yIndex - 1] <= values[xIndex][yIndex]))
            {
                int indexNew = xIndex * columns + (yIndex - 1);
                DFS(rows, columns, grid, visited, indexNew, xIndex, (yIndex - 1), values);
            }
        }
    }

    public static void main(String[] args)
    {
        new Thread(null, new DeepSkiingDFS(), "whatever", 1<<26).start();
    }

    public void run()
    {
        // Do whatever you want in this function instead of main
        int testcases;
        Scanner in = new Scanner(System.in);
        testcases = in.nextInt();
        for(int l = 0; l < testcases; l++)
        {
            int rows = in.nextInt();
            int columns = in.nextInt();
            int[][] grid = new int[rows][columns];
            int[][] values = new int[rows][columns];
            ArrayList<SkiNode> skicells = new ArrayList<SkiNode>();
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < columns; j++)
                {
                    grid[i][j] = in.nextInt();
                    values[i][j] = grid[i][j];
                    SkiNode skicell = new SkiNode();
                    skicell.index = i * columns + j;
                    skicell.value = grid[i][j];
                    skicells.add(skicell);
                }
            }
            boolean[][] visited = new boolean[rows][columns];
            Collections.sort(skicells, new Comparator<SkiNode>()
            {
                public int compare(SkiNode left, SkiNode right)
                {
                    if(left.value < right.value)
                    {
                        return 1;
                    }
                    else if(left.value > right.value)
                    {
                        return -1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            });
            Iterator skicellsIter = skicells.iterator();
            int counter = 0;
            while(skicellsIter.hasNext())
            {
                SkiNode cell = (SkiNode)skicellsIter.next();
                int index = cell.index;
                int xIndex = index / columns;
                int yIndex = index % columns;
                if(!visited[xIndex][yIndex])
                {
                    counter++;
                    DFS(rows, columns, grid, visited, index, xIndex, yIndex, values);
                }
            }
            System.out.println(counter);
        }
    }
}
