/****************************************************************************************************************************************************
 *  File Name   		: divisibilityby8.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter03\divisibilityby8.h
 *  Created on			: Jun 8, 2014 :: 3:23:24 PM
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

#ifndef DIVISIBILITYBY8_H_
#define DIVISIBILITYBY8_H_

//Tested
void init(hash_map<unsigned int,bool> &multiplesOf8){
	for(unsigned int counter = 0;8*counter < 10000;counter++){
		multiplesOf8.insert(pair<unsigned int,bool>(8*counter,true));
	}
}

//Tested
bool divisibilityBy8(int userInput){
	hash_map<unsigned int,bool> multiplesOf8;
	init(multiplesOf8);
	unsigned int lastThreeDigits = userInput % 1000;
	return multiplesOf8.find(lastThreeDigits) == multiplesOf8.end()?false:true;
}

#endif /* DIVISIBILITYBY8_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
