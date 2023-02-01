package sds.DAY03.P10828;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static ArrayList<Integer> stack = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY03/P10828/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            String commend = st.nextToken();

            if (commend.equals("push")){
                int X = Integer.parseInt(st.nextToken());
                push(X);
            }

            else if (commend.equals("pop")){
                System.out.println(pop());
            }

            else if (commend.equals("size")){
                System.out.println(size());
            }

            else if (commend.equals("empty")){
                System.out.println(empty());
            }

            else if (commend.equals("top")){
                System.out.println(top());
            }
        }
    }

    private static void push(int X){
        stack.add(X);
    }

    private static int pop() {
        if (stack.isEmpty()) {
            return -1;
        } else {
            return stack.remove(stack.size() - 1);
        }
    }

    private static int size() {
        return stack.size();
    }

    private static int empty() {
        if (stack.isEmpty()){
            return 1;
        } else {
            return 0;
        }
    }

    private static int top() {
        if (stack.isEmpty()){
            return -1;
        } else {
            return stack.get(stack.size()-1);
        }
    }
}
