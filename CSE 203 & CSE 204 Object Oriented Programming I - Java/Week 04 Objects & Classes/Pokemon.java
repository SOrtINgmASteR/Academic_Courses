public class Pokemon {
    static String x = "UAP";
    int pokemonPower;
    String pokemonName;
    int pokemonAttackNumber;
    public Pokemon(){

    }
    public Pokemon(int p, String s, int n){
        pokemonPower = p;
        pokemonName = s;
        pokemonAttackNumber = n;
    }
    public void attack(){
        System.out.println("Attack!!");
    }
    public void printDetails(){
        System.out.println("Pokemon Name : " + pokemonName);
        System.out.println("Pokemon Attack Number : " + pokemonAttackNumber);
        System.out.println("Pokemon Power : " + pokemonPower);
    }
}