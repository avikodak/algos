/****************************************************************************************************************************************************
 *  File Name   		: favltree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\utils\common\tree\favltree.h
 *  Created on			: Jun 10, 2014 :: 2:07:46 PM
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

#ifndef FAVLTREE_H_
#define FAVLTREE_H_

struct ifavltNode{
	int value;
	unsigned int height;
	unsigned int frequency;
	ifavltNode *left;
	ifavltNode *parent;
	ifavltNode *right;

	ifavltNode(){

	}

	ifavltNode(int value){
		this->value = value;
		height = 1;
		frequency = 1;
		left = null;
		right = null;
		parent = null;
	}
};

class favlutils{
private:
	ifavltNode *root;

	ifavltNode *insertNodeAtRightPlace(ifavltNode *currentNode,int value){
		if(this->root == null){
			this->root = new ifavltNode(value);
			return null;
		}else{
			if(currentNode->value == value){
				currentNode->frequency += 1;
				return null;
			}
			if(currentNode->value > value){
				if(currentNode->left == null){
					currentNode->left = new ifavltNode(value);
					currentNode->left->parent = currentNode;
					return currentNode->left;
				}else{
					return insertNodeAtRightPlace(currentNode->left,value);
				}
			}else{
				if(currentNode->right == null){
					currentNode->right = new ifavltNode(value);
					currentNode->right->parent = currentNode;
					return currentNode->right;
				}else{
					return insertNodeAtRightPlace(currentNode->right,value);
				}
			}
		}
	}

	void rotateNodes(ifavltNode *parent,ifavltNode *child){
		ifavltNode *grandParent = parent->parent;
		if(grandParent != null){
			child->parent = grandParent;
			if(grandParent->left == parent){
				grandParent->left = child;
			}else{
				grandParent->right = child;
			}
		}else{
			this->root = child;
			child->parent  = null;
		}
		parent->parent = child;
		ifavltNode *temp;
		if(parent->left == child){
			temp = child->right;
			parent->left = temp;
			child->right = parent;
			if(temp != null){
				temp->parent = parent;
			}
		}else{
			temp = child->left;
			parent->right = temp;
			child->left = parent;
			if(temp != null){
				temp->parent = parent;
			}
		}
	}

	void setHeightForNode(ifavltNode *ptr){
		if(ptr == null){
			return;
		}
		ptr->height = max(ptr->left == null?0:ptr->left->height,ptr->right == null?0:ptr->right->height)+1;
	}

	ifavltNode *searchMain(ifavltNode *currentNode,int value){
		if(currentNode == null){
			return null;
		}
		if(currentNode->value == value){
			return currentNode;
		}
		if(currentNode->value > value){
			return searchMain(currentNode->left,value);
		}else{
			return searchMain(currentNode->right,value);
		}
	}

	ifavltNode *deleteALeafNodeOrOneChild(ifavltNode *ptr){
		if(ptr == null){
			return null;
		}
		if(ptr->left != null && ptr->right != null){
			return null;
		}
		ifavltNode *parent = ptr->parent;
		if(ptr->left == null && ptr->right == null){
			if(parent == null){
				this->root = null;
				free(ptr);
				return null;
			}
			if(parent->left == ptr){
				parent->left = null;
			}else{
				parent->right = null;
			}
			free(ptr);
			return parent;
		}
		ifavltNode *temp;
		if(ptr->left != null){
			temp = ptr->left;
			if(parent->left == ptr){
				parent->left = temp;
			}else{
				parent->right = temp;
			}
			if(temp != null){
				temp->parent = parent;
			}
			free(ptr);
			return parent;
		}else{
			temp = ptr->right;
			if(parent->left == ptr){
				parent->left = temp;
			}else{
				parent->right = temp;
			}
			if(temp != null){
				temp->parent = parent;
			}
			free(ptr);
			return parent;
		}
	}

public:
	favlutils(){
		this->root = null;
	}

	void insertNodeIntoAvlTree(int value){
		ifavltNode *ptrToNodeInserted = insertNodeAtRightPlace(this->root,value);
		if(ptrToNodeInserted == null){
			return;
		}
		ifavltNode *z,*y,*x;
		z = ptrToNodeInserted->parent;
		int leftHeight,rightHeight;
		while(z != null){
			leftHeight = z->left == null?0:z->left->height;
			rightHeight = z->right == null?0:z->right->height;
			if(abs(leftHeight - rightHeight) > 1){
				y = z->value > value?z->left:z->right;
				x = y->value >value?y->left:y->right;
				if((z->left == y && y->left == x)||(z->right == y && y->right == x)){
					rotateNodes(z,y);
					setHeightForNode(z);
					setHeightForNode(y);
					return;
				}else{
					rotateNodes(y,x);
					rotateNodes(z,x);
					setHeightForNode(y);
					setHeightForNode(z);
					setHeightForNode(x);
					return;
				}
			}
			z->height = max(leftHeight,rightHeight)+1;
			z = z->parent;
		}
	}

	iftNode *search(int value){
		return searchMain(this->root,value);
	}

	void deleteValue(int value){
		if(this->root == null){
			return;
		}
		ifavltNode *nodeToBeDeleted = search(value);
		if(nodeToBeDeleted == null){
			return;
		}
		ifavltNode *z,*y,*x;
		if(nodeToBeDeleted->left == null && nodeToBeDeleted->right == null){
			z = deleteALeafNodeOrOneChild(nodeToBeDeleted);
		}else{
			nodeToBeDeleted = nodeToBeDeleted->left;
			while(nodeToBeDeleted->right != null){
				nodeToBeDeleted = nodeToBeDeleted->right;
			}
			z = deleteALeafNodeOrOneChild(nodeToBeDeleted);
		}
		int leftHeight,rightHeight;
		while(z != null){
			leftHeight = z->left == null?0:z->left->height;
			rightHeight = z->right == null?0:z->right->height;
			if(abs(leftHeight-rightHeight) > 1){
				y = (z->left == null?0:z->left->height) >= (z->right == null?0:z->right->height)?z->left:z->right;
				x = (y->left == null?0:y->left->height) >= (y->right == null?0:y->right->height)?y->left:y->right;
				if((z->left == y && y->left == x)||(z->right == y && y->right == x)){
					rotateNodes(z,y);
					setHeightForNode(z);
					setHeightForNode(y);
					z = y->parent;
				}else{
					rotateNodes(y,x);
					rotateNodes(z,x);
					setHeightForNode(y);
					setHeightForNode(z);
					setHeightForNode(x);
					z = x->parent;
				}
			}else{
				setHeightForNode(z);
				z = z->parent;
			}
		}
	}
};

#endif /* FAVLTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
