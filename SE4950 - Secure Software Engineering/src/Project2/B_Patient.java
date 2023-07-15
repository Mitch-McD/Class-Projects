package Project2;

public class B_Patient extends Bills {
    // runs if bills is run with patient level (Admin has its own class)
    @Override
    public void run() {
        System.out.println("You got the bills for patient.");
    }
}
