// CS1300 Spring 2019
// Author: Jake Bonner
// Recitation: 205 – Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/jacobbonner0109/csci1300_jacobbonner
// Homework 8 - Problem # 1


#include <iostream>
#include <vector>
using namespace std;


/** Algorithm: Takes two vectors and creates a new vector by alternating between values from each of the vectors and combining them.
 * 1. Take the two vectors passed into the function, and create a new empty vector to be returned by the function.
 * 2. Check if the size of the first vector is not equal to 0 OR if the size of the second vector is not equal to 0.
 *      If yes...
 *          Check if the vectors are equal in size.
 *              If yes, alternate between the two given vectors (starting with the first one) and add each element to the new vector.
 *          If no...
 *              Check if the size of the first vector is greater than the size of the second vector.
 *                  If yes, alternate between the two vectors and add each element (through the length of the second vector), starting with the first vector, and then append the remaining elements from the first vector.
 *              If no, alternate between the two vectors and add each element (through the length of the second vector), starting with the second vector, and then append the remaining elements from the second vector.
 *          Return the new changed vector.
 * 3. If no, return the new empty vector.
 * Input Parameters: two vectors of integer values
 * Output: nothing
 * Returns: A new vector formed by alternating through the elements of the two input vectors, or an empty vector if both input vectors are empty.
*/
vector<int> shuffle(vector<int> vec1, vector<int> vec2){
    vector<int> newVec;
    int indx = -1; // declares this as -1 so when only one of the vectors has 0 elements, the other vector starts appending at the first value. See below
    if(vec1.size() != 0 || vec2.size() != 0){
        if(vec1.size() == vec2.size()){
            for(int i=0; i<vec1.size(); i++){
                newVec.push_back(vec1[i]);
                newVec.push_back(vec2[i]);
            }
        }
        else{
            if(vec1.size() > vec2.size()){
                for(int j=0; j<vec2.size(); j++){
                    newVec.push_back(vec1[j]);
                    newVec.push_back(vec2[j]);
                    indx = j;
                }
                for(int k=indx+1; k<vec1.size(); k++){ // appends the rest of the longer vector
                    newVec.push_back(vec1[k]);
                }
            }
            else{
                for(int j=0; j<vec1.size(); j++){
                    newVec.push_back(vec2[j]);
                    newVec.push_back(vec1[j]);
                    indx = j;
                }
                for(int k=indx+1; k<vec2.size(); k++){ // appends the rest of the longer vector
                    newVec.push_back(vec2[k]);
                }
            }
        }
        return newVec;
    }
    else{
        return newVec;
    }
}


int main(){
    // Test Case 1
    // expected output
    // 1 2 3 4 5 6 7 8 9 10
    vector<int> v1{2,4,6,8};
    vector<int> v2{1,3,5,7,9,10};
    vector<int> v3 = shuffle(v1,v2);
    for (int i=0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }


    cout << endl;
    
    
    // Test Case 2
    // expected output
    // 4 3 2 1
    vector<int> v4{4,3,2,1};
    vector<int> v5;
    vector<int> v6 = shuffle(v4,v5);
    for (int i=0; i < v6.size(); i++) {
        cout << v6[i] << " ";
    }

    
    return 0;
}
