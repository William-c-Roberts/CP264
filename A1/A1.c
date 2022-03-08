/**
 * -------------------------
 * Student Name:
 * Student ID:
 * Student email:
 * -------------------------
 */
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
#include <limits.h>
/**
 * CP264: Assignment 1 - Task 1
 * @param base_height
 * @param base_length
 * @param roof_height
 * @param door_height
 * @param door_length
 */
void calculate_cost(float base_height, float base_length, float roof_height,
		float door_height, float door_length) {
	float base_area;
	float door_area;
	float roof_area;
	float concrete_cost = 84.79;
	float shingles_cost = 11.91;
	float wood_cost = 8.73;
	float base_cost;
	float door_cost;
	float roof_cost;
	float total;

	door_area = door_height * door_length;
	base_area = (base_height * base_length) - door_area;
	roof_area = base_length * roof_height * (0.5);

	base_cost = base_area * concrete_cost;
	door_cost = door_area * wood_cost;
	roof_cost = roof_area * shingles_cost;

	total = base_cost + door_cost + roof_cost;

	printf("House Drawing dimensions (meters):\n");
	printf("BH = %-9.3fBL = %-8.3f\n", base_height, base_length);
	printf("RH = %-8.3f\n", roof_height);
	printf("DH = %-9.3fDL = %-8.3f\n\n", door_height, door_length);

	printf("House dimensions (square meter):\n");
	printf("Door area =%9.3f\n", door_area);
	printf("Base area =%9.3f\n", base_area);
	printf("Roof area =%9.3f\n\n", roof_area);

	printf("House cost (CAD):\n");
	printf("Door cost = $%8.3f\n", door_cost);
	printf("Base cost = $%8.3f\n", base_cost);
	printf("Roof cost = $%8.3f\n", roof_cost);
	printf("--------------------\n");
	printf("Total cost = $%.3f\n", total);

	return;
}

/**
 * CP264: Assignment 1 - Task 2
 *  [-:0):           Invalid
 *	[0:20):           No Promotion
 *	[20-35]:          Level 1 Promotion
 *	(35-50]:          Level 2 Promotion
 *	(50-100]:         No Promotion
 *	(100-200]+VIP:    Gold Promotion
 *	(100-200]-VIP:    Silver Promotion
 *	(200, -]:         Special Promotion
 * @param ticket
 * @param vip
 */
void find_promotion(short ticket, char vip) {
	if (vip == 'Y') {
		if (ticket < 0) {
			printf(
					"Ticket# VIP-%d: Error(find_promotion): Invalid input - Code# -99",
					ticket);
		} else if (ticket >= 0 && ticket < 20) {
			printf("Ticket# VIP-%d: No Promotion - Code# 0", ticket);

		} else if (ticket >= 20 && ticket <= 35) {
			printf("Ticket# VIP-%d: Level 1 Promotion - Code# 130", ticket);

		} else if (ticket > 35 && ticket <= 50) {
			printf("Ticket# VIP-%d: Level 2 Promotion - Code# 240", ticket);

		} else if (ticket > 50 && ticket <= 100) {
			printf("Ticket# VIP-%d: No Promotion - Code# 0", ticket);

		} else if (ticket > 100 && ticket <= 200) {
			printf("Ticket# VIP-%d: Gold Promotion - Code# 1110", ticket);

		} else {
			printf("Ticket# VIP-%d: Special Promotion - Code# 3333", ticket);
		}
	} else if (vip == 'N') {
		if (ticket < 0) {
			printf(
					"Ticket# %d: Error(find_promotion): Invalid input - Code# -99",
					ticket);
		} else if (ticket >= 0 && ticket < 20) {
			printf("Ticket# %d: No Promotion - Code# 0", ticket);

		} else if (ticket >= 20 && ticket <= 35) {
			printf("Ticket# %d: Level 1 Promotion - Code# 130", ticket);

		} else if (ticket > 35 && ticket <= 50) {
			printf("Ticket# %d: Level 2 Promotion - Code# 240", ticket);

		} else if (ticket > 50 && ticket <= 100) {
			printf("Ticket# %d: No Promotion - Code# 0", ticket);

		} else if (ticket > 100 && ticket <= 200) {
			printf("Ticket# %d: Silver Promotion - Code# 700", ticket);

		} else {
			printf("Ticket# %d: Special Promotion - Code# 3333", ticket);
		}
	} else {
		printf("Ticket# %d: Error(find_promotion): Invalid input - Code# -99",
				ticket);
	}
}

/**
 * Assignment 1 - Task 3
 * @param num1 (short int)
 * @param num2 (short int)
 * @param opr + , - , * , / , % , ^ (char)
 * @return result (int)
 */
int mini_calculator(short num1, short num2, char opr) {
	if (opr == '+')
		goto addition;

	if (opr == '-')
		goto subtrction;

	if (opr == '*')
		goto multiplcation;

	if (opr == '/' && num2 != 0)
		goto division;

	if (opr == '%' && (num1 < 0 || num2 < 0))
		goto division;

	if (opr == '%' && num2 != 0)
		goto moduls;

	if (opr == '^' && num2 >= 0)
		goto power;

	return -99;

	addition: return (num1 + num2);

	subtrction: return (num1 - num2);

	multiplcation: return (num1 * num2);

	division: return (num1 / num2);

	moduls: return (num1 % num2);

	power: return pow(num1, num2);

}

/**
 * Assignment 1 - Task 4
 * @param num1
 * @param num2
 * @param opr
 */
void mini_calculator2(short num1, short num2, char opr) {
	double result;
	bool err = false;

	switch (opr) {
	case ('+'):
		result = num1 + num2;
		break;
	case ('-'):
		result = num1 - num2;
		break;
	case ('*'):
		result = num1 * num2;
		break;
	case ('/'):
		if (num2 == 0)
			err = true;
		else
			result = num1 / ((double) num2);
		break;
	case ('%'):
		if (num2 == 0)
			err = true;
		else
			result = num1 % num2;
		break;
	case ('^'):
		result = pow(num1, num2);
		break;
	default:
		err = true;
		break;

	}
	if (err)
		printf("%d %c %d = ERROR\n", num1, opr, num2);
	else if ((result > 0 && (result - INT_MAX) > 0)
			|| (result < 0 && (result + INT_MAX) < 0))
		printf("%d %c %d = OVERFLOW\n", num1, opr, num2);
	else if (fmod(result, 1) != 0)
		printf("%d %c %d = %.4f\n", num1, opr, num2, result);
	else
		printf("%d %c %d = %.0f\n", num1, opr, num2, result);
	return;
}
