	Time complexity: O(N*(log(N))) 
	Space complexity: O(N)
#include<queue>

#include<vector>

int signum(int a, int b){

    if(a == b) return(0);

    else if(a > b) return(1);

    else return(-1);

}

void callMedian(int element, priority_queue<int> &maxHeap, 

priority_queue<int, vector<int>, greater<int>> &minHeap, int & median){

    switch(signum(maxHeap.size(), minHeap.size())){

        case 0:{

            if(element > median){

                minHeap.push(element);

                median = minHeap.top();

            }else{

                maxHeap.push(element);

                median = maxHeap.top();

            }break;

        }

 

        case 1:{

            if(element > median){

                minHeap.push(element);

                median = (maxHeap.top() + minHeap.top()) / 2;

            }else{

                minHeap.push(maxHeap.top());

                maxHeap.pop();

                maxHeap.push(element);

                median = (maxHeap.top() + minHeap.top()) / 2;

            }break;

        }

 

        case -1:{

            if(element > median){

                maxHeap.push(minHeap.top());

                minHeap.pop();

                minHeap.push(element);

                median = (maxHeap.top() + minHeap.top()) / 2;

            }else{

                maxHeap.push(element);

                median = (maxHeap.top() + minHeap.top()) / 2;

            }break;

        }

    }

}

vector<int> findMedian(vector<int> &arr, int n){

    

    // Write your code here:

 

    vector<int> foundMedian;

    priority_queue<int> maxHeap;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    int median = -1;

 

    for(int i=0;i<n;i++){

        callMedian(arr[i], maxHeap, minHeap, median);

        foundMedian.push_back(median);

    }

 

    return(foundMedian);

}


//  CS solution ->



/*

	Time complexity: O(N*(log(N))) 
	Space complexity: O(N)
	
	where N is the total number of elements in the array.

*/

#include <queue>

vector<int> findMedian(vector<int> &arr, int n){
	
	// To store the medians
	vector<int> medians;
	
	// max heap
	priority_queue<int> lo;  
	
	//min heap                            
    priority_queue<int, vector<int>, greater<int>> hi;   
    
    for(int i = 0; i < n; i++){
    	
    	int num = arr[i];
    	
    	// Add to max heap
    	lo.push(num);                                
		
		// Balancing step, that is inserting the current element at its position that is either less than median or more than median value
        hi.push(lo.top());                        
        lo.pop();

		// Maintain size property, as 'lo' can have utmost one more element than 'hi' or both have equal number of elements
        if (lo.size() < hi.size()) {                    
            lo.push(hi.top());
            hi.pop();
        }
        
        int median;
        
        // For odd number of elements
        if(lo.size() > hi.size()){
        	
        	median = lo.top();
        	
		}
		// For even number of elements
		else{
			
			median = (lo.top() + hi.top())/2;  
			
		}
        
    	medians.push_back(median);
	}
	
	return medians;

	
}


