#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <boost/concept_check.hpp>
#include <string.h>
// #include <string>
#include <bits/basic_string.h>
#include <list>
#include <vector>

using namespace std;
static int node_id = 0;
template <class Type>
class BinTreeNode{
public:
	BinTreeNode<Type> *LChild, *RChild;
	Type data;
};

template <class Type>
class BinaryTree{
private:
	BinTreeNode<Type> *root;
public:
	BinaryTree<Type>(BinTreeNode<Type>* rt){
		root = rt;
	}

};
template <class Type>
void linkLeaf(BinTreeNode<Type>* rt,vector<BinTreeNode<Type>* >& List){
	//if current node is a leaf
	if((rt->LChild == NULL) && (rt->RChild == NULL) ){
		List.push_back(rt);

		return ;
	}
	cerr<<">>"<<rt->data<<" left "<<rt->LChild->data<<" "<<"right "<<rt->RChild->data<<endl;
	
	
	linkLeaf(rt->LChild, List);
	linkLeaf(rt->RChild, List);
}
template <class Type>
void createBinTree(BinTreeNode<Type>*& T ){
	Type x;
	if(sizeof(Type) == sizeof(char)) {
		scanf("%c", &x);
		if(x == '#')
			return;
	}
	if(sizeof(Type) == sizeof(int)){
		scanf("%d", &x);

		if(x < 0)
			return;
	}
	T = (BinTreeNode<Type>*)malloc(sizeof(BinTreeNode<Type>));
	T->data = x;
	cerr<<"node "<<node_id++<<endl;
	createBinTree<Type>(T->LChild);
	createBinTree<Type>(T->RChild);


}

template <class Type>
void deleteNode(BinTreeNode<Type>*& root ){
	if((root->LChild == NULL) && (root->RChild == NULL) ){
// 		delete root;
		free(root);
		root = NULL;
		return ;
	}
	deleteNode<Type>(root->LChild);
	deleteNode<Type>(root->RChild);

}

template <class Type>
void findNodes(vector<BinTreeNode<Type>* >& deletenodes , BinTreeNode<Type>*& root, Type value){
	if(root->data == value){
		deletenodes.push_back(root);
		deleteNode<Type>(root);
		return;
	}
	if((root->LChild == NULL) && (root->RChild == NULL) ){
		return ;
	}
	findNodes<Type>(deletenodes,root->LChild,value);
	findNodes<Type>(deletenodes,root->RChild,value);

}

int main(){
	BinTreeNode<int>* root;

	cerr<<"Create BinTree...\nPlease enter letters or integer numbers, end with '#' or a negative number..."<<endl;
	createBinTree<int>(root);
	BinaryTree<int > btree(root);
	cerr<<"Building tree done..."<<endl;

	cerr<<"Please enter the number of the node you want to delete..."<<endl;
	int del_num;
	scanf("%d", &del_num);
	cerr<<"delete node "<<del_num<<" and its children"<<endl;
	vector<BinTreeNode<int>* > deletenodes;
	findNodes<int>(deletenodes, root, del_num);
	cerr<<"delete "<<deletenodes.size()<<" trees"<<endl;
// 	for(int i = 0; i<deletenodes.size(); i++){
// 		deleteNode<int>(deletenodes[i]);
// 	}
// 	cerr<<root->data<<endl;
// 	vector<BinTreeNode<int>*> list;
// 	linkLeaf<int>(root, list);
// 	cerr<<"leaves size "<<list.size()<<endl;
	
}