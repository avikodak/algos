/****************************************************************************************************************************************************
 *  File Name   		: mergesortedarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page09\mergesortedarray.h
 *  Created on			: Apr 20, 2014 :: 7:39:53 PM
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

#ifndef MERGESORTEDARRAY_H_
#define MERGESORTEDARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void mergeSortedArray(vector<int> &largeSortedArray,vector<int> smallSortedArray){
	if(largeSortedArray.size() == 0 || smallSortedArray.size() == 0){
		return;
	}
	int largeArrayCounter = largeSortedArray.size() - 1;
	int smallArrayCounter = smallSortedArray.size() - 1;
	unsigned int fillCounter = largeSortedArray.size()+smallSortedArray.size()-1;
	largeSortedArray.resize(largeSortedArray.size() + smallSortedArray.size());
	while(largeArrayCounter >= 0 && smallArrayCounter >= 0){
		if(largeSortedArray[largeArrayCounter] > smallSortedArray[smallArrayCounter]){
			largeSortedArray[fillCounter] = largeSortedArray[largeArrayCounter];
			largeArrayCounter--;
		}else{
			largeSortedArray[fillCounter] = smallSortedArray[smallArrayCounter];
			smallArrayCounter--;
		}
		fillCounter--;
	}
	while(largeArrayCounter >= 0){
		largeSortedArray[fillCounter] = largeSortedArray[largeArrayCounter];
		largeArrayCounter--;
		fillCounter--;
	}
	while(smallArrayCounter >= 0){
		largeSortedArray[fillCounter] = smallSortedArray[smallArrayCounter];
		smallArrayCounter--;
		fillCounter--;
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void mergeSortedArrayONLOGN(vector<int> &largeSortedArray,vector<int> smallSortedArray){
	if(largeSortedArray.size() == 0  || smallSortedArray.size() == 0){
		return;
	}
	unsigned int fillCounter = largeSortedArray.size() + smallSortedArray.size();
	largeSortedArray.resize(largeSortedArray.size() + smallSortedArray.size());
	for(unsigned int counter = 0;counter < smallSortedArray.size();counter++){
		largeSortedArray[--fillCounter] = smallSortedArray[counter];
	}
	sort(largeSortedArray.begin(),largeSortedArray.end());
}


#endif /* MERGESORTEDARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
