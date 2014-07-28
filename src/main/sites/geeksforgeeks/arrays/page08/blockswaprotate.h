/****************************************************************************************************************************************************
 *  File Name   		: blockswaprotate.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page08\blockswaprotate.h
 *  Created on			: May 7, 2014 :: 6:44:58 PM
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
#include "../../../../utils/printingutil.h"

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef BLOCKSWAPROTATE_H_
#define BLOCKSWAPROTATE_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void swapBlock(vector<int> &userInput,unsigned int firstArrayBeginIndex,unsigned int firstArrayEndIndex,unsigned int secondArrayBeginIndex,unsigned int secondArrayEndIndex){
	if(abs(firstArrayEndIndex - firstArrayBeginIndex) != abs(secondArrayEndIndex - secondArrayBeginIndex)){
		throw "Invalid inputs";
	}
	int tempForSwap;
	for(unsigned int counter = firstArrayBeginIndex;counter <= firstArrayEndIndex;counter++){
		tempForSwap = userInput[counter];
		userInput[counter] = userInput[secondArrayBeginIndex + counter-firstArrayBeginIndex];
		userInput[secondArrayBeginIndex + counter-firstArrayBeginIndex] = tempForSwap;
	}
}

//Tested
void rotateArrayBlockSwapMain(vector<int> &userInput,unsigned int rotateBy,unsigned int startIndex,unsigned int endIndex){
	if(startIndex > endIndex || startIndex == endIndex){
		return;
	}
	rotateBy = rotateBy % (endIndex-startIndex+1);
	if(rotateBy == 0){
		return;
	}
	unsigned int dividingIndex = startIndex + rotateBy - 1;
	int firstArraySize = abs(dividingIndex - startIndex)+1,secondArraySize = abs(endIndex - dividingIndex);
	if(firstArraySize == secondArraySize){
		swapBlock(userInput,startIndex,dividingIndex,endIndex-firstArraySize+1,endIndex);
		return;
	}
	if(firstArraySize > secondArraySize){
		swapBlock(userInput,startIndex,startIndex+secondArraySize-1,endIndex-secondArraySize+1,endIndex);
		rotateArrayBlockSwapMain(userInput,rotateBy,startIndex,dividingIndex);
	}else{
		swapBlock(userInput,startIndex,dividingIndex,endIndex-(firstArraySize)+1,endIndex);
		rotateArrayBlockSwapMain(userInput,rotateBy,dividingIndex+1,endIndex);
	}
}

//Tested
void rotateArrayBlockSwap(vector<int> &userInput,unsigned int rotateBy){
	if(userInput.size() == 0){
		return;
	}
	rotateBy %= userInput.size();
	if(rotateBy == 0){
		return;
	}
	rotateArrayBlockSwapMain(userInput,rotateBy,0,userInput.size()-1);
}

#endif /* BLOCKSWAPROTATE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
