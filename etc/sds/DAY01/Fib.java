package sds.DAY01;

public class Fib {

    public static void main(String[] args) {
        System.out.println("=== result ===");
        System.out.println(fib(4));
    }

    static int fib(int n) {
        if (n == 1 || n == 2) {
            return 1;
        }
        return fib(n-1) + fib(n-2);
    }
}
