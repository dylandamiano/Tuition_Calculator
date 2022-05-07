#include <iostream>
#include <vector>

class College {
    // set cost of attendance
    // get cost of attendance

    private:
        std::string college_name;

        int tuition; // per semester
        int room_board; // per semester
        int scholarship; // per semester

    public:
        College(std::string name);

        std::string get_name();
        std::string set_name(std::string name);

        void set_tuition(int cost);
        int get_tuition();
        
        void set_scholarship(int cost);
        int get_scholarship();

        void set_roomboard(int cost);
        int get_roomboard();

        int calculate(int years);
};

College::College(std::string name) {
    College::college_name = name;
    std::cout << name << " [College] object has been created!" << std::endl;
}

std::string College::get_name() {
    return College::college_name;
};

std::string College::set_name(std::string name) {
    College::college_name = name;
};

void College::set_tuition(int cost) {
    College::tuition = cost;
}

int College::get_tuition() {
    return College::tuition;
}

void College::set_scholarship(int cost) {
    College::scholarship = cost;
}

int College::get_scholarship() {
    return College::scholarship;
}

int College::calculate(int years) {
    int total_scholar = College::scholarship * years;
    int total_tuition = College::tuition * years;
    int total_roomboard = College::room_board * years;

    return (total_tuition - total_scholar) - total_roomboard;
};

std::string commands[] = {
    "set-tuition", 
    "get-tuition",
    "get-name",
    "set-name",
    "set-scholarship",
    "get-scholarship",
    "calculate",
    "add-college",
    "find-college",
    "select-college"
};

static std::vector<College> college_list;
static College *selected;

static std::string userinput;

void calculator_help() {
    std::cout << "Commands that are readibly available: " << std::endl;

    for (int i = 0; i < sizeof(commands) - 1; i++) {
        std::cout << commands[i] << std::endl;
    }
}

void fetch_college() {
    for (int i = 0; i < college_list.size(); i++) {
        std::cout << "[" << i << "]" <<  " COLLEGE NAME: " << college_list.at(i).get_name() << std::endl;
    } 
}

void command() {
    if (userinput == "test") {
        std::cout << userinput << " has been outputted!" << std::endl;
    } else if (userinput == "stop") {
        std::cout << userinput << " exiting application!" << std::endl;
    } else if (userinput == "help") {
        calculator_help();
    } else if (userinput == "get-tuition") {
        
    } else if (userinput == "set-tuition") {

    } else if (userinput == "get-name") {
        
    } else if (userinput == "set-name") {
        
    } else if (userinput == "get-scholarship") {
        
    } else if (userinput == "set-scholarship") {
        std::cout << "Scholarship (by year): ";

        int years;
        std::cin >> years;

        //College temp = College(name);
        //college_list.push_back(temp);

    } else if (userinput == "calculate") {
        std::cout << "Number of years attending as # (ex. 4): ";

        int years;
        std::cin >> years;

        //college_list.push_back(temp);

    } else if (userinput == "add-college") {
        std::cout << "Name of college: ";

        std::string name;
        std::cin >> name;

        College temp = College(name);
        college_list.push_back(temp);

    } else if (userinput == "find-college") {
        
        if ( college_list.size() - 1 >= 0) {
            for (int i = 0; i < college_list.size(); i++) {
                std::cout << "[" << i << "]" <<  " COLLEGE NAME: " << college_list[i].get_name() << std::endl;
            } 
        }

    } else if (userinput == "select-college") {
        
    } else {
        std::cout << "Command not recognized!" << std::endl;
        
    }
}

int main() {
    std::cout << "Welcome to the my personal College Tuition Calculator!" << std::endl;
    std::cout << college_list.size();
    while (true) {
        std::cin >> userinput;
        
        command();

        userinput = "";
    }

    std::cout << "Press any key to leave!" << std::endl;

    return 0;
}