// NOTE:
//  Missing a header guard above _HELPER_H__


// NOTE:
//   Question just wondering why use a template here.
//   Templates add a lot of bloat to C++ files due to the Compiler generating
//   many many different variations of your function or obj. A good rule of thumb is keep it simple
//   C++ offers a lot of fun and cool fancy features. But there is pros and cons with everything. In my opinion the
//   use of templates here overcomplicates things you are always reading a numerical value, why do we need to generate
//   a string, double, float, string_view, etc version of this it just adds more size to your binary
//
//

// NOTE: if you do get rid of this template mark it inline to prevent ODR violations
template<typename T>
void readInput(T& var){
    // NOTE: What happens if you can not read the value I Suggest throw an error or some sort of error
    while(!(std::cin >> var)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, Please try again. \n";
    }
}
