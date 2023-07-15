package Project2;

public class Credentials {
    // different trust levels
    enum Level { PATIENT, PCP, CONSULT, ADMIN }

    private Level level;

    // trust level is set at creation of object, cannot be changed
    public Credentials(Level level) {
        this.level = level;
    }

    // return trust level
    public Level getLevel() {
        return this.level;
    }
}
