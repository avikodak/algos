/****************************************************************************************************************************************************
 *  File Name   		: populateinordersuccessor.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page06\populateinordersuccessor.h
 *  Created on			: May 9, 2014 :: 11:23:58 PM
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

#ifndef POPULATEINORDERSUCCESSOR_H_
#define POPULATEINORDERSUCCESSOR_H_


/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

void populateInOrderSuccessor(itNextInorderNode *ptr){
	if(ptr == null){
		return;
	}
	static itNextInorderNode *prevNode = null;
	populateInOrderSuccessor(ptr->left);
	if(prevNode != null){
		prevNode->nextInorder = ptr;
	}
	prevNode = ptr;
	populateInOrderSuccessor(ptr->right);
}

void populateInorderSuccessorReverseInorder(itNextInorderNode *ptr){
	if(ptr == null){
		return;
	}
	static itNextInorderNode *prevNode = null;
	populateInorderSuccessorReverseInorder(ptr->right);
	ptr->nextInorder = prevNode;
	prevNode = ptr;
	populateInorderSuccessorReverseInorder(ptr->left);
}

void populateInOrderSuccessorIterative(itNextInorderNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNextInorderNode *> auxSpace;
	itNextInorderNode *currentNode = ptr;
	itNextInorderNode *prevNode = null;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(prevNode != null){
				prevNode->nextInorder = currentNode;
			}
			prevNode = currentNode;
			currentNode = currentNode->right;
		}
	}
}

void populateInOrderSuccessorReverseInOrderIterative(itNextInorderNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNextInorderNode *> auxSpace;
	itNextInorderNode *currentNode = ptr;
	itNextInorderNode *prevNode = null;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			auxSpace.push(currentNode);
			currentNode = currentNode->right;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			currentNode->nextInorder = prevNode;
			prevNode = currentNode;
			currentNode = currentNode->left;
		}
	}
}

void populateInOrderSuccessorMorrisInOrder(itNextInorderNode *ptr){
	if(ptr == null){
		return;
	}
	itNextInorderNode *currentNode = ptr,*temp,*prevNode = null;
	while(currentNode != null){
		if(currentNode->left != null){
			temp = currentNode->left;
			while(temp->right != null && temp->right != currentNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = currentNode;
				currentNode = currentNode->left;
			}else{
				temp->right = null;
				if(prevNode != null){
					prevNode->nextInorder = currentNode;
				}
				prevNode = currentNode;
				currentNode = currentNode->right;
			}
		}else{
			if(prevNode != null){
				prevNode->nextInorder = currentNode;
			}
			prevNode = currentNode;
			currentNode = currentNode->right;
		}
	}
}
#endif /* POPULATEINORDERSUCCESSOR_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
