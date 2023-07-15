package SecureState;

abstract class SecurityState {
    boolean login(ExampleSystem controller,
                  EncryptedString password) { return false; }
    boolean logout(ExampleSystem controller) { return false; }
    boolean op1(ExampleSystem controller) { return false; }
    boolean op2(ExampleSystem controller) { return false; }
    boolean op3(ExampleSystem controller) { return false; }
    void changeState(ExampleSystem controller,
                     SecurityState newState) {
        controller.changeState(newState);
    }
}
