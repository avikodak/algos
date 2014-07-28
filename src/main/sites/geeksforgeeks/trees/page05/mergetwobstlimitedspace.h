/****************************************************************************************************************************************************
 *  File Name   		: mergetwobstlimitedspace.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page05\mergetwobstlimitedspace.h
 *  Created on			: May 25, 2014 :: 12:26:54 PM
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

#ifndef MERGETWOBSTLIMITEDSPACE_H_
#define MERGETWOBSTLIMITEDSPACE_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void printSortedOrderOfTwoBST(itNode *firstBST,itNode *secondBST){
	if(firstBST == null && secondBST == null){
		return;
	}
	if(firstBST == null || secondBST == null){
		treeutils *utils = new treeutils();
		if(firstBST == null){
			utils->inOrderTraversal(secondBST);
		}else{
			utils->inOrderTraversal(firstBST);
		}
		return;
	}
	stack<itNode *> auxSpaceFirstTree,auxSpaceSecondTree;
	itNode *currentNodeFirstTree = firstBST,*currentNodeSecondTree = secondBST;
	while(!auxSpaceFirstTree.empty() || !auxSpaceSecondTree.empty() || currentNodeFirstTree != null || currentNodeSecondTree != null){
		if(currentNodeFirstTree != null || currentNodeSecondTree != null){
			if(currentNodeFirstTree != null){
				auxSpaceFirstTree.push(currentNodeFirstTree);
				currentNodeFirstTree = currentNodeFirstTree->left;
			}
			if(currentNodeSecondTree !=  null){
				auxSpaceSecondTree.push(currentNodeSecondTree);
				currentNodeSecondTree = currentNodeSecondTree->left;
			}
		}else{
			if(auxSpaceFirstTree.empty()){
				while(!auxSpaceSecondTree.empty()){
					printf("%d\t",auxSpaceSecondTree.top()->value);
					auxSpaceSecondTree.pop();
				}
			}
			if(auxSpaceSecondTree.empty()){
				while(!auxSpaceFirstTree.empty()){
					printf("%d\t",auxSpaceFirstTree.top()->value);
					auxSpaceFirstTree.pop();
				}
			}
			if(auxSpaceFirstTree.top() < auxSpaceSecondTree.top()){
				currentNodeFirstTree = auxSpaceFirstTree.top();
				auxSpaceFirstTree.pop();
				currentNodeFirstTree = currentNodeFirstTree->right;
				currentNodeSecondTree = null;
			}else{
				currentNodeSecondTree = auxSpaceSecondTree.top();
				auxSpaceSecondTree.pop();
				currentNodeSecondTree = currentNodeSecondTree->right;
				currentNodeFirstTree = null;
			}
		}
	}
}
#endif /* MERGETWOBSTLIMITEDSPACE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
