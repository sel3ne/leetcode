class BrowserHistory {
    private Stack<String> histories;
    private Stack<String> forward;
    
    public BrowserHistory(String homepage) {
        histories = new Stack<String>();
        forward = new Stack<String>();
        histories.push(homepage);
    }
    
    public void visit(String url) {
        forward.clear();
        histories.push(url);
    }
    
    public String back(int steps) {
        while (steps > 0 && histories.size() > 1)
        {
            String popped = histories.pop();
            forward.push(popped);
            steps--;
        }
        return histories.peek();
    }
    
    public String forward(int steps) {
        String last = histories.peek();
        while (steps > 0 && forward.size() > 0)
        {
            last = forward.pop();
            histories.push(last);
            steps--;
        }
        return last;
    }
}

