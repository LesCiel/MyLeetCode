// accepted
// pay attention to multi min value

class MinStack {
public:
	stack<int> st;
	stack<int> min_st;
    void push(int x) {
        st.push(x);
        if(min_st.empty() || x <= min_st.top())
        	min_st.push(x);
    }

    void pop() {
    	if(st.empty())
    		return;
    	if(st.top() == min_st.top())
    		min_st.pop();
    	st.pop();
    }

    int top() {
    	if(st.empty())
    		exit(1);
        return st.top();
    }

    int getMin() {
        if(min_st.empty())
        	exit(1);
        return min_st.top();
    }
};