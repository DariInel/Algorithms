#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

struct Node
{
	int key;
	int prior;
	int size;
	Node *l;
	Node *r;
};

Node * v = nullptr;

int siz(Node *v)
{
	if (v != nullptr)
		return v->size;
	return 0;
}

void update_size(Node *v)
{
	if (v == nullptr)
		return;
	v->size = siz(v->l) + siz(v->r) + 1;
}

pair < Node*, Node* > split(Node * root, int key)
{
	if (root == nullptr)
		return{ nullptr, nullptr };
	else {
		if (root->key <= key)
		{
			pair < Node*, Node*>  tmp = split(root->r, key);
			root->r = tmp.first;
			update_size(tmp.second);
			update_size(root);
			return{ root, tmp.second };
		}
		else
		{
			pair < Node*, Node* > tmp = split(root->l, key);
			root->l = tmp.second;
			update_size(tmp.first);
			update_size(root);
			return{ tmp.first, root };
		}
	}
}
Node * merge(Node * l, Node * r)
{
	if (l == nullptr)
		return r;
	if (r == nullptr)
		return l;
	if (l->prior > r->prior)
	{
		l->r = merge(l->r, r);
		update_size(l);
		return l;
	}
	else
	{
		r->l = merge(l, r->l);
		update_size(r);
		return r;
	}
}

int Find_Maxi(Node * root, int x)
{
	if (root == nullptr)
	{
		return 0;
	}

	if (root->l != nullptr && root->l->size >= x)
		return Find_Maxi(root->l, x);
	if (root->l != nullptr)
	{
		x -= root->l->size;
	}
	if (x == 1)
		return root->key;
	return Find_Maxi(root->r, x - 1);
}

Node * Insert_element(Node * root, int key)
{	
	Node * k = new Node{ key, rand(), 1, nullptr, nullptr };
	pair < Node*, Node* > tmp = split(root, key);
	root = merge(merge(tmp.first, k), tmp.second);
	return root;
}
Node * Erase_element(Node * t, int key)
{
	pair<Node *, Node *> root = split(t, key);
	pair<Node *, Node *> root2 = split(root.first, key - 1);
	t = merge(root2.first, root.second);
	return t;
}

int main()
{
	int cnt_question;
	int number;
	int keys;
	int cnt_present = 0;
	cin >> cnt_question;
	for(int i = 0; i < cnt_question; i++) {
		cin >> keys >> number;
		if(keys == -1) {
			cnt_present --;	
			v = Erase_element(v, number);			
		}
		else {
			if (keys == -1) {
			cnt_present ++;
			v = Insert_element(v, number);		
			}
			else {
				cout << Find_Maxi(v, cnt_present - number + 1) << endl;
			}
		}
	}
	return 0;
}
void up_v(Node * &v) {
	if (v == nullptr)
		return;
	v->f = true;
}

void push(Node * &root) {
	if (root == nullptr || !root -> f )
		return;
	root->f = false;
	swap(root->l, root->r);
	up_v(root->l);
	up_v(root->r);

}
