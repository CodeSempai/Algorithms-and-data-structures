#pragma once

template<class T, class Compare = std::less<T>>
class Red_Black_tree {
private:
	struct tree_node{
		tree_node*left;
		tree_node*right;
		tree_node *parent;
		char color;            
		T key;                     
	};
	tree_node *root = nullptr;
	size_t tree_size = 0;
public:
	void rotate_left(tree_node *x) {
		tree_node *y = x->right;
		x->right = y->left;
		if (y->left)
			y->left->parent = x;
		if (y)
			y->parent = x->parent;
		if (x->parent) {
			if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
		}
		else {
			root = y;
		}
		y->left = x;
		if (x)
			x->parent = y;
	}

	
	void rotate_right(tree_node *x) {
		tree_node *y = x->left;
		x->left = y->right;
		if (y->right)
			y->right->parent = x;
		if (y)
			y->parent = x->parent;
		if (x->parent) {
			if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
		}
		else {
			root = y;
		}
		y->right = x;
		if (x)
			x->parent = y;
	}

	void insertFixup(tree_node *x) {
		while (x != root && x->parent->color == 'R') {
			if (x->parent == x->parent->parent->left) {
				tree_node *y = x->parent->parent->right;
				if (y->color == 'R') {
					x->parent->color = 'B';
					y->color = 'B';
					x->parent->parent->color = 'R';
					x = x->parent->parent;
				}
				else {
					if (x == x->parent->right) {
						x = x->parent;
						rotate_left(x);
					}
					x->parent->color = 'B';
					x->parent->parent->color = 'R';
					rotate_right(x->parent->parent);
				}
			}
			else {
				tree_node *y = x->parent->parent->left;
				if (y->color == 'R') {
					x->parent->color = 'B';
					y->color = 'B';
					x->parent->parent->color = 'R';
					x = x->parent->parent;
				}
				else {

					if (x == x->parent->left) {
						x = x->parent;
						rotate_right(x);
					}
					x->parent->color = 'B';
					x->parent->parent->color = 'R';
					rotate_left(x->parent->parent);
				}
			}
		}
		root->color = 'B';
	}

	tree_node *insertNode(T key) {
		tree_node *current, *parent;
		current = root;
		parent = 0;
		while (current) {
			if (key == current->key)
				return current;
			parent = current;
			current = key < current->key ? current->left : current->right;
		}
		tree_node *x = new tree_node;
		x->key = key;
		x->parent = parent;
		x->left = nullptr;
		x->right = nullptr;
		x->color = 'R';

		if (parent) {
			if (key < parent->key)
				parent->left = x;
			else
				parent->right = x;
		}
		else {
			root = x;
		}

		insertFixup(root);
		return(root);
	}
	
	void insert(T key) {
		tree_size++;
		this->root = insertNode(key);
	}

	void deleteFixup(tree_node *x) {
		while (x != root && x->color == 'B') {
			if (x == x->parent->left) {
				tree_node *w = x->parent->right;
				if (w->color == 'R') {
					w->color = 'B';
					x->parent->color = 'R';
					rotate_left(x->parent);
					w = x->parent->right;
				}
				if (w->left->color == 'B' && w->right->color == 'B') {
					w->color = 'R';
					x = x->parent;
				}
				else {
					if (w->right->color == 'B') {
						w->left->color = 'B';
						w->color = 'R';
						rotate_right(w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = 'B';
					w->right->color = 'B';
					rotate_left(x->parent);
					x = root;
				}
			}
			else {
				tree_node *w = x->parent->left;
				if (w->color == 'R') {
					w->color = 'B';
					x->parent->color = 'R';
					rotate_right(x->parent);
					w = x->parent->left;
				}
				if (w->right->color == 'B' && w->left->color == 'B') {
					w->color = 'R';
					x = x->parent;
				}
				else {
					if (w->left->color == 'B') {
						w->right->color = 'B';
						w->color = 'R';
						rotate_left(w);
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = 'B';
					w->left->color = 'B';
					rotate_right(x->parent);
					x = root;
				}
			}
		}
		if(x)
			x->color = 'B';
	}

	void deleteNode(tree_node *z) {
		tree_node *x, *y;

		if (!z) 
			return;
		if (!z->left || !z->right){
			y = z;
		}
		else {
			y = z->right;
			while (y->left) 
				y = y->left;
		}

		
		if (y->left)
			x = y->left;
		else
			x = y->right;
		if(x && y)
			x->parent = y->parent;
		if (y->parent)
			if (y == y->parent->left)
				y->parent->left = x;
			else
				y->parent->right = x;
		else
			root = x;

		if (y != z)
			z->key = y->key;

		if (y->color == 'B')
			deleteFixup(x);
		tree_size--;
		free(y);
	}

	void remove(T key) {
		tree_node *del = find_node(key);
		deleteNode(del);
	}

	tree_node *find_node(T key) {
		tree_node *current = root;
		
		while (current) 
			if (key == current->key)
				return current;		
			else
				current = key < current->key ? current->left : current->right;
		return nullptr;
	}

	bool find(T key) {
		tree_node *current = root;
		while (current)
			if (key == current->key)
				return 1;
			else
				current = key < current->key ? current->left : current->right;
		return 0;
	}
	

	bool empty()const {
		if (tree_size == 0)
			return 1;
		else
			return 0;
	}

	size_t size()const {
		return tree_size;
	}


};