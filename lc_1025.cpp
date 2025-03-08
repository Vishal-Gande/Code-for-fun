// I'd not have thought about the soln myself

// read below from discussions

// For the specific problem of Alice and Bob playing a game where they each choose divisors until they can't anymore, the optimal strategy does not come directly from number theory. It's more a consequence of the specific rules of the game and the properties of odd and even numbers.

// When it comes to finding optimal strategies in games, it often comes down to experience, intuition, and a systematic analysis of the game. For this problem, analyzing the outcomes for small values of n reveals a pattern: Alice wins when n is even and loses when n is odd. This is an observation that doesn't require deep mathematical theory.

// However, understanding why this pattern occurs does involve some mathematical reasoning. In this game, the only move that can change the parity (evenness or oddness) of the number on the chalkboard is subtracting 1. Hence, if Alice starts with an even number, she can always subtract 1 to give Bob an odd number. And since all divisors of an odd number are odd, Bob can only give Alice an even number. This way, Alice can ensure that she always plays on even numbers and Bob always plays on odd numbers, which ensures that Bob will eventually receive a 1 and lose the game.

// This kind of mathematical reasoning and strategy deduction is often necessary in competitive programming problems and game theory problems. While deep mathematical theory isn't always required, a solid understanding of basic mathematical properties and problem-solving skills can be very helpful.

class Solution {
public:
    bool divisorGame(int n) {

        // if n is even, whoever starts the game wins
        // if n is odd, whoever starts the game loses
        if(n%2 == 0) return true;

        return false;

    }
};