#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void makeWordLadder(string startWord, string endWord){

    queue<stack<string> > Q;
    stack<string> wordladder;

    stack<string> myStack;
    myStack.push(startWord);
    Q.push(myStack);
    
    string token;
    ifstream file("EnglishWords.dat");
    set<string> wordList;
    set<string> testedWords;
    
    if(file.is_open()) {
      
	      while (file >> token) {
	    	wordList.insert(token);
	      }
	      
	      while (!(Q.empty())) {

			stack<string> ladder = Q.front();
			Q.pop();
			string topWord = ladder.top();
		        
			if (topWord == endWord) {
			
			  cout << "The ladder: \n";
			  while(!ladder.empty()){
			  	wordladder.push(ladder.top());
			  	ladder.pop();
			  }
			  while(!wordladder.empty()){
			  	cout<<wordladder.top()<<" -> ";
			  	wordladder.pop();
			  }
			} else {
			  string test;
			  for (int i = 0; i < topWord.size(); i++) {
			    for (char j = 'a'; j <= 'z'; j++) {
			    test = topWord.substr(0, i) + j + topWord.substr(i + 1);
		            
			    if (wordList.count(test)) {
			      if (!testedWords.count(test)) {
				
						stack<string> copy = ladder;
						copy.push(test);
						Q.push(copy);
			      	}
			    }
		            
			    	testedWords.insert(test);
				}
			}
	      }
	    }
	    
    }else {
      cerr << "Couldn't open the dictionary" << endl;
    }
    
}


/* Main function */
int main() {
    
  	string startWord, endWord;
  	cout<<"Hello! Enter two words of the same length to generate \n";
    cout<<"the shortest word ladder between the words.\n\n";
    
	while (true) {
    cout << "Enter the first word: \n";
    cin>>startWord;
    
    cout << "Enter the second word: \n";
    cin>>endWord;
    
    if (startWord.length() == endWord.length()) {
      break;
    }
    cout << "Words must have same length!\n";;
  	} 
  	makeWordLadder(startWord, endWord);
    
  return 0;
}




