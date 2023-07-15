package Project2;

public class B_Admin extends Bills {
    // runs if Bill factory is called with admin level (I didn't know how to merge MedStaff and Patient
    // without creating a new class entirely)
    @Override
    public void run() {
        System.out.println("You got the bills for patient and medstaff.");
    }
}
