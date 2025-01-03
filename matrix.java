package bmsit;
import java.util.Scanner;
public class matrix {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Please provide the value of N as a command line argument.");
            return;
        }
        int N = Integer.parseInt(args[0]);
        int[][] matrix1 = new int[N][N], matrix2 = new int[N][N], result = new int[N][N];
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter elements of first matrix:");
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                matrix1[i][j] = sc.nextInt();

        System.out.println("Enter elements of second matrix:");
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                matrix2[i][j] = sc.nextInt();

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                result[i][j] = matrix1[i][j] + matrix2[i][j];

        System.out.println("Resultant matrix:");
        for (int[] row : result) {
            for (int val : row)
                System.out.print(val + " ");
            System.out.println();
        }
        sc.close();
    }
}
