import java.util.Collections;
import java.util.*;
class p{
    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        pq.add(10);
        pq.add(80);
        pq.add(30);
        pq.add(90);
        pq.add(20);
        System.out.println("size of pq "+pq.size());
        while (!pq.isEmpty())
        {
            System.out.print(pq.poll()+" ");
            
        }
        System.out.println();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        maxHeap.add(10);
        maxHeap.add(80);
        maxHeap.add(30);
        maxHeap.add(90);
        maxHeap.add(20);
        System.out.println("size of maxHeap "+maxHeap.size());
        while (!maxHeap.isEmpty())
        {
            System.out.print(maxHeap.poll()+" ");
            
        }
        System.out.println();
    }
}