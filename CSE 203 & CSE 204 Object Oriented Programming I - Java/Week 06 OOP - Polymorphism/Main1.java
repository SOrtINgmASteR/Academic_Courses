public class Main1 {
    public static void main(String[] args) {
        ArithmeticOperations ao = new ArithmeticOperations();
        ao.summation(5, 6);
        ao.summation(5, 6, 7);
        ao.summation(7, 8, 9, 10);
        ao.summation(5.5, 6.6);
        ao.multiplication(7, 6);
        ao.multiplication(7, 6, 8);
        ao.multiplication(7, 6,7, 8);
        ao.multiplication(6.6, 7.7);

        SubClassOfArithmeticOperations sao = new SubClassOfArithmeticOperations();
        sao.summation(5, 6);
        sao.summation(5, 6, 7, 8);
        sao.multiplication(5, 6);
        sao.multiplication(5, 6, 7, 8);
    }
}