public class Main {
    public static void main(String[] args) {
        A a = new A();
        a.intA = 10;
        a.strA = "A class.";
        System.out.println(a.intA + " " + a.strA);
        a.methodA();


        B b = new B();
        b.intA = 100;
        b.intB = 1000;
        b.strA = "B class.";
        b.strB = "B class.";
        System.out.println(b.intA + " " + b.intB + " " + b.strA +" " + b.strB);
        b.methodB();
        b.methodA();

        C c = new C();
        c.intA = 10000;
        c.intB = 100000;
        c.intC = 1000000;
        c.strA = "C class";
        c.strB = "C class";
        c.strC = "C class";
        System.out.println(c.intA + " " + c.intB + " " + c.intC + " " + c.strA +" " + c.strB + " " + c.strC);
        c.methodA();
        c.methodB();
        c.methodC();

        c.commonMethod();

    }
}