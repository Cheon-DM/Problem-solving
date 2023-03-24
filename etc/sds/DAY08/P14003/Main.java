package sds.DAY08.P14003;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] inputs;
    static int[] index; // 데이터가 들어가는 index 위치 저장
    static List<Integer> LIS; // 증가 수열을 담는 리스트

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // input
        N = Integer.parseInt(br.readLine());
        inputs = new int[N];
        index = new int[N];
        LIS = new ArrayList<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            inputs[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N; i++) {
            // LIS 배열이 비어있는 경우
            if (LIS.size() == 0){
                LIS.add(inputs[i]);
                index[i] = 0;
            }

            // LIS의 마지막 원소보다 큰 경우
            else if (LIS.get(LIS.size()-1) < inputs[i]){
                LIS.add(inputs[i]);
                index[i] = LIS.size() - 1;
            }

            else {
                int left = 0;
                int right = LIS.size()-1;

                // 이분 탐색
                while (left < right) {
                    int mid = (left + right) / 2;

                    if (LIS.get(mid) < inputs[i]){
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }

                LIS.set(left, inputs[i]);
                index[i] = left;
            }
        }

        List<Integer> answer = new ArrayList<>();
        int findIdx = LIS.size() - 1;
        for (int i = N-1; i >= 0; i--) {
            if (index[i] == findIdx){
                answer.add(inputs[i]);
                findIdx--;
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(LIS.size() + "\n");
        for (int i = answer.size()-1; i >= 0; i--) {
            sb.append(answer.get(i) + " ");
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}
