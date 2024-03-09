public class B extends A{
    int intB;
    String strB;
    public B (){

    }
    public B (int intA, int intB){
        this.intA = intA;
        this.intB = intB;
    }
    public B (String strA, String strB){
        this.strA = strA;
        this.strB = strB;
    }
    public B (int intA, int intB, String strA, String strB){
        this.intA = intA;
        this.intB = intB;
        this.strA = strA;
        this.strB = strB;
    }
    public void methodB(){
        System.out.println("Method in B.");
    }
}
