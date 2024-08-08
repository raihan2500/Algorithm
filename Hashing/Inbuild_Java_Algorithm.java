import java.util.*;

public class Inbuild_Java_Algorithm {

    static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        String a = in.next();
        String b = in.next();

        a = a.replace(b, "#");
        
        int cnt = 0;
        for(int i = 0; i < a.length(); i++){
            if(a.charAt(i) == '#'){
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}