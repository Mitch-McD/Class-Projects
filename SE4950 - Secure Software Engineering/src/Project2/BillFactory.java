package Project2;

public class BillFactory extends ASSF {
    // Factory for handling returning bill information
    @Override
    public BillRecordStrategy getStrategy(Credentials credentials) {
        switch(credentials.getLevel()) {
            case PATIENT:
                return new B_Patient(); // patient level
            case PCP:
            case CONSULT:
                return new B_MedStaff(); // PCP and consult level
            case ADMIN:
                return new B_Admin(); // admin level (see comment in class for more info)
            default:
                return new B_Deny(); // default failsafe
        }
    }
}
