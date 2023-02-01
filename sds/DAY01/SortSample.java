package sds.DAY01;

import java.util.Arrays;
import java.util.Comparator;

public class SortSample {

    public static void main(String[] args) {
        Integer[] nums = {4, 1, 2, 3, 5};
        System.out.println("nums = " + Arrays.toString(nums));

        // 일반 정렬 (오름차순)
        Arrays.sort(nums);
        System.out.println("nums = " + Arrays.toString(nums));

        // compare 사용 정렬 (내림차순)
        Arrays.sort(nums, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
        System.out.println("nums = " + Arrays.toString(nums));

        // 오름차순 정렬
        Arrays.sort(nums, Comparator.reverseOrder());
        System.out.println("nums = " + Arrays.toString(nums));

        System.out.println("===============================");

        Item[] items = new Item[5];
        items[0] = new Item(1, 5);
        items[1] = new Item(2, 3);
        items[2] = new Item(3, 3);
        items[3] = new Item(4, 3);
        items[4] = new Item(5, 1);
        System.out.println("items = " + Arrays.toString(items));

        // 정렬
        Arrays.sort(items, (o1, o2) -> {
            // value1에 대해서 오름차순으로 정렬
            // return o1.value1 - o2.value1;

            // value2에 대해서 오름차순으로 정렬
            int comp1 = o1.value2 - o2.value2;
            if (comp1 == 0) {
                // value2가 같으면 value1에 대해서 내림차순으로 정렬
                return o2.value1 - o1.value1;
            } else {
                return comp1;
            }
        });
        System.out.println("items = " + Arrays.toString(items));

        // comparable compareTo 정렬 (오름차순)
        Arrays.sort(items);
        System.out.println("items = " + Arrays.toString(items));

        // getter 이용 정렬
        Arrays.sort(items, Comparator.comparing(Item::getValue1));
        System.out.println("items = " + Arrays.toString(items));
    }
}

class Item implements Comparable<Item>{
    int value1;
    int value2;

    public Item(int value1, int value2) {
        this.value1 = value1;
        this.value2 = value2;
    }

    @Override
    public String toString() {
        return "{" +
                "" + value1 +
                ", " + value2 +
                '}';
    }

    @Override
    public int compareTo(Item item) {
        // 오름차순 정렬
        return value1 - item.value1;

        // 내림차순 정렬
        // return Integer.compare(o2.value1, value1);
    }

    public int getValue1() {
        return value1;
    }

    public int getValue2() {
        return value2;
    }
}
