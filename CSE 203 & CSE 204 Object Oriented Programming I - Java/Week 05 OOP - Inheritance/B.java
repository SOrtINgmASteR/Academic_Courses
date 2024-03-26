public class B extends A{
    int intB;
    String strB;
    public B (){

    }
    public B (int intA, int intB){
        super(intA);
        this.intB = intB;
    }
    public B (String strA, String strB){
        super(strA);
        this.strB = strB;
    }
    public B (int intA, int intB, String strA, String strB){
        super(intA, strA);
        this.intB = intB;
        this.strB = strB;
    }
    public void methodB(){
        System.out.println("Method in B.");
    }
    public void commonMethod(){
        super.commonMethod();
        //System.out.println("Common method in B.");
    }
}
