import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class MD5 {


	// Driver code
	public static void main(String args[]) throws NoSuchAlgorithmException
	{
		String input = "Alamin Kawsar";
        try {

			MessageDigest md = MessageDigest.getInstance("MD5");
            
			byte[] messageDigest = md.digest(input.getBytes());

            // System.out.println("message = " + messageDigest );

			// Convert byte array into signum representation
			BigInteger signum = new BigInteger(1, messageDigest);
            
            System.out.println("Sign number represention = " + signum);

			// Convert message
			String hashtext = signum.toString(16);
			while (hashtext.length() < 32) {
				hashtext = "0" + hashtext;
			}
            System.out.println("MD5 is: " + hashtext);

		}

		// For specifying wrong message digest algorithms
		catch (NoSuchAlgorithmException e) {
			throw new RuntimeException(e);
		}
        
	}
}
