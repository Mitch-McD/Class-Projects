package Project3.P2;

public class LoggedInUser extends SecurityState {
    RobotController robotController;

    LoggedInUser(RobotController r) {
        this.robotController = r;
    }

    // see main class for why there's no name/pwd associated
    boolean superUser() {
        // compare current user instance against SUSER (superuser) trust level
        if (robotController.getCurrentUser().getTrustLevel().equals(Credentials.TrustLevel.SUSER)) {
            // LoggedInUser -> LoggedInSuperUser
            robotController.setSecState(robotController.getSUser());
            return true;
        }
        return false;
    }

    boolean logout() {
        // reset user credentials
        robotController.setCurrentUser(new Credentials("", "", Credentials.TrustLevel.INVALID));
        // LoggedInUser -> LoggedOut
        robotController.setSecState(robotController.getOut());
        return true;
    }
}
