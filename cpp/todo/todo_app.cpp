#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <string>
#include <stack>

class Todo {
private:
    std::string description;
    int id;
    static int nextId;

public:
    explicit Todo(std::string desc) : description(std::move(desc)), id(nextId++) {}

    const std::string& getDescription() const { return description; }
    int getId() const { return id; }

    void display() const { std::cout << "[" << id << "] " << description << '\n'; }
};

int Todo::nextId = 1;

class TodoManager {
private:
    std::deque<Todo> todos;          // FIFO: push_back, pop_front
    std::deque<Todo> completedTodos; // Optional history
    //
    std::stack<Todo> deletedTodos;

    static bool isBlank(const std::string& s) {
        for (unsigned char ch : s) {
            if (!std::isspace(ch)) return false;
        }
        return true;
    }

public:
    void addTodo(const std::string& description) {
        if (isBlank(description)) {
            std::cout << "Error: Todo description cannot be empty!\n";
            return;
        }

        Todo newTodo(description);
        const int newId = newTodo.getId();
        todos.push_back(std::move(newTodo));
        std::cout << "Todo added successfully! (ID: " << newId << ")\n";
    }

    void deleteTodo() {
        if (todos.empty()) {
            std::cout << "No todos to delete! The queue is empty.\n";
            return;
        }
   
        Todo deletedTodo = std::move(todos.front());
        // push the deleted todo to a stack to enable undo delete functionality
        deletedTodos.push(deletedTodo);
        todos.pop_front();
        completedTodos.push_back(deletedTodo);

        std::cout << "Deleted todo: ";
        deletedTodo.display();


    }

    void undoDelete(int id){
        //check if the stack is empty
        //if the stack is occupied push the LIFO to the end of the todos queue
        if(!deletedTodos.empty()){
            Todo deletedTodo = std::move(deletedTodos.top());
            //remove the todo from stack
            deletedTodos.pop();
            //we use push back to add the deleted to the end of the queue
            todos.push_back(deletedTodo);
            completedTodos.push_back(deletedTodo);
        }
    }

    void deleteSpecificTodo(int id) {
        if (todos.empty()) {
            std::cout << "No todos to delete! The queue is empty.\n";
            return;
        }

        for (auto it = todos.begin(); it != todos.end(); ++it) {
            if (it->getId() == id) {
                Todo deletedTodo = std::move(*it);
                todos.erase(it);
                completedTodos.push_back(deletedTodo);

                std::cout << "Deleted todo: ";
                deletedTodo.display();
                return;
            }
        }

        std::cout << "Todo with ID " << id << " not found!\n";
    }

    void deleteAllTodos() {
        if (todos.empty()) {
            std::cout << "No todos to delete! The queue is empty.\n";
            return;
        }

        const std::size_t count = todos.size();
        for (const auto& t : todos) completedTodos.push_back(t);
        todos.clear();

        std::cout << "Deleted all " << count << " todo(s)!\n";
    }

    void displayTodos() const {
        if (todos.empty()) {
            std::cout << "\nNo todos in the list!\n";
            return;
        }

        std::cout << "\nCurrent Todos (FIFO Order):\n";
        std::cout << "==============================\n";
        int position = 1;
        for (const auto& todo : todos) {
            std::cout << position << ". ";
            todo.display();
            position++;
        }
        std::cout << "==============================\n";
        std::cout << "Total: " << (position - 1) << " todo(s)\n";
    }

    void displayQueueInfo() const {
        std::cout << "\nQueue Information:\n";
        std::cout << "- Current queue size: " << todos.size() << '\n';
        std::cout << "- FIFO order: First In, First Out\n";
        if (!todos.empty()) {
            std::cout << "- Next todo to process (front): ";
            todos.front().display();
        }
    }

    bool isEmpty() const { return todos.empty(); }
};

class TodoApp {
private:
    TodoManager manager;
    static bool triedReopenStdin;

    static bool tryReopenStdinFromConsole() {
        if (triedReopenStdin) return false;
        triedReopenStdin = true;
#if defined(_WIN32)
        if (std::freopen("CONIN$", "r", stdin) != nullptr) {
            std::cin.clear();
            return true;
        }
#endif
        return false;
    }

