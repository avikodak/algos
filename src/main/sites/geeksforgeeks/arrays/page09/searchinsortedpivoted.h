/****************************************************************************************************************************************************
 *  File Name   		: searchinsortedpivoted.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page09\searchinsortedpivoted.h
 *  Created on			: Apr 20, 2014 :: 7:39:33 PM
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

#ifndef SEARCHINSORTEDPIVOTED_H_
#define SEARCHINSORTEDPIVOTED_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int searchForValueInSortedPivotedArray(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return UINT_MAX;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == key){
			return counter;
		}
	}
	return UINT_MAX;
}

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int searchForKeyBinarySearchAscendingSortedVector(vector<int> userInput,int key,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		return middleIndex;
	}
	if(userInput[middleIndex] > key){
		return searchForKeyBinarySearchAscendingSortedVector(userInput,key,startIndex,middleIndex-1);
	}else{
		return searchForKeyBinarySearchAscendingSortedVector(userInput,key,middleIndex+1,endIndex);
	}
}

unsigned int searchForKeyBinarySearchDescendingSortedVector(vector<int> userInput,int key,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		return middleIndex;
	}
	if(userInput[middleIndex] > key){
		return searchForKeyBinarySearchDescendingSortedVector(userInput,key,middleIndex+1,endIndex);
	}else{
		return searchForKeyBinarySearchDescendingSortedVector(userInput,key,startIndex,middleIndex-1);
	}
}

unsigned int getPivotElementIndex(vector<int> userInput,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex || userInput.size() == 0){
		return 0;
	}
	if(startIndex  == endIndex){
		return startIndex;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if(middleIndex+1 <= endIndex){
		if(userInput[middleIndex] > userInput[middleIndex+1]){
			return middleIndex;
		}
	}
	if(userInput[middleIndex] > userInput[startIndex]){
		return getPivotElementIndex(userInput,middleIndex+1,endIndex);
	}else{
		return getPivotElementIndex(userInput,startIndex,middleIndex-1);
	}
}

//Tested
unsigned int searchForValueInSortedPivotArrayByFindingPivot(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return UINT_MAX;
	}
	unsigned int pivotIndex = getPivotElementIndex(userInput,0,userInput.size()-1);
	if(userInput[pivotIndex] == key){
		return pivotIndex;
	}
	if(pivotIndex == 0){
		return searchForKeyBinarySearchAscendingSortedVector(userInput,key,0,userInput.size()-1);
	}else{
		if(userInput[0] <= key && userInput[pivotIndex-1] >= key){
			return searchForKeyBinarySearchAscendingSortedVector(userInput,key,0,pivotIndex-1);
		}else if(userInput[pivotIndex+1] <= key && userInput[userInput.size()-1]>=key){
			return searchForKeyBinarySearchAscendingSortedVector(userInput,key,pivotIndex+1,userInput.size()-1);
		}
	}
	return UINT_MAX;
}

//Works only for unique values
unsigned int searchForValueInSortedPivorArrayOLOGN(vector<int> userInput,int key,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex||userInput.size() == 0){
		return UINT_MAX;
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		return middleIndex;
	}

	if(userInput[middleIndex] > userInput[startIndex]){
		if(userInput[middleIndex] > key && key > userInput[startIndex]){
			return searchForValueInSortedPivorArrayOLOGN(userInput,key,startIndex,middleIndex-1);
		}else{
			return searchForValueInSortedPivorArrayOLOGN(userInput,key,middleIndex+1,endIndex);
		}
	}else{
		if(userInput[middleIndex] < key && key <= userInput[endIndex]){
			return searchForValueInSortedPivorArrayOLOGN(userInput,key,middleIndex+1,endIndex);
		}else{
			return searchForValueInSortedPivorArrayOLOGN(userInput,key,startIndex,middleIndex-1);
		}
	}

}

#endif /* SEARCHINSORTEDPIVOTED_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
