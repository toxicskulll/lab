package bmsit;
public class print {
    public static void main(String[] args) {
        int a = 10, b = 10, result = 0;
        
        try {
            result = a / b;
        } catch (ArithmeticException e) {
            System.out.println("Error: Cannot divide by zero.");
        } finally {
            System.out.println("Done!");
        }
        System.out.println(result);
    }
}
