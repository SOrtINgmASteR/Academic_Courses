//Array Declaration & Initialization
public class Class01 {
    public static void main(String[] args) {
        int array1[] = new int[5], array2[] = new int[5];
        int [] array3 = new int[5], array4 = new int[5];

        int array5[] = {1, 2, 3, 4, 5, 6};

        array1[0] = 50;
        array1[1] = 51;
        array1[2] = 52;
        array1[3] = 53;
        array1[4] = 54;

        array2[0] = 60;
        array2[1] = 61;
        array2[2] = 62;
        array2[3] = 63;
        array2[4] = 64;

        array3[0] = 70;
        array3[1] = 71;
        array3[2] = 72;
        array3[3] = 73;
        array3[4] = 74;

        array4[0] = 80;
        array4[1] = 51;
        array4[2] = 52;
        array4[3] = 53;
        array4[4] = 54;

        System.out.print(array1[0]+" "+array1[1]+" "+array1[2]+" "+array1[3]+" "+array1[4]+"\n");
        System.out.print(array2[0]+" "+array2[1]+" "+array2[2]+" "+array2[3]+" "+array2[4]+"\n");
        System.out.print(array3[0]+" "+array3[1]+" "+array3[2]+" "+array3[3]+" "+array3[4]+"\n");
        System.out.print(array4[0]+" "+array4[1]+" "+array4[2]+" "+array4[3]+" "+array4[4]+"\n");
    }
}