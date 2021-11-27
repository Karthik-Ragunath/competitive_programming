import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class RedPoints
{
    int x;
    int y;
}

class BluePoints
{
    int x;
    int y;
}

class AngularSweepRefined
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
                redPointsCoordinates[j] = new RedPoints();
                redPointsCoordinates[j].x = nextInt();
                redPointsCoordinates[j].y = nextInt();
            }

            for(int j = 0; j < bluePoints; j++)
            {
                bluePointsCoordinates[j] = new BluePoints();
                bluePointsCoordinates[j].x = nextInt();
                bluePointsCoordinates[j].y = nextInt();
            }

            int minimumSolution = 0;
            for(int j = 0; j < bluePoints; j++)
            {
                //For everyline formed by red and blue point check how many redpoints and bluePonts are in the given region (either above or below)
                //and find the min of (red + blue points above) and (red + blue points below) and print the desired answer.
                //Binary search should be used to answer the queries.
                int blueXCoordinate = bluePointsCoordinates[j].x;
                int blueYCoordinate = bluePointsCoordinates[j].y;
                double[][] redBlueAngles = new double[redPoints][2];
                ArrayList<Double> quadrant1Red = new ArrayList<Double>();
                ArrayList<Double> quadrant2Red = new ArrayList<Double>();
                ArrayList<Double> quadrant3Red = new ArrayList<Double>();
                ArrayList<Double> quadrant4Red = new ArrayList<Double>();

                ArrayList<Double> quadrant1 = new ArrayList<Double>();
                ArrayList<Double> quadrant2 = new ArrayList<Double>();
                ArrayList<Double> quadrant3 = new ArrayList<Double>();
                ArrayList<Double> quadrant4 = new ArrayList<Double>();

                for(int k = 0; k < redPoints; k++)
                {
                    double angle = Math.atan2((redPointsCoordinates[k].y - blueYCoordinate), (redPointsCoordinates[k].x - blueXCoordinate)) * 180 / Math.PI;
                    double interceptAngleQuadrant1 = (angle + 180) % 360;
                    double interceptAngleQuadrant2 = (interceptAngleQuadrant1 + 180) % 360;
                    if(redPointsCoordinates[k].y >= blueYCoordinate)
                    {
                        if(redPointsCoordinates[k].x >= blueXCoordinate)
                        {
                            if(interceptAngleQuadrant1 <= 90)
                            {
                                quadrant1Red.add(interceptAngleQuadrant1);
                                quadrant1.add(interceptAngleQuadrant1);
                                redBlueAngles[k][0] = interceptAngleQuadrant1;
                                redBlueAngles[k][1] = interceptAngleQuadrant2;
                            }
                            else
                            {
                                quadrant1Red.add(interceptAngleQuadrant2);
                                quadrant1.add(interceptAngleQuadrant2);
                                redBlueAngles[k][0] = interceptAngleQuadrant2;
                                redBlueAngles[k][1] = interceptAngleQuadrant1;
                            }
                        }
                        else
                        {
                            if(interceptAngleQuadrant1 > 90 && interceptAngleQuadrant1 <= 180)
                            {
                                quadrant2Red.add(interceptAngleQuadrant1);
                                quadrant2.add(interceptAngleQuadrant1);
                                redBlueAngles[k][0] = interceptAngleQuadrant1;
                                redBlueAngles[k][1] = interceptAngleQuadrant2;
                            }
                            else
                            {
                                quadrant2Red.add(interceptAngleQuadrant2);
                                quadrant2.add(interceptAngleQuadrant2);
                                redBlueAngles[k][0] = interceptAngleQuadrant2;
                                redBlueAngles[k][1] = interceptAngleQuadrant1;
                            }
                        }
                    }
                    else
                    {
                        if(redPointsCoordinates[k].x <= blueXCoordinate)
                        {
                            if(interceptAngleQuadrant1 > 180 && interceptAngleQuadrant1 <= 270)
                            {
                                quadrant3Red.add(interceptAngleQuadrant1);
                                quadrant3.add(interceptAngleQuadrant1);
                                redBlueAngles[k][0] = interceptAngleQuadrant1;
                                redBlueAngles[k][1] = interceptAngleQuadrant2;
                            }
                            else
                            {
                                quadrant3Red.add(interceptAngleQuadrant2);
                                quadrant3.add(interceptAngleQuadrant2);
                                redBlueAngles[k][0] = interceptAngleQuadrant2;
                                redBlueAngles[k][1] = interceptAngleQuadrant1;
                            }
                        }
                        else
                        {
                            if(interceptAngleQuadrant1 > 270 && interceptAngleQuadrant1 < 360)
                            {
                                quadrant4Red.add(interceptAngleQuadrant1);
                                quadrant4.add(interceptAngleQuadrant1);
                                redBlueAngles[k][0] = interceptAngleQuadrant1;
                                redBlueAngles[k][1] = interceptAngleQuadrant2;
                            }
                            else
                            {
                                quadrant4Red.add(interceptAngleQuadrant2);
                                quadrant4.add(interceptAngleQuadrant2);
                                redBlueAngles[k][0] = interceptAngleQuadrant2;
                                redBlueAngles[k][1] = interceptAngleQuadrant1;
                            }
                        }
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
                        double angle = Math.atan2((bluePointsCoordinates[k].y - blueYCoordinate), (bluePointsCoordinates[k].x - blueXCoordinate)) * 180 / Math.PI;
                        double interceptAngleQuadrant1 = (angle + 180) % 360;
                        double interceptAngleQuadrant2 = (interceptAngleQuadrant1 + 180) % 360;

                        if(bluePointsCoordinates[k].y >= blueYCoordinate)
                        {
                            if(bluePointsCoordinates[k].x >= blueXCoordinate)
                            {
                                if(interceptAngleQuadrant1 <= 90)
                                {
                                    quadrant1.add(interceptAngleQuadrant1);
                                }
                                else
                                {
                                    quadrant1.add(interceptAngleQuadrant2);
                                }
                            }
                            else
                            {
                                if(interceptAngleQuadrant1 > 90 && interceptAngleQuadrant1 <= 180)
                                {
                                    quadrant2.add(interceptAngleQuadrant1);
                                }
                                else
                                {
                                    quadrant2.add(interceptAngleQuadrant2);
                                }
                            }
                        }
                        else
                        {
                            if(bluePointsCoordinates[k].x <= blueXCoordinate)
                            {
                                if(interceptAngleQuadrant1 > 180 && interceptAngleQuadrant1 <= 270)
                                {
                                    quadrant3.add(interceptAngleQuadrant1);
                                }
                                else
                                {
                                    quadrant3.add(interceptAngleQuadrant2);
                                }
                            }
                            else
                            {
                                if(interceptAngleQuadrant1 > 270 && interceptAngleQuadrant1 < 360)
                                {
                                    quadrant4.add(interceptAngleQuadrant1);
                                }
                                else
                                {
                                    quadrant4.add(interceptAngleQuadrant2);
                                }
                            }
                        }
                    }
                }
                Collections.sort(quadrant1);
                Collections.sort(quadrant2);
                Collections.sort(quadrant3);
                Collections.sort(quadrant4);
                int quad1Count = quadrant1.size();
                int quad2Count = quadrant2.size();
                int quad3Count = quadrant3.size();
                int quad4Count = quadrant4.size();

                /*
                if(j == 0)
                {
                    System.out.println("Reds in Quad 1: " + redQuad1Count);
                    System.out.println("Reds in Quad 2: " + redQuad2Count);
                    System.out.println("Reds in Quad 3: " + redQuad3Count);
                    System.out.println("Reds in Quad 4: " + redQuad4Count);
                    System.out.println("Quad 1 Count: " + quad1Count);
                    System.out.println("Quad 2 Count: " + quad2Count);
                    System.out.println("Quad 3 Count: " + quad3Count);
                    System.out.println("Quad 4 Count: " + quad4Count);
                }
                */

                int minimumForParticularBluePoint = 0;
                for(int k = 0; k < redPoints; k++)
                {
                    double lineAngle = redBlueAngles[k][0];
                    double lineAngleOppositeQuadrant = redBlueAngles[k][1];
                    if(lineAngle >= 0 && lineAngle <= 90)
                    {
                        int redQuad1 = Collections.binarySearch(quadrant1Red, lineAngle);
                        int remainingRedQuad1 = redQuad1Count - (redQuad1 + 1);
                        int totalQuad1 = Collections.binarySearch(quadrant1, lineAngle);
                        int remainingTotalQuad1 = quad1Count - (totalQuad1 + 1);
                        int blueQuad1 = totalQuad1 - redQuad1;
                        int remainingBlueQuad1 = remainingTotalQuad1 - remainingRedQuad1;
                        int redQuad3 = (Collections.binarySearch(quadrant3Red, lineAngleOppositeQuadrant) * -1) - 1;
                        int remainingRedQuad3 = redQuad3Count - redQuad3;
                        int totalQuad3 = (Collections.binarySearch(quadrant3, lineAngleOppositeQuadrant) * -1) - 1;
                        int remainingTotalQuad3 = quad3Count - totalQuad3;
                        int blueQuad3 = totalQuad3 - redQuad3;
                        int remainingBlueQuad3 = remainingTotalQuad3 - remainingRedQuad3;

                        int redPointsAbove = remainingRedQuad1 + redQuad2Count + redQuad3;
                        int redPointsBelow = redQuad1 + redQuad4Count + remainingRedQuad3;
                        int bluePointsAbove = remainingBlueQuad1 + (quad2Count - redQuad2Count) + blueQuad3;
                        int bluePointsBelow = blueQuad1 + (quad4Count - redQuad4Count) + remainingBlueQuad3;

                        /*
                        if(k == 0)
                        {
                            System.out.println("Quadrant 1");
                            System.out.println("Red points above: " + redPointsAbove);
                            System.out.println("Red points below: " + redPointsBelow);
                            System.out.println("Blue points above: " + bluePointsAbove);
                            System.out.println("Blue points below: " + bluePointsBelow);
                        }
                        */

                        int min = Math.min((redPointsAbove + bluePointsBelow), (redPointsBelow + bluePointsAbove));
                        if(k == 0)
                        {
                            minimumForParticularBluePoint = min;
                        }
                        else
                        {
                            if(min < minimumForParticularBluePoint)
                            {
                                minimumForParticularBluePoint = min;
                            }
                        }
                    }
                    else if(lineAngle > 90 && lineAngle <= 180)
                    {
                        int redQuad2 = Collections.binarySearch(quadrant2Red, lineAngle);
                        int remainingRedQuad2 = redQuad2Count - (redQuad2 + 1);
                        int totalQuad2 = Collections.binarySearch(quadrant2, lineAngle);
                        int remainingTotalQuad2 = quad2Count - (totalQuad2 + 1);
                        int blueQuad2 = totalQuad2 - redQuad2;
                        int remainingBlueQuad2 = remainingTotalQuad2 - remainingRedQuad2;
                        int redQuad4 = (Collections.binarySearch(quadrant4Red, lineAngleOppositeQuadrant) * -1) - 1;
                        int remainingRedQuad4 = redQuad4Count - redQuad4;
                        int totalQuad4 = (Collections.binarySearch(quadrant4, lineAngleOppositeQuadrant) * -1) - 1;
                        int remainingTotalQuad4 = quad4Count - totalQuad4;
                        int blueQuad4 = totalQuad4 - redQuad4;
                        int remainingBlueQuad4 = remainingTotalQuad4 - remainingRedQuad4;

                        int redPointsAbove = redQuad2 + redQuad1Count + remainingRedQuad4;
                        int redPointsBelow = remainingRedQuad2 + redQuad3Count + redQuad4;
                        int bluePointsAbove = blueQuad2 + (quad1Count - redQuad1Count) + remainingBlueQuad4;
                        int bluePointsBelow = remainingBlueQuad2 + (quad3Count - redQuad3Count) + blueQuad4;

                        /*
                        if(k == 0)
                        {
                            System.out.println("Quadrant 2");
                            System.out.println("Red points above: " + redPointsAbove);
                            System.out.println("Red points below: " + redPointsBelow);
                            System.out.println("Blue points above: " + bluePointsAbove);
                            System.out.println("Blue points below: " + bluePointsBelow);
                        }
                        */

                        int min = Math.min((redPointsAbove + bluePointsBelow), (redPointsBelow + bluePointsAbove));
                        if(k == 0)
                        {
                            minimumForParticularBluePoint = min;
                        }
                        else
                        {
                            if(min < minimumForParticularBluePoint)
                            {
                                minimumForParticularBluePoint = min;
                            }
                        }
                    }
                    else if(lineAngle > 180 && lineAngle <= 270)
                    {
                        int redQuad3 = Collections.binarySearch(quadrant3Red, lineAngle);
                        int remainingRedQuad3 = redQuad3Count - (redQuad3 + 1);
                        int totalQuad3 = Collections.binarySearch(quadrant3, lineAngle);
                        int remainingTotalQuad3 = quad3Count - (totalQuad3 + 1);
                        int blueQuad3 = totalQuad3 - redQuad3;
                        int remainingBlueQuad3 = remainingTotalQuad3 - remainingRedQuad3;
                        int redQuad1 = (Collections.binarySearch(quadrant1Red, lineAngleOppositeQuadrant) * -1) - 1;
                        int remainingRedQuad1 = redQuad1Count - redQuad1;
                        int totalQuad1 = (Collections.binarySearch(quadrant1, lineAngleOppositeQuadrant) * -1) - 1;
                        int remainingTotalQuad1 = quad1Count - totalQuad1;
                        int blueQuad1 = totalQuad1 - redQuad1;
                        int remainingBlueQuad1 = remainingTotalQuad1 - remainingRedQuad1;

                        int redPointsAbove = redQuad3 + redQuad2Count + remainingRedQuad1;
                        int redPointsBelow = remainingRedQuad3 + redQuad4Count + redQuad1;
                        int bluePointsAbove = blueQuad3 + (quad2Count - redQuad2Count) + remainingBlueQuad1;
                        int bluePointsBelow = remainingBlueQuad3 + (quad4Count - redQuad4Count) + blueQuad1;

                        /*
                        if(k == 0)
                        {
                            System.out.println("Quadrant 3");
                            System.out.println("Red points above: " + redPointsAbove);
                            System.out.println("Red points below: " + redPointsBelow);
                            System.out.println("Blue points above: " + bluePointsAbove);
                            System.out.println("Blue points below: " + bluePointsBelow);
                        }
                        */

                        int min = Math.min((redPointsAbove + bluePointsBelow), (redPointsBelow + bluePointsAbove));
                        if(k == 0)
                        {
                            minimumForParticularBluePoint = min;
                        }
                        else
                        {
                            if(min < minimumForParticularBluePoint)
                            {
                                minimumForParticularBluePoint = min;
                            }
                        }
                    }
                    else
                    {
                        int redQuad4 = Collections.binarySearch(quadrant4Red, lineAngle);
                        int remainingRedQuad4 = redQuad4Count - (redQuad4 + 1);
                        int totalQuad4 = Collections.binarySearch(quadrant4, lineAngle);
                        int remainingTotalQuad4 = quad4Count - (totalQuad4 + 1);
                        int blueQuad4 = totalQuad4 - redQuad4;
                        int remainingBlueQuad4 = remainingTotalQuad4 - remainingRedQuad4;
                        int redQuad2 = (Collections.binarySearch(quadrant2Red, lineAngleOppositeQuadrant) * -1) - 1;
                        int remainingRedQuad2 = redQuad2Count - redQuad2;
                        int totalQuad2 = (Collections.binarySearch(quadrant2, lineAngleOppositeQuadrant) * -1) - 1;
                        int remainingTotalQuad2 = quad2Count - totalQuad2;
                        int blueQuad2 = totalQuad2 - redQuad2;
                        int remainingBlueQuad2 = remainingTotalQuad2 - remainingRedQuad2;

                        int redPointsAbove = remainingRedQuad4 + redQuad1Count + redQuad2;
                        int redPointsBelow = redQuad4 + redQuad3Count + remainingRedQuad2;
                        int bluePointsAbove = remainingBlueQuad4 + (quad1Count - redQuad1Count) + blueQuad2;
                        int bluePointsBelow = blueQuad4 + (quad3Count - redQuad3Count) + remainingBlueQuad2;

                        /*
                        if(k == 0)
                        {
                            System.out.println("Quadrant 4");
                            System.out.println("Red points above: " + redPointsAbove);
                            System.out.println("Red points below: " + redPointsBelow);
                            System.out.println("Blue points above: " + bluePointsAbove);
                            System.out.println("Blue points below: " + bluePointsBelow);
                        }
                        */

                        int min = Math.min((redPointsAbove + bluePointsBelow), (redPointsBelow + bluePointsAbove));
                        if(k == 0)
                        {
                            minimumForParticularBluePoint = min;
                        }
                        else
                        {
                            if(min < minimumForParticularBluePoint)
                            {
                                minimumForParticularBluePoint = min;
                            }
                        }
                    }
                }
                if(j == 0)
                {
                    minimumSolution = minimumForParticularBluePoint;
                }
                else
                {
                    if(minimumForParticularBluePoint < minimumSolution)
                    {
                        minimumSolution = minimumForParticularBluePoint;
                    }
                }
            }
            System.out.println(minimumSolution);
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

    static int nextInt()
    {
        return Integer.parseInt(in.next());
    }

    static int[] ia(int N)
    {
        int[] a = new int[N];
        for(int i = 0; i < N; i++)a[i] = nextInt();
        return a;
    }

    static long[] la(int N)
    {
        long[] a = new long[N];
        for(int i = 0; i < N; i++)a[i] = nextLong();
        return a;
    }

    static long nextLong()
    {
        return Long.parseLong(in.next());
    }

    static double nextDouble()
    {
        return Double.parseDouble(in.next());
    }

    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
        public FastReader()
        {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}
