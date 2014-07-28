/****************************************************************************************************************************************************
 *  File Name   		: productarray.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page07\productarray.h
 *  Created on			: May 1, 2014 :: 7:38:49 PM
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

#ifndef PRODUCTARRAY_H_
#define PRODUCTARRAY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<int> productArrayPuzzle(vector<int> userInput){
	vector<int> productArray;
	if(userInput.size() == 0){
		return productArray;
	}
	vector<int> leftProductArray;
	leftProductArray.push_back(1);
	int rightProduct = 1;
	for(unsigned int counter = 1;counter < userInput.size();counter++){
		leftProductArray[counter] = leftProductArray[counter-1] * userInput[counter-1];
	}
	productArray[userInput.size()-1] = leftProductArray[userInput.size()-1];
	for(int counter = userInput.size()-2;counter >= 0;counter--){
		productArray[counter] = rightProduct * leftProductArray[counter+1];
		rightProduct *= userInput[counter];
	}
	return productArray;
}

#endif /* PRODUCTARRAY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
