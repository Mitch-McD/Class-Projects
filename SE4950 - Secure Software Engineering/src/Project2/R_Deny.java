package Project2;

public class R_Deny extends Records {
    // Runs if record factory is run with either admin or invalid trust level
    @Override
    public void run() {
        System.out.println("You were denied record access.");
    }
}
