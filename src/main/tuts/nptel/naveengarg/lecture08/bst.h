/****************************************************************************************************************************************************
 *  File Name   		: bst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture08\bst.h
 *  Created on			: Jun 4, 2014 :: 1:16:32 AM
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

#ifndef BST_H_
#define BST_H_

//All keys greater than given node
//Search
class bst{
private:
	void getBSTreeFromVectorMain(itNode **root,itNode *currentNode,vector<int> userInput,unsigned int currentIndex){
		if(userInput.size() == 0 || currentIndex >= userInput.size()){
			return;
		}
		if(*root == null){
			*root = new itNode(userInput[currentIndex]);
			getBSTreeFromVectorMain(root,*root,userInput,currentIndex+1);
		}else{
			if(currentNode->value == userInput[currentIndex]){
				getBSTTreeFromVectorMain(root,*root,userInput,currentIndex+1);
			}else{
				if(currentNode->value > userInput[currentIndex]){
					if(currentNode->left == null){
						currentNode->left = new itNode(userInput[currentIndex]);
						getBSTreeFromVectorMain(root,*root,userInput,currentIndex+1);
					}else{
						getBSTreeFromVectorMain(root,currentNode->left,userInput,currentIndex);
					}
				}else{
					if(currentNode->right == null){
						currentNode->right = new itNode(userInput[currentIndex]);
						getBSTreeFromVectorMain(root,*root,userInput,currentIndex+1);
					}else{
						getBSTreeFromVectorMain(root,currentNode->right,userInput,currentIndex);
					}
				}
			}
		}
	}

	void getPBSTreeFromVectorMain(iptNode **root,iptNode *currentNode,vector<int> userInput,unsigned int currentIndex){
		if(userInput.size() == 0 || currentIndex >= userInput.size()){
			return;
		}
		if(*root == null){
			*root = new iptNode(userInput[currentIndex]);
			getPBSTreeFromVectorMain(root,*root,userInput,currentIndex+1);
		}else{
			if(currentNode->value == userInput[currentIndex]){
				getPBSTreeFromVectorMain(root,*root,userInput,currentIndex+1);
			}else{
				if(currentNode->value > userInput[currentIndex]){
					if(currentNode->left == null){
						currentNode->left = new iptNode(userInput[currentIndex]);
						currentNode->left->parent = currentNode;
						getPBSTreeFromVectorMain(root,*root,userInput,currentIndex+1);
					}else{
						getPBSTreeFromVectorMain(root,currentNode->left,userInput,currentIndex);
					}
				}else{
					if(currentNode->right == null){
						currentNode->right = new iptNode(userInput[currentIndex]);
						currentNode->right->parent = currentNode;
						getPBSTreeFromVectorMain(root,*root,userInput,currentIndex+1);
					}else{
						getPBSTreeFromVectorMain(root,currentNode->right,userInput,currentIndex);
					}
				}
			}
		}
	}

	void getFBSTreeFromVectorMain(iftNode **root,iftNode *currentNode,vector<int> userInput,unsigned int currentIndex){
		if(userInput.size() == 0||currentIndex >= userInput.size()){
			return;
		}
		if(*root == null){
			*root = new iftNode(userInput[currentIndex]);
			getFBSTreeFromVectorMain(root,*root,userInput,currentIndex+1);
		}else{
			if(currentNode->value == userInput[currentIndex]){
				currentNode->frequency += 1;
				getFBSTreeFromVectorMain(root,*root,userInput,currentIndex+1);
			}else{
				if(currentNode->value > userInput[currentIndex]){
					if(currentNode->left == null){
						currentNode->left = new iftNode(userInput[currentIndex]);
						getFBSTreeFromVectorMain(root,*root,userInput,currentIndex+1);
					}else{
						getFBSTreeFromVectorMain(root,currentNode->left,userInput,currentIndex);
					}
				}else{
					if(currentNode->right == null){
						currentNode->right = new iftNode(userInput[currentIndex]);
						getFBSTreeFromVectorMain(root,*root,userInput,currentIndex+1);
					}else{
						getFBSTreeFromVectorMain(root,currentNode->right,userInput,currentIndex);
					}
				}
			}
		}
	}

	void getFPBSTreeFromVectorMain(ifptNode **root,ifptNode *currentNode,vector<int> userInput,unsigned int currentIndex){
		if(userInput.size() == 0 || currentIndex >= userInput.size()){
			return;
		}
		if(*root == null){
			*root = new ifptNode(userInput[currentIndex]);
			getFPBSTreeFromVectorMain(root,*root,userInput,currentIndex+1);
		}else{
			if(currentNode->value == userInput[currentIndex]){
				currentNode->frequency += 1;
				getFPBSTreeFromVectorMain(root,*root,userInput,currentIndex+1);
			}else{
				if(currentNode->value > userInput[currentIndex]){
					if(currentNode->left == null){
						currentNode->left = new ifptNode(userInput[currentIndex]);
						currentNode->left->parent = currentNode;
						getFBSTreeFromVectorMain(root,*root,userInput,currentIndex+1);
					}else{
						getFBSTreeFromVectorMain(root,currentNode->left,userInput,currentIndex);
					}
				}else{
					if(currentNode->right == null){
						currentNode->right = new ifptNode(userInput[currentIndex]);
						currentNode->right->parent = currentNode;
						getFBSTreeFromVectorMain(root,*root,userInput,currentIndex+1);
					}else{
						getFBSTreeFromVectorMain(root,currentNode->right,currentIndex);
					}
				}
			}
		}
	}
public:
	itNode *getBSTreeIterative(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		itNode *root = new itNode(userInput[0]);
		itNode *traversalNode;
		for(unsigned int counter = 1;counter < userInput.size();counter++){
			traversalNode = root;
			while(true){
				if(traversalNode->value == userInput[counter]){
					break;
				}else{
					if(traversalNode->value > userInput[counter]){
						if(traversalNode->left == null){
							traversalNode->left = new itNode(userInput[counter]);
							break;
						}else{
							traversalNode = traversalNode->left;
						}
					}else{
						if(traversalNode->right == null){
							traversalNode->right = new itNode(userInput[counter]);
							break;
						}else{
							traversalNode= traversalNode->right;
						}
					}
				}
			}
		}
		return root;
	}

	iptNode *getPBSTreeIterative(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		iptNode *root = userInput[0];
		iptNode *traversingNode;
		for(unsigned int counter = 1;counter < userInput.size();counter++){
			traversingNode = root;
			while(true){
				if(traversingNode->value == userInput[counter]){
					break;
				}else{
					if(traversingNode->value > userInput[counter]){
						if(traversingNode->left == null){
							traversingNode->left = new iptNode(userInput[counter]);
							traversingNode->left->parent = traversingNode;
							break;
						}else{
							traversingNode = traversingNode->left;
						}
					}else{
						if(traversingNode->right == null){
							traversingNode->right = new iptNode(userInput[counter]);
							traversingNode->right->parent = traversingNode;
							break;
						}else{
							traversingNode = traversingNode->right;
						}
					}
				}
			}
		}
		return root;
	}

	iftNode *getFBSTreeIterative(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		iftNode *root = new iftNode(userInput[0]);
		iftNode *traversingNode;
		for(unsigned int counter = 1;counter < userInput.size();counter++){
			traversingNode = root;
			while(true){
				if(traversingNode->value == userInput[counter]){
					traversingNode->frequency += 1;
					break;
				}else{
					if(traversingNode->value > userInput[counter]){
						if(traversingNode->left == null){
							traversingNode->left = new iftNode(userInput[counter]);
							break;
						}else{
							traversingNode = traversingNode->left;
						}
					}else{
						if(traversingNode->right == null){
							traversingNode->right = new iftNode(userInput[counter]);
							break;
						}else{
							traversingNode = traversingNode->right;
						}
					}
				}
			}
		}
		return root;
	}

	ifptNode *getPFBSTreeIterative(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		ifptNode *root = new ifptNode(userInput[0]);
		ifptNode *traversingNode;
		for(unsigned int counter = 1;counter < userInput.size();counter++){
			traversingNode = root;
			while(true){
				if(traversingNode->value == userInput[counter]){
					traversingNode->frequency += 1;
					break;
				}else{
					if(traversingNode->value > userInput[counter]){
						if(traversingNode->left == null){
							traversingNode->left = new ifptNode(userInput[counter]);
							traversingNode->left->parent = traversingNode;
							break;
						}else{
							traversingNode = traversingNode->left;
						}
					}else{
						if(traversingNode->right == null){
							traversingNode->right = new ifptNode(userInput[counter]);
							traversingNode->right->parent = traversingNode;
							break;
						}else{
							traversingNode = traversingNode->right;
						}
					}
				}
			}
		}
		return root;
	}
};

#endif /* BST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
