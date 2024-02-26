public class Main {
    public static void main(String[] args) {
        Pokemon p = new Pokemon();
        p.power = 10;
        p.pokemonName = "Pikachu";
        p.attack();
        p.printPower();

        Pokemon p1 = new Pokemon(11, "Bulbasor");
        p1.attack();
        p1.printPower();
    }
}