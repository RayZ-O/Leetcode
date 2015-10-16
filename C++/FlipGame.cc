// You are playing the following Flip Game with your friend: Given a string
// that contains only these two characters: + and -, you and your friend take
// turns to flip two consecutive "++" into "--". The game ends when a person
// can no longer make a move and therefore the other person will be the winner.

// Write a function to compute all possible states of the string after one valid move.

// For example, given s = "++++", after one move, it may become one of the following states:

// [
//   "--++",
//   "+--+",
//   "++--"
// ]
// If there is no valid move, return an empty list [].

class Solution {
    string flip(string base, int pos) {
        return base.replace(pos, 2, "--");
    }
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> output;
        int end = s.size() - 1;
        for (int i = 0; i < end; i++) {
            if (s[i] == '-')
                continue;
            else if (s[i+1] == '+')
                output.push_back(flip(s, i));
            else
                i++;
        }
        return output;
    }
};
