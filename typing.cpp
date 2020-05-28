#include <iostream>
#include <string> 
#include <chrono>
#include <ctime> 
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std; 

int presentation();
int game(char selected[4][50], string difficultyMode);

int main () 
{
	
	presentation();
	char flag = '1';
	while (flag == '1'){
		
		string difficulty;
		cout << "\n\n Choose a difficulty \n";
		cout << " 1. Easy \n 2. Medium \n 3. Hard \n Option: ";
		cin  >> difficulty;
		cin.ignore();
		cout << "Selected difficulty: " << difficulty << "\n";
	
			if(difficulty == "1") {
				char easy[4][50] = {"Python its the best language", "Alaska is the largest state of the US",
				"Lenovo is the best laptop brand", "Im an student of FCFM"};
				string difficultyMode = "easy";
				game(easy, difficultyMode);
			}
		char s;
		cout << "Play again? [1: Yes, 2: No]: ";
		cin >> s;
		flag = s;
	}
	
	
	
	return 0;
}

int presentation() {
	cout << "\n\t\t English Typing Speed \n";
	cout << "\t Are you fast and accurate enough? \n";
}

int game(char selected[4][50], string difficultyMode){
	
	int correct = 0;
	double accuracy = 0;
	
	double avgAccuracy = 0;
	double avgTime = 0;
	
	for (int i = 0; i < 4; i++){
		
		cout << " \n\t\t SENTENCE \n\n ";
		cout << selected[i] << "\n\n";
		
		int lengthSentence = 0;	
		
		for(int j = 0; j < 50; j++) {
			char mychar = selected[i][j];
			if (isalpha(mychar) != 0 || isspace(mychar) == 8){
				lengthSentence++;
			}
		}
		
		//cout << "Length of sentence: " << lengthSentence << "  \n";
		
		auto start = std::chrono::system_clock::now();
		
		cout << "Type here: ";
		string response;
		getline(cin, response);
		
		auto end = std::chrono::system_clock::now();
		
		correct = 0;
		accuracy = 0;
		
		int sizeResponse = response.length();
		
		for(int j = 0; j < sizeResponse; j++) {
			std::string letterR(1, response[j]); // cast to string
			std::string letterUser(1, selected[i][j]);
			
			correct = correct + (letterR == letterUser);
		}
		cout << "Correct characters: " << correct << " of " << lengthSentence << "\n";
		
		accuracy = ((double)correct / lengthSentence) * 100; // casting
		avgAccuracy = avgAccuracy + accuracy;
		cout << " Accuracy: " << accuracy << "% \n\n";
		
		std::chrono::duration<double> elapsed_seconds = end-start;
		
		avgTime = avgTime + elapsed_seconds.count();
		cout << " Time spend: " << elapsed_seconds.count() << " seconds\n\n";
		system("pause");
	}
	
	avgAccuracy = avgAccuracy / 4;
	avgTime = avgTime / 4;
	
	cout << "\n\n\t\t STATS on " << difficultyMode << " mode \n\n";
	cout << " Average Accuracy: " << avgAccuracy << "% \n\n";
	cout << " Average Time: " << avgTime << " seconds \n\n";
	
	
}



