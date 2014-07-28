/****************************************************************************************************************************************************
 *  File Name   		: divisibilityby3.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\divisibilityby3.h
 *  Created on			: Jun 8, 2014 :: 3:22:25 PM
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

#ifndef DIVISIBILITYBY3_H_
#define DIVISIBILITYBY3_H_

//Tested
bool divisibilityBy3(unsigned int userInput){
	if(userInput == 3 || userInput == 6 || userInput == 9){
		return true;
	}
	if(userInput < 9){
		return false;
	}
	unsigned int sumOfDigits = 0;
	while(userInput){
		sumOfDigits += userInput % 10;
		userInput /= 10;
	}
	return divisibilityBy3(sumOfDigits);
}

#endif /* DIVISIBILITYBY3_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
