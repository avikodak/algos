/****************************************************************************************************************************************************
 *  File Name   		: adaptorqueuedequeue.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture03\adaptorqueuedequeue.h
 *  Created on			: May 31, 2014 :: 1:08:43 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <algos/utils/ds/tree/treeds.h>
#include <algos/utils/common/tree/tree.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef ADAPTORQUEUEDEQUEUE_H_
#define ADAPTORQUEUEDEQUEUE_H_

class apdaptorQueueDeque{
private:
	pdeque *adaptor;
public:
	apdaptorQueueDeque(){
		this->adaptor = new pdeque();
	}

	void queue(int value){
		this->adaptor->push_front(value);
	}

	void deque(){
		this->adaptor->pop_rear();
	}

	unsigned int size(){
		return this->adaptor->size();
	}

	bool isEmpty(){
		return this->adaptor->isEmpty();
	}

	int front(){
		return this->adaptor->getFront();
	}
};

#endif /* ADAPTORQUEUEDEQUEUE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
