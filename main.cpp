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
        int front, rear;
        int size;
        int dequeue() {}
        void enqueue() {}
        void initQueue() {}
        bool queueIsEmpty() {}
        bool queueIsFull() {

        }
    };

    struct Stack {
        int top;
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
                }
                else {
                    tail->next = newProcess;
                    tail = newProcess;
                }
            }
            file.close();
            processObj = head;
            return true;
        }
        bool write(const std::string algorithm, const std::string filename, Results& resultObj) {
            const std::string filepath = fs::path("logs") / filename;
            std::ofstream file(filepath, std::ios::app);
            if (!file) return false;
            file << "Algorithm: " << algorithm << "\n";
            file << "Total Waiting Time: " << resultObj.totalwaiting << "\n";
            file << "Total Turnaround Time: " << resultObj.totalturnaround << "\n";
            file << "Total Completion Time: " << resultObj.totalcompletion << "\n";
            file << "Average Waiting Time: " << resultObj.averagewaiting << "\n";
            file << "Average Turnaround Time: " << resultObj.averageturnaround << "\n";
            file << "Average Completion Time: " << resultObj.averagecompletion << "\n\n";
            file.close();
            return true;
        }
    };
};


class algorithms : public schedular {
public:
    void FCFS(const std::string input, const std::string output, Process* processObj, Results* resultObj) {
        std::cout << "First Come, First Serve in progress.\n";
        filereaders fileReader;
        fileReader.read(input, processObj);
        Process* current = processObj;
        int time = 0, count = 0;
        while (current) {
            if (time < current->arrival_time) time = current->arrival_time;
            time += current->burst_time;
            resultObj->totalwaiting += time - current->arrival_time - current->burst_time;
            resultObj->totalturnaround += time - current->arrival_time;
            resultObj->totalcompletion += time;
            current = current->next;
            count++;
        }
        resultObj->averagewaiting = resultObj->totalwaiting / count;
        resultObj->averageturnaround = resultObj->totalturnaround / count;
        resultObj->averagecompletion = resultObj->totalcompletion / count;
        fileReader.write("FCFS", output, *resultObj);
        std::cout << "First Come, First Serve completed.\n";
    }

    void RoundRobin(const std::string input, const std::string output, int quantum, Process* processObj, Results* resultObj) {
        std::cout << "Round Robin in progress.\n";
        filereaders fileReader;
        fileReader.read(input, processObj);
        Process* current = processObj;
        int time = 0;
        while (current) {
            if (current->arrival_time <= time) {
                if (current->burst_time > quantum) {
                    time += quantum;
                    current->burst_time -= quantum;
                }
                else {
                    time += current->burst_time;
                    resultObj->totalwaiting += time - current->arrival_time - current->burst_time;
                    resultObj->totalturnaround += time - current->arrival_time;
                    resultObj->totalcompletion += time;
                    current->burst_time = 0;
                }
            }
            current = current->next;
        }
        resultObj->averagewaiting = resultObj->totalwaiting / 5;
        resultObj->averageturnaround = resultObj->totalturnaround / 5;
        resultObj->averagecompletion = resultObj->totalcompletion / 5;
        fileReader.write("Round Robin", output, *resultObj);
        std::cout << "Round Robin completed.\n";
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