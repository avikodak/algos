/****************************************************************************************************************************************************
 *  File Name   		: arraystack.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture02\arraystack.h
 *  Created on			: May 29, 2014 :: 2:20:15 AM
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

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

class stack{
private:
	int top = -1;
	int SIZE_OF_ARRAY = 10;
	int *stackAuxspace;
public:
	stack(){
		this->stackAuxspace = (int *)calloc(SIZE_OF_ARRAY,sizeof(int));
	}

	stack(int size){
		this->stackAuxspace = (int *)calloc(size,sizeof(int));
		this->SIZE_OF_ARRAY = size;
	}

	void push(int userInput){
		if(top == this->SIZE_OF_ARRAY-1){
			throw "Stack full";
		}
		this->stackAuxspace[++top] = userInput;
	}

	bool empty(){
		return this->top == -1?true:false;
	}

	int top(){
		if(empty()){
			throw "Stack empty";
		}
		return this->stackAuxspace[top];
	}

	void pop(){
		this->stackAuxspace[top--] = 0;
	}

	unsigned int size(){
		return this->top+1;
	}
};

#endif /* ARRAYSTACK_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
