#include <bits/stdc++.h>
const int m = 1000000;
using namespace std;
 
struct my_list{
        string key;
        string value;
        my_list* next = NULL;
        my_list* next_p = NULL;
        my_list* prev_p = NULL;
    };
class Hash_Map{
public:
    my_list* put_in_chain(string k, string v, my_list* pr){
        if(head == NULL){
            my_list *chain_head = new my_list;
            chain_head -> key = k;
            chain_head  -> value = v;
            chain_head -> prev_p = pr;
            if(pr != NULL)
                pr -> next_p = chain_head;
            head = chain_head;
            return chain_head;
        }else{
            my_list *chain = head;
            while(chain -> next && chain -> key != k)
                chain = chain -> next;
            if(chain -> key == k){
                chain -> value = v;
                return pr;
            }else{
                my_list* add = new my_list;
                add -> key = k;
                add -> value = v;
                if(pr != NULL)
                    pr -> next_p = add;
                chain -> next = add;
                add -> prev_p = pr;
                return add;
            }
        }
    }
 
    my_list* delete_from_chain(string k){
        if(head != NULL){
         my_list* chain = head;
         if(chain -> key == k){
            chain -> value = "-";
            if(chain -> prev_p != NULL)
                chain -> prev_p -> next_p = chain -> next_p;
            if(chain -> next_p != NULL){
                chain -> next_p -> prev_p = chain -> prev_p;
                head = chain -> next;
                return NULL;
            }else{
                head = chain -> next;
                return chain -> prev_p;
            }
         }while(chain -> next && chain -> next -> key != k)
            chain = chain -> next;
            if(chain -> next == NULL)
                return NULL;
            my_list* del = chain -> next;
            chain -> next = chain -> next -> next;
            del -> value = "-";
            if(del -> prev_p != NULL)
                del -> prev_p -> next_p = del -> next_p;
            if(del -> next_p != NULL){
                del -> next_p -> prev_p = del -> prev_p;
                return NULL;
            }else
                return del -> prev_p;
        }else
            return NULL;
    }
 
    string get_from_chain(string k){
        if(head == NULL)
           return "none";
        my_list *chain = head;
        while(chain && chain -> key != k)
            chain = chain -> next;
        if(chain == NULL)
            return "none";
        else
            return chain -> value;
    }
 
    string get_prev(string k){
        if(head == NULL)
            return "none";
        my_list* chain = head;
        while(chain && chain -> key != k)
            chain = chain -> next;
        if(chain == NULL || chain -> prev_p == NULL)
            return "none";
        return chain -> prev_p -> value;
    }
 
    string get_next(string k){
        if(head == NULL)
            return "none";
        my_list* chain = head;
        while(chain && chain -> key != k)
            chain = chain -> next;
        if(chain == NULL || chain -> next_p == NULL)
            return "none";
        return chain -> next_p -> value;
 
    }
 
 
    my_list* head = NULL;
 
};
Hash_Map table[1000000];
 
int hash_func(string key){
    int h = 0;
    for (int i = 0; i < key.length();i++)
        h += key[i] * (i + 1);
    return h;
}
 
 
 
int main()
{   freopen("linkedmap.in  ", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    my_list *prev = NULL;
    my_list *del_check = NULL;
 
    string com;
    string key;
    string value;
 
    while(cin >> com){
        cin >> key;
        int hash_temp = hash_func(key);
        if(com == "put"){
            cin >> value;
            prev = table[hash_temp].put_in_chain(key, value, prev);
        }else if(com == "delete"){
            del_check = table[hash_temp].delete_from_chain(key);
            if(del_check != NULL)
                prev = del_check;
        }else if(com == "prev"){
            string check_prev = table[hash_temp].get_prev(key);
            if(check_prev != "-")
                cout << check_prev << endl;
            else
                cout << "none" << endl;
        }else if(com == "next"){
            cout << table[hash_temp].get_next(key) << endl;
        }else{
            cout << table[hash_temp].get_from_chain(key) << endl;
        }
 
    }
 
    return 0;
}