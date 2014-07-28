/****************************************************************************************************************************************************
 *  File Name   		: arrayqueue.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture03\arrayqueue.h
 *  Created on			: May 31, 2014 :: 12:44:40 PM
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


#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

class aqueue{
private:
	int front = -1;
	int rear = 0;
	int *auxspace;
	int SIZE_OF_ARRAY = 10;
public:
	aqueue(){
		auxspace = (int *)calloc(SIZE_OF_ARRAY,sizeof(int));
	}

	aqueue(int userInput){
		auxspace = (int *)calloc(userInput,sizeof(int));
		SIZE_OF_ARRAY = userInput;
	}

	void enqueue(int userInput){
		if(full()){
			throw "Queue is full";
		}
		if(front == -1){
			front = 0;
		}
		auxspace[rear++] = userInput;
	}

	void deque(){
		if(empty()){
			throw "Queue is empty";
		}
	}

	bool empty(){

	}

	bool full(){

	}

	int front(){

	}
};

#endif /* ARRAYQUEUE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
