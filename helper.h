template<typename T>
void readInput(T& var){
    while(!(std::cin >> var)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, Please try again. \n";
    }
}
