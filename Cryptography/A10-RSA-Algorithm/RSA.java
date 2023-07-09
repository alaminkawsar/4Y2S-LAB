import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class RSA{
    public static BigInteger p, q, n, e, d, co, msg;
    public static void main(String[] args) {
        // Take two largest prime
        Scanner scanner = new Scanner(System.in);
        /*
            Big prime number example
            https://t5k.org/curios/index.php?start=20&stop=24
        */
        String message = scanner.nextLine();
        scanner.close();
        p=new BigInteger("47");
        q=new BigInteger("71");
        System.out.println();
        n = p.multiply(q);
        co = p.subtract(BigInteger.valueOf(1)).multiply(q.subtract(BigInteger.ONE));
        // choose value e such e and (p-1)*(q-1) is relatively prime
        e = BigInteger.TWO;

        while(true){
            if(co.gcd(e).equals(BigInteger.ONE)) break;
            e = e.add(BigInteger.ONE);
        }
        
        e = BigInteger.valueOf(79);
        d = e.modInverse(co);

        List<String> encList = encryption(message);
        String decString = decryption(encList);

    }

    static List<String> encryption(String message){
        List<String> list = new ArrayList<>();

        int blockSize = n.toString().length()-1;
        int len = message.length();
        int pad=blockSize-len%blockSize;
        
        System.out.println("Encryption Message:");
        for(int i=0;i<len;i+=3){
            // padding message if need;
            String block="";

            // handle last block
            if(i+blockSize>len){
                for(int j=0;j<pad;j++) block+="0";
                block+=message.substring(i,len);
            }
            else{
                block = message.substring(i, i+3);
            }
            msg = new BigInteger(block);
            BigInteger c = msg.modPow(e,n);
            String temp = c.toString();
            list.add(temp);
        }
        for(String item: list){
            System.out.print(item);
        }

        return list;
    }

    static String decryption(List<String> list){
        String decrypted="";
        
        for(String item: list){
            BigInteger num = new BigInteger(item);
            num = num.modPow(d,n);
            decrypted+=num.toString();
        }
        System.out.println(decrypted);

        return decrypted;
    }
 
}