
#include<iostream>
#include<vector>
using namespace std;
class Matrix{

	int rows, cols;
    int** array;
		public:
	Matrix(){
		rows = 0;
		cols = 0;
	}
	Matrix(int rows, int cols){
	 array = new int*[rows];
	 for(int i=0; i<rows; i++)
	  array[i] = new int[cols];
	  this->rows = rows;
	  this->cols = cols;
	  
	}
	void inputMatrix(){
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++)
				cin>>array[i][j];
		}
	}
	
	Matrix operator*(Matrix& m){
		if(cols != m.rows)
		 return Matrix();
		 
		 	Matrix result(this->rows, m.cols); // First matrix rows and second matrix columns
			for(int i=0; i<rows; i++){
				for(int k=0; k<m.cols; k++){
					   int sum = 0;
						for(int j=0; j<cols; j++){
					       sum += array[i][j]*m.array[j][k];
				        }
				        result.array[i][k] = sum;
				}
			}
			return result;
	}
	Matrix operator+(Matrix& m){
		if(m.rows!=rows || m.cols!=cols)
		return Matrix();
	   Matrix result(rows, cols); 
	   for(int i=0; i<rows; i++){
				for(int j=0; j<cols; j++)
				result.array[i][j] = array[i][j] + m.array[i][j];
			}
		return result;
	}
	Matrix operator-(Matrix& m){
		if(m.rows!=rows || m.cols!=cols)
		return Matrix();	
	   Matrix result(rows, cols);  
	   for(int i=0; i<rows; i++){
				for(int j=0; j<cols; j++)
				result.array[i][j] = array[i][j] - m.array[i][j];
			}
			return result;	
	}
	
	void print(){
		cout<<endl<<"Output:"<<endl;
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++)
			cout<<array[i][j]<<" ";
			cout<<endl;
		}
		
	}
};
Matrix applyOp(Matrix& m1, Matrix& m2, char op){
	if(op == '*')
	return m1*m2;
	if(op=='+')
	return m1+m2;
	if(op=='-')
	return m1-m2;
	
	return Matrix();
}
int main(){
   Matrix* matArray;
   int no;
   cout<<"\nEnter the number of matrix: ";
   cin>>no;
   matArray = new Matrix[no];
   
   for(int i=0; i<no; i++){
   	cout<<endl<<"Matrix "<< i + 1<<endl;
   	int rows, cols;
   	cout<<"Rows and cols"<<endl;
   	cin>>rows>>cols;
   	cout<<endl;
   	matArray[i] = Matrix(rows, cols);
   	matArray[i].inputMatrix();
   }
   char operations[no-1];
   cout<<"\nEnter the operations between matrices i.e * + - / (no of operations allowed: "<<no-1<<" )"<<endl;
   for(int i=0; i<no-1; i++)
   cin>>operations[i];
   Matrix result = matArray[0];
   for(int i=1; i<no; i++){
   	result = applyOp(result, matArray[i], operations[i-1]);
   }
   result.print();
   
   
	
}
