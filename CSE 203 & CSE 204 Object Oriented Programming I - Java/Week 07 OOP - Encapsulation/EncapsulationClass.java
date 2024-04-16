public class EncapsulationClass {
    private int a;
    private String b;
    private double c;

    //Setter Methods
    public void setA(int a) {
        this.a = a;
    }
    public void setB(String b) {
        this.b = b;
    }
    public void setC(double c) {
        this.c = c;
    }

    //Getter Methods
    public int getA() {
        return a;
    }
    public String getB() {
        return b;
    }
    public double getC() {
        return c;
    }

    public void printAllData(){
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
    }
}
