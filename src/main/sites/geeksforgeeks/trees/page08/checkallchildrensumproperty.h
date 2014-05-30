/****************************************************************************************************************************************************
 *  File Name   		: checkallchildrensumproperty.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page08\checkallchildrensumproperty.h
 *  Created on			: Apr 29, 2014 :: 8:42:31 AM
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

#ifndef CHECKALLCHILDRENSUMPROPERTY_H_
#define CHECKALLCHILDRENSUMPROPERTY_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

int checkAllChildrenSumPropertyMain(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	if(ptr->left == null && ptr->right == null){
		return ptr->value;
	}
	int leftSubTreeSum = checkAllChildrenSumPropertyMain(ptr->left);
	if(leftSubTreeSum == INT_MAX){
		return INT_MAX;
	}
	int rightSubTreeSum = checkAllChildrenSumPropertyMain(ptr->right);
	if(rightSubTreeSum == INT_MAX){
		return INT_MAX;
	}
	return ptr->value == leftSubTreeSum + rightSubTreeSum?2*ptr->value:INT_MAX;
}


bool checkAllChildrenSumProperty(itNode *ptr){
	if(ptr == null){
		return true;
	}
	return checkAllChildrenSumPropertyMain(ptr) == INT_MAX?false:true;
}

bool isNodeLeafNode(itNode *ptr){
	if(ptr == null){
		return false;
	}
	if(ptr->left == null && ptr->right == null){
		return true;
	}
	return false;
}

bool checkAllChildrenSumPropertyPostOrderIterativeTwoStacks(itNode *ptr){
	if(ptr == null){
		return true;
	}
	stack<itNode *> primaryAuxspace,secondaryAuxspace;
	primaryAuxspace.push(ptr);
	itNode *currentTopNode;
	int subTreesSum;
	while(!primaryAuxspace.empty()){
		currentTopNode = primaryAuxspace.top();
		primaryAuxspace.pop();
		secondaryAuxspace.push(currentTopNode);
		if(currentTopNode->left != null){
			primaryAuxspace.push(currentTopNode->left);
		}
		if(currentTopNode->right != null){
			primaryAuxspace.push(currentTopNode->right);
		}
	}
	while(!secondaryAuxspace.empty()){
		currentTopNode = secondaryAuxspace.top();
		if(currentTopNode->left != null || currentTopNode->right != null){
			subTreesSum = 0;
			if(currentTopNode->left != null){
				if(isNodeLeafNode(currentTopNode->left)){
					subTreesSum += currentTopNode->left->value;
				}else{
					subTreesSum += 2 * currentTopNode->left->value;
				}
			}
			if(currentTopNode->right != null){
				if(isNodeLeafNode(currentTopNode->right)){
					subTreesSum += currentTopNode->right->value;
				}else{
					subTreesSum += 2 * currentTopNode->right->value;
				}
			}
			if(subTreesSum != currentTopNode->value){
				return false;
			}
		}
	}
	return true;
}

bool checkAllChildrenSumPropertyPostOrderIterative(itNode *ptr){
	if(ptr == null){
		return false;
	}
	stack<itNode *> auxSpace;
	itNode *currentNode = ptr;
	int childrenSum = 0;
	while(!auxSpace.empty() || currentNode != null){
		if(currentNode != null){
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(!auxSpace.empty() && currentNode->right == auxSpace.top()){
				auxSpace.pop();
				auxSpace.push(currentNode);
				currentNode = currentNode->right;
			}else{
				if(currentNode->left != null || currentNode->right != null){
					childrenSum = 0;
					if(currentNode->left != null){
						if(isNodeLeafNode(currentNode->left)){
							childrenSum += currentNode->left->value;
						}else{
							childrenSum += 2 *currentNode->left->value;
						}
					}
					if(currentNode->right != null){
						if(isNodeLeafNode(currentNode->right)){
							childrenSum += currentNode->right->value;
						}else{
							childrenSum += 2 * currentNode->right->value;
						}
					}
					if(childrenSum != currentNode->value){
						return false;
					}
				}
				currentNode = null;
			}
		}
	}
	return true;
}

bool checkAllChildrenSumPropertyNode(itNode *ptr){
	if(ptr == null){
		return true;
	}
	if(ptr->left == null && ptr->right == null){
		return true;
	}
	int childrenSum = 0;
	if(ptr->left != null){
		childrenSum += 2 *ptr->left->value;
	}
	if(ptr->right != null){
		childrenSum += 2*ptr->right->value;
	}
	return childrenSum == ptr->value;
}

bool checkAllChildrenSumPropertyPostOrderIterativeV2(itNode *ptr){
	if(ptr == null){
		return true;
	}
	stack<itNode *> auxSpace;
	itNode *traversingNode = ptr;
	while(!auxSpace.empty() || traversingNode != null){
		while(traversingNode != null){
			auxSpace.push(traversingNode);
			traversingNode = traversingNode->left;
		}
		if(!auxSpace.empty() && auxSpace.top()->right == null){
			traversingNode = auxSpace.top();
			auxSpace.pop();
			checkAllChildrenSumPropertyNode(traversingNode);
			while(!auxSpace.empty() && auxSpace.top()->right == traversingNode){
				traversingNode = auxSpace.top();
				checkAllChildrenSumPropertyNode(traversingNode);
				auxSpace.pop();
			}
		}
		traversingNode = auxSpace.empty()?null:auxSpace.top()->right;
	}
	return true;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

int getSumOfNodes(itNode *ptr){
	if(ptr == null){
		return 0;
	}
	return ptr->value + getSumOfNodes(ptr->left) + getSumOfNodes(ptr->right);
}

bool checkAllChildrenSumPropertyPreOrderON2(itNode *ptr){
	if(ptr == null){
		return false;
	}
	return ptr->value == getSumOfNodes(ptr->left) + getSumOfNodes(ptr->right) && checkAllChildrenSumPropertyPreOrderON2(ptr->left) && checkAllChildrenSumPropertyPreOrderON2(ptr->right);
}

bool checkAllChildrenSumPropertyPostOrderON2(itNode *ptr){
	if(ptr == null){
		return false;
	}
	return checkAllChildrenSumPropertyPostOrderON2(ptr->left) && checkAllChildrenSumPropertyPostOrderON2(ptr->right) && ptr->value == getSumOfNodes(ptr->left) + getSumOfNodes(ptr->right);
}

#endif /* CHECKALLCHILDRENSUMPROPERTY_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
