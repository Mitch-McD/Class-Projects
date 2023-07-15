package SecureState;

class
UserFunctionsMachine {
  private UserCredentials _user;
  // Someone is trying to log onto the system as the current user.
  public void login(EncryptedString password) {
    System.out.println("Logging in " + _user.getName());
  }
  // The user is logging out.
  public void logout() {}
  // The user is attempting to perform one of the three user-level
  // system operations.
  public void op1() {}
  public void op2() {}
  public void op3() {}

  // Create a new user functionality state machine for the given user.
  public UserFunctionsMachine(UserCredentials user) { _user = user; };
};
