//
//  main.cpp
//  Queue
//
//  Created by Siren Chen on 15/11/6.
//  Copyright © 2015年 Siren Chen. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <vector>
#include "queue.h"

using namespace std;

/**
 Compare the given queue to the given array of data elements.  Return
 true if they are all equal.
 Copy from professor's handout
 */
bool testQueueEquality( Queue& q, vector<Data> const array)
{
    if (q.size() != array.size())
        return false;
    
    for (unsigned i = 0; i < q.size(); ++i)
    {
        Data d(0,0);
        q.remove(&d);
        if ( !d.equals(array[i]) )
            return false;
        q.insert(d);
    }
    return true;
}

int main(int argc, const char * argv[]) {
    Queue q;
    q.insert(Data(1,2));
    q.insert(Data(3,4));
    q.insert(Data(5,6));
    q.insert(Data(-2,-3), 1);
    q.insert(Data(-4,-5), 3);
    
    vector<Data> dataVec;
    dataVec.push_back(Data(1,2));
    dataVec.push_back(Data(-2,-3));
    dataVec.push_back(Data(3,4));
    dataVec.push_back(Data(-4,-5));
    dataVec.push_back(Data(5,6));

    // q is 0:(1,2) 1:(-2,-3) 2:(3,4) 3:(-4,-5) 4:(5,6)
    // dataVes is 0:(1,2) 1:(-2,-3) 2:(3,4) 3:(-4,-5) 4:(5,6)
    // should equal
    assert(testQueueEquality(q, dataVec));
    
    q.print();
    
}
