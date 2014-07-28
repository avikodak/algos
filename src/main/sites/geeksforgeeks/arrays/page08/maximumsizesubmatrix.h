/****************************************************************************************************************************************************
 *  File Name   		: maximumsizesubmatrix.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page08\maximumsizesubmatrix.h
 *  Created on			: May 8, 2014 :: 12:34:52 AM
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

#ifndef MAXIMUMSIZESUBMATRIX_H_
#define MAXIMUMSIZESUBMATRIX_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
unsigned int maximumsizeSubMatrixWithAllOnes(vector<vector<unsigned int> > userInput){
	if(userInput.size() == 0){
		return 0;
	}

	for(unsigned int rowCounter = 1;rowCounter < userInput.size();rowCounter++){
		for(unsigned int columnCounter = 1;columnCounter < userInput[0].size();columnCounter++){

			userInput[rowCounter][columnCounter] = min(userInput[rowCounter-1][columnCounter-1],userInput[rowCounter-1][columnCounter],userInput[rowCounter][columnCounter-1]) + 1;
		}
	}
	unsigned int maxSize = 0;
	for(unsigned int rowCounter = 1;rowCounter < userInput.size();rowCounter++){
		for(unsigned int columnCounter = 1;columnCounter < userInput[0].size();columnCounter++){
			maxSize = max(maxSize,userInput[rowCounter][columnCounter]);
		}
	}
	return maxSize;
}

#endif /* MAXIMUMSIZESUBMATRIX_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
