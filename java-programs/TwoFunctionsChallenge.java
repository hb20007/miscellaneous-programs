// Given only the following two functions and the two
// functions alone, construct another that determines
// the product of two positive integer inputs with
// using any arithmetic operands (+, -, *, /).
// (Hint: think Peano axioms)

import java.util.Scanner;

public class TwoFunctionsChallenge {
	static int addOne(int n) {
		return n + 1;
	}
	static int subOne(int num) {
		return num - 1;
	}

	static int product(int number1, int number2) {
		int result = number1;
		for (int i = number2; i > 1; i = subOne(i)) {
			for (int j = number1; j > 0; j = subOne(j)) {
				result = addOne(result);          // I had this wrong code here: addOne(result);
			}
		}
		return result;
	}

	public static void main(String[] args) {
		int int1, int2;
		Scanner in = new Scanner(System.in);
		System.out.println("Insert first number");
		int1 = in.nextInt();
		System.out.println("Insert second number");
		int2 = in.nextInt();
		in.close();
		System.out.println(int1 + " * " + int2 + " = " + product(int1, int2));
	}
}

//The better solution:
//	var add_one = function(n) {
//	   return n + 1;
//	}
//
//	var subtract_one = function(n) {
//	   return n - 1;
//	}
//
//	var sum = function(a, b) {
//	   if (b === 0) {
//	   		return a;
//	   } else {
//	   		return sum(add_one(a), subtract_one(b));
//	   };
//	}
//
//	var product = function(a, b) {
//		if (b == 1) {
//			return a;
//		} else {
//			return sum(a, product(a, subtract_one(b))); // This code sums a to itself as many times as b is greater than 1. Note subtract_one(b) will ultimately return a cuz when b becomes 0 this returns a so we just end up summing "a" a certain no of times
//		};
//	}
