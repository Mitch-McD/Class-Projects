package MessageGenerator;

import Project2.BillFactory;

abstract class ASSF {
    static private ASSF instance = new CF1();

    static public void setInstance(ASSF newInstance) {
        instance = newInstance;
    }

    static public ASSF getInstance() {
        return instance;
    }

    abstract request foo();
}

class CF1 extends ASSF {
    public request foo() {
        return new Bills();
    }
}

class CF2 extends ASSF {
    public request foo() {
        return new Records();
    }
}

interface request {
    public void run();
}

class Bills implements request {
    public void run() {
        System.out.println("This is TL1!");
    }
}

class Records implements request {
    public void run() {
        System.out.println("This is TL2!");
    }
}


public class InterfaceDemo {
    public static void main(String[] args) {

    }

}
