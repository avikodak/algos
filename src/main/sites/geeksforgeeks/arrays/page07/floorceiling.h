/****************************************************************************************************************************************************
 *  File Name   		: floorceiling.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page07\floorceiling.h
 *  Created on			: May 1, 2014 :: 7:36:10 PM
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

#ifndef FLOORCEILING_H_
#define FLOORCEILING_H_

/****************************************************************************************************************************************************/
/* 																O(LOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

int getFloorFromSortedListOLOGN(vector<int> userInput,int key,unsigned int startIndex,unsigned int endIndex){
	if(userInput.size() == 0 || startIndex < endIndex){
		return INT_MIN;
	}
	if(startIndex == endIndex){
		return userInput[startIndex];
	}
	unsigned int middleIndex = (startIndex + endIndex)/2;
	if(userInput[middleIndex] == key){
		return userInput[middleIndex];
	}
	if(userInput[middleIndex] > key){
		return getFloorFromSortedListOLOGN(userInput,key,startIndex,middleIndex-1);
	}else{
		return getFloorFromSortedListOLOGN(userInput,key,middleIndex+1,endIndex);
	}
}

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
int getFloorFromSortedList(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	if(userInput[0] > key){
		return INT_MIN;
	}
	unsigned int counter = 0;
	while(counter < userInput.size() && userInput[counter] <= key){
		counter++;
	}
	return userInput[counter-1];
}

int getCeilingFromSortedList(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return INT_MAX;
	}
	if(userInput[userInput.size()-1] < key){
		return INT_MAX;
	}
	unsigned int counter = 0;
	while(counter < userInput.size() && userInput[counter] < key){
		counter++;
	}
	return userInput[counter];
}

#endif /* FLOORCEILING_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
