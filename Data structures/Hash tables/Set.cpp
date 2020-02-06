#include <bits/stdc++.h>
int m = 1000000;
 
const double A = (sqrt(5) - 1) / 2;
 
using namespace std;
 
 
 
 
class Hash_Set{
public:
    void put_in_chain(int k){
        if(head == NULL){
            my_list *chain_head = new my_list;
            chain_head -> key = k;
            head = chain_head;
        }else{
            my_list *chain = head;
            while(chain -> next && chain -> key != k)
                chain = chain -> next;
            if(chain -> key != k){
                my_list* add = new my_list;
                add -> key = k;
                chain -> next = add;
               }
            }
        }
 
    void delete_from_chain(int k){
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
 
    string get_from_chain(int k){
        if(head == NULL)
           return "false";
        my_list *chain = head;
        while(chain && chain -> key != k)
            chain = chain -> next;
        if(chain == NULL)
            return "false";
        else
            return "true";
    }
private:
    struct my_list{
       int key;
       my_list* next = NULL;
    };
    my_list* head = NULL;
};
Hash_Set table[1000000];
 
int hash_function(int key){
    return abs(m * fmod(key * A, 1));
}
 
 
int main()
{   freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 
 
    string com;
    int key;
 
 
    while(cin >> com){
        cin >> key;
        int hash_temp = hash_function(key);
        if(com == "insert"){
            table[hash_temp].put_in_chain(key);
        }else if(com == "delete"){
            table[hash_temp].delete_from_chain(key);
        }else{
            cout << table[hash_temp].get_from_chain(key) << endl;
        }
 
    }
 
    return 0;
}