import java.util.*;

public class CGPACalculation {
    double semesterWiseGPA[] = new double[8];
    public void collectGPA(){
        Scanner input = new Scanner(System.in);
        for(int i = 0; i < 8; i++){
            try {
                System.out.print("Enter GPA for "+ (i+1) +" Semester : ");
                semesterWiseGPA[i] = input.nextDouble();
                isInRange(semesterWiseGPA[i]);
            }
            catch(InputMismatchException e){
                System.out.println("GPA need to be Double value");
                System.out.print("Please enter again.");
                input.next();
                i--;
            }
            catch (UserDefinedException e){
                System.out.println("GPA Out of Range. " + e.getMessage());
                i--;
            }
        }
    }
    public void isInRange(double gpa) throws UserDefinedException{
        if(gpa < 0.00){
            //System.out.println("GPA can't be less than 0.00");
            throw new UserDefinedException("GPA can't be less than 0.00");
        }
        else if(gpa > 4.00){
            //System.out.println("GPA can't be greater than 4.00");
            throw new UserDefinedException("GPA can't be greater than 4.00");
        }
    }

}
