import java.math.BigInteger;
import java.util.Scanner;

public class RSASimple{
    public static void main(String[] args) {
        BigInteger p, q, n, e, d, co, msg;
        // Take two largest prime
        Scanner scanner = new Scanner(System.in);
        /*

            Big prime number example
            https://t5k.org/curios/index.php?start=20&stop=24

        */
        // System.out.print("Input P: ");
        // p = scanner.nextBigInteger();

        // System.out.print("Input Q: ");
        // q = scanner.nextBigInteger();

        // System.out.print("Input Message: ");
        // String str = scanner.nextLine();
        // char[] ch = new char[str.length()];
        // for (int i = 0; i < str.length(); i++) {
        //     ch[i] = str.charAt(i);
        // }
        // msg = BigInteger.ZERO;
        // for(int i=0;i<str.length();i++){
        //     //System.out.println(ch[i]);
        //     msg = msg.multiply(BigInteger.valueOf(100)).add(BigInteger.valueOf(ch[i]-'a'+10));
        //     // System.out.println(ch[i]-'a'+10);
        // }
        msg = scanner.nextBigInteger();


        scanner.close();

        System.out.println(msg);

        // initialize big prime 
        p=new BigInteger("3737373737373737373737373737373737373737373737373737373737373737373737373743434343434343434343434343434343434343434343434343434343434343434343434343434343434343");
        q=new BigInteger("4001160567659443111330503282468707739798434620548604221627193504975920082305041881662090135042017773659662575788983801725920353518125641884669217468110276929673");
        // msg = new BigInteger("123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456");
        System.out.println();


        n = p.multiply(q);
        co = p.subtract(BigInteger.valueOf(1)).multiply(q.subtract(BigInteger.ONE));

        // choose value e such e and (p-1)*(q-1) is relatively prime
        e = BigInteger.TWO;

        while(true){
            if(co.gcd(e).equals(BigInteger.ONE)) break;
            e=e.add(BigInteger.ONE);
        }
        
        //e = BigInteger.valueOf(79); // for manual teting
        // now calculate d = e^-1 mod (p-1)(q-1)
        d = e.modInverse(co);

        System.out.println("message= "+msg+", n="+n+", e="+e+", d="+d+", co="+co);
        System.out.println();

        BigInteger c = msg.modPow(e,n);
        System.out.println("Encrypted message is : " + c);
 
        BigInteger N = n;
 
        BigInteger C = c;
        BigInteger decrypted = (C.modPow(d,N));
        System.out.println("Decrypted message is : "+ decrypted);

        // integer to string convertion
        // System.out.print("Decrypted Message: ");
        // String decr="";
        // while(true){
        //     if(decrypted.equals(BigInteger.ZERO)) break;
        //     int decimal =decrypted.mod(BigInteger.valueOf(100)).intValue();
        //     int element = decimal - 10 +'a';
        //     char chr = (char) element;
        //     //System.out.print(chr);
        //     decr += chr;
        //     decrypted = decrypted.divide(BigInteger.valueOf(100));
        // }
        // StringBuilder input1 = new StringBuilder();
        // input1.append(decr);
        // input1.reverse();
        // System.out.println(input1);

    }
 
}