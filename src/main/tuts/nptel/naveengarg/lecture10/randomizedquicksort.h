/****************************************************************************************************************************************************
 *  File Name   		: randomizedquicksort.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture10\randomizedquicksort.h
 *  Created on			: Jun 7, 2014 :: 12:00:04 PM
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

#ifndef RANDOMIZEDQUICKSORT_H_
#define RANDOMIZEDQUICKSORT_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int partitionRandomizedQuickSort(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	int pivotElement = userInput[endIndex];
	int tempForSwap;
	while(startIndex < endIndex){
		while(userInput[startIndex] < pivotElement){
			startIndex++;
		}
		while(userInput[endIndex] > pivotElement){
			endIndex--;
		}
		if(startIndex < endIndex){
			tempForSwap = userInput[startIndex];
			userInput[startIndex] = userInput[endIndex];
			userInput[endIndex] = tempForSwap;
		}
	}
	return endIndex;
}

unsigned int generateRandomIndex(unsigned int lowerLimit,unsigned int upperLimit){
	srand(time(NULL));
	return rand()%upperLimit + lowerLimit;
}

void randomizedQuickSort(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return;
	}
	unsigned int randomIndex = generateRandomIndex(startIndex,endIndex);
	int temp;
	temp = userInput[randomIndex];
	userInput[randomIndex] = userInput[endIndex];
	userInput[endIndex] = temp;
	unsigned int dividingIndex = partitionRandomizedQuickSort(userInput,startIndex,endIndex);
	randomizedQuickSort(userInput,startIndex,dividingIndex);
	randomizedQuickSort(userInput,dividingIndex+1,endIndex);
}

#endif /* RANDOMIZEDQUICKSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
