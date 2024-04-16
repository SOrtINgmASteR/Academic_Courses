public class Main {
    public static void main(String[] args) {
        EncapsulationClass object = new EncapsulationClass();
        //Setter Method
        object.setA(34);
        object.setB("Priom");
        object.setC(3.81);
        object.printAllData();

        object.setA(4);
        object.setB("Ovi");
        object.setC(3.81);
        object.printAllData();

        //Getter Method
        int a = object.getA();
        String b = object.getB();
        double c = object.getC();
        System.out.println(a+"\n"+b+"\n"+c);
    }
}