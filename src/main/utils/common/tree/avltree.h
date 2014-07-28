/****************************************************************************************************************************************************
 *  File Name   		: avltree.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\utils\common\tree\avltree.h
 *  Created on			: Jun 9, 2014 :: 9:07:20 PM
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

#ifndef AVLTREE_H_
#define AVLTREE_H_

class avltreeutils {
	iavltNode *root;

	//Tested
	iavltNode *searchMain(int userInput, iavltNode *currentNode) {
		if (currentNode == null) {
			return null;
		}
		if (currentNode->value == userInput) {
			return currentNode;
		}
		if (currentNode->value > userInput) {
			return searchMain(userInput, currentNode->left);
		} else {
			return searchMain(userInput, currentNode->right);
		}
	}

	//Tested
	iavltNode *insertAtRightPlace(int userInput, iavltNode *currentNode) {
		if (this->root == null) {
			this->root = new iavltNode(userInput);
			return this->root;
		} else {
			if (currentNode->value == userInput) {
				return null;
			}
			if (currentNode->value > userInput) {
				if (currentNode->left == null) {
					currentNode->left = new iavltNode(userInput);
					currentNode->left->parent = currentNode;
					return currentNode->left;
				} else {
					return insertAtRightPlace(userInput, currentNode->left);
				}
			} else {
				if (currentNode->right == null) {
					currentNode->right = new iavltNode(userInput);
					currentNode->right->parent = currentNode;
					return currentNode->right;
				} else {
					return insertAtRightPlace(userInput, currentNode->right);
				}
			}
		}
	}

	//Tested
	void rotateNodes(iavltNode *parent, iavltNode *child) {
		iavltNode *grandParent = parent->parent;
		if (grandParent != null) {
			child->parent = grandParent;
			if (grandParent->left == parent) {
				grandParent->left = child;
			} else {
				grandParent->right = child;
			}
		} else {
			this->root = child;
			child->parent = null;
		}
		parent->parent = child;
		iavltNode *temp;
		if (parent->left == child) {
			temp = child->right;
			child->right = parent;
			parent->left = temp;
		} else {
			temp = child->left;
			child->left = parent;
			parent->right = temp;
		}
		if(temp != null){
			temp->parent = parent;
		}
	}

	//Tested
	void inorderMain(iavltNode *currentNode) {
		if (currentNode == null) {
			return;
		}
		inorderMain(currentNode->left);
		printf("v = %d h = %d p = %d\n", currentNode->value, currentNode->height,currentNode->parent == null?0:currentNode->parent->value);
		inorderMain(currentNode->right);
	}

	//Tested
	iavltNode *deleteLeafOrOneChildNode(iavltNode *ptr){
		if(ptr == null){
			return null;
		}
		iavltNode *parent = ptr->parent;
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
		if(ptr->left == null || ptr->right == null){
			if(ptr->left != null){
				if(parent == null){
					this->root = ptr->left;
					free(ptr);
					return null;
				}
			}else{
				if(parent == null){
					this->root = ptr->right;
					free(ptr);
					return null;
				}
			}
			if(parent->left == ptr){
				if(ptr->left != null){
					parent->left = ptr->left;
					ptr->left->parent = parent;
				}else{
					parent->left = ptr->right;
					ptr->right->parent = parent;
				}
			}else{
				if(ptr->left != null){
					parent->right = ptr->left;
					ptr->left->parent = parent;
				}else{
					parent->right = ptr->right;
					ptr->right->parent = parent;
				}
			}
			free(ptr);
			return parent;
		}
		return null;
	}

public:

	avltreeutils(){
		this->root = null;
	}

	//Tested
	void insert(int userInput) {
		iavltNode *ptrToInsertedNode = insertAtRightPlace(userInput,this->root);
		if(ptrToInsertedNode == null){
			return;
		}
		iavltNode *z, *y, *x;
		z = ptrToInsertedNode->parent;
		int leftHeight, rightHeight;
		while (z != null) {
			leftHeight = z->left == null ? 0 : z->left->height;
			rightHeight = z->right == null ? 0 : z->right->height;
			if (abs(leftHeight - rightHeight) > 1) {
				y = z->value > userInput ? z->left : z->right;
				x = y->value > userInput ? y->left : y->right;
				if ((z->left == y && y->left == x) || (z->right == y && y->right == x)) {
					if (z->parent == null) {
						this->root = y;
					}
					rotateNodes(z, y);
					z->height = max(z->left==null?0:z->left->height,z->right==null?0:z->right->height)+1;
					y->height = max(y->left==null?0:y->left->height,y->right==null?0:y->right->height)+1;
				} else {
					if (z->parent == null) {
						this->root = x;
					}
					rotateNodes(y, x);
					rotateNodes(z, x);
					y->height = max(y->left==null?0:y->left->height,y->right==null?0:y->right->height)+1;
					z->height = max(z->left==null?0:z->left->height,z->right==null?0:z->right->height)+1;
					x->height = max(x->left==null?0:x->left->height,x->right==null?0:x->right->height)+1;
				}
				return;
			}
			z->height = max(leftHeight,rightHeight)+1;
			z = z->parent;
		}
	}

	//Tested
	void createAvlTreeFromVector(vector<int> userInput) {
		if (userInput.size() == 0) {
			return;
		}
		for (unsigned int counter = 0; counter < userInput.size(); counter++) {
			insert(userInput[counter]);
		}
	}

	//Tested
	void deleteValueFromAvlTree(int value){
		if(this->root == null){
			return;
		}
		iavltNode *ptrToNodeDeleted = search(value);
		if(ptrToNodeDeleted == null){
			return;
		}
		iavltNode *z,*y,*x;
		if(ptrToNodeDeleted->left == null || ptrToNodeDeleted->right == null){
			z = deleteLeafOrOneChildNode(ptrToNodeDeleted);
		}else{
			iavltNode *predecessor = ptrToNodeDeleted->left;
			while(predecessor->right != null){
				predecessor = predecessor->right;
			}
			ptrToNodeDeleted->value = predecessor->value;
			ptrToNodeDeleted = predecessor;
			z = deleteLeafOrOneChildNode(ptrToNodeDeleted);
		}
		int leftHeight,rightHeight;
		while(z != null){
			leftHeight = z->left == null?0:z->left->height;
			rightHeight = z->right == null?0:z->right->height;
			if(abs(leftHeight-rightHeight) > 1){
				y = leftHeight >= rightHeight?z->left:z->right;
				x = (y->left == null?0:y->left->height) >= (y->right==null?0:y->right->height)?y->left:y->right;
				if((z->left == y && y->left == x)||(z->right == y && y->right == x)){
					rotateNodes(z,y);
					z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height) + 1;
					y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height) + 1;
					z = y->parent;
				}else{
					rotateNodes(y,x);
					rotateNodes(z,x);
					y->height = max(y->left == null?0:y->left->height,y->right == null?0:y->right->height) + 1;
					z->height = max(z->left == null?0:z->left->height,z->right == null?0:z->right->height) + 1;
					x->height = max(x->left == null?0:x->left->height,x->right == null?0:x->right->height) + 1;
					z = x->parent;
				}
			}else{
				z->height = max(leftHeight,rightHeight)+1;
				z = z->parent;
			}
		}
	}

	//Tested
	iavltNode *search(int userInput){
		return searchMain(userInput,this->root);
	}

	//Tested
	void inorder(){
		inorderMain(this->root);
	}
};

#endif /* AVLTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
