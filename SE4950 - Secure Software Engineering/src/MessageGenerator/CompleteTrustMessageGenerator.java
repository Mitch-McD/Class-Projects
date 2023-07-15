package MessageGenerator;

public class CompleteTrustMessageGenerator extends MessageGenerator {
    public String genFaultMessage(FaultCode code, String moreInfo) {
      // To completely trusted clients we will always return as much
      // information as possible regarding faults.
      return fillOutMessage(code, getErrorString(code) + " " + moreInfo);
    }
}

