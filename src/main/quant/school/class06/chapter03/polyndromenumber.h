/****************************************************************************************************************************************************
 *  File Name   		: polyndromenumber.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\polyndromenumber.h
 *  Created on			: Jun 15, 2014 :: 10:52:33 PM
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

#ifndef POLYNDROMENUMBER_H_
#define POLYNDROMENUMBER_H_

//Tested
bool isNumberPolyndrome(unsigned int userInput){
	if(userInput < 9){
		return true;
	}
	unsigned int reversedNumber = 0;
	unsigned int auxCopy = userInput;
	while(auxCopy){
		reversedNumber *= 10;
		reversedNumber += auxCopy % 10;
		auxCopy /= 10;
	}
	auxCopy = userInput;
	while(auxCopy && reversedNumber){
		if(reversedNumber%10 != auxCopy % 10){
			return false;
		}
		auxCopy /= 10;
		reversedNumber /= 10;
	}
	return true;
}

//Tested
bool isNumberPolyndromeAuxspace(unsigned int userInput){
	if(userInput < 9){
		return true;
	}
	stack<uint8_t> digits;
	unsigned int copy = userInput;
	while(copy){
		digits.push(copy%10);
		copy /= 10;
	}
	copy = userInput;
	while(!digits.empty()){
		if(copy%10 != digits.top()){
			return false;
		}
		digits.pop();
		copy  /= 10;
	}
	return true;
}

#endif /* POLYNDROMENUMBER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
