package Project2;

public class B_MedStaff extends Bills {
    // runs if bills is run with either primary care physician or consulting physician level
    // (Admin has its own class)
    @Override
    public void run() {
        System.out.println("You got the bills for the med staff.");
    }
}
