/****************************************************************************************************************************************************
 *  File Name   		: printmatrixspiral.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page06\printmatrixspiral.h
 *  Created on			: May 10, 2014 :: 1:01:31 PM
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

#ifndef PRINTMATRIXSPIRAL_H_
#define PRINTMATRIXSPIRAL_H_

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void printMatrixSpiral(vector<vector<int> > userInput,unsigned int startRowIndex,unsigned int endRowIndex,unsigned int startColumnIndex,unsigned int endColumnIndex){
	if(userInput.size() == 0 || userInput[0].size() == 0||startRowIndex > endRowIndex || startColumnIndex > endColumnIndex){
		return;
	}
	for(unsigned int columnCounter = startColumnIndex;columnCounter <= endColumnIndex;columnCounter++){
		printf("%d\t",userInput[startRowIndex][columnCounter]);
	}
	for(unsigned int rowCounter = startRowIndex;rowCounter <= endRowIndex;rowCounter++){
		printf("%d\t",userInput[rowCounter][endColumnIndex]);
	}
	for(unsigned int columnCounter = endColumnIndex;columnCounter>=startColumnIndex;columnCounter--){
		printf("%d\t",userInput[endRowIndex][columnCounter]);
	}
	for(unsigned int rowCounter = endRowIndex;rowCounter>=startRowIndex;rowCounter--){
		printf("%d\t",userInput[rowCounter][startColumnIndex]);
	}
	printMatrixSpiral(userInput,startRowIndex+1,endRowIndex-1,startColumnIndex+1,endColumnIndex-1);
}

void printMatrixSpiralIterative(vector<vector<int> > userInput){
	if(userInput.size() == 0 || userInput[0].size() == 0){
		return;
	}
	unsigned int startRowIndex=0,endRowIndex=userInput.size(),startColumnIndex=0,endColumnIndex=userInput[0].size();
	while(startRowIndex < endRowIndex && startColumnIndex < endColumnIndex){
		for(unsigned int columnCounter = startColumnIndex;columnCounter <= endColumnIndex;columnCounter++){
			printf("%d\t",userInput[startRowIndex][columnCounter]);
		}
		for(unsigned int rowCounter = startRowIndex;rowCounter <= endRowIndex;rowCounter++){
			printf("%d\t",userInput[rowCounter][endColumnIndex]);
		}
		for(unsigned int columnCounter = endColumnIndex;columnCounter>=startColumnIndex;columnCounter--){
			printf("%d\t",userInput[endRowIndex][columnCounter]);
		}
		for(unsigned int rowCounter = endRowIndex;rowCounter>=startRowIndex;rowCounter--){
			printf("%d\t",userInput[rowCounter][startColumnIndex]);
		}
	}
}
#endif /* PRINTMATRIXSPIRAL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
