
#ifndef KEY_VALUE_STORE_H
#define KEY_VALUE_STORE_H

#include<iostream>
#include<limits>
#include<map>
#include<string>


/*
 * Template class for a simple key-value store.
 * Allows the user to create a database of any data type combination for key and value.
 * Template parameters:
 *   KeyType   - the type of the keys in the store
 *   ValueType - the type of the values in the store
 */


// NOTE:
//   I suggest limiting your template here because you use 2 typenames KeyType, ValueType
//   Becuase of this you permit a user to use string, double, int, double. ETC this violates how your program suppose to work
//   Instead just do typename T. this will enforce it bieng of the same value. If you want to keep how it is then you need to
//   Tweak the main
template <typename KeyType, typename ValueType>
class keyValueStore {
    private:
    // NOTE: mark all member vars eithier m_store or _store
    std::map<KeyType, ValueType>store; // Internal storage: map from KeyType to ValueType.
    public:
    //dataype aliases to be used in database handleAction function.
    // NOTE: Are these used at all?
    using key = KeyType;
    using value = ValueType;
   
    //member functions
    void insert(const KeyType& key, const ValueType& value);
    void remove(const KeyType& Key);
    void update(const KeyType& key, const ValueType& value);
    bool search(const KeyType& key, ValueType& value);
    void display(); 


};
   
    

//Template function definitions.
template <typename KeyType, typename ValueType>
void keyValueStore<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value){

    // NOTE: This can be rewritten better to avoid the branching
    //  Delete the else and add a return to exit
    if (store.count(key) > 0){ 
        std::cout << "Key already exists\n"; 
        return;
    } 
   
    store[key] = value; 
}

template <typename KeyType, typename ValueType>
void keyValueStore<KeyType, ValueType>::remove(const KeyType& key){
    // NOTE: Same as above
    if (store.count(key) > 0) 
    {
        store.erase(key);
    }
    else
    {
        std::cout << "Key does not exist\n"; 
    }  
}

template <typename KeyType, typename ValueType>
void keyValueStore<KeyType, ValueType>::update(const KeyType& key, const ValueType& value){
    auto it = store.find(key); 
    if(it != store.end()) 
    { 
        it->second = value; 
    }
    else{
        std::cout << "Key doesn't exist\n"; 
    }
 }


template<typename KeyType, typename ValueType>
bool keyValueStore<KeyType, ValueType>::search(const KeyType &key, ValueType &value){
    
    auto it = store.find(key);
    if(it != store.end()){
        value = it->second;
        return true;
        
    }
    // NOTE: just return false outside no need to add the else
    // When a function hits a return it automatically exits so no need for the else
    
   return false;
}

template<typename KeyType, typename ValueType>
void keyValueStore<KeyType, ValueType>::display(){
    // NOTE: same as above
    if (store.empty())
    {
        std::cout << "No key-value pairs in Database\n";
        return;
    }

        for (auto it = store.begin(); it != store.end(); it++)
            std::cout << it->first << ":" << it->second << std::endl;

}
}
#endif
