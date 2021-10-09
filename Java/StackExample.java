package Java;// stack using array
import java.util.Scanner;
class StackExample {
    // declaring array and top of the stack
    int ar[];
    int top;
    StackExample(){
        // initializing size of array
        ar = new int[5];
        top = -1;
    }
    // making method push to insert element in stack
    void push(){
        if(top == 4){
            System.out.println("Stack is full");
        }
        else{
            System.out.println("Enter data");
            Scanner sc1 = new Scanner(System.in);
            int data = sc1.nextInt();
            top = top + 1;
            ar[top] = data;
            System.out.println("data inserted...");
        }
    }
    // making method pop to delete element form stack
    void pop(){
        if(top==-1){
            System.out.println("Stack is empty...");
        }
        else{
            System.out.println("deleted..."+ar[top]);
            top=top-1;
        }
    }
    // making method to traverse the elements in stack
    void traverse(){
        if(top==-1){
            System.out.println("Stack is empty");
        }
        else{
            for(int i=top; i>=0; i--){
                System.out.println(ar[i]);
            }
        }
    }

    // main method to implement Stack using array with menu driven program
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        StackExample obj = new StackExample();
        while(true){
            System.out.println("Press 1 for push");
            System.out.println("Press 2 for pop");
            System.out.println("Press 3 for Traverse");
            System.out.println("Press 4 for exit");
            System.out.println("Enter your choice");
            int ch = sc.nextInt();
            switch(ch){
                case 1:
                    obj.push();
                    break;
                case 2:
                    obj.pop();
                    break;
                case 3:
                    obj.traverse();
                    break;
                case 4:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Wrong choice");
            }
        }
    }
}
