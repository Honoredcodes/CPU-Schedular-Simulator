#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
#include <filesystem>
#include <fstream>

// class DataStructures {Temp};
namespace fs = std::filesystem;
class schedular {
protected:
    struct Process {
        int process_id, arrival_time, burst_time, priority;
        Process* next = nullptr;
        Process* prev = nullptr;
    };

    struct Results {
        int waiting, turnaround, completion;
        int totalturnaround, totalwaiting, totalcompletion;
        long averageturnaround, averagewaiting, averagecompletion;
        Results* next = nullptr;
        Results* prev = nullptr;
    };

public:
    struct Queue {
        int dequeue() {}
        void enqueue() {}
        void initQueue() {}
        bool queueIsEmpty() {}
        bool queueIsFull() {

        }
    };

    struct Stack {
        int pop() {}
        void push() {}
        void initStack() {}
        bool stackIsEmpty() {}
        bool stackIsFull() {}
    };

    struct filereaders {
        bool read(const std::string filename, Process*& processObj) {
            const std::string filepath = fs::path("logs") / filename;
            std::ifstream file(filepath);
            if (!file) return false;
            Process* head = nullptr;
            Process* tail = nullptr;
            std::string line;
            while (std::getline(file, line)) {
                std::string delimiter = ":";
                size_t pos = 0;
                int i = 0;
                Process* newProcess = new Process();
                newProcess->next = nullptr;
                while ((pos = line.find(delimiter)) != std::string::npos) {
                    std::string token = line.substr(0, pos);
                    if (i == 0) newProcess->process_id = std::stoi(token);
                    else if (i == 1) newProcess->arrival_time = std::stoi(token);
                    else if (i == 2) newProcess->burst_time = std::stoi(token);
                    else if (i == 3) newProcess->priority = std::stoi(token);
                    line.erase(0, pos + delimiter.length());
                    i++;
                }
                newProcess->priority = std::stoi(line);
                if (!head) {
                    head = newProcess;
                    tail = newProcess;
                } else {
                    tail->next = newProcess;
                    tail = newProcess;
                }
            }
            file.close();
            processObj = head;
            return true;
        }
        void write() {}
    };
};


class algorithms : public schedular {
public:
    void FCFS(Process* processObj, Results* resultObj) {
        std::cout << "This is fcfs\n";
    }
    void RoundRobin() {
        std::cout << "This is RR\n";
    }
    void SJFPreemptive() {
        std::cout << "This is SJF Pre\n";
    }
    void SJFNonPreemptive() {
        std::cout << "This is SJF Non\n";
    }
    void PriorityPreemptive() {
        std::cout << "This is priority Pre\n";
    }
    void PriorityNonPreemptive() {
        std::cout << "This is priority non\n";
    }
};

int main() {
    return 0;
}