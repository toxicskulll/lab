package bmsit;
import java.util.Scanner;

class ss1 {
private int top = -1;
private  int max_size = 10;
private int[] stack = new int[max_size];

Scanner input = new Scanner(System.in);

public void push() {
   if (top == (max_size - 1)) 
       System.out.println("Stack overflow");                                 
   else {
       System.out.println("Enter the item to be pushed:");
       int item = input.nextInt();
       stack[++top] = item;
   }
}


public void pop() {
   if (top == -1) 
       System.out.println("Stack underflow");
    else {
       int item = stack[top--];
       System.out.println("Popped element: " + item);
   }
}


public void display() {
   if (top == -1) 
       System.out.println("Stack is empty ");
    else {
       System.out.println("elements are: ");
       for (int i = top; i >= 0; i--) {
           System.out.printf("%d  ", stack[i]);
       }
       System.out.println();                                             
   }
}
}

public class print {

	public static void main(String[] args) {
	ss1 stack1 = new ss1();                                                                        
      Scanner input = new Scanner(System.in);
      int choice;

      while (true) {
          System.out.println("1. Push  2. Pop  3. Display  4. Quit");
          System.out.println("Enter your choice: ");

          choice = input.nextInt();
          switch (choice) {
              case 1:
                  stack1.push();
                  break;
              case 2:
                  stack1.pop();
                  break;
              case 3:
                  stack1.display();
                  break;
              case 4:
                  System.out.println("Exiting...");
                  input.close();
                  System.exit(0);                                               
              default:  
                  System.out.println("Wrong choice! ");
                  
          }
          
      }

  }
  
}
