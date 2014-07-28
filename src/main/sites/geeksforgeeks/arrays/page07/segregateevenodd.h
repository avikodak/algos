/****************************************************************************************************************************************************
 *  File Name   		: segregateevenodd.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\arrays\page07\segregateevenodd.h
 *  Created on			: May 1, 2014 :: 7:36:26 PM
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

#ifndef SEGREGATEEVENODD_H_
#define SEGREGATEEVENODD_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void segregateEvenOddNumbers(vector<int> userInput){
	if(userInput.size()==0){
		return;
	}
	unsigned int frontCrawler = 0,backCrawler = userInput.size()-1;
	int temp;
	while(frontCrawler < backCrawler){
		while(userInput[frontCrawler]%2 == 0){
			frontCrawler++;
		}
		while(frontCrawler < backCrawler && userInput[backCrawler]%2 == 1){
			backCrawler--;
		}
		if(frontCrawler < backCrawler){
			temp = userInput[frontCrawler];
			userInput[frontCrawler] = userInput[backCrawler];
			userInput[backCrawler] = temp;
		}
	}
}

void segregateEvenOddNumbersAuxspace(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	queue<int> evenNumber,oddNumber;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		if(userInput[counter]%2 == 0){
			evenNumber.push(userInput[counter]);
		}else{
			oddNumber.push(userInput[counter]);
		}
	}
	unsigned int fillCounter = 0;
	while(!evenNumber.empty()){
		userInput[fillCounter++] = evenNumber.front();
		evenNumber.pop();
	}
	while(!oddNumber.empty()){
		userInput[fillCounter++] = oddNumber.front();
		oddNumber.pop();
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

void sortfuncOddeven(int firstUserInput,int secondUserInput){
	if(firstUserInput%2 == 0){
		return true;
	}else{
		return firstUserInput < secondUserInput;
	}
}

void segregateEvenOddNumberONLOGN(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	sort(userInput.begin(),userInput.end(),sortfuncOddeven);
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void segregateEvenOddNumberON2(vector<int> userInput){
	if(userInput.size() == 0){
		return;
	}
	unsigned int innerCrawler;
	int temp;
	for(unsigned int outerCrawler = 0;outerCrawler < userInput.size()-1;outerCrawler++){
		if(userInput[outerCrawler]%2 == 0){
			continue;
		}
		innerCrawler = outerCrawler+1;
		while(innerCrawler < userInput.size() && userInput[innerCrawler] % 2 == 0){
			innerCrawler++;
		}
		if(innerCrawler < userInput.size()){
			temp = userInput[innerCrawler];
			userInput[innerCrawler] = userInput[outerCrawler];
			userInput[outerCrawler] = temp;
		}
	}
}

#endif /* SEGREGATEEVENODD_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

