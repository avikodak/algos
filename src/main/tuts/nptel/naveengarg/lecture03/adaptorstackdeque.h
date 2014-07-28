/****************************************************************************************************************************************************
 *  File Name   		: adaptorstackdeque.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture03\adaptorstackdeque.h
 *  Created on			: May 31, 2014 :: 1:08:29 PM
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

#include "deque.h"
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef ADAPTORSTACKDEQUE_H_
#define ADAPTORSTACKDEQUE_H_

class adaptorStackDeque{
private:
	pdeque *adaptor;
public:
	adaptorStackDeque(){
		this->adaptor = new pdeque();
	}

	void push(int value){
		this->adaptor->push_back(value);
	}

	int top(){
		return this->adaptor->getRear();
	}

	void pop(){
		this->adaptor->pop_rear();
	}

	unsigned int size(){
		return this->adaptor->size();
	}
};

#endif /* ADAPTORSTACKDEQUE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
