#include <iostream>
#include <vector>

class College {
    // set cost of attendance
    // get cost of attendance

    private:
        std::string college_name;

        int tuition = 0; // per year
        int room_board = 0; // per year
        int scholarship = 0; // per year

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

void College::set_roomboard(int cost) {
    College::room_board = cost;
}

int College::get_roomboard() {
    return College::room_board;
}

int College::calculate(int years) {
    int total_scholar = College::scholarship * years;
    int total_tuition = College::tuition * years;
    int total_roomboard = College::room_board * years;

    return (total_tuition - total_scholar) + total_roomboard;
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
    "select-college",
    "get-roomboard",
    "set-roomboard"
};

static std::vector<College> college_list;
static int selected = -1;

static std::string userinput;

void calculator_help() {
    std::cout << "Commands that are readibly available: " << std::endl;

    for (std::string cmd : commands) {
        std::cout << cmd << std::endl;
    }
}

void fetch_college() {
    for (int i = 0; i < college_list.size(); i++) {
        std::cout << "[" << i << "]" <<  " COLLEGE NAME: " << college_list[i].get_name() << std::endl;
    }
}

void command() {
    if (userinput == "test") {
        std::cout << userinput << " has been outputted!" << std::endl;
    } else if (userinput == "stop") {
        std::cout << std::endl << userinput << " exiting application!" << std::endl;
        delete &userinput;

        exit(0);

    } else if (userinput == "help") {
        calculator_help();
    } else if (userinput == "get-tuition") {
        if (!(selected <= -1)) {
            std::cout << "Your tuition for " << college_list[selected].get_name() << " is: " << college_list[selected].get_tuition() << std::endl;
        } else {
            std::cout << "You must select a college first!" << std::endl;
        }
        
    } else if (userinput == "set-tuition") {
        if (!(selected <= -1)) {

            std::cout << "Tuition (by year): ";

            int cost;
            std::cin >> cost;

            college_list[selected].set_tuition(cost);

            std::cout << "Tuition set to: " << cost << " for " << college_list[selected].get_name() << std::endl;
        } else {
            std::cout << "You must select a college first!" << std::endl;
        }

    } else if (userinput == "get-name") {
        if (!(selected <= -1)) {
            std::cout << college_list[selected].get_name() << std::endl;
        } else {
            std::cout << "You must select a college first!" << std::endl;
        }
    } else if (userinput == "set-name") {
        if (!(selected <= -1)) {
            std::cout << "New name of college: ";

            std::string name;
            std::cin >> name;

            std::string old_name;
            old_name = college_list[selected].get_name();

            college_list[selected].set_name(name);
            std::cout << "Set new name for: " << old_name << " to " << name << std::endl;

        } else {
            std::cout << "You must select a college first!" << std::endl;
        }
    } else if (userinput == "get-scholarship") {
        if (!(selected <= -1)) {
            std::cout << "Your scholarship amount for " << college_list[selected].get_name() << " is: " << college_list[selected].get_scholarship() << std::endl;
        } else {
            std::cout << "You must select a college first!" << std::endl;
        }
    } else if (userinput == "set-scholarship") {
        if (!(selected <= -1)) {
            std::cout << "Scholarship (by year): ";

            int cost;
            std::cin >> cost;

            college_list[selected].set_scholarship(cost);

            std::cout << "Scholarship set to: " << cost << " for " << college_list[selected].get_name() << std::endl;
        } else {
            std::cout << "You must select a college first!" << std::endl;
        }

    } else if (userinput == "get-roomboard") {
        if (!(selected <= -1)) {
            std::cout << "Your room & board amount for " << college_list[selected].get_name() << " is: " << college_list[selected].get_roomboard() << std::endl;
        } else {
            std::cout << "You must select a college first!" << std::endl;
        }
    } else if (userinput == "set-roomboard") {
        if (!(selected <= -1)) {
            std::cout << "Room & board (by year): ";

            int cost;
            std::cin >> cost;

            college_list[selected].set_roomboard(cost);

            std::cout << "Room & board set to: " << cost << " for " << college_list[selected].get_roomboard() << std::endl;
        } else {
            std::cout << "You must select a college first!" << std::endl;
        }
    } else if (userinput == "calculate") {
        if (!(selected <= -1)) {
            std::cout << "Number of years attending as # (ex. 4): ";

            int years;
            std::cin >> years;

            std::cout << "The total cost for attending for " << years << " years" << " is " << college_list[selected].calculate(years) << std::endl;
        } else {
            std::cout << "You must select a college first!" << std::endl;
        }

    } else if (userinput == "add-college") {
        std::cout << "Name of college: ";

        std::string name;
        std::cin >> name;

        College temp = College(name);
        college_list.push_back(temp);

    } else if (userinput == "find-college") {
        if (college_list.size() >= 1) {
            fetch_college();
        } else {
            std::cout << "There are currently no colleges to query information from!" << std::endl;
        }
    } else if (userinput == "select-college") {
        if (college_list.size() >= 1) {
            fetch_college();
            std::cout << std::endl << "Which college # number (ex: 0) do you wish to select?: ";

            int sel;
            std::cin >> sel;

            selected = sel;
            std::cout << college_list[selected].get_name() << std::endl;
        } else {
            std::cout << "There are currently no colleges to query information from!" << std::endl;
        }
    } else {
        std::cout << "Command not recognized!" << std::endl;
        
    }
}

int main() {
    std::cout << "Welcome to the my personal College Tuition Calculator!" << std::endl;
    std::cout << college_list.size() << selected;

    while (true) {
        std::cin >> userinput;
        
        command();

        userinput = "";
    }

    std::cout << "Press any key to leave!" << std::endl;

    return 0;
}