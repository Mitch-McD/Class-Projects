package MessageGenerator;

interface Strategy{
    void run();
}

abstract class Strategy1 implements Strategy{
    public abstract void run();

}

abstract class Strategy2 implements Strategy{
    public abstract void run();
}

class HighTrustStrategy1 extends Strategy1{
    public void run(){
        System.out.println("Run factory 1 high trust object ");
    }
}

class MiddleTrustStrategy1 implements Strategy{
    public void run(){
        System.out.println("Run factory 1 middle trust object");
    }
}

class LowTrustStrategy1 implements Strategy{
    public void run(){
        System.out.println("Run factory 1 low trust object");
    }
}

class DefaultTrustStrategy1 implements Strategy{
    public void run(){
        System.out.println("Run factory 1 default trust object");
    }
}

class HighTrustStrategy2 implements Strategy{
    public void run(){
        System.out.println("Run factory 2 high trust object ");
    }
}

class MiddleTrustStrategy2 implements Strategy{
    public void run(){
        System.out.println("Run factory 2 middle trust object");
    }
}

class LowTrustStrategy2 implements Strategy{
    public void run(){
        System.out.println("Run factory 2 low trust object");
    }
}

class DefaultTrustStrategy2 implements Strategy{
    public void run(){
        System.out.println("Run factory 2 default trust object");
    }
}


class SecurityCredentials{
    public String text="";

    public SecurityCredentials(String text) {
        this.text=text;
    }
}

abstract class AbstractSecureStrategyFactory{
    static private AbstractSecureStrategyFactory defaultInstance=new ConcreteSecureFactory1();
    static AbstractSecureStrategyFactory getInstance(){
        return defaultInstance;
    }

    static void setInstance(AbstractSecureStrategyFactory newInstance){
        defaultInstance=newInstance;
    }

    abstract Strategy getStrategy(SecurityCredentials givenCredentials);
}

////

class ConcreteSecureFactory1 extends AbstractSecureStrategyFactory {


    @Override
    public Strategy getStrategy(SecurityCredentials givenCredentials) {
        System.out.println("This is ConcreteSecureFactory1");
        switch (givenCredentials.text) {
            case "high":
                return new HighTrustStrategy1();
            case "middle":
                return new MiddleTrustStrategy1();
            case "low":
                return new LowTrustStrategy1();
        }
        return new DefaultTrustStrategy1();
    }
}

class ConcreteSecureFactory2 extends AbstractSecureStrategyFactory {


    @Override
    public Strategy getStrategy(SecurityCredentials givenCredentials) {
        System.out.println("This is ConcreteSecureFactory2");
        switch (givenCredentials.text) {
            case "high":
                return new HighTrustStrategy2();
            case "middle":
                return new MiddleTrustStrategy2();
            case "low":
                return new LowTrustStrategy2();
        }
        return new DefaultTrustStrategy2();
    }
}


public class Main{
    public static void main(String args[]){

        System.out.println(AbstractSecureStrategyFactory.getInstance().toString());
        AbstractSecureStrategyFactory.setInstance(new ConcreteSecureFactory1());

        //just to try getInstance and setInstance work or not
        System.out.println(AbstractSecureStrategyFactory.getInstance().toString());
//        AbstractSecureStrategyFactory.setInstance(new ConcreteSecureFactory2());
        System.out.println(AbstractSecureStrategyFactory.getInstance().toString());

        //get the ConcreteSecureFactory
        AbstractSecureStrategyFactory currentFactory=AbstractSecureStrategyFactory.getInstance();
        //AbstractSecureFactory newFactory=new ConcreteSecureFactory1();

        //create  object
        SecurityCredentials givenCredentials=new SecurityCredentials("high");
        Strategy secureObject= currentFactory.getStrategy(givenCredentials);
        secureObject.run();

    }
}