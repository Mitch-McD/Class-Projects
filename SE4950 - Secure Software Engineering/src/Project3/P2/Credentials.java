package Project3.P2;

public class Credentials {
    enum TrustLevel {USER,ADM,SUSER,INVALID};
    private String name;
    private String pwd;
    private TrustLevel trustLevel;

    Credentials(String n, String p, TrustLevel trustLevel) {
        this.name = n;
        this.pwd = p;
        this.trustLevel = trustLevel;
    }
    public String getName() {
        return this.name;
    }
    public boolean validate(String name, String pwd) {
        return this.name.equals(name) && this.pwd.equals(pwd);
    }
    public TrustLevel getTrustLevel() {
        return trustLevel;
    }
}
