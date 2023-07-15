package MessageGenerator;

public class NoneTrustMessageGenerator extends MessageGenerator {
    public String genFaultMessage(FaultCode code, String moreInfo) {
          // For clients that are not trusted, we will just tell them if the
          // error was a client or server error. They will get no more
          // information.
          FaultCode newCode = FaultCode.SERVER_ERROR;
          switch (code) {
              case SERVER_ERROR:
              case MALFORMED_RESPONSE: 
                newCode = FaultCode.SERVER_ERROR;
                break;
              case CLIENT_ERROR:
              case REQUEST_TOO_LONG:
              case TOO_MANY_FAULTY_REQUESTS:
              case MALFORMED_CLIENT_REQUEST:
              case UNKNOWN_METHOD:
              case UNAUTHORIZED_METHOD:
              case INVALID_METHOD_ARGUMENTS: 
                newCode = FaultCode.CLIENT_ERROR;
                break; 
          }
          return fillOutMessage(code, getErrorString(newCode));
    }
}

