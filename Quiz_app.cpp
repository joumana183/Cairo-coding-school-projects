#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Questions {
    string question;
    string choices[4];
    char correct;
};

void displayQuestion(Questions q) {
    cout << q.question << endl;

    for (int i = 0; i<4; i++) {
        cout << q.choices[i] << endl;
    }
}

char getAnswer() {
    char answer;
    cout << "Your answer: ";
    cin >> answer;
    answer = tolower(answer);
    while (answer < 'a'|| answer > 'd') {
        cout << "Invalid choice! Enter A, B, C, or D: ";
        cin >> answer;
        answer = tolower(answer);
    }
    return answer;
}

bool isCorrect(char answer, char correct) {
    return answer==correct;
}
int main() {

    Questions quiz[5] = {
        {   "What does OOP stand for?",
            {"A) Object Oriented Programming", "B) Only One Program",
             "C) Open Output Protocol", "D) Object Output Process"},
            'a'
        },
        {   "Which concept allows a class to inherit properties and methods from another class?",
            {"A) Encapsulation", "B) Inheritance",
             "C) Polymorphism", "D) Abstraction"},
            'b'
        },
        {   "What is encapsulation in OOP?",
            {"A) Creating multiple objects",
             "B) Bundling data and methods together and controlling access",
             "C) Deriving a class from another class",
             "D) Creating many functions with the same name"},
            'b'
        },
        {   "What is inheritance in OOP?",
            {"A) Hiding data from other classes",
             "B) Creating objects from functions",
             "C) A class acquiring properties and methods from another class",
             "D) Changing the value of a variable"},
            'c'
        },
        {   "What is polymorphism in OOP?",
            {"A) One interface with multiple possible behaviors",
             "B) Protecting data using private members",
             "C) Creating a constructor",
             "D) Copying one object into another"},
            'a'
        }
    };

    int score = 0;
    cout << "=== Quiz App ===" << endl;
    for (int i = 0; i <5; i++) {
        cout << "Q" << i + 1 << ": ";
        displayQuestion(quiz[i]);
        char answer = getAnswer();
        if (isCorrect(answer, quiz[i].correct)) {
            cout << "Correct!" << endl;
            score++;
        }
        else {
            cout << "Wrong! Correct answer: "
                 << char(toupper(quiz[i].correct)) << endl;
        }
        cout << endl;
    }

    cout << "=== Quiz Complete ===" << endl;
    cout << "Score: " << score << " / " << 5 << endl;

    return 0;
}
