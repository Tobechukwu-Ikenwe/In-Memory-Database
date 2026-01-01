
#include "keyValueStore.h"
#include "helper.h"

template<typename DB>
bool handleAction(DB& database){
    typename DB::key key;
    typename DB::value value;

    int action;   //Declare an Integer action to take in users choice of operation.
    std::cout << "1. Insert key-value pair\n";
    std::cout << "2. Remove key-value pair\n";
    std::cout << "3. Update key-value pair\n";
    std::cout << "4. Search for Key-Value pair\n";
    std::cout << "5. display all the key-value pairs\n"; 
    std::cout << "6. Exit code\n";
    

    readInput(action);



    //switch statement to perform operations on database based on user input.
    switch (action) {

        case 1: // INSERT
            std::cout << "Enter key: ";
            readInput(key);
            std::cout << "Enter value: ";
            readInput(value);
            database.insert(key, value);
            break;

        case 2: // REMOVE
            std::cout << "Enter key to remove: ";
            readInput(key);
            database.remove(key);
            break;

        case 3: // UPDATE
            std::cout << "Enter key to update: ";
            readInput(key);
            std::cout << "Enter new value: ";
            readInput(value);
            database.update(key, value);
            break;

        case 4: // SEARCH
            std::cout << "Enter key to search: ";
            readInput(key);
            if (database.search(key, value)) {
                std::cout << "Value: " << value << "\n";
            } else {
                std::cout << "Key not found\n";
            }
            break;

        case 5: // DISPLAY
            database.display();
            break;

        case 6: // EXIT
            return false;

        default:
            std::cout << "Invalid menu option\n";
    }

    return true;
}





int main(){
    //declare 3 database objects of different types from the keyValueStore class template.
    keyValueStore<int, int> database1; 
    keyValueStore<double, double> database2;
    keyValueStore<std::string, std::string> database3;


    int choice;  //Declare an Integer choice to take in users choice of database type.
    int action;  //Declare an Integer that will be used by the database objects.
    bool running = true;
    while(running){  //The code inside while loop keeps running.
        std::cout << "Welcome to your in-Memory Database\n";
        std::cout << "What type of database would you like (select 1-4)\n";
        std::cout << "1. Integer(Int) Database\n";
        std::cout << "2. Double Database\n";
        std::cout << "3. String Database\n";
        std::cout << "4. Exit code\n";


        readInput(choice);
        
        
        
        // Switch to call handleAction for the database type chosen by the user.

        switch(choice){
            case 1:
                std::cout << "Welcome to your Integer database\n";
                std::cout << "Only Enter Values of Integer datatype\n";
                running = handleAction(database1);
                break;
            case 2:
                std::cout << "Welcome to your Double database\n";
                std::cout << "Only Enter Values of Double datatype\n";
                running = handleAction(database2);
                break;
            case 3:
                std::cout << "Welcome to your String database\n";
                std::cout << "Only Enter Values of String datatype\n";
                running = handleAction(database3);
                break;
            case 4:
                return 1;
                break;
            default:
            std::cout << "Please select a valid number(1-3) for your database or 4 to exit code\n";
            
        }

        std::cout << "Exiting program...\n";

       
    



    

 
   


        
    
}
    
    

    return 0;
}


