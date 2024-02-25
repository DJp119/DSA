vector<int> rev(vector<int>&nums,int i,int j){
    if(j<i) return nums;
    swap(nums[i],nums[j]);
    i++;
    j--;
    return rev(nums,i++, j--);
}
vector<int> reverseArray(int n, vector<int> &nums)
{
    int i=0;
    int j=n-1;
    rev(nums,i,j);
    return nums;
}

https://www.codingninjas.com/studio/problems/reverse-an-array_8365444?leftPanelTabValue=PROBLEM



/*
    Time Complexity: O(n)
    Space Complexity: O(n)
    where n is the size of the input array.
*/

// Function to reverse the elements of the given array 'nums'.
vector<int> reverseArray(int n, vector<int> &nums)
{
    // Create a new vector to store the reversed elements.
    vector<int> reversedArray(n);

    // Traverse the original array in reverse order and store the elements in the new array.
    for (int i = n - 1; i >= 0; i--)
    {
        reversedArray[n - i - 1] = nums[i];
    }

    // Returning the reversed array.
    return reversedArray;
}

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
    where n is the size of the input array.
*/

// Function to reverse the elements of the given array 'nums'.
vector<int> reverseArray(int n, vector<int> &nums)
{
    // Create a new vector to store the reversed elements.
    vector<int> reversedArray(n);

    // Traverse the original array in reverse order and store the elements in the new array.
    for (int i = n - 1; i >= 0; i--)
    {
        reversedArray[n - i - 1] = nums[i];
    }

    // Returning the reversed array.
    return reversedArray;
}

/*
    Time Complexity: O(n)
    Space Complexity: O(1)
    where n is the size of the input array.
*/

// Function to reverse the elements of the given array 'arr'.
vector<int> reverseArray(int n, vector<int> &nums)
{
    // Initialize two pointers, left and right,
    // pointing to the first and last indices of the array, respectively.
    int left = 0, right = n - 1;

    // Iterate until left crosses right.
    while (left < right)
    {
        // Swap the elements at positions left and right.
        swap(nums[left], nums[right]);

        // Move left one step forward.
        left++;

        // Move right one step backward.
        right--;
    }

    // Returning the reversed array.
    return nums;
}

/*
    Time Complexity: O(n)
    Space Complexity: O(1)
    where n is the size of the input array.
*/

// Recursive function to reverse the array elements between 'start' and 'end' indices.
void reverseArray(int start, int end, vector<int> &nums)
{
    // Base case: If 'end' is less than 'start', the array is already reversed.
    if (start > end)
        return;

    // Swapping the elements at 'start' and 'end' indices.
    swap(nums[start], nums[end]);

    // Recursively call the function to reverse the remaining elements.
    return reverseArray(start + 1, end - 1, nums);
}

// Function to reverse the elements of the given array 'nums'.
vector<int> reverseArray(int n, vector<int> &nums)
{
    // Calling the recursive function to reverse the array.
    reverseArray(0, n - 1, nums);

    // Returning the reversed array.
    return nums;
}
