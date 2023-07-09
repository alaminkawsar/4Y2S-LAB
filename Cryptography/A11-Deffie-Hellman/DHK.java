import java.math.BigInteger;
import java.util.Random;

public class DHK{
    public static void main(String[] args) {
        BigInteger P, a, b, Xa, Xb,Ya,Yb, Ka, Kb;

        P = BigInteger.probablePrime(10, new Random());
        a = BigInteger.probablePrime(10, new Random());

        System.out.println("\nP = "+P+" @ = "+a);
        
        //define private key a,  b
        Xa = BigInteger.valueOf(123);
        Xb = BigInteger.valueOf(234);

        // System.out.println("\nPrivate Key a = "+a+",  b = "+b);
        // key generate
        Ya = a.modPow(Xa, P);
        Yb = a.modPow(Xb, P);

        //System.out.println("\nGenerated Key x = "+Xa+",  y = "+Xb);

        //generate secrete key
        Ka = Yb.modPow(Xa, P);
        Kb = Ya.modPow(Xb, P);

        System.out.println("\nPrivate Key Ka = "+Ka+",  Kb = "+Kb);
        System.out.println();
    }
}

