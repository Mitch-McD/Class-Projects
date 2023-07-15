package SecureState;

public class SecureStateTester {
    
  public static void main(String[] args) {
    EncryptedString myPassword = new EncryptedString("myPassword");
    UserCredentials me = new UserCredentials("me", myPassword, true);

    ExampleSystem controller = new ExampleSystem(me);
    EncryptedString loginPassword = new EncryptedString("myPassword");
    controller.login(loginPassword);
  }
}
