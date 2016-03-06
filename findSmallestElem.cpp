#include "findSmallestElem.h"
#include <algorithm>
#include <unistd.h>
#include <stdio.h> 
#include <assert.h>

int recursiveTurns = 0;
int main(){
    srand(time(0));
    vector<int> A;

    for(int i = 0; i < 100; i++)
        A.push_back(i);

    random_shuffle(A.begin(), A.end());
    int n = 10;

    A.resize(n); // Have an array with n random distinct numbers
    vector<int> B;
    
   for(int i = 1; i <= n; i++)
        B.push_back(i);

    //You can comment the loop above and uncomment lines below to
    //add specific index values to B.
    //
    //B.push_back(1);
    //B.push_back(4);
    //B.push_back(6);
    //B.push_back(8);
    
    for(int i = 0; i < A.size(); i++)
        printf("This is A[%d] (before findRanks): %d\n", i, A[i]);
    for(int i = 0; i < B.size(); i++)
        printf("This is B[%d]: %d\n", i, B[i]);

    findRanks(A, B, 0);
    return 0;
}

void findRanks(vector<int> A, vector<int> B, int k){ 
    assert(B.size());

    if(B.size() == 1)
    {
        nth_element(A.begin(), A.begin() + B[0]-1, A.end());  
        printf("This is the level: %d, kth smallest element: %d, leaf value: %d\n", k, B[0], A[B[0]-1]);
        return;
    }

    vector<int>::const_iterator start_1 = B.begin();
    vector<int>::const_iterator end_1 =  B.begin() + ((B.size())/2)-1;

    vector<int>::const_iterator start_2 = B.begin() + ((B.size())/2);
    vector<int>::const_iterator end_2;

    if(B.size()%2)
        end_2 = B.end() - 2;
    else
        end_2 = B.end() - 1;

    //printf("This is *end_1+1: %d\n", *end_1+1);
    vector<int> leftSubArray(start_1,  end_1+1); //+1: One past the last element
    vector<int> rightSubArray(start_2, end_2+1); //+1: One past the last element

    //printf("This is leftSubArray.size(): %lu\n", leftSubArray.size());
    //printf("This is rightSubArray.size(): %lu\n", rightSubArray.size());

    //for(auto & item: leftSubArray)
    //    cout << "This is item: " << item << endl;

    findRanks(A, leftSubArray, k+1);
    findRanks(A, rightSubArray, k+1);

    if(B.size()%2)
    {
        //printf("Entered the odd condition, B.size(): %lu\n", B.size());
        vector<int> sub_B_Array(1);
        sub_B_Array[0] = B[B.size()-1];
        findRanks(A, sub_B_Array, k+1); 
    }
}
