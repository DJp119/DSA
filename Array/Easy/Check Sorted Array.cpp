int isSorted(int n, vector<int> a) {
    for(int i=1;i<n;i++){
        if(a[i]>=a[i-1]) continue;
        else return false;
    }
    return true;
}


/*
    Time complexity: O(N)
    Space complexity: O(1)

    Where 'N' is the input array 'A'.
*/

int isSorted(int n, vector<int> a) {
    // Iterating over the array 'A'.
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i]) {
            return 0;
        }
    }

    return 1;
}

https://www.codingninjas.com/studio/problems/ninja-and-the-sorted-check_6581957?leftPanelTabValue=PROBLEM
