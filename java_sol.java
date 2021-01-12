import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
       Scanner in = new Scanner(System.in);
       int tt = in.nextInt();
       for (int qq = 1; qq <= tt; qq++) {
           String s = in.next();
           int[] alphabet = new int[26];
           Arrays.fill(alphabet, 0);
           for (int i = 0; i < (int) s.length(); i++) {
               alphabet[(int) s.charAt(i) - 'a']++;
           }
           Vector<Integer> distinct = new Vector<Integer>();
           for (int x : alphabet) {
               if (x > 0) {
                   distinct.add(x);
               }
           }
           Collections.sort(distinct);
           boolean checker1 = true;
           boolean checker2 = true;
           if (distinct.size() > 2) {
            for (int i = 2; i < (int) distinct.size(); i++) {
                if (distinct.get(i) != distinct.get(i - 1) + distinct.get(i - 2)) {
                    checker1 = false;
                    break;
                }
            }
            int tmp = distinct.get(0);
            distinct.set(0, distinct.get(1));
            distinct.set(1, tmp);
            for (int i = 2; i < (int) distinct.size(); i++) {
                if (distinct.get(i) != distinct.get(i - 1) + distinct.get(i - 2)) {
                    checker2 = false;
                    break;
                }
            }
           }
           System.out.println(checker1 || checker2 ? "Dynamic" : "Not");
       }
    }
}
