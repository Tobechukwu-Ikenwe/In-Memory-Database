
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



template <typename KeyType, typename ValueType>
class keyValueStore {
    private:
    std::map<KeyType, ValueType>store; // Internal storage: map from KeyType to ValueType.
    public:
    //dataype aliases to be used in database handleAction function.
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

    if (store.count(key) > 0){ 
        std::cout << "Key already exists\n"; 

    } 
    else
    {
        store[key] = value; 
    }

}

template <typename KeyType, typename ValueType>
void keyValueStore<KeyType, ValueType>::remove(const KeyType& key){
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
    else{
        return false;
    }

}

template<typename KeyType, typename ValueType>
void keyValueStore<KeyType, ValueType>::display(){
    if (store.empty())
    {
        std::cout << "No key-value pairs in Database\n";
    }
    else
    {
        for (auto it = store.begin(); it != store.end(); it++) {
        std::cout << it->first << ":" << it->second << std::endl;
    }

}
}
#endif
