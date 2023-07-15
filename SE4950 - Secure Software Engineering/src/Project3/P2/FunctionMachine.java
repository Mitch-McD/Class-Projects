package Project3.P2;

public class FunctionMachine {
    RobotController robotController;

    private ConnectionState connect;
    private ConnectionState disconnect;

    private ConnectionState connectState;

    FunctionMachine(RobotController rc) {
        connect = new Connected(this);
        disconnect = new Disconnected(this);

        connectState = disconnect;

        this.robotController = rc;
    }

    ConnectionState getConnect() { return connect; }
    ConnectionState getDisconnect() { return disconnect; }

    void setConnectState(ConnectionState cs) { this.connectState = cs; }

    void login(String name) {
        SecurityState state = robotController.getSecState();
        String stateStr = "";
        if (state.equals(robotController.getUser()))
            stateStr = "User";
        if (state.equals(robotController.getAdmin()))
            stateStr = "Admin";

        System.out.println("Logging into " + stateStr + " as " + name + ".");
    }

    void logout() {
        SecurityState state = robotController.getSecState();
        String stateStr = "";
        if (state.equals(robotController.getUser()))
                stateStr = "User";
        if (state.equals(robotController.getOut()))
                stateStr = "Out";

        System.out.println("Logging out to " + stateStr + ".");
    }

    void superUser() { System.out.println("Logging into Superuser."); }
    void op1() {
        if (connectState.equals(connect))
            System.out.println("Executing op1.");
    }
    void op2() {
        if (connectState.equals(connect))
            System.out.println("Executing op2.");
    }
    void connect() {
        System.out.println("Connected!");
        connectState.connect();
    }
    void disconnect() {
        System.out.println("Disconnected!");
        connectState.disconnect();
    }
}
