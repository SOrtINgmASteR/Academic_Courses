public class C extends B{
    int intC;
    String strC;
    public C(){

    }
    public C(int intA, int intB, int intC){
        super(intA, intB);
        this.intC = intC;
    }
    public C(String strA, String strB, String strC){
        super(strA, strB);
        this.strC = strC;
    }
    public C(int intA, int intB, int intC, String strA, String strB, String strC){
        super(intA, intB, strA, strB);
        this.intC = intC;
        this.strC = strC;
    }
    public void methodC(){
        System.out.println("Method in C.");
    }
    public void commonMethod(){
        super.commonMethod();
    }
}