    static std::string trim(const std::string& s) {
        std::size_t start = 0;
        while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start]))) start++;
        std::size_t end = s.size();
        while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) end--;
        return s.substr(start, end - start);
    }

    static int readIntLine(const std::string& prompt, int minValue, int maxValue) {
        while (true) {
            std::cout << prompt << std::flush;
            std::string line;
            if (!std::getline(std::cin, line)) {
                if (tryReopenStdinFromConsole()) continue;
                return std::numeric_limits<int>::min();
            }

            line = trim(line);
            if (line.empty()) {
                std::cout << "Please enter a number.\n";
                continue;
            }

            try {
                std::size_t pos = 0;
                const long long value = std::stoll(line, &pos, 10);
                if (pos != line.size()) throw std::invalid_argument("trailing");
                if (value < minValue || value > maxValue) {
                    std::cout << "Please enter a number between " << minValue << " and " << maxValue << ".\n";
                    continue;
                }
                return static_cast<int>(value);
            } catch (...) {
                std::cout << "Invalid input. Please enter a valid number.\n";
            }
        }
    }

    static bool readYesNo(const std::string& prompt) {
        while (true) {
            std::cout << prompt << std::flush;
            std::string line;
            if (!std::getline(std::cin, line)) {
                if (tryReopenStdinFromConsole()) continue;
                return false;
            }

            line = trim(line);
            if (line.size() == 1) {
                const char c = static_cast<char>(std::tolower(static_cast<unsigned char>(line[0])));
                if (c == 'y') return true;
                if (c == 'n') return false;
            }
            std::cout << "Please enter 'y' or 'n'.\n";
        }
    }

    static std::string readLineOrExit(const std::string& prompt) {
        std::cout << prompt << std::flush;
        std::string line;
        if (!std::getline(std::cin, line)) {
            if (tryReopenStdinFromConsole() && std::getline(std::cin, line)) return line;
            std::cout << "\nInput closed. Exiting.\n";
            std::exit(0);
        }
        return line;
    }

    void displayMenu() const {
        std::cout << "\n==============================\n";
        std::cout << "        TODO LIST APP\n";
        std::cout << "==============================\n";
        std::cout << " 1) Add Todo\n";
        std::cout << " 2) Delete Todo (FIFO)\n";
        std::cout << " 3) Delete Specific Todo\n";
        std::cout << " 4) Delete All Todos\n";
        std::cout << " 5) Display All Todos\n";
        std::cout << " 6) Show Queue Info\n";
        std::cout << " 7) Exit\n";
    }

    void addTodoUI() {
        const std::string description = trim(readLineOrExit("Enter todo description: "));
        manager.addTodo(description);
    }

    void deleteTodoUI() {
        if (manager.isEmpty()) {
            std::cout << "No todos to delete!\n";
            return;
        }

        std::cout << "This will delete the OLDEST todo (FIFO principle).\n";
        if (readYesNo("Confirm deletion? (y/n): ")) {
            manager.deleteTodo();
        } else {
            std::cout << "Deletion cancelled.\n";
        }
    }

    void deleteSpecificTodoUI() {
        if (manager.isEmpty()) {
            std::cout << "No todos to delete!\n";
            return;
        }

        manager.displayTodos();
        const int id = readIntLine("Enter the ID of todo to delete: ", 1, std::numeric_limits<int>::max());
        if (id == std::numeric_limits<int>::min()) {
            std::cout << "\nInput closed. Exiting.\n";
            std::exit(0);
        }

        if (readYesNo("Confirm deletion? (y/n): ")) {
            manager.deleteSpecificTodo(id);
        } else {
            std::cout << "Deletion cancelled.\n";
        }
    }

public:
    void run() {
        std::cout << "\nWelcome to the FIFO Todo List Application!\n";
        std::cout << "This app uses a Queue (FIFO) data structure.\n";

        while (true) {
            displayMenu();
            const int choice = readIntLine("Enter your choice (1-7): ", 1, 7);
            if (choice == std::numeric_limits<int>::min()) {
                std::cout << "\nInput closed. Exiting.\n";
                return;
            }

            switch (choice) {
                case 1:
                    addTodoUI();
                    break;
                case 2:
                    deleteTodoUI();
                    break;
                case 3:
                    deleteSpecificTodoUI();
                    break;
                case 4:
                    if (manager.isEmpty()) {
                        std::cout << "No todos to delete!\n";
                        break;
                    }
                    std::cout << "This will delete ALL todos!\n";
                    if (readYesNo("Confirm deletion? (y/n): ")) {
                        manager.deleteAllTodos();
                    } else {
                        std::cout << "Deletion cancelled.\n";
                    }
                    break;
                case 5:
                    manager.displayTodos();
                    break;
                case 6:
                    manager.displayQueueInfo();
                    break;
                case 7:
                    std::cout << "\nThank you for using Todo App! Goodbye!\n";
                    return;
            }
        }
    }
};

bool TodoApp::triedReopenStdin = false;

int main() {
    TodoApp app;
    app.run();
    return 0;
}
