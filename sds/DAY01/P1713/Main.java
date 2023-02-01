package sds.DAY01.P1713;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

class People implements Comparable<People>{
    // 번호
    int num;

    // 추천 횟수
    int count;

    // 시간
    int time;

    // frame에 존재하는가
    boolean isIn;

    public People(int num, int count, int time, boolean isIn) {
        this.num = num;
        this.count = count;
        this.time = time;
        this.isIn = isIn;
    }

    @Override
    public int compareTo(People p2) {
        // 뒤에서 넣다 빼기 위해 내림차순으로 정렬
        int comp1 = p2.count - count;
        if (comp1 == 0){ // 최신순(내림차순)으로 정렬
            return p2.time - time;
        }
        return comp1;
    }
}

public class Main {

    static int N, M;
    // 추천받은 학생 목록
    static int[] inputs;
    // 학생 상태 목록
    static People[] people;

    public static void main(String[] args) throws FileNotFoundException {
        System.setIn(new FileInputStream("src/sds/DAY01/P1713/input.txt"));
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        inputs = new int[M];
        people = new People[101];
        List<People> peopleList = new ArrayList<>();

        for (int i = 0 ; i < M; i++){
            int num = sc.nextInt();
            if (people[num] == null) {
                people[num] = new People(num, 0, 0, false);
            }

            if (people[num].isIn){ // 사진틀에 이미 있음
                people[num].count++;
            } else { // 사진틀에 없음
                if (peopleList.size() == N) { // 사진틀 꽉참
                    Collections.sort(peopleList);
                    People removeTarget = peopleList.remove(N - 1);
                    removeTarget.isIn = false;
                }
                people[num].count = 1;
                people[num].isIn = true;
                people[num].time = i;
                peopleList.add(people[num]);
            }
        }

        // num 오름차순으로 정렬
        Collections.sort(peopleList, Comparator.comparingInt(o -> o.num));

        for (People p : peopleList) {
            System.out.print(p.num + " ");
        }
    }
}
