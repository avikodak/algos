/****************************************************************************************************************************************************
 *  File Name   		: largestsumcontigoussubarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page09\largestsumcontigoussubarray.h
 *  Created on			: Apr 16, 2014 :: 11:53:38 PM
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

#ifndef LARGESTSUMCONTIGOUSSUBARRAY_H_
#define LARGESTSUMCONTIGOUSSUBARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int largestSumContigousSubarray(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	int globalMax = userInput[0],localMax = userInput[0];
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		localMax = max(userInput[counter],localMax + userInput[counter]);
		globalMax = max(globalMax,localMax);
	}
	return globalMax;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int largestSumContigousSubarrayON3(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	int maxSum = INT_MIN,currentSum;
	for(unsigned int outerCounter = 0;outerCounter < userInput.size();outerCounter++){
		for(unsigned int innerCounter = outerCounter;innerCounter < userInput.size();innerCounter++){
			currentSum = 0;
			printf("%d %d\n",outerCounter,innerCounter);
			for(unsigned int counter = outerCounter;counter <= innerCounter;counter++){
				currentSum += userInput[counter];
			}
			maxSum = max(maxSum,currentSum);
		}
	}
	return maxSum;
}

#endif /* LARGESTSUMCONTIGOUSSUBARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
