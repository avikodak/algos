/****************************************************************************************************************************************************
 *  File Name   		: verticalsum.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page06\verticalsum.h
 *  Created on			: May 9, 2014 :: 8:49:49 PM
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

#ifndef VERTICALSUM_H_
#define VERTICALSUM_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void setVerticalSumInHashMapPreorder(itNode *ptr,int column,hash_map<int,int> &columnSumMap){
	if(ptr == null){
		return;
	}
	hash_map<int,int>::iterator itToColumnSumMap;
	itToColumnSumMap = columnSumMap.find(column);
	if(itToColumnSumMap == columnSumMap.end()){
		columnSumMap[column] = ptr->value;
	}else{
		columnSumMap[column] += ptr->value;
	}
	setVerticalSumInHashMapPreorder(ptr->left,column-1,columnSumMap);
	setVerticalSumInHashMapPreorder(ptr->right,column-1,columnSumMap);
}

void setVerticalSumInHashMapInorder(itNode *ptr,int column,hash_map<int,int> &columnSumMap){
	if(ptr == null){
		return;
	}
	setVerticalSumInHashMapInorder(ptr->left,column-1,columnSumMap);
	hash_map<int,int>::iterator itToColumnSumMap;
	itToColumnSumMap = columnSumMap.find(column);
	if(itToColumnSumMap == columnSumMap.end()){
		columnSumMap[column] = ptr->value;
	}else{
		columnSumMap[column] += ptr->value;
	}
	setVerticalSumInHashMapInorder(ptr->right,column+1,columnSumMap);
}

void setVerticalSumInHashmapPostorder(itNode *ptr,int column,hash_map<int,int> &columnSumMap){
	if(ptr == null){
		return;
	}
	setVerticalSumInHashmapPostorder(ptr->left,column-1,columnSumMap);
	setVerticalSumInHashmapPostorder(ptr->right,column+1,columnSumMap);
	hash_map<int,int>::iterator itToColumnSumMap;
	itToColumnSumMap = columnSumMap.find(column);
	if(itToColumnSumMap == columnSumMap.end()){
		columnSumMap[column] = ptr->value;
	}else{
		columnSumMap[column] += ptr->value;
	}
}

hash_map<int,int> getVerticalSumInHashmapPreorderIterative(itNode *ptr){
	hash_map<int,int> verticalSumMap;
	if(ptr == null){
		return verticalSumMap;
	}
	hash_map<uint32_t,int> nodeVerticalIndexMap;
	hash_map<uint32_t,int>::iterator itToNodeVerticalIndexMap;
	hash_map<int,int>::iterator itToVerticalSumMap;
	stack<itNode *> auxSpace;
	itNode *currentTopNode;
	auxSpace.push(ptr);
	nodeVerticalIndexMap.insert(pair<uint32_t,int>((uint32_t)ptr,0));
	while(!auxSpace.empty()){
		currentTopNode = auxSpace.top();
		auxSpace.pop();
		itToNodeVerticalIndexMap = nodeVerticalIndexMap.find((uint32_t)ptr);
		verticalSumMap.insert(pair<int,int>(itToNodeVerticalIndexMap->second,currentTopNode->value));
		if(currentTopNode->right != null){
			auxSpace.push(currentTopNode->right);
			nodeVerticalIndexMap.insert(pair<uint32_t,int>((uint32_t)currentTopNode->right,itToNodeVerticalIndexMap->second + 1));
		}
		if(currentTopNode->left != null){
			auxSpace.push(currentTopNode->left);
			nodeVerticalIndexMap.insert(pair<uint32_t,int>((uint32_t)currentTopNode->left,itToNodeVerticalIndexMap->second - 1));
		}
	}
	return verticalSumMap;
}

hash_map<int,int> getVerticalSumInHashmapInorderIterative(itNode *ptr){
	hash_map<int,int> verticalSumMap;
	if(ptr == null){
		return verticalSumMap;
	}
	hash_map<uint32_t,int> nodeVerticalIndexMap;
	hash_map<uint32_t,int>::iterator itToNodeVerticalIndexMap;
	hash_map<int,int>::iterator itToVerticalSumMap;
	stack<itNode *> auxSpace;
	itNode *currentTopNode = ptr;
	nodeVerticalIndexMap.insert(pair<uint32_t,int>((uint32_t)ptr,0));
	while(!auxSpace.empty() || currentTopNode != null){
		if(currentTopNode != null){
			auxSpace.push(currentTopNode);
			if(currentTopNode->left != null){
				itToNodeVerticalIndexMap = nodeVerticalIndexMap.find((uint32_t)currentTopNode);
				nodeVerticalIndexMap.insert(pair<uint32_t,int>((uint32_t)currentTopNode->left,itToNodeVerticalIndexMap->second-1));
			}
			currentTopNode = currentTopNode->left;
		}else{
			currentTopNode = auxSpace.top();
			auxSpace.pop();
			itToNodeVerticalIndexMap = nodeVerticalIndexMap.find((uint32_t)currentTopNode);
			if((itToVerticalSumMap = verticalSumMap.find(itToNodeVerticalIndexMap->second)) == verticalSumMap.end()){
				verticalSumMap[itToVerticalSumMap->second] = currentTopNode->value;
			}else{
				verticalSumMap[itToVerticalSumMap->second] += currentTopNode->value;
			}
			if(currentTopNode->right != null){
				nodeVerticalIndexMap.insert(pair<uint32_t,int>((uint32_t)currentTopNode->right,itToNodeVerticalIndexMap->second+1));
			}
			currentTopNode = currentTopNode->right;
		}
	}
	return verticalSumMap;
}

hash_map<int,int> getVerticalSumInHashmapPostorderIterativeTwoStacks(itNode *ptr){
	hash_map<int,int> verticalSumMap;
	if(ptr == null){
		return verticalSumMap;
	}
	hash_map<uint32_t,int> nodeVerticalIndexMap;
	hash_map<uint32_t,int>::iterator itToNodeVerticalIndexMap;
	hash_map<int,int>::iterator itToVerticalSumMap;
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	primaryAuxspace.push(ptr);
	itNode *currentTopNode;
	nodeVerticalIndexMap.insert(pair<uint32_t,int>((uint32_t)ptr,0));
	while(!primaryAuxspace.empty()){
		currentTopNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		secondaryAuxspace.push(currentTopNode);
		itToNodeVerticalIndexMap = nodeVerticalIndexMap.find((uint32_t)currentTopNode);
		if(currentTopNode->left != null){
			primaryAuxspace.push(currentTopNode->left);
			nodeVerticalIndexMap.insert(pair<uint32_t,int>((uint32_t)currentTopNode->left,itToNodeVerticalIndexMap->second-1));
		}
		if(currentTopNode->right != null){
			primaryAuxspace.push(currentTopNode->right);
			nodeVerticalIndexMap.insert(pair<uint32_t,int>((uint32_t)currentTopNode->right,itToNodeVerticalIndexMap->second+1));
		}
	}

	while(!secondaryAuxspace.empty()){
		currentTopNode = secondaryAuxspace.top();
		secondaryAuxspace.pop();
		itToNodeVerticalIndexMap = nodeVerticalIndexMap.find((uint32_t)currentTopNode);
		if((itToVerticalSumMap = verticalSumMap.find(itToNodeVerticalIndexMap->second)) == verticalSumMap.end()){
			verticalSumMap[itToNodeVerticalIndexMap->second] = currentTopNode->value;
		}else{
			verticalSumMap[itToNodeVerticalIndexMap->second] += currentTopNode->value;
		}
	}
	return verticalSumMap;
}


#endif /* VERTICALSUM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
