/****************************************************************************************************************************************************
 *  File Name   		: binarysearch.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture04\binarysearch.h
 *  Created on			: May 31, 2014 :: 7:51:49 PM
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

#ifndef BINARYSEARCH_H_
#define BINARYSEARCH_H_

/****************************************************************************************************************************************************/
/* 																	O(LOGN) Algorithm 																*/
/****************************************************************************************************************************************************/
bool binarySearch(vector<int> userInput,int key,unsigned int startIndex,unsigned int endIndex){
	if(userInput.size() == 0 || startIndex > endIndex){
		return false;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		return true;
	}
	if(userInput[middleIndex] > key){
		return binarySearch(userInput,startIndex,middleIndex-1);
	}else{
		return binarySearch(userInput,middleIndex+1,endIndex);
	}
}

bool binarySearchIterative(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return false;
	}
	unsigned int startIndex = 0,endIndex = userInput.size()-1,middleIndex;
	while(startIndex < endIndex){
		middleIndex = (startIndex + endIndex)/2;
		if(userInput[middleIndex] == key){
			return true;
		}
		if(userInput[middleIndex] > key){
			endIndex = middleIndex-1;
		}else{
			startIndex = middleIndex;
		}
	}
	return false;
}

#endif /* BINARYSEARCH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
