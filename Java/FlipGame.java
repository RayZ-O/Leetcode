// You are playing the following Flip Game with your friend: Given a string that contains only these
// two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The
// game ends when a person can no longer make a move and therefore the other person will be the winner.

// Write a function to compute all possible states of the string after one valid move.

// For example, given s = "++++", after one move, it may become one of the following states:

// [
//   "--++",
//   "+--+",
//   "++--"
// ]
// If there is no valid move, return an empty list [].

public class FlipGame {
    public List<String> generatePossibleNextMoves(String s) {
        List<String> out = new ArrayList<>();
        char[] c = s.toCharArray();
        for (int i = 1; i < c.length; i++) {
            if (c[i] == '+' && c[i-1] == '+') {
                c[i] = '-';
                c[i-1] = '-';
                out.add(new String(c));
                c[i] = '+';
                c[i-1] = '+';
            }
        }
        return out;
    }
}
