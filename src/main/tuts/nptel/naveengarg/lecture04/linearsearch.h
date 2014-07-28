/****************************************************************************************************************************************************
 *  File Name   		: linearsearch.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture04\linearsearch.h
 *  Created on			: May 31, 2014 :: 7:51:36 PM
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

#ifndef LINEARSEARCH_H_
#define LINEARSEARCH_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
bool linearSearch(vector<int> userInput,int key,unsigned int counter){
	if(userInput.size() == counter){
		return false;
	}
	if(userInput[counter] == key){
		return true;
	}
	return linearSearch(userInput,key,counter+1);
}

bool linearSearchIterative(vector<int> userInput,int key){
	if(userInput.size() == 0){
		return false;
	}
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter] == key){
			return true;
		}
	}
	return false;
}

#endif /* LINEARSEARCH_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
