/****************************************************************************************************************************************************
 *  File Name   		: fixedpointarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page06\fixedpointarray.h
 *  Created on			: May 10, 2014 :: 1:01:16 PM
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

#ifndef FIXEDPOINTARRAY_H_
#define FIXEDPOINTARRAY_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int getFixedPointArray(vector<int> userInput,int startIndex,int endIndex){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == middleIndex){
		return middleIndex;
	}
	if(userInput[middleIndex] > middleIndex){
		return getFixedPointArray(userInput,startIndex,middleIndex-1);
	}else{
		return getFixedPointArray(userInput,middleIndex+1,endIndex);
	}
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int getFixedPointArray(vector<int> userInput){
	if(userInput.size() == 0){
		return UINT_MAX;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == counter){
			return counter;
		}
	}
	return UINT_MAX;
}
#endif /* FIXEDPOINTARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
