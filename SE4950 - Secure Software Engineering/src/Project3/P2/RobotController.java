package Project3.P2;

public class RobotController {
    private SecurityState admin;
    private SecurityState user;
    private SecurityState suser;
    private SecurityState out;

    private Credentials currentUser;

    // List of allowed users (names, passwords, trust levels (user, superuser, admin))
    private Credentials[] userList;

    private SecurityState secState;

    private FunctionMachine functionMachine;

    RobotController(Credentials[] userList) {
        admin = new LoggedInAdmin(this);
        user = new LoggedInUser(this);
        suser = new LoggedInSuperUser(this);
        out = new LoggedOut(this);

        this.userList = userList;

        secState = out;

        // creates null user until a valid one logs in
        currentUser = new Credentials("","", Credentials.TrustLevel.INVALID);

        functionMachine = new FunctionMachine(this);
    }
    Credentials[] getUserList() { return userList; }
    Credentials getCurrentUser() { return currentUser; }
    void setCurrentUser(Credentials user) { this.currentUser = user; }

    SecurityState getUser() { return user; }
    SecurityState getAdmin() { return admin; }
    SecurityState getSUser() { return suser; }
    SecurityState getOut() { return out; }

    void setSecState(SecurityState state) { secState = state; }
    SecurityState getSecState() { return secState; }

    void login(String name, String pwd) {
        if (secState.login(name, pwd))
            functionMachine.login(name);
    }
    void superUser() {
        if (secState.superUser())
            functionMachine.superUser();
    }
    void logout() {
        if (secState.logout())
            functionMachine.logout();
    }
    void op1() {
        if (secState.op1())
            functionMachine.op1();
    }
    void op2() {
        if (secState.op2())
            functionMachine.op2();
    }
    void connect() {
        if (secState.connect())
            functionMachine.connect();
    }
    void disconnect() {
        if (secState.disconnect())
            functionMachine.disconnect();
    }
}
