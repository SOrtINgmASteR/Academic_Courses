public class A {
    int intA;
    String strA;
    public A(){

    }
    public A(int intA){
        this.intA = intA;
    }
    public A(String strA){
        this.strA = strA;
    }
    public A(int intA, String strA){
        this.intA = intA;
        this.strA = strA;
    }
    public void methodA(){
        System.out.println("Method in A.");
    }
    public void commonMethod(){
        System.out.println("Common method in A.");
    }
}
