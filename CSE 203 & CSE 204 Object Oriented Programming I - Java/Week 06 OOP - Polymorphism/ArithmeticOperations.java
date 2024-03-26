public class ArithmeticOperations {
    int a;
    String b;
    //Overloading
    public void summation(int a, int b){
        System.out.println("Sum : " + (a + b));
    }
    public void summation(int a, int b, int c){
        System.out.println("Sum : " + (a + b + c));
    }
    public void summation(int a, int b, int c, int d){
        System.out.println("Sum : " + (a + b + c + d));
    }
    public void summation(double a, double b){
        System.out.println("Sum : " + (a + b));
    }
    public void multiplication(int a, int b){
        System.out.println("Mul : " + (a * b));
    }
    public void multiplication(int a, int b, int c){
        System.out.println("Mul : " + (a * b * c));
    }
    public void multiplication(int a, int b, int c, int d){
        System.out.println("Mul : " + (a * b * c * d));
    }
    public void multiplication(double a, double b){
        System.out.println("Mul : " + (a * b));
    }
}