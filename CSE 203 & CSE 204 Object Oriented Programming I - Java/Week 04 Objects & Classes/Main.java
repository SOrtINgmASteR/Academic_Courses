public class Main {
    public static void main(String[] args) {
        Pokemon p1 = new Pokemon(10, "Pikachu", 5);
        Pokemon p2 = new Pokemon();
        p2.pokemonAttackNumber = 7;
        p2.pokemonName = "Charmendar";
        p2.pokemonPower = 12;
        p1.printDetails();
        p2.printDetails();
        System.out.println(Pokemon.x);
    }
}