/****************************************************************************************************************************************************
 *  File Name   		: reversearray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page08\reversearray.h
 *  Created on			: Apr 23, 2014 :: 11:39:08 PM
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

#ifndef REVERSEARRAY_H_
#define REVERSEARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void reverseArray(vector<int> &userInput,unsigned int frontCrawler,unsigned int rearCrawler){
	if(userInput.size() == 0 || frontCrawler >= rearCrawler){
		return;
	}
	int temp = userInput[frontCrawler];
	userInput[frontCrawler] = userInput[rearCrawler];
	userInput[rearCrawler] = temp;
	reverseArray(userInput,frontCrawler+1,rearCrawler-1);
}

//Tested
void reverseArrayIterative(vector<int> &userInput){
	if(userInput.size()  == 0){
		return;
	}
	unsigned int frontCrawler = 0,rearCrawler = userInput.size()-1;
	int temp;
	while(frontCrawler < rearCrawler){
		temp = userInput[frontCrawler];
		userInput[frontCrawler] = userInput[rearCrawler];
		userInput[rearCrawler] = temp;
		frontCrawler++;
		rearCrawler--;
	}
}

#endif /* REVERSEARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
