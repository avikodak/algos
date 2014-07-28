/****************************************************************************************************************************************************
 *  File Name   		: segregate0s1sarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page08\segregate0s1sarray.h
 *  Created on			: May 1, 2014 :: 6:11:12 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/
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

#ifndef SEGREGATE0S1SARRAY_H_
#define SEGREGATE0S1SARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void segregate0s1sQuickSort(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int frontCrawler = 0,backCrawler = userInput.size()-1;
	while(frontCrawler < backCrawler){
		while(frontCrawler < backCrawler && userInput[frontCrawler] == 0){
			frontCrawler++;
		}
		while(frontCrawler < backCrawler && userInput[backCrawler] == 1){
			backCrawler--;
		}
		if(frontCrawler < backCrawler){
			userInput[frontCrawler] = 0;
			userInput[backCrawler] = 1;
		}
	}
}

//Tested
void segregate0s1sBuckets(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int trueCounter = 0,falseCounter = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter]){
			trueCounter++;
		}else{
			falseCounter++;
		}
	}
	unsigned int fillCounter = 0;
	while(falseCounter--){
		userInput[fillCounter++] = 0;
	}
	while(trueCounter--){
		userInput[fillCounter++] = 1;
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/
bool sortFunc0s1s(bool first,bool second){
	return !first;
}

//Tested
void segregate0s1sSorted(vector<int> userInput){
	if(userInput.size()==0){
		return;
	}
	sort(userInput.begin(),userInput.end());
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void segregate0s1sON2(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int outerCrawler,innerCrawler;
	for(outerCrawler = 0;outerCrawler < userInput.size();outerCrawler++){
		if(userInput[outerCrawler] != 0){
			for(innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
				if(userInput[innerCrawler] == 0){
					break;
				}
			}
			if(innerCrawler < userInput.size()){
				userInput[outerCrawler] = 0;
				userInput[innerCrawler] = 1;
			}
		}
	}

}

#endif /* SEGREGATE0S1SARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
