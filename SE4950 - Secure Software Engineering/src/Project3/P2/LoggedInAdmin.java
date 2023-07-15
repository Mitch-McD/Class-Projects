package Project3.P2;

public class LoggedInAdmin extends SecurityState {
    RobotController robotController;

    LoggedInAdmin(RobotController r) {
        this.robotController = r;
    }

    boolean logout() {
        // reset user credentials
        robotController.setCurrentUser(new Credentials("", "", Credentials.TrustLevel.INVALID));
        // LoggedInAdmin -> LoggedOut
        robotController.setSecState(robotController.getOut());
        return true;
    }

    boolean op1() { return true; }
    boolean op2() { return true; }
    boolean connect() { return true; }
    boolean disconnect() { return true; }
}
