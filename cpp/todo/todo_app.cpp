#include <iostream>
#include <queue>
#include <string>
#include <memory>
#include <limits>

class Todo {
private:
    std::string description;
    int id;
    static int nextId;

public:
    Todo(const std::string& desc) : description(desc) {
        id = nextId++;
    }

    std::string getDescription() const {
        return description;
    }

    int getId() const {
        return id;
    }

    void display() const {
        std::cout << "[" << id << "] " << description << std::endl;
    }
};

int Todo::nextId = 1;

class TodoManager {
private:
    std::queue<Todo*> todoQueue;  // FIFO structure
    std::queue<Todo*> completedQueue; // For deleted/completed todos

public:
    ~TodoManager() {
        // Clean up memory
        while (!todoQueue.empty()) {
            delete todoQueue.front();
            todoQueue.pop();
        }
        while (!completedQueue.empty()) {
            delete completedQueue.front();
            completedQueue.pop();
        }
    }

    void addTodo(const std::string& description) {
        if (description.empty()) {
            std::cout << "Error: Todo description cannot be empty!" << std::endl;
            return;
        }
        
        Todo* newTodo = new Todo(description);
        todoQueue.push(newTodo);
        std::cout << "✓ Todo added successfully! (ID: " << newTodo->getId() << ")" << std::endl;
    }

    void deleteTodo() {
        if (todoQueue.empty()) {
            std::cout << "No todos to delete! The queue is empty." << std::endl;
            return;
        }

        Todo* deletedTodo = todoQueue.front();
        todoQueue.pop();
        
        // Store in completed queue for history (optional)
        completedQueue.push(deletedTodo);
        
        std::cout << "✓ Deleted todo: ";
        deletedTodo->display();
    }

    void deleteSpecificTodo(int id) {
        if (todoQueue.empty()) {
            std::cout << "No todos to delete! The queue is empty." << std::endl;
            return;
        }

        // Since queue doesn't allow random access, we need to use a temporary queue
        std::queue<Todo*> tempQueue;
        bool found = false;
        Todo* deletedTodo = nullptr;

        // Transfer todos to temp queue, skipping the one with matching id
        while (!todoQueue.empty()) {
            Todo* current = todoQueue.front();
            todoQueue.pop();
            
            if (current->getId() == id && !found) {
                deletedTodo = current;
                found = true;
            } else {
                tempQueue.push(current);
            }
        }

        // Restore the original queue
        todoQueue = tempQueue;

        if (found) {
            completedQueue.push(deletedTodo);
            std::cout << "✓ Deleted todo: ";
            deletedTodo->display();
        } else {
            std::cout << "Todo with ID " << id << " not found!" << std::endl;
            if (deletedTodo) delete deletedTodo; // Clean up if found but not pushed
        }
    }

    void deleteAllTodos() {
        if (todoQueue.empty()) {
            std::cout << "No todos to delete! The queue is empty." << std::endl;
            return;
        }

        int count = 0;
        while (!todoQueue.empty()) {
            Todo* deletedTodo = todoQueue.front();
            todoQueue.pop();
            completedQueue.push(deletedTodo);
            count++;
        }
        
        std::cout << "✓ Deleted all " << count << " todo(s)!" << std::endl;
    }

    void displayTodos() const {
        if (todoQueue.empty()) {
            std::cout << "\n📝 No todos in the list!" << std::endl;
            return;
        }

        std::cout << "\n📋 Current Todos (FIFO Order):" << std::endl;
        std::cout << "==============================" << std::endl;
        
        // Create a copy to display without modifying original
        std::queue<Todo*> tempQueue = todoQueue;
        int position = 1;
        
        while (!tempQueue.empty()) {
            std::cout << position << ". ";
            tempQueue.front()->display();
            tempQueue.pop();
            position++;
        }
        std::cout << "==============================" << std::endl;
        std::cout << "Total: " << (position - 1) << " todo(s)" << std::endl;
    }

