class MinStack {
public:
    stack<long long> st;
    long long min;

    MinStack() {
        min = LLONG_MAX;
    }

    void push(int val) {
        long long value = val;

        if (st.empty()) {
            min = value;
            st.push(value);
        } else {
            if (value < min) {
                st.push(2LL * value - min); // Encode previous min
                min = value;
            } else {
                st.push(value);
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long el = st.top();
        st.pop();

        if (el < min) {
            min = 2LL * min - el; // Decode previous min
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long el = st.top();
        return (el < min) ? (int)min : (int)el;
    }

    int getMin() {
        return (int)min;
    }
};
