/****************************************************************************************************************************************************
 *  File Name   		: printreverse.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\strings\page03\printreverse.h
 *  Created on			: Jun 26, 2014 :: 3:44:15 PM
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

#ifndef PRINTREVERSE_H_
#define PRINTREVERSE_H_

void printReverseRecursion(char *userInput){
	if(userInput == null){
		return;
	}
	printReverseRecursion(userInput+1);
	printf("%c",*userInput);
}

void printReverseIterative(char *userInput){
	if(userInput == null){
		return;
	}
	stack<char> auxSpace;
	while(userInput != null){
		auxSpace.push((char)(*userInput));
		userInput++;
	}
	while(!auxSpace.empty()){
		printf("%c",auxSpace.top());
		auxSpace.pop();
	}
}

#endif /* PRINTREVERSE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
