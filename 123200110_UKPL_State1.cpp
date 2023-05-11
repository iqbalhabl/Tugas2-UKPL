#include <iostream>
using namespace std;

enum State {
    OFF,
    STARTUP,
    IDLE,
    RUNNING,
    ERROR
};

State getNextState(State current, int input) {
    switch(current) {
        case OFF:
            if(input == 1) {
                return STARTUP;
            }
            break;
        case STARTUP:
            if(input == 0) {
                return IDLE;
            } else if(input == 1) {
                return ERROR;
            }
            break;
        case IDLE:
            if(input == 1) {
                return RUNNING;
            } else if(input == 2) {
                return ERROR;
            }
            break;
        case RUNNING:
            if(input == 0) {
                return IDLE;
            } else if(input == 2) {
                return ERROR;
            }
            break;
        case ERROR:
            return ERROR;
    }
    return current;
}

int main() {
    State currentState = OFF;

    int inputSequence[] = {1, 0, 1, 1, 0, 2};
    int inputSize = sizeof(inputSequence) / sizeof(int);

    for(int i = 0; i < inputSize; i++) {
        State nextState = getNextState(currentState, inputSequence[i]);
        cout << "State: " << currentState << " Input: " << inputSequence[i] << " Next State: " << nextState << endl;
        currentState = nextState;
    }

    return 0;
}

