import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;

public class ProjectEuler29 {
    public static void main(String [] args) {
        Scanner in=new Scanner(System.in);
        int number;
        number=in.nextInt();
        Set<BigInteger> distinctTerms = new HashSet<BigInteger>();
        for (int i = 2; i <= number; i++) {
            BigInteger bigI = BigInteger.valueOf(i);
            for (int j = 2; j <= number; j++) {
                BigInteger temp = bigI.pow(j);
                distinctTerms.add(temp);
            }
        }
       
        System.out.println(distinctTerms.size());
    }
}