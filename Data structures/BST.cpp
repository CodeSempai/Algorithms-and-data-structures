#include <bits/stdc++.h>

using namespace std;
int min_key = 0;
struct tree_node{
  int key;
  tree_node *left = NULL;
  tree_node *right = NULL;
};

void insert_in_tree(tree_node *&node, int k){
    if(node == NULL){
        node = new tree_node;
        node -> key = k;
        node -> left = NULL;
        node -> right = NULL;
    }else{
        if(node -> key > k){
            insert_in_tree(node -> left, k);
        }else if(node -> key < k){
            insert_in_tree(node -> right, k);
        }
    }
}


bool exist_in_tree(tree_node *node, int k){
    if(node == NULL)
        return false;
    if(node -> key == k)
        return true;
    if(node -> key > k)
        return exist_in_tree(node -> left, k);
    else
        return exist_in_tree(node -> right, k);

}

tree_node* minimum(tree_node *node){
    if(node -> left == NULL)
        return node;
    return minimum(node -> left);
}

tree_node* delete_node(tree_node *node, int k){
    if(node == NULL)
        return node;
    if(node -> key > k)
        node -> left = delete_node(node -> left, k);
    else if(node -> key < k)
        node -> right = delete_node(node -> right, k);
    else if(node -> left != NULL && node -> right != NULL){
        node -> key = minimum(node -> right) -> key;
        node -> right = delete_node(node -> right, node -> key);
    }else{
        if(node -> left != NULL)
            node = node -> left;
        else
            node = node -> right;
    }
    return node;
}

int get_next(tree_node *node, int k , int min_key){
    if(node == NULL)
        return min_key;
    if(node -> key > k){
        min_key = node -> key;
        get_next(node -> left , k, min_key);
    }else
        get_next(node -> right , k , min_key);
}


int get_prev(tree_node *node, int k , int min_key){
    if(node == NULL)
        return min_key;
    if(node -> key < k){
        min_key = node -> key;
        get_prev(node -> right , k, min_key);
    }else
        get_prev(node -> left , k , min_key);
}


int main()
{
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);

    std::ios_base::sync_with_stdio (false);
    cin.tie(NULL);

    tree_node *temp = NULL;
    string com;
    int k;

    int min_key = 1000000001;


    while(cin >> com){
        cin >> k;
        if(com == "insert"){
            insert_in_tree(temp, k);
        }else if(com == "exists"){
            if(exist_in_tree(temp, k))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }else if(com == "delete"){
             temp = delete_node(temp, k);
        }else if(com == "next"){
            int check = get_next(temp, k, min_key);
            if(check != 1000000001){
                cout << check << endl;
                min_key = 1000000001;
            }
            else
                cout << "none" << endl;
        }else{
            int check = get_prev(temp, k, min_key);
            if(check != 1000000001){
                cout << check << endl;
                min_key = 1000000001;
            }
            else
                cout << "none" << endl;
        }
    }
    return 0;
}
