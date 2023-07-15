package Project3.P1;

public class Reviewing implements State {

    private Book book;

    public Reviewing(Book book){ this.book = book; }

    // Invalid transfer
    public void write() { System.out.println("Book has already been written!"); }
    // Reviewing -> Writing
    public void reject() {
        System.out.println("Rejected book!");
        book.setState(book.getWriting());
    }
    // Reviewing -> Published
    public void accept() {
        System.out.println("Accepted, publishing book!");
        book.setState(book.getPublished());
    }
}
