/****************************************************************************************************************************************************
 *  File Name   		: preorder.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture07\preorder.h
 *  Created on			: Jun 3, 2014 :: 9:07:02 PM
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

#ifndef PREORDER_H_
#define PREORDER_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void preOrderTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	printf("%d\t",ptr->value);
	preOrderTraversal(ptr->left);
	preOrderTraversal(ptr->right);
}

void preOrderTraversalIterative(itNode *ptr){
	if(ptr == null){
		return;
	}
	stack<itNode *> auxspace;
	itNode *currentTopNode;
	auxspace.push(ptr);
	while(!auxspace.empty()){
		currentTopNode = auxspace.top();
		auxspace.pop();
		printf("%d\t",currentTopNode->value);
		if(currentTopNode->right != null){
			auxspace.push(currentTopNode->right);
		}
		if(currentTopNode->left != null){
			auxspace.push(currentTopNode->left);
		}
	}
}

void preOrderMorrisTraversal(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *traversingNode = ptr,*temp;
	while(traversingNode != null){
		if(traversingNode->left != null){
			temp = traversingNode->left;
			while(temp->right != null && temp->right != traversingNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = traversingNode;
				printf("%d\t",traversingNode->value);
				traversingNode = traversingNode->left;
			}else{
				temp->right = null;
				traversingNode = traversingNode->right;
			}
		}else{
			printf("%d\t",traversingNode->value);
			traversingNode = traversingNode->value;
		}
	}
}

#endif /* PREORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
