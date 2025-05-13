#include <iostream>

class DataStructures {
public:
    void Queue() {
        std::cout << "This is queue\n";
    }
    void Stack() {
        std::cout << "This is stac;\n";
    }
    void LinkedList() {
        std::cout << "This is LL\n";
    }
};

class algorithms {
public:
    void FCFS() {
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

class schedular {
    struct Process {
        int process_id, arrival_time, burst_time, priority;
        Process* next = nullptr;
    };

    struct SimulationResult {
        int waiting, turnaround, completion;
    };
};

int main() {
    return 0;
}