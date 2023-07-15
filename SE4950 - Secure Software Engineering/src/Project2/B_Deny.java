package Project2;

public class B_Deny extends Bills {
    // runs if bills is run and invalid level is called (default failsafe)
    @Override
    public void run() {
        System.out.println("You were denied bill access.");
    }
}
