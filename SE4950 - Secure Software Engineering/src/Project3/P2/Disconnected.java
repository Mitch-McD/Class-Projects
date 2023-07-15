package Project3.P2;

public class Disconnected extends ConnectionState {
    FunctionMachine functionMachine;

    Disconnected(FunctionMachine fm) {
        this.functionMachine = fm;
    }
    void connect() {
        functionMachine.setConnectState(functionMachine.getConnect());
    }
}
