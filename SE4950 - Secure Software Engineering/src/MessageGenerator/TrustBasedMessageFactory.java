package MessageGenerator;

public class TrustBasedMessageFactory extends MessageFactory {
    private MessageGenerator complete = 
        new CompleteTrustMessageGenerator();
    private MessageGenerator somewhat = 
        new SomewhatTrustMessageGenerator();
    private MessageGenerator none = 
        new NoneTrustMessageGenerator();
    public MessageGenerator getMessageGenerator(TrustLevel trust) {
        switch(trust.level) {
            case COMPLETE:
                return complete;
            case SOMEWHAT:
                return somewhat;
            case LITTLE:
                return somewhat;
            case NONE:
                return none;
            default:
                return none;
        }
    }
};

