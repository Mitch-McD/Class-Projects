package Project2;

public class Main {
    public static void main(String[] args) {

        /*
        Note: This code is runnable, and seems to work based on my testing.

        Four trust levels, PATIENT, ADMIN (Administrative Professional), CONSULT (Consulting Physician),
        and PCP (Primary Care Physician).

        Note: Went ahead and added two more classes than prescribed, B_Deny and B_Admin - B_Deny is the default
        catch-all / failsafe (I get a NullPointerException if I try to return null as the default casE), and B_Admin
        is for the Administrative assistant as I couldn't figure out how to return two objects (B_Patient and
        B_MedStaff) at the same time.

         */

        // Create credentials object - Can be either PATIENT, ADMIN, PCP, or CONSULT
        Credentials securityCredentials = new Credentials(Credentials.Level.ADMIN);

        // set the instance to the bill factory and create a factory object
        ASSF.setInstance(new BillFactory());
        ASSF factory = ASSF.getInstance();

        // create strategy object with instance of bill factory and run it with security credentials set beforehand
        BillRecordStrategy obj = factory.getStrategy(securityCredentials);
        obj.run();

        // set the instance to the record factory and update the factory object
        ASSF.setInstance(new RecordFactory());
        factory = ASSF.getInstance();

        // update strategy object to the record factory instance and run it with security credentials set beforehand
        obj = factory.getStrategy(securityCredentials);
        obj.run();
    }

}
