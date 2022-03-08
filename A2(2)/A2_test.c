/**
 -------------------------
 CP264 (Spring 2020)
 Assignment: A2
 Testing File
 -------------------------
 **/
# include <stdio.h>
# include "A2.h"
# include "matrix.h"
# define SIZE 10

void test_is_square();
void test_is_identity();
void test_is_uniform();
void test_is_unique();
void test_is_symmetric();
void test_is_binary();
void test_is_incremental();

//-------------------------------------------------------------------
int main() {

	setbuf(stdout, NULL);
	test_is_square();
	test_is_identity();
	test_is_uniform();
	test_is_unique();
	test_is_symmetric();
	test_is_binary();
	test_is_incremental();

	return 0;
}

//-------------------------------------------------------------------------
// some matrices for testing

//Matrix (a) is a valid matrix with numbers 1 to 10
int a[10][10] = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8,
		9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9,
		10 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, {
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } };

//Matrix (s3) is a valid square and symmetric matrix of size 3x3
int s3[10][10] = { { 1, 7, 3, -1, -1, -1, -1, -1, -1, -1 }, { 7, 4, 8, -1, -1,
		-1, -1, -1, -1, -1 }, { 3, 8, 6, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1 }, };

//Matrix (i2) is a valid square and identity matrix of size 2x2
int i2[10][10] = { { 1, 0, -1, -1, -1, -1, -1, -1, -1, -1 }, { 0, 1, -1, -1, -1,
		-1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, {
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1 }, };

//Matrix (i3) is a valid square and identity matrix of size 2x2
int i3[10][10] = { { 1, 0, 0, -1, -1, -1, -1, -1, -1, -1 }, { 0, 1, 0, -1, -1,
		-1, -1, -1, -1, -1 }, { 0, 0, 1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1 }, };

//Matrix (vr) is a valid vector matrix of size 1x8
int vr[10][10] = { { 1, 2, 3, 4, 5, 6, 7, 8, -1, -1 }, { -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1 }, };

//Matrix (vc) is a valid column matrix of size 10x1
int vc[10][10] = { { 1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { 2, -1, -1, -1,
		-1, -1, -1, -1, -1, -1 }, { 3, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, {
		4, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { 5, -1, -1, -1, -1, -1, -1,
		-1, -1, -1 }, { 6, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { 7, -1, -1,
		-1, -1, -1, -1, -1, -1, -1 }, { 8, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 9, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { 10, -1, -1, -1, -1, -1, -1,
				-1, -1, -1 }, };

//Matrix (vx) represent an invalid row vector
int vx[10][10] = { { -1, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, { -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1 }, };

void test_is_square() {
	printf("------------------------------\n");
	printf("Testing is_square\n");
	printf("------------------------------\n\n");

	printf("Case 1: Empty Matrix:\n");
	printf("create Empty Matrix\n");
	clear();
	print(SIZE, SIZE);
	printf("is_square = %d\n\n", is_square());

	printf("Case 2: Matrix of size 1x1:\n");
	printf("set first element to 9\n");
	set_element(0, 0, 9);
	print(SIZE, SIZE);
	printf("is_square = %d\n\n", is_square());

	printf("Case 3: Matrix of size 1x2:\n");
	printf("set second element to 9\n");
	set_element(0, 1, 9);
	print(SIZE, SIZE);
	printf("is_square = %d\n\n", is_square());

	printf("Case 4: Matrix of size 2x2:\n");
	printf("use global matrix (i2)\n");
	copy(i2);
	print(SIZE, SIZE);
	printf("is_square = %d\n\n", is_square());

	printf("Case 5: Invalid Matrix:\n");
	printf("set Last element to 9\n");
	set_element(9, 9, 9);
	print(SIZE, SIZE);
	printf("is_square = %d\n\n", is_square());

	printf("Case 6: Matrix of size 3x3:\n");
	printf("Use global matrix (s3)\n");
	copy(s3);
	print(SIZE, SIZE);
	printf("is_square = %d\n\n", is_square());

	printf("Case 7: Matrix of size 10x1:\n");
	printf("Use global matrix vc\n");
	copy(vc);
	print(SIZE, SIZE);
	printf("is_square = %d\n\n", is_square());

	printf("\n");
	return;
}

void test_is_identity() {
	printf("------------------------------\n");
	printf("Testing is_identity\n");
	printf("------------------------------\n\n");

	printf("Case 1: Empty Matrix:\n");
	printf("create Empty Matrix\n");
	clear();
	print(SIZE, SIZE);
	printf("is_identity = %d\n\n", is_identity());

	printf("Case 2: I1:\n");
	printf("setFirst element to 1\n");
	set_element(0, 0, 1);
	print(SIZE, SIZE);
	printf("is_identity = %d\n\n", is_identity());

	printf("Case 3: invalid I1:\n");
	printf("setFirst element to 0\n");
	set_element(0, 0, 0);
	print(SIZE, SIZE);
	printf("is_identity = %d\n\n", is_identity());

	printf("Case 4: I2:\n");
	printf("use global matrix (i2)\n");
	copy(i2);
	print(SIZE, SIZE);
	printf("is_identity = %d\n\n", is_identity());

	printf("Case 5: I3:\n");
	printf("use global matrix (i3)\n");
	copy(i3);
	print(SIZE, SIZE);
	printf("is_identity = %d\n\n", is_identity());

	printf("Case 6: invalid I3:\n");
	printf("Modify last identity matrix\n");
	set_element(2, 2, 2);
	print(SIZE, SIZE);
	printf("is_identity = %d\n\n", is_identity());

	printf("\n");
	return;
}

void test_is_uniform() {
	printf("------------------------------\n");
	printf("Testing is_uniform\n");
	printf("------------------------------\n\n");

	printf("Case 1: Empty Matrix:\n");
	clear();
	print(SIZE, SIZE);
	printf("is_uniform = %d\n\n", is_uniform());

	printf("Case 2: Single Element Matrix:\n");
	set_element(0, 0, 5);
	print(SIZE, SIZE);
	printf("is_uniform = %d\n\n", is_uniform());

	printf("Case 3: Uniform Vector:\n");
	set_element(0, 1, 5);
	print(SIZE, SIZE);
	printf("is_uniform = %d\n\n", is_uniform());

	printf("Case 4: Invalid Matrix:\n");
	set_element(1, 0, 5);
	print(SIZE, SIZE);
	printf("is_uniform = %d\n\n", is_uniform());

	printf("Case 5: Uniform Square Matrix 2x2\n");
	set_element(1, 1, 5);
	print(SIZE, SIZE);
	printf("is_uniform = %d\n\n", is_uniform());

	printf("Case 6: Uniform non-square Matrix 2x3\n");
	set_element(0, 2, 5);
	set_element(1, 2, 5);
	print(SIZE, SIZE);
	printf("is_uniform = %d\n\n", is_uniform());

	printf("Case 7: Non uniform 2x3 matrix\n");
	set_element(0, 2, 8);
	print(SIZE, SIZE);
	printf("is_uniform = %d\n\n", is_uniform());

	return;
}

void test_is_unique() {
	printf("------------------------------\n");
	printf("Testing is_unique\n");
	printf("------------------------------\n\n");

	printf("Case 1: Empty Matrix:\n");
	clear();
	print(SIZE, SIZE);
	printf("is_unique = %d\n\n", is_unique());

	printf("Case 2: Single Element Matrix:\n");
	set_element(0, 0, 8);
	print(SIZE, SIZE);
	printf("is_unique = %d\n\n", is_unique());

	printf("Case 3: Unique Vector:\n");
	set_element(0, 1, 6);
	set_element(0, 2, 4);
	set_element(0, 3, 2);
	print(SIZE, SIZE);
	printf("is_unique = %d\n\n", is_unique());

	printf("Case 4: Non-unique Vector:\n");
	set_element(0, 4, 8);
	print(SIZE, SIZE);
	printf("is_unique = %d\n\n", is_unique());

	printf("Case 5: Invalid Matrix:\n");
	set_element(1, 0, 5);
	print(SIZE, SIZE);
	printf("is_unique = %d\n", is_unique());
	printf("--------------------\n\n");

	printf("Case 6: Full Unique Matrix:\n");
	int counter = 1;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			set_element(i, j, counter++);
	print(SIZE, SIZE);
	printf("is_unique = %d\n\n", is_unique());

	printf("Case 7: Full Non-Unique Matrix:\n");
	set_element(1, 9, 100);
	print(SIZE, SIZE);
	printf("is_unique = %d\n", is_unique());

	printf("\n");
	return;
}

void test_is_symmetric() {
	printf("------------------------------\n");
	printf("Testing is_symmetric\n");
	printf("------------------------------\n\n");

	printf("Case 1: Empty Matrix:\n");
	clear();
	print(SIZE, SIZE);
	printf("is_symmetric = %d\n\n", is_symmetric());

	printf("Case 2: Single Element matrix:\n");
	set_element(0, 0, 8);
	print(SIZE, SIZE);
	printf("is_symmetric = %d\n\n", is_symmetric());

	printf("Case 3: Identity Matrix 3x3:\n");
	copy(i3);
	print(SIZE, SIZE);
	printf("is_symmetric = %d\n\n", is_symmetric());

	printf("Case 4: valid symmetric matrix 3x3:\n");
	copy(s3);
	print(SIZE, SIZE);
	printf("is_symmetric = %d\n\n", is_symmetric());

	printf("Case 5: invalid symmetric matrix 3x3:\n");
	set_element(0, 2, 10);
	print(SIZE, SIZE);
	printf("is_symmetric = %d\n\n", is_symmetric());

	printf("Case 6: Invalid Matrix:\n");
	set_element(2, 2, 7);
	set_element(2, 5, 10);
	print(SIZE, SIZE);
	printf("is_symmetric = %d\n\n", is_symmetric());

	printf("Case 7: a vector:\n");
	copy(vr);
	print(SIZE, SIZE);
	printf("is_symmetric = %d\n\n", is_symmetric());

	return;
}

void test_is_binary() {
	printf("------------------------------\n");
	printf("Testing is_binary\n");
	printf("------------------------------\n\n");

	printf("Case 1: Empty Matrix:\n");
	clear();
	print(SIZE, SIZE);
	printf("is_binary = %d\n\n", is_binary());

	printf("Case 2: Valid Single Element Matrix:\n");
	set_element(0, 0, 1);
	print(SIZE, SIZE);
	printf("is_binary = %d\n\n", is_binary());

	printf("Case 3: invalid Single Element Matrix:\n");
	set_element(0, 0, 4);
	print(SIZE, SIZE);
	printf("is_binary = %d\n\n", is_binary());

	printf("Case 4: Valid binary vector:\n");
	set_element(0, 0, 1);
	set_element(1, 0, 0);
	set_element(2, 0, 0);
	set_element(3, 0, 1);
	print(SIZE, SIZE);
	printf("is_binary = %d\n\n", is_binary());

	printf("Case 5: Invalid Matrix:\n");
	set_element(6, 0, 1);
	print(SIZE, SIZE);
	printf("is_binary = %d\n\n", is_binary());

	printf("Case 6: I3\n");
	copy(i3);
	print(SIZE, SIZE);
	printf("is_binary = %d\n\n", is_binary());

	printf("Case 7: Non-square binary matrix 5x4\n");
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
			set_element(i, j, j % 2);
	print(SIZE, SIZE);
	printf("is_binary = %d\n\n", is_binary());

	printf("Case 8: invalid binary matrix 5x4\n");
	set_element(2, 2, 4);
	print(SIZE, SIZE);
	printf("is_binary = %d\n\n", is_binary());

	return;
}

void test_is_incremental() {
	printf("------------------------------\n");
	printf("Testing is_incremental\n");
	printf("------------------------------\n\n");

	printf("Case 1: Empty Matrix:\n");
	clear();
	print(SIZE, SIZE);
	printf("is_incremental = %d\n\n", is_incremental());

	printf("Case 2: single element Matrix:\n");
	set_element(0, 0, 7);
	print(SIZE, SIZE);
	printf("is_incremental = %d\n\n", is_incremental());

	printf("Case 3: Valid incremental Vector:\n");
	set_element(0, 0, 7);
	set_element(0, 1, 9);
	set_element(0, 2, 10);
	set_element(0, 3, 10);
	print(SIZE, SIZE);
	printf("is_incremental = %d\n\n", is_incremental());

	printf("Case 3: Valid 2x3 incremental matrix:\n");
	clear();
	set_element(0, 0, 1);
	set_element(0, 1, 5);
	set_element(0, 2, 7);
	set_element(1, 0, 8);
	set_element(1, 1, 8);
	set_element(1, 2, 10);
	print(SIZE, SIZE);
	printf("is_incremental = %d\n\n", is_incremental());

	printf("Case 4: invalid 2x3 incremental matrix:\n");
	set_element(1, 0, 6);
	print(SIZE, SIZE);
	printf("is_incremental = %d\n\n", is_incremental());

	printf("Case 5: invalid matrix:\n");
	set_element(1, 0, 8);
	set_element(2, 0, 10);
	set_element(2, 1, 11);
	print(SIZE, SIZE);
	printf("is_incremental = %d\n\n", is_incremental());

	printf("Case 6: valid 3x3 incremental matrix:\n");
	set_element(2, 2, 11);
	print(SIZE, SIZE);
	printf("is_incremental = %d\n\n", is_incremental());

	printf("Case 7: invalid 3x3 incremental matrix:\n");
	set_element(1, 2, 7);
	print(SIZE, SIZE);
	printf("is_incremental = %d\n\n", is_incremental());

	return;
}

