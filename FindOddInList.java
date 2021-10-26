import java.util.function.*;
import java.util.stream.*;
import java.util.*;
public class FindOddInList {
    public static final Predicate<Integer> findOdd = (x) -> {
        return x%2 != 0;
    };
    public static final Function<List<Integer>,List<Integer>> fun = (arr) -> arr.stream().filter(findOdd).collect(Collectors.toList());
    public static void main(String args[]) {
        List<Integer> a1 = new ArrayList<>(Arrays.asList(11,12,22,3,12,44,53,33));
        ArrayList<Integer> a2 = new ArrayList<>(Arrays.asList(231,10,9,8,76,73,81));
        System.out.println(fun.apply(a1));
        System.out.println(fun.apply(a2));
    }
}
//OUTPUT IS
//[11, 3, 53, 33]
//[231, 9, 73, 81]
