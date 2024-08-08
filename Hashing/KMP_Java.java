import java.util.*;

public class KMP_Java {

    static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        String a = in.next();
        String b = in.next();

        String c = a;
        a = a.replace(b, "#");

        System.out.println(a);
    }
}