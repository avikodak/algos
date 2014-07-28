/****************************************************************************************************************************************************
 *  File Name   		: demlonumbers.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\demlonumbers.h
 *  Created on			: Jun 15, 2014 :: 10:53:59 PM
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

#ifndef DEMLONUMBERS_H_
#define DEMLONUMBERS_H_

bool isNumberDemlo(unsigned int userInput){
	vector<uint8_t> digits;
	while(userInput){
		digits.push_back(userInput%10);
		userInput /= 10;
	}
	unsigned int middleIndex = digits.size()/2;
	unsigned int startIndex = middleIndex - 1;
	unsigned int endIndex  = middleIndex + 1;
	while(startIndex > 0 && userInput[startIndex] == userInput[middleIndex]){
		startIndex--;
	}
	while(endIndex < digits.size() && userInput[endIndex] == userInput[middleIndex]){
		endIndex++;
	}
}

#endif /* DEMLONUMBERS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
