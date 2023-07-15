package Project3.P2;

public class Main {
    public static void main(String[] args) {

        // FYI: this code is runnable

        // the following is purely because I didn't want to retype the user/password of the stored user while testing
        // and decided to create an array of Credential objects for verification

        // list of verified users
        Credentials[] userList = new Credentials[3];
        // create superuser
        userList[0] = new Credentials("super", "pwd", Credentials.TrustLevel.SUSER);
        // create admin
        userList[1] = new Credentials("adm", "passwd", Credentials.TrustLevel.ADM);
        // create normal user
        userList[2] = new Credentials("usr", "password", Credentials.TrustLevel.USER);

        // username/pwd of who will be logging in
        String name = "usr";
        String pwd = "password";

        // instantiate object and give it list of users
        RobotController rc = new RobotController(userList);

        // Test cases

        System.out.println("Test - Logging into regular user, then logging out: \n");

        rc.login(name, pwd); // attempt to log in with name/pwd defined above
        rc.logout(); // log out of user (logged out completely)

        System.out.println("\nTest - Logging into super user, connecting, starting op1/2\n" +
                "then completely logging out, leaving the connection active:\n ");

        name = "super";
        pwd = "pwd";

        rc.login(name, pwd); // login to user (super user)
        rc.superUser(); // login to super
        rc.connect(); // connect
        rc.op1(); // run op1
        rc.op2(); // run op2
        rc.logout();
        rc.logout(); // log out completely - connection is still active

        System.out.println("\nTest - Logging into admin, disconnecting, and logging out:\n");

        name = "adm";
        pwd = "passwd";

        rc.login(name, pwd); // login to admin
        rc.disconnect(); // disconnect
        rc.logout(); // log out

        RobotController rcf = new RobotController(userList);

        name = "usr";
        pwd = "password";

        System.out.println("\nFailtest - Logging into user, connecting, running op1, and logging out.\n" +
                "Expected outcome is logging in, and then logging out.\n");

        rcf.login(name, pwd); // login to user
        rcf.connect(); // connect (fails)
        rcf.op1(); // op1 (fails)
        rcf.logout(); // logout

        System.out.println("\nFailtest - Logging in with invalid credentials. \n" +
                "Expected outcome is nothing happening.\n");

        name = "fakeuser";
        pwd = "password";

        rcf.login(name, pwd); // login (fails)
        rcf.superUser(); // super (fails)
        rcf.connect(); // connect (fails)
        rcf.op1(); // op1 (fails)
        rcf.logout(); // logout (fails)

        System.out.println("\nFailtest - Logging in as admin, trying to run op1 before connecting. \n" +
                "Expected outcome is logging in, then logging out.\n");

        name = "adm";
        pwd = "passwd";

        rcf.login(name, pwd); // login
        rcf.op1(); // super (fails)
        rcf.op2(); // op1 (fails)
        rcf.logout(); // logout

    }
}
