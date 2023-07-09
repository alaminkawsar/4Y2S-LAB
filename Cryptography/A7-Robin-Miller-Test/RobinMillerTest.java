import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Random;

public class RobinMillerTest {
    Boolean isPrime(String num){
        BigInteger p = new BigInteger(num);
        // factoring p by 2
        int b = 0;
        BigInteger temp = p.subtract(BigInteger.ONE);
        if(p.mod(BigInteger.TWO).equals(BigInteger.ZERO)){
            return false;
        }
        while(temp.mod(BigInteger.TWO).equals(BigInteger.ZERO)){
            temp=temp.divide(BigInteger.TWO);
            b++;
        }
        temp = p.subtract(BigInteger.ONE);
        BigInteger m = temp.divide(BigInteger.TWO.pow(b));

        // take a less than p
        BigInteger a = new BigInteger(p.bitLength()-1, new Random());
        if(BigInteger.ONE.compareTo(a)<=1){
            a = BigInteger.TWO;
        }
        int j = 0;
        BigInteger z = a.modPow(m, p);
        if (z.equals(BigInteger.ONE) || z.equals(p.subtract(BigInteger.ONE))){
            return true;
        }
        
        while(true){
            if(j>0 && z.equals(BigInteger.ONE)){
                return false;
            }
            j++;
            if(j<b && !z.equals(p.subtract(BigInteger.ONE))){
                z = z.modPow(BigInteger.TWO, p);
            }else break;
        }
        if(j==b && !z.equals(p.subtract(BigInteger.ONE))){
            return false;
        }

        return true;
    }

}
