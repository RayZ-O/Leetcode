// Validate if a given string is numeric.

// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true

// Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. 

class Solution {
    enum State { START, GOT_DOT, GOT_SIGN, GOT_DIGIT, DOT_DIGIT, GOT_EXP, EXP_SIGN, DIGIT, GOT_SPACE };
public:
    bool isNumber(string s) {
        int i = 0;
        int size = s.size();
        State state = START;
        while (i < size) {
            char ch = s[i];
            switch(state) {
                case START:
                    switch(ch) {
                        case '.':
                            state = GOT_DOT;
                            break;
                        case '+': case '-':
                            state = GOT_SIGN;
                            break;
                        default:
                            if(isdigit(ch)) {
                                state = GOT_DIGIT;
                            } else if (ch == ' ') {
                                state = START;
                            } else {
                                return false;
                            }
                    }
                    break;
                case GOT_SIGN: 
                    switch(ch) {                                
                        case '.':
                            state = GOT_DOT;
                            break;
                        default:
                            if(isdigit(ch)) {
                                state = GOT_DIGIT;
                            } else {
                                return false;
                            }
                    }
                    break;
                case GOT_DOT:
                    if(isdigit(ch)) {
                        state = DOT_DIGIT;
                    } else {
                        return false;
                    }
                    break;  
                case DOT_DIGIT: 
                    switch(ch) {
                        case 'e': case 'E':
                            state = GOT_EXP;
                            break;
                        case ' ':
                            state = GOT_SPACE;
                            break;
                        default:
                            if(!isdigit(ch)) {
                                return false;
                            }
                    }
                    break; 
                case GOT_DIGIT:
                    switch(ch) {
                        case 'e':case'E':
                            state = GOT_EXP;
                            break;
                        case ' ':
                            state = GOT_SPACE;
                            break;
                        case '.':
                            state = DOT_DIGIT;
                            break;
                        default:
                            if(!isdigit(ch)) {                          
                                return false;
                            }
                    }
                    break;
                case GOT_EXP:
                    if(isdigit(ch)) {
                        state = DIGIT;
                    } else if (ch == '+' || ch == '-') {
                        state = EXP_SIGN;
                    } else {
                        return false;
                    }
                    break;
                case EXP_SIGN:
                    if(isdigit(ch)) {
                        state = DIGIT;
                    } else {
                        return false;
                    }
                    break;      
                case DIGIT:
                    if (ch == ' ') {
                        state = GOT_SPACE;
                    } else if (!isdigit(ch)) {
                        return false;
                    }
                    break;
                case GOT_SPACE:
                    if (ch != ' ') {
                        return false;
                    }
                    break;
            }
            i++;
        }
        vector<State> valid { GOT_DIGIT, DOT_DIGIT, DIGIT, GOT_SPACE };
        if (any_of(valid.begin(), valid.end(), [&](State &v){ return state == v; })) {
            return true;
        } else {
            return false;
        }
    }
};
