#include<bits/stdc++.h>
using namespace std;

struct node {
	int val;
	node *left;
	node *right;
	node(int val) {
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

node* construct_binary_tree_level_order() {

	int x;
	cin >> x;
	if (x == -1) return NULL;

	node *root = new node(x);

	queue<node*> Q;
	Q.push(root);

	while (!Q.empty()) {

		node *cur = Q.front();
		Q.pop();

		int x, y;
		cin >> x >> y;

		if (x != -1) {
			node *temp = new node(x);
			cur->left = temp;
			Q.push(temp);
		}

		if (y != -1) {
			node *temp = new node(y);
			cur->right = temp;
			Q.push(temp);
		}

	}

	return root;
}


node *construct_binary_tree_pre_order() {

	int x;
	cin >> x;
	if (x == -1) return NULL;

	node *cur = new node(x);
	// left subtree
	cur->left = construct_binary_tree_pre_order();
	// right subtree
	cur->right = construct_binary_tree_pre_order();

	return cur;
}


int give_height(node* root) {
	if (root == NULL) return 0;
	int left_height = give_height(root->left);
	int right_height = give_height(root->right);
	return max(left_height , right_height) + 1;
}

int give_diameter(node* root) {
	if (root == NULL) return 0;

	int diameter_left = give_diameter(root->left);
	int diameter_right = give_diameter(root->right);
	int left_height = give_height(root->left);
	int right_height = give_height(root->right);

	return max({diameter_left, diameter_right, left_height + right_height});
}

// {diameter,height}
pair<int, int> give_diameter_height(node* root) {
	if (root == NULL) return {0, 0};

	pair<int, int> left = give_diameter_height(root->left);
	pair<int, int> right = give_diameter_height(root->right);

	int diameter_cur =  max({left.first, right.first, left.second + right.second});
	int cur_height = max(left.second, right.second) + 1;

	return {diameter_cur, cur_height};
}

// RLR
void preorder(node* root) {
	if (root == NULL) return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

// LRRight
void inorder(node* root) {
	if (root == NULL) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

// LRRoot
void postorder(node* root) {
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->val << " ";
}

bool is_identical(node *root1, node *root2) {

	// if (root1 == NULL && root2 == NULL) return true;
	// if (root1 == NULL && root2 != NULL) return false;
	// if (root1 != NULL && root2 == NULL) return false;

	if (root1 == NULL || root2 == NULL) return root1 == root2;

	// neither root1 is NULL and nor root2 is NULL
	bool left_identical = is_identical(root1->left, root2->left);
	bool right_identical = is_identical(root1->right, root2->right);

	return (left_identical && right_identical && root1->val == root2->val);

}

bool mirror(node *left_part, node *right_part) {
	if (left_part == NULL || right_part == NULL) return left_part == right_part;

	bool mirror1 = mirror(left_part->left, right_part->right);
	bool mirror2 = mirror(left_part->right, right_part->left);

	return mirror1 && mirror2 && (left_part->val == right_part->val);

}
bool isSymmetric(node* root) {
	if (root == NULL) return true;
	return mirror(root, root);
}

node* mergeTrees(node* t1, node* t2) {

	if (t1 == NULL) return t2;
	if (t2 == NULL) return t1;

	t1->left = mergeTrees(t1->left, t2->left);
	t1->right = mergeTrees(t1->right, t2->right);
	t1->val += t2->val;

	return t1;
}

void invert(node* root) {
	if (root == NULL) return;
	swap(root->left, root->right);
	invert(root->left);
	invert(root->right);
}

map<int, int> top_view(node* root) {

	map<int, int> mp;
	// node,column
	queue<pair<node*, int>> Q;
	Q.push({root, 0});

	while (!Q.empty()) {
		node* cur = Q.front().first;
		int col = Q.front().second;
		Q.pop();

		if (cur == NULL) continue;

		if (!mp.count(col)) mp[col] = cur->val;

		Q.push({cur->left, col - 1});
		Q.push({cur->right, col + 1});
	}

	return mp;
}

map<int, int> bottom_view(node* root) {

	map<int, int> mp;
	// node,column
	queue<pair<node*, int>> Q;
	Q.push({root, 0});

	while (!Q.empty()) {
		node* cur = Q.front().first;
		int col = Q.front().second;
		Q.pop();

		if (cur == NULL) continue;

		mp[col] = cur->val;

		Q.push({cur->left, col - 1});
		Q.push({cur->right, col + 1});
	}

	return mp;
}

map<int, int> left_view(node* root) {

	map<int, int> mp;
	// node,level
	queue<pair<node*, int>> Q;
	Q.push({root, 0});

	while (!Q.empty()) {
		node* cur = Q.front().first;
		int level = Q.front().second;
		Q.pop();

		if (cur == NULL) continue;

		if (!mp.count(level)) mp[level] = cur->val;

		Q.push({cur->left, level + 1});
		Q.push({cur->right, level + 1});
	}

	return mp;
}

map<int, int> right_view(node* root) {

	map<int, int> mp;
	// node,level
	queue<pair<node*, int>> Q;
	Q.push({root, 0});

	while (!Q.empty()) {
		node* cur = Q.front().first;
		int level = Q.front().second;
		Q.pop();

		if (cur == NULL) continue;

		mp[level] = cur->val;

		Q.push({cur->left, level + 1});
		Q.push({cur->right, level + 1});
	}

	return mp;
}

map<int, vector<int>> vertical_order(node* root) {

	map<int, vector<int>> mp;
	// node,column
	queue<pair<node*, int>> Q, Q1;
	Q.push({root, 0});

	while (!Q.empty()) {

		// on a level
		Q1 = Q;
		while (!Q.empty()) Q.pop();

		vector<pair<int, int>> v;
		while (!Q1.empty()) {
			node* cur = Q1.front().first;
			int col = Q1.front().second;
			Q1.pop();
			if (cur == NULL) continue;
			v.push_back({col, cur->val});
			Q.push({cur->left, col - 1});
			Q.push({cur->right, col + 1});
		}

		sort(v.begin(), v.end());
		for (auto x : v) {
			mp[x.first].push_back(x.second);
		}

	}
	return mp;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	// node* root = construct_binary_tree_level_order();
	node *root = construct_binary_tree_pre_order();
	// preorder(root);
	// int height = give_height(root);
	// cout << height;
	// int diameter = give_diameter(root);
	// cout << diameter;

	// pair<int, int> dh = give_diameter_height(root);
	// cout << dh.first << " " << dh.second;

	// top view
	// map<int, int> mp = top_view(root);
	// for (auto x : mp) {
	// 	cout << x.second << " ";
	// }

	// map<int, int> mp = bottom_view(root);
	// for (auto x : mp) {
	// 	cout << x.second << " ";
	// }

	map<int, vector<int>> mp = vertical_order(root);
	for (auto x : mp) {
		for (auto y : x.second) {
			cout << y << " ";
		}
		cout << '\n';
	}

}