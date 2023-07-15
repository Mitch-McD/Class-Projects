package SecureState;

import java.util.HashMap;

class Locked extends SecurityState {
    private static HashMap<UserCredentials, Locked> instances = 
        new HashMap<UserCredentials, Locked>();
    public static Locked instance(UserCredentials user) {
        if (!instances.containsKey(user)) 
            instances.put(user, new Locked(user)); 
        return instances.get(user); }
    private UserCredentials _user;
    public Locked(UserCredentials user) { _user = user; }
  // For this simple example, once a user's account is locked it
  // cannot be unlocked. Once the user's account is locked, they
  // cannot do anything. No operations are forwarded to the user
  // functionality machine.
};
