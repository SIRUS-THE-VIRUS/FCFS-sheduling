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
	}
	processes(int arrival_time, int burst_time, int priority, int process_num) {
		this->arrival_time = arrival_time;
		this->burst_time = burst_time;
		this->priority = priority;
		this->process_num = process_num;
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
		cout << "Position in execution cycle: " << order_of_execution << "\n" << endl;
		cout << "process num: " << process_num << endl;
		cout << "arrival time: " << arrival_time << endl;
		cout << "burst time: " << burst_time << endl;
		cout << "priority: " << priority << endl;
	}
};

bool compareTwoprocesses(processes a, processes b)
{
	// If total marks are not same then 
	// returns true for higher total 
	if (a.get_arrival_time() != b.get_arrival_time())
		return a.get_arrival_time() < b.get_arrival_time();

	// If marks in Maths are not same then 
	// returns true for higher marks 
	if (a.get_priority() != b.get_priority())
		return a.get_priority() < b.get_priority();

	return (a.get_process_num() < b.get_process_num());

}
// Fills total marks and ranks of all Students 
void computeRanks(processes a[], int n)
{
	// Sort structure array using user defined 
	// function compareTwoStudents() 
	sort(a, a + n, compareTwoprocesses);

	// Assigning ranks after sorting 
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
	computeRanks(Pobj, num_processes);
	for (int i = 0; i < num_processes; i++) {
		Pobj[i].display();
	}





	return 0;
}