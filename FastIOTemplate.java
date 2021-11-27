import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class RedPoints
{
    int x;
    int y;
}
class RedBlueAngularSweep
{
    static FastReader in;
    public static void main(String[] args)
    {
        in = new FastReader();
        int testcases;
        testcases = nextInt();
        for(int i = 0; i < testcases; i++)
        {
            int redPoints;
            int bluePoints;
            redPoints = nextInt();
            bluePoints = nextInt();
            RedPoints[] redPointsCoordinates = new RedPoints[redPoints];
            BluePoints[] bluePointsCoordinates = new BluePoints[bluePoints];

            for(int j = 0; j < redPoints; j++)
            {
                redPointsCoordinates[j].x = nextInt();
                redPointsCoordinates[j].y = nextInt();
            }

            for(int j = 0; j < bluePoints; j++)
            {
                bluepointsCoordinates[j].x = nextInt();
                bluepointsCoordinates[j].j = nextInt();
            }

            ArrayList<Double> quadrant1Blue = new ArrayList<Double>();
            ArrayList<Double> quadrant2Blue = new ArrayList<Double>();
            ArrayList<Double> quadrant3Blue = new ArrayList<Double>();
            ArrayList<Double> quadrant4Blue = new ArrayList<Double>();

            ArrayList<Double> quadrant1Red = new ArrayList<Double>();
            ArrayList<Double> quadrant2Red = new ArrayList<Double>();
            ArrayList<Double> quadrant3Red = new ArrayList<Double>();
            ArrayList<Double> quadrant4Red = new ArrayList<Double>();

            ArrayList<Double> quadrant1 = new ArrayList<Double>();
            ArrayList<Double> quadrant2 = new ArrayList<Double>();
            ArrayList<Double> quadrant3 = new ArrayList<Double>();
            ArrayList<Double> quadrant4 = new ArrayList<Double>();

            int minimumSolution = 0;
            double[][][] blueRedAngles = new double[bluePoints][redPoints][2];
            for(int j = 0; j < bluePoints; j++)
            {
                //For everyline formed by red and blue point check how many redpoints and bluePonts are in the given region (either above or below)
                //and find the min of (red + blue points above) and (red + blue points below) and print the desired answer.
                //Binary search should be used to answer the queries.
                for(int k = 0; k < redPoints; k++)
                {
                    double angle = Math.atan2((redPointsCoordinates[k].y - bluePointsCoordinates[j].y), (redPointsCoordinates[k].x - bluePointsCoordinates[j].x)) * 180 / Math.PI;
                    double interceptAngleQuadrant1 = angle + 180 % 360;
                    double interceptAngleQuadrant2 = interceptQuadrant1 + 180 % 360;
                    blueRedAngles[j][k][0] = interceptAngleQuadrant1;
                    blueRedAngles[j][k][1] = interceptAngleQuadrant2;
                    if(interceptAngleQuadrant1 > 0 && interceptAngleQuadrant1 <= 90)
                    {
                        //Quadrant 1 and the other end is in quadrant 3.
                        quadrant1Red.add(interceptAngleQuadrant1);
                        quadrant3Red.add(interceptAngleQuadrant2);
                        quadrant1.add(interceptAngleQuadrant1);
                        quadrant3.add(interceptAngleQuadrant2);
                    }
                    else if(interceptAngleQuadrant1 > 90 && interceptAngleQuadrant2 <= 180)
                    {
                        //Quadrant 2 and the other end is in quadrant 4.
                        quadrant2Red.add(interceptAngleQuadrant1);
                        quadrant4Red.add(interceptAngleQuadrant2);
                        quadrant2.add(interceptAngleQuadrant1);
                        quadrant4.add(interceptAngleQuadrant2);
                    }
                    else if(interceptAngleQuadrant1 > 180 && interceptAngleQuadrant2 <= 270)
                    {
                        //Quadrant 3 and the other end is in quadrant 1.
                        quadrant3Red.add(interceptAngleQuadrant1);
                        quadrant1Red.add(interceptAngleQuadrant2);
                        quadrant3.add(interceptAngleQuadrant1);
                        quadrant1.add(interceptAngleQuadrant2);
                    }
                    else
                    {
                        //Quadrant 4 and the other end is in quadrant 2.
                        quadrant4Red.add(interceptAngleQuadrant1);
                        quadrant2Red.add(interceptAngleQuadrant2);
                        quadrant4.add(interceptAngleQuadrant1);
                        quadrant2.add(interceptAngleQuadrant2);
                    }
                }
                Collections.sort(quadrant1Red);
                Collections.sort(quadrant2Red);
                Collections.sort(quadrant3Red);
                Collections.sort(quadrant4Red);
                int redQuad1Count = quadrant1Red.size();
                int redQuad2Count = quadrant2Red.size();
                int redQuad3Count = quadrant3Red.size();
                int redQuad4Count = quadrant4Red.size();
                for(int k = 0; k < bluePoints; k++)
                {
                    if(k != j)
                    {
                        double angle = Math.atan2((bluePointsCoordinates[k].y - bluePointsCoordinates[j].y), (bluePointsCoordinates[k].x - bluePointsCoordinates[j].x)) * 180 / Math.PI;
                        double interceptAngleQuadrant1 = angle + 180 % 360;
                        double interceptAngleQuadrant2 = interceptQuadrant1 + 180 % 360;

                        if(interceptAngleQuadrant1 > 0 && interceptAngleQuadrant1 <= 90)
                        {
                            //Quadrant 1 and the other end is in quadrant 3.
                            quadrant1Blue.add(interceptAngleQuadrant1);
                            quadrant3Blue.add(interceptAngleQuadrant2);
                            quadrant1.add(interceptAngleQuadrant1);
                            quadrant3.add(interceptAngleQuadrant2);
                        }
                        else if(interceptAngleQuadrant1 > 90 && interceptAngleQuadrant2 <= 180)
                        {
                            //Quadrant 2 and the other end is in quadrant 4.
                            quadrant2Blue.add(interceptAngleQuadrant1);
                            quadrant4Blue.add(interceptAngleQuadrant2);
                            quadrant2.add(interceptAngleQuadrant1);
                            quadrant4.add(interceptAngleQuadrant2);
                        }
                        else if(interceptAngleQuadrant1 > 180 && interceptAngleQuadrant2 <= 270)
                        {
                            //Quadrant 3 and the other end is in quadrant 1.
                            quadrant3Blue.add(interceptAngleQuadrant1);
                            quadrant1Blue.add(interceptAngleQuadrant2);
                            quadrant3.add(interceptAngleQuadrant1);
                            quadrant1.add(interceptAngleQuadrant2);
                        }
                        else
                        {
                            //Quadrant 4 and the other end is in quadrant 2.
                            quadrant4Blue.add(interceptAngleQuadrant1);
                            quadrant2Blue.add(interceptAngleQuadrant2);
                            quadrant4.add(interceptAngleQuadrant1);
                            quadrant2.add(interceptAngleQuadrant2);
                        }
                    }
                }
                Collections.sort(quadrant1Blue);
                Collections.sort(quadrant2Blue);
                Collections.sort(quadrant3Blue);
                Collections.sort(quadrant4Blue);
                int blueQuad1Count = quadrant1Blue.size();
                int blueQuad2Count = quadrant2Blue.size();
                int blueQuad3Count = quadrant3Blue.size();
                int blueQuad4Count = quadrant4Blue.size();
                Collections.sort(quadrant1);
                Collections.sort(quadrant2);
                Collections.sort(quadrant3);
                Collections.sort(quadrant4);
                int blueQuad1Count = quadrant1.size();
                int blueQuad2Count = quadrant2.size();
                int blueQuad3Count = quadrant3.size();
                int blueQuad4Count = quadrant4.size();
                for(int j = 0; j < bluePoints; j++)
                {
                    for(int k = 0; k < redPoints; k++)
                    {
                        double lineAngle = blueRedAngles[j][k][1];
                        if(lineAngle > 0 && lineAngle <= 90)
                        {
                            int indexQuad1Red = Collections.binarySearch(quadrant1Red, lineAngle);
                            int indexQuad3Red = Collections.binarySearch(quadrant3Red, lineAngle);
                            int indexQuad1 = Collections.binarySearch(quadrant1, lineAngle);
                            int indexQuad3 = Collections.binarySearch(quadrant3, lineAngle);
                            int blueQuad1 = indexQuad1 - indexQuad1Red;
                            int blurQuad3 = indexQuad3 - indexQuad3Red;
                            int remainingRedQuad1 = redQuad1Count - indexQuad1Red;
                            int remainingRedQuad3 = redQuad3Count - indexQuad3Red;
                            int remainingBlueQuad1 = blueQuad1Count - blueQuad1;
                            int remainingBlueQuad3 = blueQuad3Count - blueQuad3;
                        }
                        else if(lineAngle > 90 && lineAngle <= 180)
                        {

                        }
                        else if(lineAngle > 180 && lineAngle <= 270)
                        {

                        }
                        else
                        {

                        }
                    }
                }
            }
        }
    }

    static String next()
    {
        return in.next();
    }

    static String nextLine()
    {
        return in.nextLine();
    }

    static int nextInt(){
        return Integer.parseInt(in.next());
    }

    static int[] ia(int N){
        int[] a = new int[N];
        for(int i = 0; i < N; i++)a[i] = nextInt();
        return a;
    }

    static long[] la(int N){
        long[] a = new long[N];
        for(int i = 0; i < N; i++)a[i] = nextLong();
        return a;
    }

    static long nextLong(){
        return Long.parseLong(in.next());
    }

    static double nextDouble(){
        return Double.parseDouble(in.next());
    }

    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next(){
            while (st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch (IOException  e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine(){
            String str = "";
            try{
                str = br.readLine();
            }catch (IOException e){
                e.printStackTrace();
            }
            return str;
        }
    }
}
