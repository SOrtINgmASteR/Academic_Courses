//Linear Search
public class Class05 {
    public static void main(String[] args) {
        int array[] = {-6, -3, -1, 4, 9, 15, 16, 18, 20, 23};
        int i, search_value = 16, flag;
        for(i = 0; i < 10; i++){
            if(array[i] == search_value){
                System.out.println(search_value + " is at " + i + " index.");
            }
        }
    }
}