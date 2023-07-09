import java.math.BigInteger;
import java.security.SecureRandom;

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
            a = getRandomBigInteger(p);
            //System.out.println("random number: "+a);
            x = a.modPow(e, p);
            if((x.equals(ONE)) || x.equals(p.subtract(ONE))){
                continue;
            }else return false;
        }

        return flag;
    }
    public static BigInteger getRandomBigInteger(BigInteger mx){
        SecureRandom secureRandom = new SecureRandom();
        BigInteger randBigInteger = new BigInteger(mx.bitLength(), secureRandom);
        randBigInteger = randBigInteger.mod(mx);
        if(randBigInteger.equals(BigInteger.ZERO)) randBigInteger = BigInteger.TWO;
        return randBigInteger;
    }

    
}