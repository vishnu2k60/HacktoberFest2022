// This program calculate perimeter value of different shapes


import java.util.Scanner;
 
public class perimeter{
    public static void main(String[] arr){
        System.out.println("Enter whoes perimeter you want to calculate(c/et/p/rec/sq): ");
        // c=Circle , et=Equilateral triangle, p=Parallelogram, rec=Ractangle, sq=Square 
        Scanner scan = new Scanner(System.in);
        String figer = scan.next();

        switch(figer){
            case "c":{
                System.out.println("Enter value of radius(r): ");
                int r = scan.nextInt();
                System.out.println("Perimeter of Circle: " + (2*3.14*r));
                break;
            }
             case "et":{
                System.out.println("Enter value of side(a): ");
                int a = scan.nextInt();
                System.out.println("Perimeter of Equilateral triangle: " + (3*a));
                break;
            }
             case "p":{
                System.out.println("Enter two sides of parallelogram(a,b): ");
                int a = scan.nextInt();
                int b = scan.nextInt();
                System.out.println("Perimeter of Parallelogram: " + (2*(a+b)));
                break;
            }
             case "rec":{
                System.out.println("Enter length and width of Rectangle(l,w): ");
                int l = scan.nextInt();
                int w = scan.nextInt();
                System.out.println("Perimeter of Ractangle: " + (2*(l+w)));
                break;
            }
             case "sq":{
                System.out.println("Enter value of side(s): ");
                int s = scan.nextInt();
                System.out.println("Perimeter of Square: " + (4*s));
                break;
            }
            default: {
                System.out.println("none");
                break;
            }
        }
    }
}
