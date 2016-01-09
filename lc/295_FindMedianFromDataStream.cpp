class MedianFinder {
private:
    // from big to small, max heap
    priority_queue<int> smallNum;
    // from small to big, min heap
    priority_queue<int, vector<int>, greater<int>> bigNum;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (smallNum.empty() && bigNum.empty())
            smallNum.push(num);
        else{
            if (num <= smallNum.top()){
                smallNum.push(num);
            } else{
                bigNum.push(num);
            }
        }
        int m = smallNum.size();
        int n = bigNum.size();
        if (m - n > 1){
            int tmp = smallNum.top();
            smallNum.pop();
            bigNum.push(tmp);
        } else if (n - m > 1){
            int tmp = bigNum.top();
            bigNum.pop();
            smallNum.push(tmp);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (smallNum.empty() && bigNum.empty()) return 0.0;
        if (bigNum.empty() || smallNum.empty()) 
            return smallNum.empty() ? (double)bigNum.top() : (double)smallNum.top();
        int a = smallNum.top();
        int b = bigNum.top();
        if (smallNum.size() == bigNum.size()){
            return (double)(a+b)/2;
        } else{
            return smallNum.size() > bigNum.size() ? (double)smallNum.top() : (double)bigNum.top();
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();