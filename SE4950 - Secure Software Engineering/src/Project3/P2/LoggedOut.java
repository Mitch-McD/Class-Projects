package Project3.P2;

public class LoggedOut extends SecurityState {
    RobotController robotController;

    LoggedOut(RobotController r) {
        this.robotController = r;
    }

    boolean login(String name, String pwd) {
        boolean valid = false;
        for (Credentials cred : robotController.getUserList()) {
            // if given name/pwd match stored credentials
            if (cred.validate(name, pwd)) {
                valid = true;
                // get current user credentials
                robotController.setCurrentUser(cred);
                // go to LoggedInUser, LoggedInAdmin, or return false depending on trust level
                switch(cred.getTrustLevel()) {
                    case SUSER:
                    case USER:
                        // LoggedOut -> LoggedInUser
                        robotController.setSecState(robotController.getUser());
                        break;
                    case ADM:
                        // LoggedOut -> LoggedInAdmin
                        robotController.setSecState(robotController.getAdmin());
                        break;
                    case INVALID:
                    default:
                        valid = false;
                }
                break;
            }
        }
        return valid;
    }
}
