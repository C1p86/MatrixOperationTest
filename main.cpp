#include <iostream>

using namespace std;

float MatrixOperation(float *A, int n, int m, int recursionIndex) {
	float result = 1;
	int* indexes = new int[recursionIndex];
	for (int i=0;i<recursionIndex;++i) {
		indexes[i] = 0;
	}
	indexes[0] = 1; //this fix the first index to 1  A(1,i)*A(i,m)
                     //                                 ^ 
	indexes[recursionIndex-1] = m;
					 
	for (int c=0; c<(n-2)^recursionIndex; ++c) { //iterate for all combination of indexes
												 // n-1 because the first index in fixed
												 // to 1 and I have not to iterate on it and the last one is fixed to m
		for (int i=0; i<recursionIndex; ++i) {   //increment index array of 1
			if (indexes[i]>=m) {
				indexes [i] = 0;
				++indexes[i+1];
			} else {
				++indexes[i];
			}
		}
		for (int step=0;step<recursionIndex-1;++step) {
			result *= A[indexes[step],indexes[step+1]];
		}
	}
	return result;

}


float FunctionName(float *A, int n, int m) {
	float result;
	
	for (int i=0; i<n-1; ++i) {
		result = MatrixOperation(A, n, m, i);
		if (result>0) {
		    return result;
		}
	}
	return -1;

}

int main()
{
    cout << "Running..." << endl;
    float A[3][3] = {1,2,3,4,5,6,7,8,9};
    float result = FunctionName(*A,3,1);
    cout << "Result: " << result << endl;
    return 0;
}

