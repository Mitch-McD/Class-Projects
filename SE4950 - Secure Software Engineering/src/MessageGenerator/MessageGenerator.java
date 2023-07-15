package MessageGenerator;

public abstract class MessageGenerator {

  enum FaultCode { SERVER_ERROR, MALFORMED_RESPONSE,
                   CLIENT_ERROR, REQUEST_TOO_LONG,
                   TOO_MANY_FAULTY_REQUESTS,
                   MALFORMED_CLIENT_REQUEST,
                   UNKNOWN_METHOD, UNAUTHORIZED_METHOD,
                   INVALID_METHOD_ARGUMENTS; }
  final static int maxRequestSize = 256;

  protected static String fillOutMessage(FaultCode code, String moreInfo) {
    // Code to make message
    return moreInfo;
  }
  protected static String getErrorString(FaultCode code) {
    return code.toString();
  }
  public MessageGenerator() {};
  public abstract String genFaultMessage(FaultCode code, String moreInfo);
};

