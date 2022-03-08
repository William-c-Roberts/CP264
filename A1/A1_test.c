/**
 -------------------------
 CP264 (Winter 2020)
 Assignment: A1
 Testing File
 -------------------------
 **/

# include <stdio.h>
# include "A1.h"

void test_calculate_cost();
void test_find_promotion();
void test_mini_calculator();
void test_mini_calculator2();

int main() {
	setbuf(stdout, NULL);
	test_calculate_cost();
	test_find_promotion();
	test_mini_calculator();
	test_mini_calculator2();
	return 0;
}

void test_calculate_cost() {
	printf("Start: Testing calculate_cost:\n\n");
	calculate_cost(15, 23, 8, 5, 3);
	printf("\n");
	calculate_cost(9.02, 14.3, 5.28, 4.0, 2.11);
	printf("\n");

	printf("End: Testing calculate_cost\n");
	printf("------------------------------\n\n");
	return;
}

void test_find_promotion() {
	printf("Start: Testing find_promotion:\n\n");
	find_promotion(-1, 'Y');
	printf("\n\n");

	printf("find_promotion(10,'U'):\n");
	find_promotion(10, 'U');
	printf("\n\n");

	printf("find_promotion(15,'N'):\n");
	find_promotion(15, 'N');
	printf("\n\n");

	printf("find_promotion(60,'N'):\n");
	find_promotion(60, 'N');
	printf("\n\n");

	printf("find_promotion(30,'Y'):\n");
	find_promotion(30, 'Y');
	printf("\n\n");

	printf("find_promotion(40,'N'):\n");
	find_promotion(40, 'N');
	printf("\n\n");

	printf("find_promotion(200,'N'):\n");
	find_promotion(200, 'N');
	printf("\n\n");

	printf("find_promotion(110,'Y'):\n");
	find_promotion(110, 'Y');
	printf("\n\n");

	printf("find_promotion(500,'N'):\n");
	find_promotion(500, 'N');
	printf("\n\n");

	printf("End: Testing find_promotion\n");
	printf("------------------------------\n\n");

	return;
}

void test_mini_calculator() {
	printf("Start: Testing mini_calculator:\n\n");
	printf("3 # 5 = %d\n", mini_calculator(3, 5, '#'));
	printf("10 # 0 = %d\n", mini_calculator(10, 0, '#'));
	printf("\n");

	printf("3 + 5 = %d\n", mini_calculator(3, 5, '+'));
	printf("10 + 0 = %d\n", mini_calculator(10, 0, '+'));
	printf("\n");

	printf("3 - 5 = %d\n", mini_calculator(3, 5, '-'));
	printf("10 - 0 = %d\n", mini_calculator(10, 0, '-'));
	printf("\n");

	printf("3 * 5 = %d\n", mini_calculator(3, 5, '*'));
	printf("10 * 0 = %d\n", mini_calculator(10, 0, '*'));
	printf("\n");

	printf("5 / 2 = %d\n", mini_calculator(5, 2, '/'));
	printf("3 / 5 = %d\n", mini_calculator(3, 5, '/'));
	printf("10 / 0 = %d\n", mini_calculator(10, 0, '/'));
	printf("\n");

	printf("5 %% 2 = %d\n", mini_calculator(5, 2, '%'));
	printf("3 %% 5 = %d\n", mini_calculator(3, 5, '%'));
	printf("10 %% 0 = %d\n", mini_calculator(10, 0, '%'));
	printf("10 %% -2 = %d\n", mini_calculator(10, -2, '%'));
	printf("-100 %% 7 = %d\n", mini_calculator(-100, 7, '%'));
	printf("\n");

	printf("5 ^ 3 = %d\n", mini_calculator(5, 3, '^'));
	printf("3 ^ -5 = %d\n", mini_calculator(3, -5, '^'));
	printf("10 ^ 0 = %d\n", mini_calculator(10, 0, '^'));
	printf("0 ^ 0 = %d\n", mini_calculator(0, 0, '^'));
	printf("0 ^ 3 = %d\n", mini_calculator(0, 3, '^'));
	printf("\n");

	printf("End: Testing mini_calculator\n");
	printf("------------------------------\n\n");

	return;
}

void test_mini_calculator2() {
	printf("Start: Testing mini_calculator2:\n\n");

	//min for int = -2147483648, max for int = 2147483647
	//Min for short = -32768, max for short = 32767

	mini_calculator2(3, 5, '#');
	printf("\n");

	mini_calculator2(3, 5, '+');
	mini_calculator2(32767, 32767, '+');
	mini_calculator2(-32767, 0, '+');
	printf("\n");

	mini_calculator2(3, 5, '-');
	mini_calculator2(-32768, 32767, '-');
	mini_calculator2(-32768, 1, '-');
	printf("\n");

	mini_calculator2(3, 5, '*');
	mini_calculator2(32767, 32767, '*');
	mini_calculator2(32767, -32768, '*');
	printf("\n");

	mini_calculator2(5, 2, '/');
	mini_calculator2(1, 3, '/');
	mini_calculator2(10, 0, '/');
	printf("\n");

	mini_calculator2(5, 2, '%');
	mini_calculator2(3, 5, '%');
	mini_calculator2(10, 0, '%');
	mini_calculator2(10, -2, '%');
	mini_calculator2(-100, 7, '%');
	printf("\n");

	mini_calculator2(5, 3, '^');
	mini_calculator2(3, -5, '^');
	mini_calculator2(10, 0, '^');
	mini_calculator2(0, 0, '^');
	mini_calculator2(0, 3, '^');
	mini_calculator2(327, 100, '^');
	mini_calculator2(200, 300, '^');
	printf("\n");

	printf("End: Testing mini_calculator2\n");
	printf("------------------------------\n\n");
	return;
}
