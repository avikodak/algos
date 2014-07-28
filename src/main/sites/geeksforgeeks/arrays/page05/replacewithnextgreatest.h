/****************************************************************************************************************************************************
 *  File Name   		: replacewithnextgreatest.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page05\replacewithnextgreatest.h
 *  Created on			: Jun 30, 2014 :: 11:24:39 PM
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

#ifndef REPLACEWITHNEXTGREATEST_H_
#define REPLACEWITHNEXTGREATEST_H_


/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void replaceElementWithNextGreatestIterative(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	int maxTillNow = userInput[userInput.size()-1],tempForSwap;
	userInput[userInput.size()-1] = -1;
	for(unsigned int counter = userInput.size()-2;counter >= 0;counter--){
		if(maxTillNow < userInput[counter]){
			tempForSwap = maxTillNow;
			maxTillNow = userInput[counter];
			userInput[counter] = tempForSwap;
		}else{
			userInput[counter] = maxTillNow;
		}
	}
}

int replaceElementWithNextGreatest(vector<int> userInput,unsigned int currentIndex){
	if(userInput.size() == 0 || currentIndex >= userInput.size()){
		return -1;
	}
	int result = replaceElementWithNextGreatest(userInput,currentIndex+1);
	int temp = userInput[currentIndex];
	userInput[currentIndex] = result;
	return max(result,temp);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void replaceElementWithNextGreatestON2(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	int maxElement;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-1;outerCrawler++){
		maxElement = INT_MIN;
		for(unsigned int innerCrawler = outerCrawler+1;innerCrawler < userInput.size();innerCrawler++){
			maxElement = max(maxElement,userInput[innerCrawler]);
		}
		userInput[outerCrawler] = maxElement;
	}
	userInput[userInput.size()-1] = -1;
}

#endif /* REPLACEWITHNEXTGREATEST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
