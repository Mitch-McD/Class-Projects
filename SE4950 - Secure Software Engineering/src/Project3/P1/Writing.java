package Project3.P1;

public class Writing implements State {

    private Book book;

    public Writing(Book book){ this.book = book; }

    // Writing -> Reviewing
    public void write() {
        System.out.println("Book has been written!");
        book.setState(book.getReviewing());
    }
    // Invalid transfer
    public void reject() { System.out.println("Cannot be rejected, hasn't been written yet!"); }
    // Invalid transfer
    public void accept() { System.out.println("Cannot be accepted, hasn't been written yet!"); }
}
