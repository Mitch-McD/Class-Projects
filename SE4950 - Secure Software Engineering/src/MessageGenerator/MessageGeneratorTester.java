package MessageGenerator;

public class MessageGeneratorTester {
    
  public static void main(String[] args) {
    TrustLevel currClient = new TrustLevel();
    currClient.level = TrustLevel.Level.NONE;

    MessageFactory.setInstance(new TrustBasedMessageFactory());
    // First, get the current concrete message generation strategy factory.
    MessageFactory messageGenFactory = MessageFactory.getInstance();
    // Then get the appropriate strategy for generating a message given
    // the current clients trust level.
    MessageGenerator currMsgGen =
      messageGenFactory.getMessageGenerator(currClient);
    // Generate the XML-RPC fault message with the correct amount of
    // information.
    // This example fault message is sent when a client request is too long.
    String errMsg = currMsgGen.genFaultMessage(
            MessageGenerator.FaultCode.REQUEST_TOO_LONG,
            "The maximum request length is " +
            Integer.toString(MessageGenerator.maxRequestSize));
    System.out.println(errMsg);
    }
}
