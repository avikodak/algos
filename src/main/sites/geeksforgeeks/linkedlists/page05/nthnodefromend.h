/****************************************************************************************************************************************************
 *  File Name   		: nthnodefromend.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page05\nthnodefromend.h
 *  Created on			: Apr 16, 2014 :: 11:29:44 PM
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

#ifndef NTHNODEFROMEND_H_
#define NTHNODEFROMEND_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
sillNode *nthNodeFromEnd(sillNode *ptr,int nthValue){
	if(ptr == null){
		return null;
	}
	sillNode *frontCrawler = ptr,*rearCrawler = ptr;
	while(frontCrawler != null && nthValue--){
		frontCrawler = frontCrawler->next;
	}
	if(nthValue < 0){
		throw "Value is greater than length of single linked list";
	}
	while(rearCrawler != null && frontCrawler != null){
		rearCrawler = rearCrawler->next;
		frontCrawler = frontCrawler->next;
	}
	return rearCrawler;
}

//Tested
sillNode *nthNodeFromEndRecursive(sillNode *ptr,int &nthValue){
	if(ptr == null){
		return null;
	}
	sillNode *temp = nthNodeFromEndRecursive(ptr->next,nthValue);
	if(temp != null){
		return temp;
	}
	nthValue--;
	return nthValue==0?ptr:null;
}

//Tested
sillNode *nthNodeFromEndByFindingLengthIterative(sillNode *ptr,unsigned int nthValue){
	if(ptr == null){
		return null;
	}
	unsigned int lengthOfSILL = 0,diff;
	sillNode *traversalNode = ptr;
	while(traversalNode != null){
		lengthOfSILL++;
		traversalNode = traversalNode->next;
	}
	if(nthValue > lengthOfSILL){
		throw "Value is greater than length of single linked list";
	}
	diff = lengthOfSILL - nthValue;
	traversalNode = ptr;
	while(diff--){
		traversalNode = traversalNode->next;
	}
	return traversalNode;
}

//Tested
sillNode *nthNodeFromEndHashmap(sillNode *ptr,unsigned int nthValue){
	if(ptr == null){
		return null;
	}
	sillutils *utils = new sillutils();
	hash_map<unsigned int,sillNode *> nodeIndexMap = utils->getHashmapOfSILL(ptr)->indexNodeMap;
	if(nodeIndexMap.size() < nthValue){
		throw "Value is greater than length of single linked list";
	}
	unsigned int requiredNodePosition = nodeIndexMap.size() - nthValue;
	return nodeIndexMap.find(requiredNodePosition)->second;
}


/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
unsigned int lengthOfLinkedList(sillNode *ptr){
	return ptr == null?0:1+lengthOfLinkedList(ptr->next);
}

//Tested
sillNode *nthNodeFromEndON2(sillNode *ptr,unsigned int nthValue){
	if(ptr == null){
		return null;
	}
	sillNode *traversalNode = ptr;
	unsigned int lengthOfSill;
	while(traversalNode != null){
		lengthOfSill = lengthOfLinkedList(traversalNode->next);
		if(lengthOfSill == nthValue - 1){
			return traversalNode;
		}
		traversalNode = traversalNode->next;
	}
	return null;
}

#endif /* NTHNODEFROMEND_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
