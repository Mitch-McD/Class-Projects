package Project2;

public class RecordFactory extends ASSF {
    // Factory for handling returning record information
    @Override
    public BillRecordStrategy getStrategy(Credentials credentials) {
        switch(credentials.getLevel()) {
            case PATIENT:
                return new R_Patient(); // patient level
            case PCP:
                return new R_PCP(); // primary care physician level
            case CONSULT:
                return new R_Consult(); // consulting physician level
            case ADMIN:
            default:
                return new R_Deny(); // default (invalid level, failsafe) or administrative professional level
        }
    }
}
