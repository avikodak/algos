/****************************************************************************************************************************************************
 *  File Name   		: postordertwostacks.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page04\postordertwostacks.h
 *  Created on			: May 25, 2014 :: 2:08:48 PM
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

#ifndef POSTORDERTWOSTACKS_H_
#define POSTORDERTWOSTACKS_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void postOrderTreeTwoStacks(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	itNode *currentNode;
	primaryAuxspace.push(ptr);
	while(!primaryAuxspace.empty()){
		currentNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		secondaryAuxspace.push(currentNode);
		if(currentNode->left != null){
			primaryAuxspace.push(currentNode->left);
		}
		if(currentNode->right != null){
			primaryAuxspace.push(currentNode->right);
		}
	}
	while(!secondaryAuxspace.empty()){
		currentNode = secondaryAuxspace.top();
		secondaryAuxspace.pop();
		printf("%d\t",currentNode->value);
	}
}


#endif /* POSTORDERTWOSTACKS_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
