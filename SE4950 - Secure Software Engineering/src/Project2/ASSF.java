package Project2;

public abstract class ASSF {
    // set default factory to Bills
    static private ASSF instance = new BillFactory();

    static public void setInstance(ASSF newInstance) {
        instance = newInstance;
    }

    static public ASSF getInstance() {
        return instance;
    }

    abstract public BillRecordStrategy getStrategy(Credentials credentials);
}
