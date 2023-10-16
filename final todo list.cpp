#include <iostream>
#include <vector>
#include <string>

// Task structure to store task details
struct Task {
    std::string description;
    bool completed;
};

// Function to add a task to the to-do list
void AddTask(std::vector<Task>& todoList, const std::string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    todoList.push_back(newTask);
    std::cout << "Task added: " << description << std::endl;
}

// Function to view tasks in the to-do list
void ViewTasks(const std::vector<Task>& todoList) {
    if (todoList.empty()) {
        std::cout << "No tasks in the to-do list." << std::endl;
        return;
    }

    std::cout << "To-Do List:" << std::endl;
    for (size_t i = 0; i < todoList.size(); ++i) {
        std::cout << i + 1 << ". ";
        if (todoList[i].completed) {
            std::cout << "[X] ";
        } else {
            std::cout << "[ ] ";
        }
        std::cout << todoList[i].description << std::endl;
    }
}

// Function to delete a task from the to-do list
void DeleteTask(std::vector<Task>& todoList, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= todoList.size()) {
        std::cout << "Task deleted: " << todoList[taskIndex - 1].description << std::endl;
        todoList.erase(todoList.begin() + taskIndex - 1);
    } else {
        std::cout << "Invalid task index. Please try again." << std::endl;
    }
}

int main() {
    std::vector<Task> todoList;

    while (true) {
        std::cout << "Options:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Delete Task" << std::endl;
        std::cout << "4. Quit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 4) {
            std::cout << "Goodbye!" << std::endl;
            break;
        }

        switch (choice) {
            case 1: {
                std::cin.ignore(); // Clear the newline character from the input buffer
                std::string description;
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                AddTask(todoList, description);
                break;
            }
            case 2:
                ViewTasks(todoList);
                break;
            case 3: {
                int taskIndex;
                std::cout << "Enter the task index to delete: ";
                std::cin >> taskIndex;
                DeleteTask(todoList, taskIndex);
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

