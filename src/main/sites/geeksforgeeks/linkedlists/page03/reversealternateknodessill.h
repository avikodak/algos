/****************************************************************************************************************************************************
 *  File Name   		: reversealternateknodessill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page03\reversealternateknodessill.h
 *  Created on			: May 1, 2014 :: 7:47:59 PM
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

#ifndef REVERSEALTERNATEKNODESSILL_H_
#define REVERSEALTERNATEKNODESSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//hashmap,recursive,iterative
void reverseAlternateKNodesSill(sillNode *ptr,unsigned int kValue){
	if(ptr == null || kValue == 0){
		return;
	}
	stack<int> reverseValues;
	queue<int> auxSpace,inlineValues;
	sillNode *traversalNode = ptr;
	unsigned int temp = kValue;
	bool reverseValue = true;
	while(traversalNode != null){
		if(temp != 0){
			if(reverseValue){
				reverseValues.push(traversalNode->value);
			}else{
				inlineValues.push(traversalNode->value);
			}
			traversalNode = traversalNode->next;
			temp -= 1;
		}else{
			if(reverseValue){
				while(!reverseValues.empty()){
					auxSpace.push(reverseValues.top());
					reverseValues.pop();
				}
			}else{
				while(!inlineValues.empty()){
					auxSpace.push(inlineValues.front());
					inlineValues.pop();
				}
			}
			temp = kValue;
			reverseValue = !reverseValue;
		}
	}
	traversalNode = ptr;
	while(!auxSpace.empty()){
		traversalNode->value = auxSpace.front();
		auxSpace.pop();
		traversalNode = traversalNode->next;
	}
}


/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* REVERSEALTERNATEKNODESSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
