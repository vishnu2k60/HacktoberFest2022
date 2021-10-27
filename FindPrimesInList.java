import java.util.function.*;
import java.util.stream.*;
import java.util.*;
public class FindPrimesInList {
    public static final Predicate<Integer> findPrime = (x) -> {
        if(x <= 1){
              return false;
          }
          if(x==2 || x==3){
              return true;
          }
          if(x%2 == 0){
              return false;
          }
          for(int i=3;i<=Math.sqrt(x);i+=2){
              if(x%i == 0){
                  return false;
              }
          }
          return true;
    };
    public static final Function<List<Integer>,List<Integer>> fun = (arr) -> arr.stream().filter(findPrime).collect(Collectors.toList());
    public static void main(String args[]) {
        List<Integer> a1 = new ArrayList<>(Arrays.asList(13,122,32,11,111,44,53,33,97));
        List<Integer> a2 = new ArrayList<>(Arrays.asList(231,10,9,8,76,73,81));
        System.out.println(fun.apply(a1));
        System.out.println(fun.apply(a2));
    }
}
//OUTPUT IS
//[13, 11, 53, 97]
//[73]
