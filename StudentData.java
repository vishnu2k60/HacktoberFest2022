import java.util.*;
 class Studentt
{
    int sno;
    String sname;
    Scanner sc=new Scanner(System.in);
    void get()
    {
        System.out.println("enter Student roll number:");
        sno=sc.nextInt();
        System.out.println("Enter Student name");
        sname=sc.next();
    }
    void disp()
    {
        System.out.println(sno+"\t"+sname);
    }
}
class Stud1 extends Studentt
{

    String crs;
    float fs;
    void get1()
    {
        super.get();
        System.out.println("enter course name and fess:");
        crs=sc.next();
        fs=sc.nextFloat();
    }
    void disp()
    {
        super.disp();
        System.out.println("course name="+crs);
        System.out.println("fess="+fs);
    }
   
    public static void main(String[] a)
    {
        Stud1 ss=new Stud1();
        ss.get1();
        ss.disp();
    }
}
