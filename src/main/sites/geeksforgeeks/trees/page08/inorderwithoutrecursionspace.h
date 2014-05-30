/****************************************************************************************************************************************************
 *  File Name   		: inorderwithoutrecursionspace.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page08\inorderwithoutrecursionspace.h
 *  Created on			: Apr 28, 2014 :: 2:38:49 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
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

#ifndef INORDERWITHOUTRECURSIONSPACE_H_
#define INORDERWITHOUTRECURSIONSPACE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
//Tested
void morrisInOrderON(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *traversalNode = ptr,*temp;
	while(traversalNode != null){
		if(traversalNode->left != null){
			temp = traversalNode->left;
			while(temp->right != null && temp->right != traversalNode){
				temp = temp->right;
			}
			if(temp->right == null){
				temp->right = traversalNode;
				traversalNode = traversalNode->left;
			}else{
				temp->right = null;
				printf("%d\t",traversalNode->value);
				traversalNode = traversalNode->right;
			}
		}else{
			printf("%d\t",traversalNode->value);
			traversalNode = traversalNode->right;
		}
	}
}

#endif /* INORDERWITHOUTRECURSIONSPACE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
