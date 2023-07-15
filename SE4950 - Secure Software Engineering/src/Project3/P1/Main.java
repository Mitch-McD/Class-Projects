package Project3.P1;

public class Main {
    public static void main(String[] args) {

        // FYI: This code is runnable

        Book book = new Book();

        // Test cases:

        // Write and accept book (writing -> reviewing -> published)
        book.write();
        book.accept();

        // any further state changes can't take place
        book.write();
        book.reject();
        book.accept();

        System.out.println();

        book = new Book();

        // Write and reject book (writing -> reviewing -> writing)
        book.write();
        book.reject();

        // trying to accept or reject again doesn't work
        book.accept();
        book.reject();

        // writing and then trying to write again doesn't work (writing -> writing)
        book.write();
        book.write();

        book.accept();

    }
}
