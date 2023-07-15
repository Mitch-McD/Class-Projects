package SecureState;

class UserCredentials
    {
    private String _name;
    private EncryptedString _pw;
    private boolean _admin;
    public UserCredentials(String name, EncryptedString pw, boolean admin) {
        _name = name;
        _pw = pw;
        }
    public String getName() { return _name; }
    public boolean validate(EncryptedString pw) { return pw.equals(_pw); }
    public boolean isAdministrator() { return _admin; }
    }
