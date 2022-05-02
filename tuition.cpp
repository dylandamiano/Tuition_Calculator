#include <iostream>

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
    "calculate"
};

void calculator_help() {
    std::cout << "Commands that are readibly available: " << std::endl;

    for (int i = 0; i < sizeof(commands); i++) {
        std::cout << commands[i] << std::endl;
    }
}

std::string calculator_match(std::string userinput) {
    for (int i = 0; i < sizeof(commands); i++) {
        if (commands[i] == userinput) {

        }
    }
}

int command(std::string userinput) {
    if (userinput == "test") {
        std::cout << userinput << " has been outputted!" << std::endl;
    } else if (userinput == "stop") {
        std::cout << userinput << " exiting application!" << std::endl;
        return 0;
    } else if (calculator_match(userinput) == "get") {

    } else if (calculator_match(userinput) == "set") {

    } else {
        std::cout << "Command not recognized!" << std::endl;
    }
}

int main() {
    std::cout << "Welcome to the my personal College Tuition Calculator!" << std::endl;
    College stored = College("Yes");

    std::cout << stored.get_name() << std::endl;

    while (true) {
        std::string userinput;
        std::cin >> userinput;

        if (command(userinput) == 0) {
            break;
        }
    }

    calculator_help();
    std::cout << "Press any key to leave!" << std::endl;

    return 0;
}