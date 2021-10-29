import java.util.*;

public class patterns {
    public static void main(String argc[]) {
        int b = 1;
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        for (int i = 1; i<=a; i++) {

               for (int j2 = 0; j2 < i; j2++) {
                System.out.print(" *");
               }
               for (int j3 = 0; j3 < 2*a-2*i; j3++) {
                System.out.print("  ");
               }
               for (int j4 = 0; j4 < i; j4++) {
                System.out.print(" *");
               }

            System.out.println("");
        }

        for (int i = 0; i <a; i++) {

            for (int j2 = 0; j2 < a-i; j2++) {
             System.out.print(" *");
            }
            for (int j3 = 0; j3 <2*i; j3++) {
             System.out.print("  ");
            }
            for (int j4 = 0; j4 < a-i; j4++) {
             System.out.print(" *");
            }

         System.out.println("");
     }
    }

}
