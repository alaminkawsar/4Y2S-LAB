import java.math.BigInteger;
import java.security.SecureRandom;

public class LehmanTest {
    BigInteger number,a,x,e;

    Boolean isPrime(String num){
        number = new BigInteger(num);
        BigInteger ZERO = BigInteger.ZERO;
        BigInteger ONE = BigInteger.ONE;
        BigInteger TWO = BigInteger.TWO;
        Boolean flag=true;
        
        if(number.mod(TWO).equals(ZERO)){
            return false;
        }
        e = number.subtract(ONE).divide(TWO);
        for(int i=0;i<50;i++){
            a = getRandomBigInteger(number.subtract(ONE));
            System.out.println("random number: "+a);
            x = a.modPow(e, number);
            if((x.equals(ONE)) || x.equals(number.subtract(ONE))){
                continue;
            }else return false;
        }

        return flag;
    }
    public static BigInteger getRandomBigInteger(BigInteger mx){
        BigInteger randBigInteger = new BigInteger(mx.bitLength(), new SecureRandom());
        return randBigInteger.compareTo(mx)>=0? randBigInteger.mod(mx): randBigInteger;
    }

    
}