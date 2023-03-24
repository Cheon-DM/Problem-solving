package sds.DAY03.P10845;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

class queue {
    LinkedList<Integer> list;

    public queue() {
        list = new LinkedList<>();
    }

    public void push(int X) {
        list.add(X);
    }

    public int pop() {
        if (list.isEmpty()){
            return -1;
        } else {
            return list.pollFirst();
        }
    }

    public int size() {
        return list.size();
    }

    public int empty() {
        if (list.isEmpty()){
            return 1;
        } else {
            return 0;
        }
    }

    public int front() {
        if (list.isEmpty()){
            return -1;
        } else {
            return list.getFirst();
        }
    }

    public int back() {
        if (list.isEmpty()){
            return -1;
        } else {
            return list.getLast();
        }
    }
}

public class Main {

    static int N;
    static queue q = new queue();

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY03/P10845/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            String commend = st.nextToken();

            if (commend.equals("push")){
                q.push(Integer.parseInt(st.nextToken()));
            } else if (commend.equals("pop")) {
                System.out.println(q.pop());
            } else if (commend.equals("size")) {
                System.out.println(q.size());
            } else if (commend.equals("empty")) {
                System.out.println(q.empty());
            } else if (commend.equals("front")) {
                System.out.println(q.front());
            } else if (commend.equals("back")) {
                System.out.println(q.back());
            }
        }
    }
}
