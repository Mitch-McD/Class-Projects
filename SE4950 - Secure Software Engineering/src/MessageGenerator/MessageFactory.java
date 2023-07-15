package MessageGenerator;

public abstract class MessageFactory {
    //! The current default concrete message generator factory.
    private static MessageFactory instance;

    public abstract MessageGenerator getMessageGenerator(TrustLevel trust);
    public static MessageFactory getInstance() { 
        return instance;
    }
    public static void setInstance(MessageFactory newFactory) { 
        instance = newFactory; 
    }
};

