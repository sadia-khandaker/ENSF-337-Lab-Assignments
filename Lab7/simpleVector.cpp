/* ENSF 337 - Lab 7 Exercise D
 * File Name: simpleVector.cpp
 * Completed By: Sadia Khandaker
 * Submission Date: November 18, 2021
 */

#include "simpleVector.h"
#include <cassert>
using namespace std;

SimpleVector::SimpleVector(const TYPE *arr, int n) {
    storageM = new TYPE[n];
    sizeM = n;
    capacityM = n;
    for(int i =0; i < sizeM; i++)
        storageM[i] = arr[i];
}

TYPE& SimpleVector::at(int i) {
    assert(i >= 0 && i < sizeM);
    return storageM[i];
}

const TYPE& SimpleVector::at(int i)const {
    assert(i >= 0 && i < sizeM);
    return storageM[i];
}


// The followng member function should follow the above-mentioned memory
// management policy to resize the vector, if necessary. More specifically:
//   - If sizeM < capacityM it doesn't need to make any changes to the size of
//     allocated memory for vector
//   - Otherwise it follows the above-mentioned memory policy to create additionl
//     memory space and adds the new value, val, to the end of the current vector
//     and increments the value of sizeM by 1
void SimpleVector::push_back(TYPE val) {
    while (sizeM < capacityM) {
        if (sizeM == capacityM != 0) {
            capacityM *= 2;
        } else if (sizeM == capacityM == 0) {
            capacityM = 2;
        }
    }
    TYPE *n_arr = new TYPE[capacityM];
    for (int i = 0; i < sizeM; i++) {
        n_arr[i] = storageM[i];
    }
    n_arr[sizeM] = val;
    delete[] storageM;
    storageM = n_arr;
    sizeM++;
}

SimpleVector::SimpleVector(const SimpleVector& source) {
    sizeM = source.sizeM;
    storageM = new TYPE [sizeM];
    assert (storageM != 0);
    for (int i = 0; i<sizeM; i++){
        storageM[i] = source.storageM[i];
    }
}

SimpleVector& SimpleVector::operator= (const SimpleVector& rhs ){
    sizeM = rhs.sizeM;
    capacityM = rhs.capacityM;
    storageM = new TYPE[capacityM];
    for(int i = 0; i < sizeM; i++) {
        storageM[i] = rhs.storageM[i];
    }
    return *this;
}

