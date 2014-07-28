/****************************************************************************************************************************************************
 *  File Name   		: twinprimes.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\twinprimes.h
 *  Created on			: Jun 15, 2014 :: 6:08:09 PM
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

#include "primenumbers.h"
/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef TWINPRIMES_H_
#define TWINPRIMES_H_

//Tested
bool areTwinPrimes(unsigned int firstUserInput,unsigned int secondUserInput){
	if(!isNumberPrimeOptimised(firstUserInput)){
		return false;
	}
	if(!isNumberPrimeOptimised(secondUserInput)){
		return false;
	}
	return firstUserInput > secondUserInput?firstUserInput-secondUserInput:secondUserInput-firstUserInput == 2;
}

#endif /* TWINPRIMES_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
