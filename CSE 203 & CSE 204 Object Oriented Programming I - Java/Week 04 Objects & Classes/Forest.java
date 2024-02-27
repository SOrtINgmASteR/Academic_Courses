public class Forest {
    public static void main(String[] args) {
        Monkey monkey1 = new Monkey("Pigmy", 0.25, 0.5);
        Monkey monkey2 = new Monkey("Mandril", 0.25, 0.45);
        monkey1.eat(0.1f);
        Monkey.animalClass = "Spinal";
        monkey2.grow();
        monkey1.display();
        monkey2.display();
    }
}
