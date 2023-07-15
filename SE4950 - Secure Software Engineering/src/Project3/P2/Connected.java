package Project3.P2;

public class Connected extends ConnectionState {
    FunctionMachine functionMachine;

    Connected(FunctionMachine fm) {
        this.functionMachine = fm;
    }
    public void disconnect() {
        functionMachine.setConnectState(functionMachine.getDisconnect());
    }
}
