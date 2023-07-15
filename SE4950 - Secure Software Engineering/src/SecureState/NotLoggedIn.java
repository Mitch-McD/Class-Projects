package SecureState;

import java.util.HashMap;

class NotLoggedIn extends SecurityState {
    private static HashMap<UserCredentials, NotLoggedIn> instances = 
        new HashMap<UserCredentials, NotLoggedIn>();
    public static NotLoggedIn instance(UserCredentials user) {
        if (!instances.containsKey(user)) 
            instances.put(user, new NotLoggedIn(user)); 
        return instances.get(user); }
    private UserCredentials _user;
    private int numFailedLogins;
    public NotLoggedIn(UserCredentials user) { _user = user; }
    public boolean login(ExampleSystem controller, EncryptedString password) {
        if (controller.getUser().validate(password)) {
            numFailedLogins = 0;
            if (controller.getUser().isAdministrator()) {
                changeState(controller, LoggedInAdmin.instance(_user)); }
            else { 
                changeState(controller, LoggedInClerk.instance(_user)); }
            return true; }
        else {
            numFailedLogins++;
            if (numFailedLogins >= 5) {
              numFailedLogins = 0;
              changeState(controller, Locked.instance(_user));
               }
            return false; } }
}
