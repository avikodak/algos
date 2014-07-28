/****************************************************************************************************************************************************
 *  File Name   		: divisibilityby11.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\divisibilityby11.h
 *  Created on			: Jun 8, 2014 :: 3:23:47 PM
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

#ifndef DIVISIBILITYBY11_H_
#define DIVISIBILITYBY11_H_

//Tested
bool divisibilityBy11(unsigned int userInput){
	if(userInput == 11 || userInput  == 0){
		return true;
	}
	if(userInput < 11){
		return false;
	}
	unsigned int oddDigitsSum = 0,evenDigitsSum = 0;
	bool oddBit = true;
	while(userInput){
		if(oddBit){
			oddDigitsSum += userInput % 10;
		}else{
			evenDigitsSum += userInput % 10;
		}
		userInput /= 10;
		oddBit = !oddBit;
	}
	return divisibilityBy11(abs(oddDigitsSum - evenDigitsSum));
}

#endif /* DIVISIBILITYBY11_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
