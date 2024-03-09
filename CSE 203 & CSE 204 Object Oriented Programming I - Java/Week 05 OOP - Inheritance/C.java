public class C extends B{
    int intC;
    String strC;
    public C(){

    }
    public C(int intA, int intB, int intC){
        this.intA = intA;
        this.intB = intB;
        this.intC = intC;
    }
    public C(String strA, String strB, String strC){
        this.strA = strA;
        this.strB = strB;
        this.strC = strC;
    }
    public C(int intA, int intB, int intC, String strA, String strB, String strC){
        this.intA = intA;
        this.intB = intB;
        this.intC = intC;
        this.strA = strA;
        this.strB = strB;
        this.strC = strC;
    }
    public void methodC(){
        System.out.println("Method in C.");
    }
}
