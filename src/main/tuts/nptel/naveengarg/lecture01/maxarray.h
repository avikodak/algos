/****************************************************************************************************************************************************
 *  File Name   		: maxarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture01\maxarray.h
 *  Created on			: May 23, 2014 :: 12:52:13 AM
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

#ifndef MAXARRAY_H_
#define MAXARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getMaxFromArray(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	int maxValue = INT_MIN;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		maxValue = max(maxValue,userInput[counter]);
	}
	return maxValue;
}

int getMaxForArrayDivideAndConquer(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return INT_MAX;
	}
	if(startIndex == endIndex){
		return userInput[startIndex];
	}
	if(abs(startIndex-endIndex) == 1){
		return max(userInput[startIndex],userInput[endIndex]);
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	int leftResult = getMaxForArrayDivideAndConquer(userInput,startIndex,middleIndex);
	int rightResult = getMaxForArrayDivideAndConquer(userInput,middleIndex+1,endIndex);
	return max(leftResult,rightResult);
}
/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getMaxFromArrayONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	sort(userInput.begin(),userInput.end());
	return userInput[userInput.size()-1];
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getMaxFromArrayON2(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	unsigned int outerCrawler,innerCrawler;
	bool isCurrentElementMax;
	for(outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		isCurrentElementMax = true;
		for(innerCrawler = 0;innerCrawler < userInput.size();innerCrawler++){
			if(userInput[outerCrawler] < userInput[innerCrawler]){
				isCurrentElementMax = false;
			}
		}
		if(isCurrentElementMax){
			return userInput[outerCrawler];
		}
	}
	return INT_MAX;
}

#endif /* MAXARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
