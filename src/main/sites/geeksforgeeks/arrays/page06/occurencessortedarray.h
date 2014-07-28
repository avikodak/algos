/****************************************************************************************************************************************************
 *  File Name   		: occurencessortedarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page06\occurencessortedarray.h
 *  Created on			: May 10, 2014 :: 11:51:52 AM
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

#ifndef OCCURENCESSORTEDARRAY_H_
#define OCCURENCESSORTEDARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int occurencesSortedArray(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return 0;
	}
	unsigned int frequency = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == key){
			frequency += 1;
		}
	}
	return frequency;
}

unsigned int lowerIndexForKey(vector<int> userInput,int startIndex,int endIndex,int key){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		if(middleIndex-1 >= startIndex){
			if(userInput[middleIndex-1] == key){
				return lowerIndexForKey(userInput,startIndex,middleIndex-1,key);
			}
		}
		return middleIndex;
	}
	if(userInput[middleIndex] > key){
		return lowerIndexForKey(userInput,startIndex,middleIndex-1);
	}else{
		return lowerIndexForKey(userInput,middleIndex+1,endIndex);
	}
}

unsigned int upperIndexForKey(vector<int> userInput,int startIndex,int endIndex,int key){
	if(startIndex > endIndex){
		return UINT_MAX;
	}
	int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		if(middleIndex+1 <= endIndex){
			if(userInput[middleIndex+1] == key){
				return upperIndexForKey(userInput,middleIndex+1,endIndex);
			}
		}
		return middleIndex;
	}
	if(userInput[middleIndex] > key){
		return upperIndexForKey(userInput,startIndex,middleIndex-1);
	}else{
		return upperIndexForKey(userInput,middleIndex+1,endIndex);
	}
}

unsigned int occurenceSortedArrayBinarySearch(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return 0;
	}
	unsigned int lowerIndex = lowerIndexBinarySearch(userInput,0,userInput.size()-1,key);
	unsigned int upperIndex = upperIndexForKey(userInput,0,userInput.size()-1,key);
	return upperIndex - lowerIndex + 1;
}

unsigned int occurenceSortedArraySTL(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return 0;
	}
	unsigned int lowerIndex = lower_bound(userInput.begin(),userInput.end(),key) - userInput.begin();
	unsigned int upperIndex = upper_bound(userInput.begin(),userInput.end(),key) - userInput.begin();
	return upperIndex - lowerIndex + 1;
}

#endif /* OCCURENCESSORTEDARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
