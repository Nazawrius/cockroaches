#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void header(){
	cout << "--------------------------\n";
	cout << "-----Cockroach Racing-----\n";
	cout << "--------------------------\n";
}

int main(){
	srand(time(NULL));
	int correct_gueses = 0;
	string state = "main menu";
	int cockroach_number = 0;
	int cockroaches[10][5];
	int favourite = 0;
	int tasty_legs = 0;
	int first = true;

	system("clear");
	header();
	cout << "Greetings, stranger!\n";
	cout << "type \"help\" for list of all availible commands\n";

	while(true){
		if(!first){
			header();
		}
		first = false;
		if(correct_gueses > 0){
			cout << "Correct gueses: " << correct_gueses << "\n";
		}
		if(cockroach_number){
			cout << "--------------------------\n";
			for(int i = 0; i < cockroach_number; ++i){
				cout << "Cockroach " << i << ", Health: " << cockroaches[i][2];
				cout << ", Experience: " << cockroaches[i][3] << "\n";
			}
			cout << "--------------------------\n";
		}
		if(favourite){
			cout << "--------------------------\n";
			cout << "Your favourite is cockroach number " << favourite << "\n";
			cout << "--------------------------\n";
		}

		string s;
		cin >> s;
    	if(s == "help"){
    		cout << "help - ouputs list of all availible commands\n";
    		cout << "gather <number> - gathers given number cockroaches for a race\n";
    		cout << "guess <number> - places your guess on the cockroach\n";
    		cout << "start race - starts the race\n";
    		cout << "exit - exits the game\n";
    		string ok;
			cout << "Type ok to continue: "; 
			cin >> ok;
    		system("clear");
    		continue;
    	}

    	if(s == "gather"){
    		int n;
    		cin >> n;
    		if(n <= 0){
    			cout << "Invalid number of cockroaches\n";
    			string ok;
			    cout << "Type ok to continue: "; 
			    cin >> ok;
    			system("clear");
    			continue;
    		}
    		cockroach_number = n;
    		for(int i = 0; i < cockroach_number; ++i){
    			cockroaches[i][0] = 6;
    			cockroaches[i][1] = 1 + rand() % 15;
    			cockroaches[i][2] = 50 + rand() % 50;
    			cockroaches[i][3] = rand() % 100;
    			cockroaches[i][4] = 0;
    		}
    		state = "gathered";
    		string ok;
			cout << "Type ok to continue: "; 
			cin >> ok;
    		system("clear");
    		continue;
    	}

    	if(s == "start"){
    		cin >> s;
    		if(s == "race"){
    			if(state == "gathered"){
    				int track_length = 40 + rand() % 60;
					int gathered_legs = 0;

					while(true){

						system("clear");
						header();
						if(favourite){
							cout << "--------------------------\n";
							cout << "Your favourite is cockroach number " << favourite << "\n";
							cout << "--------------------------\n";
						}

						for(int i = 0; i < cockroach_number; ++i){
							cout << "Cockroach " << i << "\t";

							int step_length = floor((4 + (rand() % 20) / 20) * (cockroaches[i][0] / 6.0) * (cockroaches[i][2] / 100.0) * (1.0 + cockroaches[i][3] / 100.0));
							cockroaches[i][4] += step_length;

							int break_chance = rand() % 50;
							if(break_chance < 10){
								cockroaches[i][0]--;
								gathered_legs += 1;
							}

							for(int i = 0; i < cockroaches[i][4]; ++i){
								cout << '.';
							}
							cout << "C";

							for(int i = cockroaches[i][4] + 1; i <= track_length; ++i){
								cout << '.';
							}
							cout << "\n";
						}

						float max_pos = track_length;
						int winner = -1;
						for(int i = 0; i < cockroach_number; ++i){
							if(cockroaches[i][4] >= max_pos){
								max_pos = cockroaches[i][4];
								winner = i;
							}
						}

						if(winner != -1){
							cout << "The winner is cockroach number " << winner + 1 << "\n";
							if(favourite == winner){
								cout << "You guessed right!\n";
								correct_gueses++;
							}
							else{
								cout << "You didn't guess right!\n";
							}
							string ok;
						    cout << "Type ok to continue: "; 
						    cin >> ok;
							break;
						}

						string ok;
					    cout << "Type ok to continue: "; 
					    cin >> ok;
					}
    				tasty_legs += gathered_legs;
    				string ok;
				    cout << "Type ok to continue: "; 
				    cin >> ok;
    				system("clear");
    				continue; 
    			}
    			else{
    				cout << "You need to gather cockroaches first\n";
    				string ok;
				    cout << "Type ok to continue: "; 
				    cin >> ok;
    				system("clear");
    				continue; 
    			}
    		}
    		else{
    			cout << "Unknown command\n";
    			string ok;
			    cout << "Type ok to continue: "; 
			    cin >> ok;
    			system("clear");
    			continue;
    		}
    	}

    	if(s == "guess"){
    		int n;
    		cin >> n;
    		if(n <= 0 or n > cockroach_number){
    			cout << "Invalid favourite\n";
    			string ok;
			    cout << "Type ok to continue: "; 
			    cin >> ok;
    			system("clear");
    			continue;
    		}
    		favourite = n;
    		string ok;
			cout << "Type ok to continue: "; 
			cin >> ok;
    		system("clear");
    		continue;
    	}

    	if(s == "exit"){
    		break;
    	}

    	cout << "Unknown command\n";
    	string ok;
    	cout << "Type ok to continue: "; 
    	cin >> ok;
    	system("clear");
 
    }
    cout << "Bye, friend! You earned " << tasty_legs << " tasty legs\n";
    string ok;
    cout << "Type ok to continue: "; 
    cin >> ok;
	return 0;
}