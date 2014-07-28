/****************************************************************************************************************************************************
 *  File Name   		: divisibilityby9.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\divisibilityby9.h
 *  Created on			: Jun 8, 2014 :: 3:23:33 PM
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

#ifndef DIVISIBILITYBY9_H_
#define DIVISIBILITYBY9_H_

//Tested
bool divisibilityBy9(unsigned int userInput){
	if(userInput == 9 || userInput == 0){
		return true;
	}
	if(userInput < 9){
		return false;
	}
	unsigned int sumOfDigits = 0;
	while(userInput){
		sumOfDigits += userInput%10;
		userInput /= 10;
	}
	return divisibilityBy9(sumOfDigits);
}

#endif /* DIVISIBILITYBY9_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
