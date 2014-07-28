/****************************************************************************************************************************************************
 *  File Name   		: quicksort.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture10\quicksort.h
 *  Created on			: Jun 7, 2014 :: 12:38:41 AM
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

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int quickSortPartition(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	int pivotElement = userInput[endIndex],temp;
	while(startIndex < endIndex){
		while(userInput[startIndex] < pivotElement){
			startIndex++;
		}
		while(userInput[endIndex] > pivotElement){
			endIndex--;
		}
		if(startIndex < endIndex){
			temp = userInput[startIndex];
			userInput[startIndex] = userInput[endIndex];
			userInput[endIndex] = temp;
		}
	}
	return endIndex;
}

void quickSort(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return;
	}
	unsigned int dividingIndex = quickSortPartition(userInput,startIndex,endIndex);
	quickSort(userInput,startIndex,dividingIndex);
	quickSort(userInput,dividingIndex+1,endIndex);
}

#endif /* QUICKSORT_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
