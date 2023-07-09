import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Random;

public class LehmanTest {
    BigInteger p,a,x,e;

    Boolean isPrime(String num){
        p = new BigInteger(num);
        BigInteger ZERO = BigInteger.ZERO;
        BigInteger ONE = BigInteger.ONE;
        BigInteger TWO = BigInteger.TWO;
        Boolean flag=true;
        
        if(p.mod(TWO).equals(ZERO)){
            return false;
        }
        e = p.subtract(ONE).divide(TWO);
        for(int i=0;i<50;i++){
            a = new BigInteger(p.bitLength()-1,new Random());
            if(BigInteger.ONE.compareTo(a)<=1){
                a = BigInteger.TWO;
            }
            //System.out.println("random number: "+a);
            x = a.modPow(e, p);
            if((x.equals(ONE)) || x.equals(p.subtract(ONE))){
                continue;
            }else return false;
        }

        return flag;
    }

    
}