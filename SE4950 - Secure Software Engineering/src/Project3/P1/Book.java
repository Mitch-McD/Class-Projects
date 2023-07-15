package Project3.P1;


public class Book {
    // define states
    private State writing;
    private State reviewing;
    private State published;

    // book's current state
    private State state;

    public Book() {
        // init states
        writing = new Writing(this);
        reviewing = new Reviewing(this);
        published = new Published(this);

        // default state is writing
        state = writing;
    }

    public State getWriting() { return writing; }
    public State getReviewing() { return reviewing; }
    public State getPublished() { return published; }

    public void setState(State state) { this.state = state; }

    // state change methods
    public void write() { state.write(); }
    public void accept() { state.accept(); }
    public void reject() { state.reject(); }
}
