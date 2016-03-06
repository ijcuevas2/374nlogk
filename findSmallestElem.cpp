#include "findSmallestElem.h"
#include <algorithm>
#include <unistd.h>
#include <stdio.h> 

int recursiveTurns = 0;
int main(){
    srand(time(0));
    vector<int> A;

    for(int i = 0; i < 100; i++)
        A.push_back(i);

    random_shuffle(A.begin(), A.end());
    A.resize(10); // Have an array with 10 random distinct numbers

    vector<int> B;
    B.push_back(1);
    B.push_back(4);
    B.push_back(6);
    B.push_back(8);

    //B.push_back(11);
    //B.push_back(12);
    //B.push_back(54);

    findQRanks(A, B);
    return 0;
}

void findRanks(vector<int> A, vector<int> B, int k){ 
    //printf("This is B.size() at start: %lu\n", B.size());
    if(B.size() == 0)
    {
        printf("why\n"); //never supposed to happen 
        return;
    }
    
    if(B.size() == 1)
    {
        nth_element(A.begin(), A.begin() + B[0], A.end());  //pass in a subset vector 
        printf("This is the level: %d\n", k);
        printf("This is a leaf: %d\n", A[B[0]]);
        return;
    }

    vector<int>::const_iterator start_1 = B.begin();
    vector<int>::const_iterator end_1 =  B.begin() + ((B.size())/2)-1;

    vector<int>::const_iterator start_2 = B.begin() + ((B.size())/2);
    vector<int>::const_iterator end_2;

    //cout << "This is *start_1: " << *start_1 << endl;
    //cout << "This is *end_1: " << *end_1 << endl;


    if(B.size()%2)
    {
        //printf("Entered B.size()mod2\n");
        end_2 = B.end() - 2;
    }

    else
    {
        end_2 = B.end() - 1;
    }

    //cout << "This is *start_2: " << *start_2 << endl;
    //cout << "This is *end_2: " << *end_2 << endl;
        
    vector<int> leftSubArray(start_1,  end_1+1, k+1); //+1: To make the end iter NULL
    vector<int> rightSubArray(start_2, end_2+1, k+1); //+1: To make the end iter NULL

    //for(auto & currVal : leftSubArray)
    //    cout << "This is currVal: " << currVal << endl;

    //cout << "This is leftSubArray.size(): " << leftSubArray.size() << endl;
    //cout << "This is rightSubArray.size(): " << rightSubArray.size() << endl;

    //recursiveTurns++;
    //printf("This is recursiveTurns: %d\n", recursiveTurns);

    findQRanks(A, leftSubArray);
    findQRanks(A, rightSubArray);

    if(B.size()%2)
    {
        vector<int> sub_B_Array(1);
        sub_B_Array[0] = B[B.size()-1];
        findQRanks(A, sub_B_Array); 
    }
}
