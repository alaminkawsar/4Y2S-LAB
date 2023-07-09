import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class SHA {


	// Driver code
	public static void main(String args[])
	{
		String input = "Alamin Kawsar";
        try {

			MessageDigest md = MessageDigest.getInstance("SHA-256");
			byte[] messageDigest = md.digest(input.getBytes());

            // System.out.println("message = " + messageDigest );
			// Convert byte array into signum representation

			BigInteger signum = new BigInteger(1, messageDigest);
            //System.out.println("Sign number represention = " + signum);

			// Convert message
			String hashtext = signum.toString(16);
			
            System.out.println("SHA-256 Hash: " + hashtext);

		}

		// For specifying wrong message digest algorithms
		catch (NoSuchAlgorithmException e) {
			throw new RuntimeException(e);
		}
        
	}
}
