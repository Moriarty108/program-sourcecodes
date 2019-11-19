import java.util.ArrayList;
import java.util.List;

public class DynamicStack extends Stack<Integer> {
    private List<Integer> contents;
    private int sp;

    @Override
    public void push(Integer element) {
        contents.add(element);
        sp++;
    }

    @Override
    public Integer pop() {
        sp--;
        int element = contents.remove(sp);
        return element;
    }

    @Override
    public void display() {
        System.out.println(this);
    }

    @Override
    public String toString() {
        return this.contents.toString();
    }

    public DynamicStack() {
        this.contents = new ArrayList<>();
        this.sp = 0;
    }

}