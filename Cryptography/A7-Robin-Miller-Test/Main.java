import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String number = "40011605676594431113305032824687077397984346205486042216271935049759200823050418816620901350420177736596625757889838017259203535181256418846692174681102769";
        // Scanner scan = new Scanner(System.in);
        // number = scan.nextLine();
        // scan.close();

        //System.out.println(LehmanTest.getRandomBigInteger(new BigInteger(number)).subtract(BigInteger.ONE));
        RobinMillerTest robinTest = new RobinMillerTest();

        if(robinTest.isPrime(number)){
            System.out.println(number+" maybe prime");
        }else{
            System.out.println(number+" is not prime");
        }
    }
}

