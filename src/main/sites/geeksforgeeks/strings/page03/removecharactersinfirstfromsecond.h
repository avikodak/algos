/****************************************************************************************************************************************************
 *  File Name   		: removecharactersinfirstfromsecond.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\strings\page03\removecharactersinfirstfromsecond.h
 *  Created on			: Jun 26, 2014 :: 3:53:22 PM
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

#ifndef REMOVECHARACTERSINFIRSTFROMSECOND_H_
#define REMOVECHARACTERSINFIRSTFROMSECOND_H_


/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

void removeAllMatchingChars(char *userInput,char *mask){
	if(userInput == null || mask == null){
		return;
	}
	hash_map<char,bool> charPresenceMap;
	hash_map<char,bool>::iterator itToCharPresenceMap;
	char *crawler = mask;
	while(crawler != null){
		if((itToCharPresenceMap = charPresenceMap.find((char)*crawler)) == charPresenceMap.end()){
			charPresenceMap.insert(pair<char,bool>((char)*crawler,true));
		}
		crawler++;
	}
	crawler = userInput;
	unsigned int fillIndex = 0;
	while(crawler != null){
		if(charPresenceMap.find((char)(*crawler)) == charPresenceMap.end()){
			userInput[fillIndex] = (*crawler);
			fillIndex++;
		}
		crawler++;
	}
	userInput[fillIndex] = '\0';
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/




/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* REMOVECHARACTERSINFIRSTFROMSECOND_H_ */


/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
