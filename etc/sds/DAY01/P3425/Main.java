package sds.DAY01.P3425;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Main {

    static List<String> commend;
    static int X, N, input;
    static Stack<Integer> s = new Stack<>();
    static final int MAX = 1000000000;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY01/P3425/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true){
            String str;
            commend = new ArrayList<>();
            while (true){
                str = br.readLine();
                if (str.equals("END") || str.equals("QUIT")) break;
                commend.add(str);
            }

            if (str.equals("QUIT")) break;

            N = Integer.parseInt(br.readLine());

            for (int i = 0; i < N; i++){
                input = Integer.parseInt(br.readLine());
                run(input);
            }
            System.out.println();
        }
    }

    static void run(int input){
        // init
        s.clear();
        s.add(input);

        int idx = 0;
        int top, second;
        long total;
        boolean flag = false;
        while (idx != commend.size()){
            String[] str = commend.get(idx++).split(" ");

            switch (str[0]) {
                case "NUM":
                    X = Integer.parseInt(str[1]);
                    s.add(X);
                    break;
                case "POP":
                    if (isEmptyStack1()) {
                        flag = true;
                        break;
                    }
                    s.pop();
                    break;
                case "INV":
                    if (isEmptyStack1()) {
                        flag = true;
                        break;
                    }
                    top = s.pop();
                    s.add(-top);
                    break;
                case "DUP":
                    if (isEmptyStack1()) {
                        flag = true;
                        break;
                    }
                    top = s.peek();
                    s.add(top);
                    break;
                case "SWP":
                    if (isEmptyStack2()) {
                        flag = true;
                        break;
                    }
                    top = s.pop();
                    second = s.pop();
                    s.add(top);
                    s.add(second);
                    break;
                case "ADD":
                    if (isEmptyStack2()) {
                        flag = true;
                        break;
                    }
                    top = s.pop();
                    second = s.pop();
                    total = top + second;
                    if (total <= MAX) {
                        s.add((int) total);
                    } else {
                        flag = true;
                        System.out.println("ERROR");
                    }
                    break;
                case "SUB":
                    if (isEmptyStack2()) {
                        flag = true;
                        break;
                    }
                    top = s.pop();
                    second = s.pop();
                    total = second - top;
                    if (total >= -MAX) {
                        s.add((int) total);
                    } else {
                        flag = true;
                        System.out.println("ERROR");
                    }
                    break;
                case "MUL":
                    if (isEmptyStack2()) {
                        flag = true;
                        break;
                    }
                    top = s.pop();
                    second = s.pop();
                    total = (long) top * second;
                    if (total <= MAX) {
                        s.add((int) total);
                    } else {
                        flag = true;
                        System.out.println("ERROR");
                    }
                    break;
                case "DIV":
                    if (isEmptyStack2()) {
                        flag = true;
                        break;
                    }
                    top = s.pop();
                    if (top == 0) {
                        flag = true;
                        System.out.println("ERROR");
                        break;
                    }
                    second = s.pop();
                    total = div(top, second);
                    if (total >= -MAX){
                        s.add((int) total);
                    } else {
                        flag = true;
                        System.out.println("ERROR");
                    }
                    break;
                case "MOD":
                    if (isEmptyStack2()) {
                        flag = true;
                        break;
                    }
                    top = s.pop();
                    if (top == 0) {
                        flag = true;
                        System.out.println("ERROR");
                        break;
                    }
                    second = s.pop();
                    total = mod(top, second);
                    if (total >= -MAX){
                        s.add((int) total);
                    } else {
                        flag = true;
                        System.out.println("ERROR");
                    }
                    break;
            }
            if (flag) break;
        }

        if (flag) return;
        if (s.size() != 1) {
            System.out.println("ERROR");
            return;
        }

        System.out.println(s.pop());
    }

    static boolean isEmptyStack1(){
        if (s.isEmpty()) {
            System.out.println("ERROR");
            return true;
        }
        return false;
    }

    static boolean isEmptyStack2(){
        if (s.size() < 2){
            System.out.println("ERROR");
            return true;
        }
        return false;
    }

    static long div(int a, int b){
        if (b < 0) {
            int tmp = -b;
            return -(tmp / a);
        } else {
            return b / a;
        }
    }

    static long mod(int a, int b){
        if (b < 0) {
            int tmp = -b;
            return -(tmp % a);
        } else {
            return b % a;
        }
    }
}
