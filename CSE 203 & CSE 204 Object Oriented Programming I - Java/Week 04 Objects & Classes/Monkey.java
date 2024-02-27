public class Monkey {
    static String animalClass = "Vertebrates";
    String breed;
    double weight;
    double height;
    public Monkey(String b, double w, double h){
        breed = b;
        weight = w;
        height = h;
    }
    public void eat(float foodWeight){
        weight += foodWeight;
    }
    public void grow(){
        height += 0.1;
    }
    public void display(){
        System.out.println("Breed : " + breed);
        System.out.println("Weight : " + weight);
        System.out.println("Height : " + height);
    }
}
