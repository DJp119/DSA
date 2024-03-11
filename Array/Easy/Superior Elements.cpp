/*
    Time Complexity: O( N^2 )
    Space Complexity: O( 1 )

    Where 'N' is the length of the array 'A'.
*/

vector<int> superiorElements(vector<int>&a) {

    int n = a.size();

    vector<int>answer;

    // Iterate over each element of the array.
    for (int i = 0; i < n; i++) {

        // 'flag' variable to determine a Superior element.
        bool flag = true;

        // Comparing with all elements to right.
        for (int j = i + 1; j < n; j++) {
            if (a[j] >= a[i]) {
                flag = false;
            }
        }

        if (flag == true) {
            answer.push_back(a[i]);
        }

    }

    sort(answer.begin(), answer.end());

    // Return the 'answer' here.
    return answer;
}

/*
    Time Complexity: O( N )
    Space Complexity: O( 1 )

    Where 'N' is the length of the array 'A'.
*/

vector<int> superiorElements(vector<int>&a) {
    int n = a.size();

    // Max element to the right.
    int maxElement = a[n - 1];

    vector<int>answer;

    // Last element is always a superior element.
    answer.push_back(a[n - 1]);

    // Iterate from right to left.
    for (int i = n - 2; i >= 0; i--) {

        // If current element is greater than all
        // the elements to the right of itself.
        if (a[i] > maxElement) {
            answer.push_back(a[i]);
            maxElement = a[i];
        }
    }

    // Return the 'answer' here.
    return answer;
}


vector<int> superiorElements(vector<int>&a) {
    int n = a.size()-1;
    int maxi = a[n];
    vector<int>ans;
    ans.push_back(maxi);
    for(int i = n;i>=0;i--){
        if(a[i]>maxi) maxi = a[i],ans.push_back(maxi);
    }
    return ans;
}

https://www.codingninjas.com/studio/problems/superior-elements_6783446?leftPanelTabValue=PROBLEM
