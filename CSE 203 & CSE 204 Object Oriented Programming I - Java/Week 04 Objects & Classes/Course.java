public class Course {
    public static void main(String[] args) {
        ClassTest ct1 = new ClassTest("Priom", 17, 3, 20);
        ClassTest ct2 = new ClassTest("Tausif", 10, 4, 20);
        ct1.addQuestion((34 % 13) + 3);
        ct1.display();
        ct2.display();
    }
}
