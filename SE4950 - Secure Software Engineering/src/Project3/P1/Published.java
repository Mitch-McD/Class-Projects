package Project3.P1;

public class Published implements State {

    private Book book;

    public Published(Book book){ this.book = book; }

    // Invalid transfer
    public void write() { System.out.println("Can't write, book is already published!"); }
    // Invalid transfer
    public void reject() { System.out.println("Can't reject, book is already published!"); }
    // Invalid transfer
    public void accept() { System.out.println("Can't accept, book is already published!"); }
}
