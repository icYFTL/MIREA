package mirea.prac;

public class Main { //NOT READY
    public static void main(String[] args) {
        try {
            System.out.println(2 / 0); //Exception in thread "main" java.lang.ArithmeticException: / by zero
        }
        catch (ArithmeticException ex) {
            System.out.println("Attempted division by zero");
        }

    }
}