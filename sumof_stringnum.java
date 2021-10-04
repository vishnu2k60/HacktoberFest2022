// sum of numbers present in string here-->57+25+2021

public class sumof_stringnum{
    public static void main(String[] arr){
        String str = "hello57to25hacktoberfest2021w";
        String num = "";
        int sum = 0;
        for(int i = 0; i<str.length(); i++){
          
            if(Character.isDigit(str.charAt(i))){
                num = num + str.charAt(i);
            }
            else{
                if(!num.equals("")){
                    sum = sum + Integer.parseInt(num);
                    num="";
                }
            }

        }
        System.out.println(sum);
    }
}
