#include<bits/stdc++.h>
int fun(vector<int> arr,int pages){
    int stu = 1,pages_stud=0;
    for(int i=0;i<arr.size();i++){
        if(pages_stud+arr[i]<= pages){
            pages_stud+=arr[i];
        }
        else {
            stu++;
            pages_stud = arr[i];
        }
    }
    return stu;
}
int Solution::books(vector<int> &A, int B) {
    if(B>A.size())return -1;
    int low=*max_element(A.begin(),A.end());
    int high = accumulate(A.begin(),A.end(),0);
    while(low<=high){
        int mid = (low+high)/2;
        int no_of_student = fun(A,mid);
        if(no_of_student>B)low=mid+1;
        else high = mid-1;
    }
    return low;
}


https://www.interviewbit.com/problems/allocate-books/
