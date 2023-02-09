package sds.DAY07.P3860;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Node {
    int x, y;

    public Node(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Edge {
    Node start, end;
    int time;

    public Edge(Node start, Node end, int time) {
        this.start = start;
        this.end = end;
        this.time = time;
    }
}

public class Main {

    static int W, H, G, X, Y, E, X1, X2, Y1, Y2, T;
    static int[][] map;
    static List<Edge> list;
    static int[][] dist;
    static final int INF = 100000000;
    static final int[] dx = {-1, 1, 0, 0};
    static final int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/sds/DAY07/P3860/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        while (true){
            // W, H 입력
            st = new StringTokenizer(br.readLine());
            W = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());

            // 0, 0 입력 받을 시 종료
            if (W == 0 && H == 0) break;

            // 지도 초기화
            map = new int[W][H];
            // 이동 목록 리스트 초기화
            list = new ArrayList<>();

            // G = 묘비의 개수 입력
            G = Integer.parseInt(br.readLine());

            for (int i = 0; i < G; i++) {
                st = new StringTokenizer(br.readLine());
                X = Integer.parseInt(st.nextToken());
                Y= Integer.parseInt(st.nextToken());
                map[X][Y] = -1; // 묘비 위치 지도에 찍기
            }

            // E = 귀신 구멍의 개수 입력
            E = Integer.parseInt(br.readLine());

            for (int i = 0; i < E; i++){
                st = new StringTokenizer(br.readLine());
                X1 = Integer.parseInt(st.nextToken());
                Y1 = Integer.parseInt(st.nextToken());
                X2 = Integer.parseInt(st.nextToken());
                Y2 = Integer.parseInt(st.nextToken());
                T = Integer.parseInt(st.nextToken());
                map[X1][Y1] = 1; // 귀신 구멍 위치 찍기

                // 간선 리스트 추가
                list.add(new Edge(new Node(X1, Y1), new Node(X2, Y2), T));
            }

            bfs();
            boolean flag = Bellman_Ford();

            if (!flag){ // 음수 사이클 존재
                bw.write("Never\n");
            } else {
                if (dist[W-1][H-1] == INF){ // 도착지에 갈 수 없음
                    bw.write("Impossible\n");
                } else {
                    bw.write(dist[W-1][H-1] + "\n");
                }
            }
        }

        bw.flush();
        bw.close();
        br.close();
    }

    static void init(){
        dist = new int[W][H];
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                dist[i][j] = INF;
            }
        }
    }

    static void bfs(){
        // 갈수 있는 모든 경로 간선 리스트에 추가
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                // 묘비 or 귀신구멍인 경우
                if (map[i][j] != 0) continue;

                // 도착점인 경우
                if (i == W-1 && j == H-1) continue;

                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
                    if (map[nx][ny] == -1) continue;

                    // (i, j) -> (nx, ny)를 1의 시간 소요로 이동
                    list.add(new Edge(new Node(i, j), new Node(nx, ny), 1));
                }
            }
        }
    }

    //Todo : 음수 사이클 확인, 도착지오면 어떻게 할지 판단필요

    static boolean Bellman_Ford(){
        // dist init
        init();

        // 시작 0
        dist[0][0] = 0;

        // 총 W*H 만큼 확인
        for (int i = 0; i <= W*H; i++) {
            for (int j = 0; j < list.size(); j++) {
                Edge cur = list.get(j);
                Node from = cur.start;
                Node to = cur.end;
                int cost = cur.time;

                // dist가 INF가 아니고 현재 이동하려고 하는 cost가 to보다 작을 때
                if (dist[from.x][from.y] != INF && dist[to.x][to.y] > dist[from.x][from.y] + cost){
                    if (i == W*H) {
                        return false;
                    }

                    dist[to.x][to.y] = dist[from.x][from.y] + cost;
                }
            }
        }

        return true;
    }
}
