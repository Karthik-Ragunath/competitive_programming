import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

class Node
{
    int count;
    Node next;
    int row;
    int column;
}

class IsItASnake
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int testcases = in.nextInt();
        for(int k = 0; k < testcases; k++)
        {
            int columns = in.nextInt();
            int count = 0;
            int counter = 0;
            in.nextLine();
            String[] inputString = new String[2];
            for(int i = 0; i < 2; i++)
            {
                inputString[i] = in.nextLine();
            }
            char[][] inputArray = new char[2][columns];
            for(int i = 0; i < 2; i++)
            {
                inputArray[i] = inputString[i].toCharArray();
            }
            boolean[][] dfsChecker = new boolean[2][columns];
            //System.out.println("-------------------");
            for(int i = 0; i < 2; i++)
            {
                for(int j = 0; j < columns; j++)
                {
                    if(inputArray[i][j] == '#')
                    {
                        count = count + 1;
                    }
                    dfsChecker[i][j] = false;
                    //System.out.println(inputArray[i][j]);
                }
            }
            //System.out.println("-------------------");
            Node root = new Node();
            boolean loopBreaker = false;
            for(int i = 0; i < columns; i++)
            {
                for(int j = 0; j < 2; j++)
                {
                    if(inputArray[j][i] == '#')
                    {
                        root.count = counter + 1;
                        counter = counter + 1;
                        root.next = null;
                        root.row = j;
                        root.column = i;
                        dfsChecker[j][i] = true;
                        loopBreaker = true;
                        break;
                    }
                }
                if(loopBreaker == true)
                {
                    break;
                }
            }
            boolean flagship = true;
            while(root.count != 0)
            {
                if(root.count == count)
                {
                    break;
                }
                if(flagship == false)
                {
                    break;
                }
                flagship = false;
                int row = root.row;
                int column = root.column;
                //System.out.println("***********");
                //System.out.println("Columns :" + columns);
                //System.out.println("Row: " + row +" Column: " + column);
                if(row == 0)
                {
                    if(dfsChecker[row + 1][column] == false && inputArray[row + 1][column] == '#')
                    {
                        dfsChecker[row + 1][column] = true;
                        root.next = new Node();
                        int tempCount = root.count;
                        root.next.next = null;
                        root = root.next;
                        root.row = row + 1;
                        root.column = column;
                        root.count = tempCount + 1;
                        flagship = true;
                        if(root.count == count)
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else if(column != (columns - 1) && dfsChecker[row][column + 1] == false && inputArray[row][column + 1] == '#')
                    {
                        //System.out.println("In row 0 Column ++");
                        dfsChecker[row][column + 1] = true;
                        int tempCount = root.count;
                        root.next = new Node();
                        root.next.next = null;
                        root = root.next;
                        root.row = row;
                        root.column = column + 1;
                        root.count = tempCount + 1;
                        flagship = true;
                        if(root.count == count)
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else if(column != 0 && dfsChecker[row][column - 1] == false && inputArray[row][column - 1] == '#')
                    {
                        dfsChecker[row][column - 1] = true;
                        int tempCount = root.count;
                        root.next = new Node();
                        root.next.next = null;
                        root = root.next;
                        root.row = row;
                        root.column = column - 1;
                        root.count = tempCount + 1;
                        flagship = true;
                        if(root.count == count)
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                else
                {
                    if(dfsChecker[row - 1][column] == false && inputArray[row - 1][column] == '#')
                    {
                        dfsChecker[row - 1][column] = true;
                        root.next = new Node();
                        int tempCount = root.count;
                        root.next.next = null;
                        root = root.next;
                        root.row = row - 1;
                        root.column = column;
                        root.count = tempCount + 1;
                        flagship = true;
                        if(root.count == count)
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else if(column != (columns - 1) && dfsChecker[row][column + 1] == false && inputArray[row][column + 1] == '#')
                    {
                        dfsChecker[row][column + 1] = true;
                        int tempCount = root.count;
                        root.next = new Node();
                        root.next.next = null;
                        root = root.next;
                        root.row = row;
                        root.column = column + 1;
                        root.count = tempCount + 1;
                        flagship = true;
                        if(root.count == count)
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else if(column != 0 && dfsChecker[row][column - 1] == false && inputArray[row][column - 1] == '#')
                    {
                        dfsChecker[row][column - 1] = true;
                        int tempCount = root.count;
                        root.next = new Node();
                        root.next.next = null;
                        root = root.next;
                        root.row = row;
                        root.column = column - 1;
                        root.count = tempCount + 1;
                        flagship = true;
                        if(root.count == count)
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
            if(flagship == true && root.count == count)
            {
                System.out.println("yes");
            }
            else
            {
                System.out.println("no");
            }
        }
    }
}
