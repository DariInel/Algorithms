#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node
{
	int size;
	int val;
	int prior;
	Node *l;
	Node *r;
};

Node *tree = nullptr;

int get_size(Node* vertex) {
	if (vertex == nullptr) {
		return 0;
	}
	return vertex -> size;
}

void update_size(Node* & vertex) {
	if (vertex == nullptr) {
		return;
	}
	vertex -> size = get_size(vertex -> l) + get_size(vertex -> r) + 1;
}

pair<Node*, Node*> split(Node* root, int k) {
	if (root == nullptr) {
		return{ nullptr, nullptr };
	}
	int l = get_size(root->l);
	if (l >= k) {
		pair<Node*, Node*> part = split(root -> l, k);
		root -> l = part.second;
		update_size(root);
		return {part.first, root};
	}
	pair<Node*, Node*> part = split(root -> r, k - l - 1);
	root -> r = part.first;
	update_size(root);
	return{root, part.second};
}

Node* merge( Node* l, Node* r) {
	
	if (r == nullptr) {
		return l;
	}
	if (l == nullptr) {
		return r;
	}	
	if (l -> prior > r -> prior) {
		l -> r = merge(l -> r, r);
		update_size(l -> r);
		return l;
	}
	else {
		r -> l = merge(l, r -> l);
		update_size(r -> l);
		return r;
	}
}

void add(int x) {
	Node* tree_element = new Node();
	tree_element -> size = 1;
	tree_element -> val = x;
	tree_element -> prior = rand();
	tree = merge(tree, tree_element);
}

void swapi(int l, int r) {
	pair<Node*, Node*> part1 = split(tree, l);
	pair<Node*, Node*> part2 = split(part1.second, r - l + 1);
	tree = merge(part2.first, part1.first);
	tree = merge(tree, part2.second);
}

void write(Node* root) {
	if (root == nullptr)
		return;
	write(root -> l);
	cout << root -> val << " ";
	write(root -> r);
}

int main() {
	
	int n;
	int request;
	cin >> n >> request;
	for (int i = 1; i <= n; i++) {
		add(i);
	}
	int left = 0;
	int right = 0;
	for (int i = 0; i < request; i++) {
		cin >> left >> right;
		right--;
		left--;
		swapi(left, right);
	}
	write(tree);
	return 0;
}


