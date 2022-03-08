/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

# include <stdio.h>
# include "matrix.h"


//-----------------------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid square matrix
 * 		A square matrix is a matrix which the number of rows is the same as the number of columns
 * 		Note that an empty matrix is a square matrix of size 0x0
 */

int is_square() {
	int i;
	int j;
	int row = 0 ;
	int col = 0 ;
	int nonz =0;
	while(matrix[row][0] !=-1&&row<SIZE){
		row++;
	}
	while(matrix[0][col] !=-1&&col<SIZE){
		col++;
	}
	for (i = 0 ; i <SIZE;i++){
		for(j = 0 ; j <SIZE;j++){
			if (matrix[i][j] !=-1){
				nonz++;
				
		}
		}
		
	} 
	if (row==col && (row*col)==nonz)
		return 1;
	else
		return 0;
}
//-----------------------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid identity matrix
 * 		An identity matrix is a square matrix, all diagonal elements equal to 1,
 * 			all other elements equal to 0
 * 		Note that an empty matrix is NOT an identity matrix
 */

int is_identity() {
	int i;
	int j;
	int count =0;
	
	
	if(is_empty()==1)
		return 0;
	if (is_square==0)
		return 0;
	while(matrix[count][0] !=-1&&count<SIZE){
		count++;
	}
	
	for ( i=0;i <count  ;i++){
		for ( j=0;j <count ;j++){
			if (i==j){
					if(matrix[i][j]!=1)
						return 0;
				}else{
					if(matrix[i][j]!=0)
						return 0;
				}
			
			
		}
		
		
	} 
	
	
		return 1;
}
//---------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid uniform matrix
 * 		A uniform matrix is a matrix in which all elements are equal
 * 		Note that an empty matrix is NOT a uniform matrix
 */
int is_uniform() {
	int i;
	int j;
	int row = 0;
	int col = 0;
	int temp;
	if(is_empty()==1)
		return 0;
	
	while(matrix[row][0] !=-1&&row<SIZE){
		row++;
	}
	while(matrix[0][col] !=-1&&col<SIZE){
		col++;
	}
	temp =matrix[0][0]; 
	
	for ( i=0;i <row  ;i++){
		
		for ( j=0;j <col ;j++){
			
			if (matrix[i][j]!=temp){
				
				return 0;
			}
			
				}
			
			
		}
		
		
	
	
	
		return 1;
	
	
}
//---------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid unique matrix
 * 		A unique matrix is a matrix in which all elements have unique values
 * 			i.e. no two elements have equal value
 * 		Note that an empty matrix is NOT a unique matrix
 */

int is_unique() {
	int i;
	int j;
	int k;
	int l;
	int row =0;
	int col =0;
	
	if(is_empty()==1)
		return 0;
	
	while(matrix[row][0] !=-1&&row<SIZE){
		
		row++;
	}
	while(matrix[0][col] !=-1&&col<SIZE){
		col++;
	}
	
	for ( i=0;i <row  ;i++){
		
		for ( j=0;j <col ;j++){
			
			for ( k=0;k <row;k++){
				
				for ( l=0;l <col ;++l){
					
					if (i!=k || j!=l){ 
						
						if (matrix[i][j]==matrix[k][l])
							return 0;
					}		
				}
			}
		}
	}
	
			
	return 1;
}

//---------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid symmetric matrix
 * 		A symmetric matrix is a matrix which equals to its transpose
 * 		Note that an empty matrix is a VALID symmetric matrix
 */
int is_symmetric() {
	int i;
	int j;
	int row = 0;
	int col = 0;
	
	if(is_square()==0)
		return 0;
	
	while(matrix[row][0] !=-1&&row<SIZE){
		row++;
	}
	while(matrix[0][col] !=-1&&col<SIZE){
		col++;
	}
	
	for ( i=0;i <row;i++){
		
		for ( j=0;j <col;j++){
			
			if (i!=j&&matrix[i][j]!=matrix[j][i]){
				
				return 0;
			}
			
		} 
			
			
	}
		
		
	
	
	
		return 1;
	
}

//---------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid binary matrix
 * 		A binary matrix is a matrix which all of its elements are equal to either 1 or 0
 * 		Note that an empty matrix is NOT a binary matrix
 */
int is_binary() {
	int i;
	int j;
	int row = 0;
	int col = 0;
	int count =0; 
	
	if(is_empty()==1)
		return 0;
	
	while(matrix[row][0] !=-1&&row<SIZE){
		row++;
	}
	while(matrix[0][col] !=-1&&col<SIZE){
		col++;
	}
	for ( i=0;i <SIZE  ;i++){
		
		for ( j=0;j <SIZE ;j++){
			if (matrix[i][j]!=-1)
				count++;
		}
	}
	if(count !=row*col)
		return 0;
	
	for ( i=0;i <row  ;i++){
		
		for ( j=0;j <col ;j++){
			
			if (matrix[i][j]!=0&&matrix[i][j]!=1){
				
				return 0;
			}
			
				}
			
			
		}
		
		
	
	
	
		return 1;
	
	
}

//---------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid incremental matrix
 * 		An incremental matrix is:
 * 		a matrix which every element is greater than or equal to the one before it
 * 		Order: left to right, then top to bottom.
 */
int is_incremental() {
	int i;
	int j;
	int row = 0;
	int col = 0;
	int temp;
	if(is_empty()==1)
		return 0;
	
	while(matrix[row][0] !=-1&&row<SIZE){
		row++;
	}
	while(matrix[0][col] !=-1&&col<SIZE){
		col++;
	}
	temp =matrix[0][0]; 
	
	for ( i=0;i <row  ;i++){
		
		for ( j=0;j <col ;j++){
			
			if (matrix[i][j]<temp){
				
				return 0;
			}
			temp = matrix[i][j];
				}
			
			
		}
		
		
	
	
	
		return 1;
	
	
}
