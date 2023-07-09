import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String number = "101";
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

