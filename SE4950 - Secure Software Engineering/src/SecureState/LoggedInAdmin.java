package SecureState;

import java.util.HashMap;

class LoggedInAdmin extends SecurityState {
    private static HashMap<UserCredentials, LoggedInAdmin> instances = 
        new HashMap<UserCredentials, LoggedInAdmin>();
    public static LoggedInAdmin instance(UserCredentials user) {
        if (!instances.containsKey(user)) 
            instances.put(user, new LoggedInAdmin(user)); 
        return instances.get(user); }
    private UserCredentials _user;
    private int op3Count;
    public LoggedInAdmin(UserCredentials user) { 
        _user = user; 
        op3Count = 0;
        }
    public boolean logout(ExampleSystem controller) {
        changeState(controller, NotLoggedIn.instance(_user));
        return true;
    }
    public boolean op1(ExampleSystem controller) { return true; }
    public boolean op2(ExampleSystem controller) { return true; }
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



