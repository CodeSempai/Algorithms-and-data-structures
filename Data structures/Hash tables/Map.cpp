#include <bits/stdc++.h>
const int m = 1000000;
using namespace std;
 
class Hash_Map{
public:
    void put_in_chain(string k, string v){
        if(head == NULL){
            my_list *chain_head = new my_list;
            chain_head -> key = k;
            chain_head  -> value = v;
            head = chain_head;
        }else{
            my_list *chain = head;
            while(chain -> next && chain -> key != k)
                chain = chain -> next;
            if(chain -> key == k)
                chain -> value = v;
            else{
                my_list* add = new my_list;
                add -> key = k;
                add -> value = v;
                chain -> next = add;
            }
        }
    }
 
    void delete_from_chain(string k){
        if(head != NULL){
            if(head -> key == k){
                head = head -> next;
            }else{
                my_list *chain = head;
                while(chain -> next && chain -> next -> key != k)
                    chain = chain -> next;
                if(chain -> next != NULL){
                    my_list* del = chain -> next;
                    chain -> next = chain -> next -> next;
                    delete del;
                }
            }
        }
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
 
 
private:
    struct my_list{
        string key;
        string value;
        my_list* next = NULL;
    };
    my_list* head = NULL;
 
};
Hash_Map table[1000000];
 
int hash_func(string key){
    int h = 0;
    for (int i = 0; i< key.length();i++)
        h += key[i] * (i + 1);
    return h;
}
 
 
 
int main()
{   freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
 
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
        }else if(com == "delete"){
            table[hash_temp].delete_from_chain(key);
        }else{
            cout << table[hash_temp].get_from_chain(key) << endl;
        }
 
    }
 
    return 0;
}