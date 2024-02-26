public class Pokemon {
    int power;
    String pokemonName;
    public Pokemon(int p, String n){
        power = p;
        pokemonName = n;
    }
    public Pokemon(){

    }
    public void attack(){
        System.out.println("Attack!!");
    }
    public void printPower(){
        System.out.println("Pokemon Power : " + power);
    }
}