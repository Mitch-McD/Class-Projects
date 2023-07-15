package Project3.P2;

public class LoggedInSuperUser extends SecurityState {
    RobotController robotController;

    LoggedInSuperUser(RobotController r) {
        this.robotController = r;
    }

    boolean logout() {
        // LoggedInSuperUser -> LoggedInUser
        robotController.setSecState(robotController.getUser());
        return true;
    }

    boolean op1() { return true; }
    boolean op2() { return true; }
    boolean connect() {
        return true;
    }
    boolean disconnect() {
        return true;
    }
}
