import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class CHATGPT {
    public static void main(String[] args) {
        String input = "Alamin Kawsar";
        
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = md.digest(input.getBytes(StandardCharsets.UTF_8));
            
            StringBuilder sb = new StringBuilder();
            for (byte b : hashBytes) {
                sb.append(String.format("%02x", b));
            }
            
            String shaHash = sb.toString();
            System.out.println("SHA-256 Hash: " + shaHash);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}
