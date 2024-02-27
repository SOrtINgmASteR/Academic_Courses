public class ClassTest {
    String name;
    int score;
    int noOfQuestions;
    int maxScore;
    public ClassTest(String n, int s, int nq, int ms){
        name = n;
        score = s;
        noOfQuestions = nq;
        maxScore = ms;
    }
    public void addQuestion(int mark){
        noOfQuestions += 1;
        score += mark;
        if(score > maxScore){
            noOfQuestions -= 1;
            score -= mark;
        }
    }
    public int getQuestionCount(){
        return noOfQuestions;
    }
    public void display(){
        System.out.println("Name : " + name);
        System.out.println("Score : " + score);
        System.out.println("number of Questions : " + noOfQuestions);
        System.out.println("Max Score : "+ maxScore);
    }

}
