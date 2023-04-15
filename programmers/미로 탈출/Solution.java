/**
 * programmers - 미로 탈출
 * bfs
 */

import java.util.*;

class Solution {
    public int solution(String[] maps) {
        int answer = 0;
        
        int M = maps.length;
        int N = maps[0].length();
        int[] dx = {0, 0, -1, 1};
        int[] dy = {-1, 1, 0, 0};
        int sx = 0, sy = 0, lx = 0, ly = 0, ex = 0, ey = 0;
        
        for (int i = 0; i < maps.length; i++){
            for (int j = 0; j < maps[i].length(); j++){
                if (maps[i].charAt(j) == 'S'){
                    sx = i;
                    sy = j;
                }
                
                else if (maps[i].charAt(j) == 'L'){
                    lx = i;
                    ly = j;
                }
                
                else if (maps[i].charAt(j) == 'E'){
                    ex = i;
                    ey = j;
                }
            }
        }
        
        Queue<Pair> q = new LinkedList<>();
        int[][] dist = new int[M][N];
        q.add(new Pair(sx, sy));
        
        // find labor
        while (!q.isEmpty()){
            Pair cur = q.poll();
            
            if (cur.x == lx && cur.y == ly) break;
            
            for (int i = 0; i < 4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                
                if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                if (maps[nx].charAt(ny) == 'X') continue;
                
                if (dist[nx][ny] == 0){
                    dist[nx][ny] = dist[cur.x][cur.y] + 1;
                    q.add(new Pair(nx, ny));
                }
            }
        }
        
        if (dist[lx][ly] == 0){
            answer = -1;
            return answer;
        }
        else {
            answer += dist[lx][ly];
        }
        
        // find exit
        q = new LinkedList<>();
        dist = new int[M][N];
        q.add(new Pair(lx, ly));
        
        while (!q.isEmpty()){
            Pair cur = q.poll();
            
            if (cur.x == ex && cur.y == ey) break;
            
            for (int i = 0; i < 4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                
                if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                if (maps[nx].charAt(ny) == 'X') continue;
                
                if (dist[nx][ny] == 0){
                    dist[nx][ny] = dist[cur.x][cur.y] + 1;
                    q.add(new Pair(nx, ny));
                }
            }
        }
        
        if (dist[ex][ey] == 0){
            answer = -1;
            return answer;
        }
        else {
            answer += dist[ex][ey];
        }
        
        
        return answer;
    }
    
    public class Pair{
        int x;
        int y;
        
        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}