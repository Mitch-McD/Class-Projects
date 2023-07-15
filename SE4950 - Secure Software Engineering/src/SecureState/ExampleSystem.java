package SecureState;

class ExampleSystem {
    private SecurityState _state;
    private UserCredentials _user;
    private UserFunctionsMachine userMachine;
    public ExampleSystem(UserCredentials user) {
        _user = user;
        userMachine = new UserFunctionsMachine(user);
        _state = NotLoggedIn.instance(user); }
    public void changeState(SecurityState newState) {
        _state = newState; }
    public UserCredentials getUser() { return _user; }
    public void login(EncryptedString password) {
        if (_state.login(this, password)) {
            userMachine.login(password);
            System.out.println("Logged in!");
        } else {
            System.out.println("Did not log in!");
        }
    }
    public void logout() {
        if (_state.logout(this)) userMachine.logout(); }
    public void op1() {
        if (_state.op1(this)) userMachine.op1(); }
    public void op2() {
        if (_state.op2(this)) userMachine.op2(); }
    public void op3() {
        if (_state.op3(this)) userMachine.op3(); }
}
