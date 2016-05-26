/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    private class CurrentPosVisited {
        List<NestedInteger> nestedList;
        int pos;
        CurrentPosVisited(List<NestedInteger> n, int p) {
            nestedList = n;
            pos = p;
        }
        void addPos() {
            pos++;
        }
    }
    private Stack<CurrentPosVisited> stack = new Stack<CurrentPosVisited>();
    
    public NestedIterator(List<NestedInteger> nestedList) {
        CurrentPosVisited p = new CurrentPosVisited(nestedList, 0);
        stack.push(p);
    }

    @Override
    public Integer next() {
        CurrentPosVisited p = stack.peek();
        Integer i = p.nestedList.get(p.pos).getInteger();
        p.addPos();
        return i;
    }

    @Override
    public boolean hasNext() {
        while (!stack.empty()) {
            CurrentPosVisited p = stack.peek();
            if (p.nestedList.size() == p.pos)
                stack.pop();
            else if (p.nestedList.get(p.pos).isInteger()) {
                return true;
            } else {
                CurrentPosVisited nextPos = new CurrentPosVisited(p.nestedList.get(p.pos).getList(), 0);
                p.addPos();
                stack.push(nextPos);
            }
        }
        return false;
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */