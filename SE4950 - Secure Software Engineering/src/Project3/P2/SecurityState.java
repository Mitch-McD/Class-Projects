package Project3.P2;

abstract class SecurityState {
    boolean login(String name, String pwd) { return false; }
    boolean logout() { return false; }
    // no need to pass name/pwd, current user information is stored in robotController upon successful login
    // and then referenced by LoggedInUser(). A user is either a normal user or superuser - a normal user
    // can't access superuser at all, but a superuser is able to go between user and superuser states freely.
    boolean superUser() { return false; }
    boolean op1() { return false; }
    boolean op2() { return false; }
    boolean connect() { return false; }
    boolean disconnect() { return false; }
}
