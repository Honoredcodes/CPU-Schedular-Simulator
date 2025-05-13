#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>

class DataStructures {
public:
    struct Queue {
        int dequeue() {}
        void enqueue() {}
        void initQueue() {}
        bool queueIsEmpty() {}
        bool queueIsFull() {}
    };

    struct Stack {
        int pop() {}
        void push() {}
        void initStack() {}
        bool stackIsEmpty() {}
        bool stackIsFull() {}
    };

    struct LinkedList {};
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