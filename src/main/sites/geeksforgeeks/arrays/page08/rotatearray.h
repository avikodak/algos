/****************************************************************************************************************************************************
 *  File Name   		: rotateArray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page08\rotateArray.h
 *  Created on			: Apr 25, 2014 :: 12:32:49 AM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/array-rotation/
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

#ifndef ROTATEARRAY_H_
#define ROTATEARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void rotateArrayAuxspace(vector<int> &userInput,unsigned int noOfTimes){
	if(userInput.size() == 0 || noOfTimes == 0){
		return;
	}
	vector<int> auxSpace;
	auxSpace.reserve(userInput.size());
	noOfTimes %= userInput.size();
	unsigned int fillCounter = 0;
	for(unsigned int counter = noOfTimes;counter < userInput.size();counter++){
		auxSpace[fillCounter++] = userInput[counter];
	}
	for(unsigned int counter = 0;counter < noOfTimes;counter++){
		auxSpace[fillCounter++] = userInput[counter];
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		userInput[counter] = auxSpace[counter];
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void rotateArrayOneByOne(vector<int> &userInput,unsigned int noOfTimes){
	if(userInput.size() == 0 || noOfTimes == 0){
		return;
	}
	noOfTimes = noOfTimes % (userInput.size());
	int frontValue;
	while(noOfTimes--){
		frontValue = userInput[0];
		for(unsigned int counter = 1;counter  < userInput.size();counter++){
			userInput[counter-1] = userInput[counter];
		}
		userInput[userInput.size()-1] = frontValue;
	}
}

#endif /* ROTATEARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
