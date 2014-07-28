/****************************************************************************************************************************************************
 *  File Name   		: numberinexpandedform.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\quant\school\class06\chapter01\numberinexpandedform.h
 *  Created on			: Jun 7, 2014 :: 10:51:09 PM
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

#ifndef NUMBERINEXPANDEDFORM_H_
#define NUMBERINEXPANDEDFORM_H_

void numberInExpandedForm(unsigned int userInput){
	stack<uint8_t> digits;
	while(userInput--){
		digits.push(userInput%10);
		userInput /= 10;
	}
	while(!digits.empty()){
		printf("%u\t",pow(10,digits.size())*digits.top());
		if(digits.size() != 1){
			printf("+\t");
		}
		digits.pop();
	}
}

#endif /* NUMBERINEXPANDEDFORM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