    void displayQueueInfo() const {
        std::cout << "\n📊 Queue Information:" << std::endl;
        std::cout << "• Current queue size: " << todoQueue.size() << std::endl;
        std::cout << "• FIFO order: First In, First Out" << std::endl;
        
        if (!todoQueue.empty()) {
            std::cout << "• Next todo to process (front): ";
            todoQueue.front()->display();
        }
    }

    bool isEmpty() const {
        return todoQueue.empty();
    }

    size_t getSize() const {
        return todoQueue.size();
    }
};

class TodoApp {
private:
    TodoManager manager;

    void displayMenu() const {
        std::cout << "\n╔══════════════════════════════════╗" << std::endl;
        std::cout << "║        📝 TODO LIST APP         ║" << std::endl;
        std::cout << "╠══════════════════════════════════╣" << std::endl;
        std::cout << "║  1.  Add Todo                  ║" << std::endl;
        std::cout << "║  2. Delete Todo (FIFO)        ║" << std::endl;
        std::cout << "║  3. Delete Specific Todo     ║" << std::endl;
        std::cout << "║  4.  Delete All Todos        ║" << std::endl;
        std::cout << "║  5. Display All Todos        ║" << std::endl;
        std::cout << "║  6. Show Queue Info         ║" << std::endl;
        std::cout << "║  7. Exit                     ║" << std::endl;
        std::cout << "╚══════════════════════════════════╝" << std::endl;
        std::cout << "Enter your choice (1-7): ";
    }

    void addTodoUI() {
        std::string description;
        std::cout << "Enter todo description: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, description);
        manager.addTodo(description);
    }

    void deleteTodoUI() {
        if (manager.isEmpty()) {
            std::cout << "No todos to delete!" << std::endl;
            return;
        }
        
        std::cout << "⚠️  This will delete the OLDEST todo (FIFO principle)" << std::endl;
        std::cout << "Confirm deletion? (y/n): ";
        char confirm;
        std::cin >> confirm;
        
        if (confirm == 'y' || confirm == 'Y') {
            manager.deleteTodo();
        } else {
            std::cout << "Deletion cancelled." << std::endl;
        }
    }

    void deleteSpecificTodoUI() {
        if (manager.isEmpty()) {
            std::cout << "No todos to delete!" << std::endl;
            return;
        }
        
        manager.displayTodos();
        std::cout << "Enter the ID of todo to delete: ";
        int id;
        std::cin >> id;
        
        std::cout << "Confirm deletion? (y/n): ";
        char confirm;
        std::cin >> confirm;
        
        if (confirm == 'y' || confirm == 'Y') {
            manager.deleteSpecificTodo(id);
        } else {
            std::cout << "Deletion cancelled." << std::endl;
        }
    }

public:
    void run() {
        std::cout << "\n🎯 Welcome to the FIFO Todo List Application!" << std::endl;
        std::cout << "This app uses a Queue (FIFO) data structure." << std::endl;
        
        int choice;
        do {
            displayMenu();
            std::cin >> choice;
            
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
                    if (!manager.isEmpty()) {
                        std::cout << "⚠️  This will delete ALL todos! (y/n): ";
                        char confirm;
                        std::cin >> confirm;
                        if (confirm == 'y' || confirm == 'Y') {
                            manager.deleteAllTodos();
                        } else {
                            std::cout << "Deletion cancelled." << std::endl;
                        }
                    } else {
                        std::cout << "No todos to delete!" << std::endl;
                    }
                    break;
                case 5:
                    manager.displayTodos();
                    break;
                case 6:
                    manager.displayQueueInfo();
                    break;
                case 7:
                    std::cout << "\n👋 Thank you for using Todo App! Goodbye!" << std::endl;
                    break;
                default:
                    std::cout << "❌ Invalid choice! Please enter a number between 1-7." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (choice != 7);
    }
};

int main() {
    TodoApp app;
    app.run();
    return 0;
}