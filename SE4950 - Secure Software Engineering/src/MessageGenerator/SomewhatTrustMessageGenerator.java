package MessageGenerator;

public class SomewhatTrustMessageGenerator extends MessageGenerator {
    public String genFaultMessage(FaultCode code, String moreInfo) {
        // To somewhatly trusted clients we will return the basic error
        // information, but leave out the additional error information.
        return fillOutMessage(code, getErrorString(code));
    }
}

