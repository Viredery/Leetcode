public class Solution {
    //string builder
    char[] combination;
    //stack
    LinkedList<Status> stack = new LinkedList<Status>();
    //result
    List<String> combinations;
    //function
    public List<String> generateParenthesis(int n) {
        combination = new char[2 * n];
        combinations = new LinkedList<String>();
        int numLeftParentheses = 0, numRightParentheses = 0;
        int pos = 0;
        stack.push(new Status(1, 0));
        while (!stack.isEmpty()) {
            Status current = stack.pop();
            numLeftParentheses = current.numLeftParentheses;
            numRightParentheses = current.numRightParentheses;
            pos = numLeftParentheses + numRightParentheses;
            combination[pos - 1] = pos == 1 ? '(' : ')';
            while (numRightParentheses != n) {
                while (numLeftParentheses >= numRightParentheses && numLeftParentheses < n) {
                    //next is '('
                    if (numLeftParentheses > numRightParentheses) {
                        stack.push(new Status(numLeftParentheses, numRightParentheses + 1));
                    }
                    numLeftParentheses++;
                    combination[pos++] = '(';
                }
                if (numLeftParentheses > numRightParentheses) {
                    //next is ')'
                    numRightParentheses++;
                    combination[pos++] = ')';
                }
            }
            combinations.add(new String(combination));
            
        }
        return combinations;
    }
    private class Status {
        int numLeftParentheses = 0;
        int numRightParentheses = 0;
        public Status(int numLeftParentheses, int numRightParentheses) {
            this.numLeftParentheses = numLeftParentheses;
            this.numRightParentheses = numRightParentheses;
        }
    }
}