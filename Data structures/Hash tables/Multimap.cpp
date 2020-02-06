#include <bits/stdc++.h>
const int m = 1000000;
using namespace std;

struct my_list{
        string key;
        my_list* next = NULL;
        my_list* next_p = NULL;
        my_list* prev_p = NULL;
    };


int hash_func(string key){
    int h = 0;
    for (int i = 0; i< key.length();i++)
        h += key[i] * (i + 1);
    return h;
}

int hash_func_for_set(string key){
        const int m = 100;
        unsigned int h = 0;
        const int P = 31;
        for(int i = 0; i < key.length(); i++)
        {
            h = h * P + (key[i] - 'a' + 1);
        }
        return h % m;

}



class Linked_Hash_Set{
public:
    my_list* put_in_set(string k, my_list* pr){
        if(head == NULL){
            my_list* chain_head = new my_list;
            chain_head -> key = k;
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
                return pr;
            }else{
                my_list* add = new my_list;
                add -> key = k;
                if(pr != NULL)
                    pr -> next_p = add;
                chain -> next = add;
                add -> prev_p = pr;
                return add;
            }
        }
    }

    my_list* delete_from_set(string k){
    if(head != NULL){
         if(head -> key == k){
            if(head -> prev_p != NULL)
                head -> prev_p -> next_p = head -> next_p;
            if(head -> next_p != NULL)
                head -> next_p -> prev_p = head -> prev_p;
            my_list* chain = head;
            if(head -> next != NULL){
                head = head -> next;
                return chain;
            }
            head = NULL;
            return chain;
         }
         my_list* temp = head;
         if(temp -> next == NULL)
            return NULL;
         while(temp -> next -> next && temp -> next -> key != k)
            temp = temp -> next;
         if(temp -> next -> key == k){
            my_list* del = temp -> next;
            if(del -> prev_p != NULL)
                del -> prev_p -> next_p = del -> next_p;
            if(del -> next_p != NULL)
                del -> next_p -> prev_p = del -> prev_p;
            temp -> next = temp -> next -> next;
            return del;
        }else
            return NULL;
    }else
        return NULL;
}

        my_list* head = NULL;

};


class Hash_Multi_Map{
public:
    struct my_list_2{
        string key;
        int chain_size = 0;
        Linked_Hash_Set values[100];
        my_list_2* next = NULL;
        my_list* first_val = NULL;
        my_list* last_val = NULL;
    };
    my_list_2* head = NULL;

    void put_in_chain(string k, string v){
        if(head == NULL){
            my_list_2 *chain_head = new my_list_2;
            chain_head -> key = k;
            int hash_temp = hash_func_for_set(v);
            chain_head -> first_val = chain_head -> values[hash_temp].put_in_set(v, NULL);
            chain_head -> last_val = chain_head -> first_val;
            chain_head -> chain_size += 1;
            head = chain_head;
        }else{
            my_list_2 *chain = head;
            while(chain -> next && chain -> key != k)
                chain = chain -> next;
            if(chain -> key == k){
                my_list* temp = chain -> last_val;
                int hash_temp =hash_func_for_set(v);
                chain -> last_val = chain -> values[hash_temp].put_in_set(v, chain -> last_val);
                if(chain -> last_val != temp){
                    chain -> chain_size += 1;
                    if(chain -> first_val == NULL)
                        chain -> first_val = chain -> last_val;
                }
                temp = NULL;
                delete temp;
            }else{
                my_list_2* add = new my_list_2;
                add -> key = k;
                int hash_temp = hash_func_for_set(v);
                add -> first_val = add -> values[hash_temp].put_in_set(v, NULL);
                add -> last_val = add -> first_val;
                add -> chain_size += 1;
                chain -> next = add;
            }
        }
    }

    void deleteall(string k){
        if(head != NULL){
            if(head -> key == k){
                if(head -> next != NULL){
                   head = head -> next;
                   return;
                }
                head = NULL;
                return;
            }else{
                if(head -> next == NULL)
                    return;
                my_list_2 *chain = head;
                while(chain -> next -> next && chain -> next -> key != k)
                    chain = chain -> next;
                if(chain -> next -> key == k){
                    chain -> next = chain -> next -> next;
                }
            }
        }
    }

    void delete_from_chain(string k, string v){
        if(head != NULL){
            my_list_2 *chain = head;
            while(chain && chain -> key != k)
                chain = chain -> next;
            if(chain != NULL){
                int hash_temp = hash_func_for_set(v);
                my_list *temp = chain -> values[hash_temp].delete_from_set(v);
                if(temp == NULL)
                    return;
                chain -> chain_size -= 1;
                if(chain -> first_val != NULL && temp == chain -> first_val){
                    chain -> first_val = chain -> first_val -> next_p;
                }else if(chain -> last_val != NULL && temp == chain -> last_val){
                    chain -> last_val = chain -> last_val -> prev_p;
                }
            }
        }
    }


   void get_from_chain(string k){
        if(head == NULL){
           cout << "0" << endl;
           return;
        }
        my_list_2 *chain = head;
        while(chain && chain -> key != k)
            chain = chain -> next;
        if(chain == NULL || chain -> chain_size == 0){
            cout << "0" << endl;
            return;
        }
        cout << chain -> chain_size << " ";
        my_list *temp = chain -> first_val;
        while(temp != NULL){
            cout << temp -> key << " ";
            temp = temp -> next_p;
        }
        cout << endl;
    }


};


Hash_Multi_Map table[1000000];





int main()
{   freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string com;
    string key;
    string value;

    while(cin >> com){
        cin >> key;
        int hash_temp = hash_func(key);
        if(com == "put"){
            cin >> value;
            table[hash_temp].put_in_chain(key, value);
        }else if(com == "deleteall"){
            table[hash_temp].deleteall(key);
        }else if(com == "get"){
            table[hash_temp].get_from_chain(key);
        }else{
            cin >> value;
            table[hash_temp].delete_from_chain(key, value);
        }
    }

    return 0;
}
