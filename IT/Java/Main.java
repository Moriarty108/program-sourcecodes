class Main {
    public static void main(String[] args) {
        Stack<Integer> stack = new StaticStack();
        stack.push(20);
        stack.push(93);
        stack.push(67);
        stack.push(45);
        stack.pop();
        stack.display();
    }
}