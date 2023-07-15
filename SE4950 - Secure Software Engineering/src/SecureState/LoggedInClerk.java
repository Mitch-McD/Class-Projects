package SecureState;

import java.util.HashMap;

class LoggedInClerk extends SecurityState {
    private static HashMap<UserCredentials, LoggedInClerk> instances = 
        new HashMap<UserCredentials, LoggedInClerk>();
    public static LoggedInClerk instance(UserCredentials user) {
        if (!instances.containsKey(user)) 
            instances.put(user, new LoggedInClerk(user)); 
        return instances.get(user); }
    private UserCredentials _user;
    private int op3Count;
    public LoggedInClerk(UserCredentials user) { 
        _user = user;
        op3Count = 0;
        }
    public boolean logout(ExampleSystem controller) {
        changeState(controller, NotLoggedIn.instance(_user));
        return true;
    }
    public boolean op1(ExampleSystem controller) { return true; }
    // Clerks aren't allowed to do op2
    public boolean op2(ExampleSystem controller) { return false; }
    public boolean op3(ExampleSystem controller) {
      op3Count++;
      if (op3Count > 50) {
        op3Count = 0;
        controller.logout();
        return false; 
      }
      return true;
    }
}



