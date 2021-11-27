import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class Node
{
    int rating;
    int minimumRating;
    int maximumRating;
    int timeControl;
    boolean isRated;
    int color;
    int index;
}
class OnlineChess
{
    public static boolean matcher(Node node1, Node node2)
    {
        if(node1.rating <= node2.maximumRating && node1.rating >= node2.minimumRating && node2.rating <= node1.maximumRating && node2.rating >= node1.minimumRating)
        {
            if(node1.timeControl == node2.timeControl && node1.isRated == node2.isRated)
            {
                if((node1.color == 1 && node2.color == 1) || (node1.color == -1 && node2.color == -1) || (node1.color == 0 && node2.color != 0) || (node1.color != 0 && node2.color == 0))
                {
                    return false;
                }
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args)
    {
        int testcases;
        Scanner in = new Scanner(System.in);
        testcases = in.nextInt();
        String rated = "rated";
        String unrated = "unrated";
        String white = "white";
        String black = "black";
        String random = "random";
        for(int m = 0; m < testcases; m++)
        {
            int numberOfValues = in.nextInt();
            ArrayList<Node> onlinePlayers = new ArrayList<Node>();
            int sizeOfArrayList = 0;
            for(int i = 0; i < numberOfValues; i++)
            {
                Node node = new Node();
                node.index = i + 1;
                node.rating = in.nextInt();
                node.minimumRating = in.nextInt();
                node.maximumRating = in.nextInt();
                node.timeControl = in.nextInt();
                String matchType = in.next();
                if(rated.equals(matchType))
                {
                    node.isRated = true;
                }
                else
                {
                    node.isRated = false;
                }
                String color = in.next();
                if(white.equals(color))
                {
                    node.color = 1;
                }
                else if(black.equals(color))
                {
                    node.color = -1;
                }
                else
                {
                    node.color = 0;
                }
                boolean matchExists = false;
                int index = -1;
                int solution = -1;
                for(int j = 0; j < sizeOfArrayList; j++)
                {
                    Node compareNode = onlinePlayers.get(j);
                    boolean matchFound = matcher(compareNode, node);
                    if(matchFound)
                    {
                        matchExists = true;
                        index = j;
                        solution = compareNode.index;
                        break;
                    }
                }
                if(matchExists)
                {
                    onlinePlayers.remove(index);
                    sizeOfArrayList--;
                    System.out.println(solution);
                }
                else
                {
                    onlinePlayers.add(node);
                    sizeOfArrayList++;
                    System.out.println("wait");
                }
            }
        }
    }
}
