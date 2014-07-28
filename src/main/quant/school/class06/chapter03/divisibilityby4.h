/****************************************************************************************************************************************************
 *  File Name   		: divisibilityby4.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\divisibilityby4.h
 *  Created on			: Jun 8, 2014 :: 3:22:37 PM
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

#ifndef DIVISIBILITYBY4_H_
#define DIVISIBILITYBY4_H_

//Tested
void init4(hash_map<unsigned int,bool> &multiplesOf4){
	for(unsigned int counter = 0;4*counter < 100;counter++){
		multiplesOf4.insert(pair<unsigned int,bool>(4*counter,true));
	}
}

//Tested
bool divisibilityBy4(unsigned int userInput){
	hash_map<unsigned int,bool> multiplesOf4;
	init4(multiplesOf4);
	unsigned int lastTwoDigits = userInput % 100;
	return multiplesOf4.find(lastTwoDigits) != multiplesOf4.end();
}

#endif /* DIVISIBILITYBY4_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
