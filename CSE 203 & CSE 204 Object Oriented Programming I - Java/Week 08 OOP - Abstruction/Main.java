public class Main {
    public static void main(String[] args) {
        ChildClass c = new ChildClass();
        c.method1(34, "Priom");
        int a = c.method2();
        System.out.println(a);
        c.sum(10, 20);
        c.summation(10, 20, 30);
        c.multiplication(5, 5, 5);

    }
}