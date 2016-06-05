class MyQueue {
   
    LinkedList<Integer> stack = new LinkedList<Integer>();
   
    // Push element x to the back of queue.
    public void push(int x) {
        int i;
        int[] arraySavedInt = new int[stack.size()];
        for (i = arraySavedInt.length - 1; i >= 0; i--) {
            arraySavedInt[i] = stack.pop();
        }
        stack.push(x);
        for (i = 0; i != arraySavedInt.length; i++) {
            stack.push(arraySavedInt[i]);
        }
    }

    // Removes the element from in front of queue.
    public void pop() {
        stack.pop();
    }

    // Get the front element.
    public int peek() {
        return stack.peekFirst();
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return stack.size() == 0;
    }
}