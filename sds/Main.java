package sds;

public class Main {

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
