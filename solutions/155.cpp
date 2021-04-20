#include <vector>
#include <utility>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack(): data(), size(0){
        data.reserve(4096);
    }
    
    void push(int val) {
        int newMin;
        if(data.size() == 0){
            newMin = val;
        }
        else{
            auto oldMin = data[data.size() - 1].second;
            newMin = (val < oldMin ? val : oldMin);
        }
        
        data.push_back(std::make_pair(val, newMin));
    }
    
    void pop() {
        data.pop_back();
    }
    
    int top() {
        return data[data.size() - 1].first;
    }
    
    int getMin() {
        return data[data.size() - 1].second;
    }
private:
    std::vector<std::pair<int, int>> data;
    size_t size;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */