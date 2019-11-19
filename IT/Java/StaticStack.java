import java.util.Arrays;

public class StaticStack extends Stack<Integer> {
    private int[] contents;
    private int sp;

    public StaticStack() {
        contents = new int[10];
        sp = 0;
    }

    @Override
    public void push(Integer element) {
        contents[sp] = element;
        sp++;
    }

    @Override
    public Integer pop() {
        return contents[--sp];
    }

    @Override
    public void display() {
        System.out.println(this);
    }

    @Override
    public String toString() {
        StringBuilder displayString = new StringBuilder("[");
        for (int i = 0; i < sp; i++) {
            displayString.append(contents[i] + ", ");
        }
        displayString.replace(displayString.length() - 2, displayString.length() - 1, "]");
        return displayString.toString();
    }

}