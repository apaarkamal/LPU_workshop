#include<bits/stdc++.h>
using namespace std;

struct node {
	int val;
	node* nxt;
	node(int val) {
		this->val = val;
		nxt = NULL;
	}
};

node* create_a_ll_1() {
	node *head = NULL, *last = NULL;

	while (1) {
		int x;
		cin >> x;
		if (x == -1) return head;

		if (last == NULL) {
			// first node
			// head node
			node* cur = new node(x);
			head = cur;
			last = cur;
		}
		else {
			// not the first
			node* cur = new node(x);
			last->nxt = cur;
			last = cur;
		}
	}
	return head;
}

node* create_a_ll_n() {
	node *head = NULL, *last = NULL;
	int n;
	cin >> n;

	while (n--) {
		int x;
		cin >> x;

		if (last == NULL) {
			// first node
			// head node
			node* cur = new node(x);
			head = cur;
			last = cur;
		}
		else {
			// not the first
			node* cur = new node(x);
			last->nxt = cur;
			last = cur;
		}
	}
	return head;
}

void print_ll(node* head) {
	node* cur = head;
	while (cur != NULL) {
		cout << cur->val << " ";
		cur = cur->nxt;
	}
	cout << '\n';
}

int find_length(node* head) {
	node* cur = head;
	int len = 0;
	while (cur != NULL) {
		len++;
		cur = cur->nxt;
	}
	return len;
}

node* reverse_ll(node* head) {
	node* cur = head;
	node* prev = NULL;

	while (cur != NULL) {
		node *ahead = cur->nxt;
		cur->nxt = prev;
		prev = cur;
		cur = ahead;
	}

	return prev;
}

node* reverse_ll_recursive(node* cur, node *prev) {
	node* ahead = cur->nxt;
	cur->nxt = prev;
	if (ahead == NULL) return cur;
	return reverse_ll_recursive(ahead, cur);
}

node* reverse_ll_recursive(node* cur) {
	// think
}

node* delete_at_kth_pos(node* head, int k) {

	node* cur = head, *prev = NULL;

	if (k == 1) return cur->nxt;

	k--;
	while (k--) {
		prev = cur;
		cur = cur->nxt;
	}
	// cur is on the kth node
	prev->nxt = cur->nxt;
	delete cur;
	return head;
}

node* delete_at_head(node *head) {
	return delete_at_kth_pos(head, 1);
}

node* delete_at_tail(node *head) {
	return delete_at_kth_pos(head, find_length(head));
}

node* insert_at_head(node* head, int x) {
	node *cur = new node(x);
	cur->nxt = head;
	return cur;
}

node* insert_at_tail(node* head, int x) {
	node *cur = head;
	while (cur->nxt != NULL) {
		cur = cur->nxt;
	}
	// cur is pointing to the last node
	node* temp = new node(x);
	cur->nxt = temp;
	return head;
}

// 0-based index
node* insert_at_k(node* head, int k, int x) {
	// if k is negative
	// overflow of k
	k = max(k, 0);
	k = min(k, find_length(head));

	if (k == 0) {
		// insert at head
		return insert_at_head(head, x);
	}
	else if (k == find_length(head)) {
		// insert at tail
		return insert_at_tail(head, x);
	}
	else {
		node* cur = head;
		k--;
		while (k--) {
			cur = cur->nxt;
		}
		node *temp = new node(x);
		temp->nxt = cur->nxt;
		cur->nxt = temp;
		return head;
	}
}

node* merge_two_ll_into_new_ll(node* head1, node* head2) {

	node *cur1 = head1;
	node *cur2 = head2;
	node *head3 = NULL;
	node *last = NULL;

	while (cur1 != NULL && cur2 != NULL) {
		if (cur1->val <= cur2->val) {
			node* temp = new node(cur1->val);
			if (last == NULL) head3 = temp, last = temp;
			else last->nxt = temp, last = temp;
			cur1 = cur1->nxt;
		}
		else {
			node* temp = new node(cur2->val);
			if (last == NULL) head3 = temp, last = temp;
			else last->nxt = temp, last = temp;
			cur2 = cur2->nxt;
		}
	}

	while (cur1 != NULL) {
		node* temp = new node(cur1->val);
		if (last == NULL) head3 = temp, last = temp;
		else last->nxt = temp, last = temp;
		cur1 = cur1->nxt;
	}

	while (cur2 != NULL) {
		node* temp = new node(cur2->val);
		if (last == NULL) head3 = temp, last = temp;
		else last->nxt = temp, last = temp;
		cur2 = cur2->nxt;
	}

	return head3;
}

node* merge_two_ll_recursive(node *head1, node *head2) {

	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;

	if (head1->val <= head2->val) {
		head1->nxt = merge_two_ll_recursive(head1->nxt, head2);
		return head1;
	}
	else {
		head2->nxt = merge_two_ll_recursive(head1, head2->nxt);
		return head2;
	}
}

// bubble sort
// selection
// insertion

node* kth_node_from_end(node *head, int k) {
	node *p1 = head;
	node *p2 = head;
	while (k--) {
		p2 = p2->nxt;
	}
	while (p2 != NULL) {
		p1 = p1->nxt;
		p2 = p2->nxt;
	}
	return p1;
}

node* middle(node *head) {
	node* slow = head;
	node* fast = head;

	while (slow && fast && fast->nxt && fast->nxt->nxt) {
		slow = slow->nxt;
		fast = fast->nxt->nxt;
	}
	return slow;
}

node* merge_sort(node* head) {

	if (head == NULL || head->nxt == NULL) return head;

	node* mid_node = middle(head);

	// a is left and b is right
	node *a = head;
	node *b = mid_node->nxt;
	mid_node->nxt = NULL;

	// mergesort a abd b recursively
	a = merge_sort(a);
	b = merge_sort(b);

	head = merge_two_ll_recursive(a, b);

	return head;
}

bool is_cycle(node *head) {

	node* slow = head;
	node* fast = head;

	while (fast && fast->nxt) {
		slow = slow->nxt;
		fast = fast->nxt->nxt;
		if (slow == fast) return true;
	}

	return false;
}

node* point_of_cycle(node *head) {

	node* slow = head;
	node* fast = head;

	while (1) {
		slow = slow->nxt;
		fast = fast->nxt->nxt;
		if (slow == fast) break;
	}

	slow = head;

	while (1) {
		slow = slow->nxt;
		fast = fast->nxt;
		if (slow == fast) return slow;
	}

}

node* rotate(node *head, int k) {
	// 0-based index
	if (k == 0) return head;
	node *cur = head, *prev = NULL;

	while (k--) {
		prev = cur;
		cur = cur->nxt;
	}

	// prev and cur nodes
	prev->nxt = NULL;
	// prev is the new tail

	node *cur1 = cur;
	while (cur1->nxt != NULL) {
		cur1 = cur1->nxt;
	}

	// cur1 is now at the last node
	cur1->nxt = head;

	// cur is the new head
	return cur;
}



int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code
	node* head = create_a_ll_n();
	print_ll(head);
	// head = reverse_ll_recursive(head, NULL);

	// head = delete_at_kth_pos(head, 2);

	// head = insert_at_k(head, 2, 10);
	// head = insert_at_k(head, 0, 50);
	// head = insert_at_tail(head, 100);
	// print_ll(head);

	// node *head1 = create_a_ll_n();
	// node *head2 = create_a_ll_n();

	// node *head3 = merge_two_ll_into_new_ll(head1, head2);

	// head1 = merge_two_ll_recursive(head1, head2);

	// head = merge_sort(head);

	head = rotate(head, 2);

	print_ll(head);



}