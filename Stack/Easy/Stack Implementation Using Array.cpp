// Stack class.
class Stack {
    
public:
    vector<int>arr;
    int topIndex;
    int size;

    Stack(int capacity) {
        this->arr.resize(capacity);
        this->topIndex=-1;
        this->size=capacity;
    }

    void push(int num) {
        if(topIndex != size -1 ){
            topIndex++;
            arr[topIndex]=num;
        }
    }


    int pop() {
        if(topIndex != -1){
            topIndex--;
            return arr[topIndex+1];
        }
        else{
            return -1;
        }
    }


    int top() {
        if(topIndex != -1)  return arr[topIndex];
        else return -1;
    }


    int isEmpty() {
        if(topIndex==-1) return 1;
        else return 0;
    }

    int isFull() {
        if(topIndex==size-1) return 1;
        else return 0;
    }
    
};


https://www.codingninjas.com/studio/problems/stack-implementation-using-array_3210209?leftPanelTabValue=PROBLEM
