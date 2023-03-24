package sds;

public class Main {

    public static void main(String[] args) {
        String a = "abc";
        String b = "efg";
        String c = a + b; // 느림

        StringBuilder sb = new StringBuilder();
        sb.append(a);
        sb.append(b);
        System.out.println(sb.toString()); // 훨 빠름

        StringBuffer sb2 = new StringBuffer(); // 멀티 쓰레드용 (살짝느림)
    }

}

/**
 * Integer(객체) 사용 시 주의할 점
 * Integer i1 = 2;
 * Integer i2 = 2;
 * i1 == i2 : true --> auto boxing해서 비교 가능
 *
 * Integer i3 = new Integer(2);
 * Integer i4 = new Integer(2);
 * i3 == i4 : false
 * ie.equals(i4) : true --> 객체이므로 equals 사용해야함.
 */
