public class SubClassOfArithmeticOperations extends ArithmeticOperations{
    @Override
    public void summation(int a, int b){
        System.out.println("This method is Overridden");
    }
    @Override
    public void summation(int a, int b, int c){
        System.out.println("This method is Overridden");
    }
    @Override
    public void multiplication(int a, int b){
        System.out.println("This method is Overridden");
    }
    @Override
    public void multiplication(int a, int b, int c){
        System.out.println("This method is Overridden");
    }
}