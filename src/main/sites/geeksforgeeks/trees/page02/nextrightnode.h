/****************************************************************************************************************************************************
 *  File Name   		: nextrightnode.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page02\nextrightnode.h
 *  Created on			: Jun 30, 2014 :: 7:48:56 PM
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

#ifndef NEXTRIGHTNODE_H_
#define NEXTRIGHTNODE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
itNode *getNextRightNode(itNode *ptr,int key){
	if(ptr == null){
		return null;
	}
	queue<itNode *> auxSpace;
	itNode *currentNode;
	auxSpace.push(ptr);
	unsigned int currentLevelSize;
	bool keyFound;
	while(!auxSpace.empty()){
		currentLevelSize = auxSpace.size();
		keyFound = false;
		while(currentLevelSize--){
			currentNode = auxSpace.front();
			auxSpace.pop();
			if(keyFound){
				return currentNode;
			}
			if(currentNode->value == key){
				keyFound = true;
			}
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
			}
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
		}
		if(keyFound){
			return null;
		}
	}
	return null;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* NEXTRIGHTNODE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
