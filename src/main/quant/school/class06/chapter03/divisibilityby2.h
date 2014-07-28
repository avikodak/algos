/****************************************************************************************************************************************************
 *  File Name   		: divisibilityby2.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\divisibilityby2.h
 *  Created on			: Jun 8, 2014 :: 3:22:15 PM
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

#ifndef DIVISIBILITYBY2_H_
#define DIVISIBILITYBY2_H_

//Tested
bool divisibilityBy2(unsigned int userInput){
	unsigned int lastDigit = userInput%10;
	return lastDigit == 2 || lastDigit == 4 || lastDigit == 6 || lastDigit == 8 || lastDigit == 0;
}

//Tested
bool divisibilityBy2Bitwise(unsigned int userInput){
	return !(userInput & 1);
}
#endif /* DIVISIBILITYBY2_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
