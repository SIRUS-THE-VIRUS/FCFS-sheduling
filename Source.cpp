#include <iostream>
#include <algorithm>
using namespace std;

class processes {
private:
	int arrival_time;
	int burst_time;
	int priority;
	int process_num;
	int order_of_execution;

public:
	processes() {
		this->arrival_time = 0;
		this->burst_time = 0;
		this->priority = 0;
		this->process_num = 0;
		this->order_of_execution = 0;
	}
	processes(int arrival_time, int burst_time, int priority, int process_num, int order_of_execution) {
		this->arrival_time = arrival_time;
		this->burst_time = burst_time;
		this->priority = priority;
		this->process_num = process_num;
		this->order_of_execution = order_of_execution;
	}

	int get_arrival_time() {
		return arrival_time;
	}
	int get_burst_time() {
		return burst_time;
	}
	int get_priority() {
		return priority;
	}
	int get_process_num(){
		return process_num;
	}
	int get_order_of_execution() {
		return order_of_execution;
	}
	void set_arrival_time(int arrival_time) {
		this->arrival_time = arrival_time;
	}
	void set_burst_time(int burst_time) {
		this->burst_time = burst_time;
	}
	void set_priority(int priority) {
		this->priority = priority;
	}
	void set_process_num(int process_num) {
		this->process_num = process_num;
	}
	void set_order_of_execution(int order_of_execution) {
		this->order_of_execution = order_of_execution;
	}
	void display() {
		cout << "Position in execution cycle: " << order_of_execution << endl;
		cout << "process num: " << process_num << endl;
		cout << "arrival time: " << arrival_time << endl;
		cout << "burst time: " << burst_time << endl;
		cout << "priority: " << priority << endl << endl;
	}
};

bool compareTwoprocesses(processes a, processes b)
{
	if (a.get_arrival_time() != b.get_arrival_time())
		return a.get_arrival_time() < b.get_arrival_time();

	if (a.get_priority() != b.get_priority())
		return a.get_priority() < b.get_priority();

	return (a.get_process_num() < b.get_process_num());

}

void computeOrderOfExecution(processes a[], int n)
{
	sort(a, a + n, compareTwoprocesses);
	for (int i = 0; i < n; i++)
		a[i].set_order_of_execution(i+1);
}

int main() {
	processes Pobj[99];
	int temp;
	int num_processes;
	cout << "Enter number of processes" << endl;
	cin >> num_processes;
	for (int i=0; i < num_processes; i++) {
		Pobj[i].set_process_num(i);
		cout << "Enter process arrival time" << endl;
		cin >> temp;
		Pobj[i].set_arrival_time(temp);
		cout << "Enter process burst time" << endl;
		cin >> temp;
		Pobj[i].set_burst_time(temp);
		cout << "Enter process priority" << endl;
		cin >> temp;
		Pobj[i].set_priority(temp);
	}
	cout << endl << endl;
	computeOrderOfExecution(Pobj, num_processes);
	for (int i = 0; i < num_processes; i++) {
		Pobj[i].display();
	}

	return 0;
}
