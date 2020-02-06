#include <bits/stdc++.h>
 
using namespace std;
 
struct tree_node{
    int key;
    int height_val;
    tree_node *left = NULL;
    tree_node *right = NULL;
};
 
int height(tree_node* node){
    if(node == NULL)
        return 0;
    else
        return node -> height_val;
}
 
void fix_tree_height(tree_node* node){
    node -> height_val = max(height(node -> right), height(node -> left)) + 1;
}
 
int get_balance(tree_node* node){
   if(!node)
        return 0;
   return height(node -> right) - height(node -> left);
}
 
tree_node* make_right_rotation(tree_node* node){
    tree_node* temp = node -> left;
    node -> left = temp -> right;
    temp -> right = node;
    fix_tree_height(node);
    fix_tree_height(temp);
    return temp;
}
 
tree_node* make_left_rotation(tree_node* node){
    tree_node* temp = node -> right;
    node -> right = temp -> left;
    temp -> left = node;
    fix_tree_height(node);
    fix_tree_height(temp);
    return temp;
}
 
tree_node* make_balance(tree_node* node){
    fix_tree_height(node);
    if(get_balance(node) == 2){
        if(get_balance(node -> right) < 0)
            node -> right = make_right_rotation(node -> right);
        return make_left_rotation(node);
    }
    if(get_balance(node) == -2){
        if(get_balance(node -> left) > 0)
            node -> left = make_left_rotation(node -> left);
        return make_right_rotation(node);
    }
    return node;
}
 
 
tree_node* insert_in_tree(tree_node* node, int k){
    if(node == NULL){
        node = new tree_node;
        node -> key = k;
        node -> height_val = 1;
        node -> left = NULL;
        node -> right = NULL;
        return node;
    }
    if(node -> key > k)
        node -> left = insert_in_tree(node -> left, k);
    else
        node -> right = insert_in_tree(node -> right, k);
    return make_balance(node);
}
 
tree_node* maximum(tree_node* node){
    if(node -> right == NULL)
        return node;
    return maximum(node -> right);
}
 
tree_node* delete_maximum(tree_node* node){
    if(node -> right == NULL)
        return node -> left;
    node -> right = delete_maximum(node -> right);
    return make_balance(node);
}
 
tree_node* delete_node(tree_node *node, int k){
    if(node == NULL)
        return node;
    if(node -> key > k)
        node -> left = delete_node(node -> left, k);
    else if(node -> key < k)
        node -> right = delete_node(node -> right, k);
    else{
        tree_node* temp_1 = node -> left;
        tree_node* temp_2 = node -> right;
        delete node;
        if(temp_1 == NULL)
            return temp_2;
            tree_node* _max_ = maximum(temp_1);
            _max_ -> left = delete_maximum(temp_1);
            _max_ -> right = temp_2;
            return make_balance(_max_);
        }
 
    return make_balance(node);
 
}
 
 
string exist_in_tree(tree_node *node, int k){
    if(node == NULL)
        return "N";
    if(node -> key == k)
        return "Y";
    if(node -> key > k)
        return exist_in_tree(node -> left, k);
    else
        return exist_in_tree(node -> right, k);
 
}
 
int main()
{
    freopen("avlset.in", "r", stdin);
    freopen("avlset.out", "w", stdout);
 
    std::ios_base::sync_with_stdio (false);
    cin.tie(NULL);
 
    tree_node *temp = NULL;
    int n;
    string com;
    int key;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> com;
        cin >> key;
        if(com == "A"){
        if(exist_in_tree(temp, key) == "N")
           temp = insert_in_tree(temp, key);
        cout << get_balance(temp) << endl;
        }else if(com == "D"){
            if(exist_in_tree(temp, key) == "Y")
                temp = delete_node(temp, key);
            cout << get_balance(temp) << endl;
        }else
            cout << exist_in_tree(temp, key) << endl;
    }
 
    return 0;
}