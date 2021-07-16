#include "functions.h"
#include "stdafx.h"
#include <cmath>


double f(double *x) {	
	return (x[0]*x[1] - 1)*(x[0]*x[1] - 1) + (x[0] - x[1] - 5)*(x[0] - x[1] - 5);
}

double fA(double *x, double *h, double A) {	
	return ((x[0] + A*h[0])*(x[1] + A*h[1]) - 1)*((x[0] + A*h[0])*(x[1] + A*h[1]) - 1) + ((x[0] + A*h[0]) - (x[1] + A*h[1]) - 5)*((x[0] + A*h[0]) - (x[1] + A*h[1]) - 5);
}

double dfdx1(double *x) {	
	return 2*x[0] - 2*x[1] + 2*x[1]*(x[0]*x[1] - 1) - 10;
}

double dfdx2(double *x) {	
	return 2*x[1] - 2*x[0] + 2*x[0]*(x[0]*x[1] - 1) + 10;
}


double ScalarProduct(double *a, double *b, int n) {
	double res = 0;
	for (int i = 0; i < n; i++) {
		res = res + a[i]*b[i];
	}
	return res;
} 

double Stop1(double *x, double *X, int n) {	
	double res = 0;
	for (int i = 0; i < n; i++) {
		res = res + (x[i] - X[i])*(x[i] - X[i]);
	}
	res = sqrt(res);
	return res;
} 

double Stop2(double *X, int n) {	
	double res = 0;
	double *grad = new double[n];
	grad[0] = dfdx1(X);
	grad[1] = dfdx2(X);
	//grad[2] = dfdx3(X);
	for (int i = 0; i < n; i++) {
		res = res + grad[i]*grad[i];
	}
	res = sqrt(res);
	return res;
}

	double Alpha(double *x, double *h) {
	double l = 3, H = 5, length; // l - требуемая длина отрезка неопределенности; H - шаг; length - вычисленная длина отрезка неопределенности
	int k = 0;
 
	double X[4]; // массив, в котором хранятся координаты А (длины шага спуска)
	X[0] = 0;
	X[1] = X[0] + H; 

	// Отделение отрезка неопределенности методом удвоения шага

	while (fA(x, h, X[1]) >= fA(x, h, X[0])) {
		H = 0.5*H;
		X[1] = X[0] + H;
	}
	
	while(fA(x, h, X[1]) < fA(x, h, X[0])) {
		H = 2*H;
		X[0] = X[1];
		X[1] = X[0] + H;
	}

	length = abs(X[1]-(X[0]- H/2.));
		if (abs(length) > l) {
			X[0] = X[0] - H/2.;
			H = 0.5;
		    X[1] = X[0] +  H;
	  
		    while(abs(length) > l) {
				while (fA(x, h, X[1]) >= fA(x, h, X[0])) {
			    H = H*0.5;
			    X[1] = X[0] + H;
		    }
		    while(fA(x, h, X[1]) < fA(x, h, X[0])) {
		        H = 2*H;
			    X[0] = X[1];
			    X[1] = X[0] + H;
		    }
		    length = abs(X[1]-(X[0] - H/2.));
			//cout << "!" << length << endl;
	    }
	}

	// Нахождение точки минимума с заданной степенью точности методом квадратичной аппроксимации

	double t23, t31, t12, s23, s31, s12, x_ext[2]; // x_ext - предполагемый экстремум
	double E = 0.001; 
		
	if (X[0] < X[1]) {
		X[3] = X[1];
		X[1] = X[0] - H*0.5;
		X[2] = (X[1] + X[3])*0.5;
	}
	else {
		//X[1] = X[1];
		X[3] = X[0] - H*0.5;
		X[2] = (X[1] + X[3])*0.5;
	}
	
	 x_ext[1] = X[1];
	do {

	   x_ext[0] =  x_ext[1];
	   t23 = X[2]*X[2] - X[3]*X[3];
	   t31 = X[3]*X[3] - X[1]*X[1];
	   t12 = X[1]*X[1] - X[2]*X[2];

	   s23 = X[2] - X[3];
	   s31 = X[3] - X[1];
	   s12 = X[1] - X[2];

	   x_ext[1] = (double) 0.5*(fA(x, h, X[1])*t23 + fA(x, h, X[2])*t31 + fA(x, h, X[3])*t12) / (fA(x, h, X[1])*s23 + fA(x, h, X[2])*s31 + fA(x, h, X[3])*s12);

	if ((X[2] <= x_ext[1]) && (x_ext[1] <= X[3])) {
		if (fA(x, h, x_ext[1]) <= fA(x, h, X[2])) {
			X[1] = X[2];
	    //  X[3] = X[3];
			X[2] = x_ext[1];
		}
		else {
        //  X[1] = X[1];
			X[3] = x_ext[1];
		//	X[2] = X[2];
		}
	}

	else if ((X[1] <= x_ext[1]) && (x_ext[1] <= X[2])) {
		if (fA(x, h, x_ext[1]) <= fA(x, h, X[2])) {
		//	X[1] = X[1];
		    X[3] = X[2];
			X[2] = x_ext[1];
		}
		else {
            X[1] = x_ext[1];
		//	X[3] = X[3];
		//	X[2] = X[2];
		}
	}
	} while (abs(x_ext[1] - x_ext[0]) > E);

	return x_ext[1];
} 
void DeltaA(double *delta_x, double *delta_y, double **A_matrix, double **delta_A, int n) {

	double s = 0, scalPr;
	double **A1 = new double*[n]; // вспомогательная матрица для умножения
	for (int i = 0; i < n; i++) {
		A1[i] = new double[n];
	}

	double **A2 = new double*[n]; // вспомогательная матрица для умножения
	for (int i = 0; i < n; i++) {
		A2[i] = new double[n];
	}

	double **AT = new double*[n]; // Транспонированная матрица A(k)
	for (int i = 0; i < n; i++) {
		AT[i] = new double[n];
	}

	for (int i = 0; i < n; i++) { // Транспонирование матрицы A(k)
		for (int j = 0; j < n; j++) {
			AT[i][j] = A_matrix[j][i];
		}
	}

	double *b1 = new double[n]; // вспомогательный вектор для умножения

	// 1 слагаемое 
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) {
			delta_A[i][j] = delta_x[i]*delta_x[j];
			delta_A[i][j] = (double) delta_A[i][j] / (-1)*ScalarProduct(delta_y, delta_x, n);
		}
	}

	// 2 слагаемое
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) {
			s = s + A_matrix[i][j]*delta_y[j];
		}
		b1[i] = s;
		s = 0;
	}

	scalPr = ScalarProduct(b1, delta_y, n); 

	for (int i = 0; i < n; i++) { //+
		for (int j = 0; j < n; j++) {
			A1[i][j] = b1[i]*delta_y[j];
		}
	}

	for (int z = 0; z < n; z++) {
		 for (int i = 0; i < n; i++) {
		 	 for (int j = 0; j < n; j++) {
				 s = s + A1[z][j]*AT[j][i];
			 } 
	     A2[z][i] = (double) s / scalPr;
	     s = 0;
		 }
	}

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) {
			delta_A[i][j] = delta_A[i][j] - A2[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		delete[]A1[i];
	}
	delete[]A1;

	for (int i = 0; i < n; i++) {
		delete[]A2[i];
	}
	delete[]A2;

	for (int i = 0; i < n; i++) {
		delete[]AT[i];
	}
	delete[]AT;

	delete[]b1;
}

void GradientMethod(double *X, double *x, int n, double E) {
	double A;
	double *h = new double[n];
	do {
		for (int i = 0; i < n; i++) {
			x[i] = X[i];
		}
	// Задаем направление спуска: h(k) = gradf(x(k-))
	    h[0] = -dfdx1(x);
	    h[1] = -dfdx2(x);
		//h[2] = -dfdx3(x);

	// Находим длину шага спуска A методом одномерной минимизации
        A = Alpha(x, h);

	// Задаем новую точку X(k) = x(k-1) + A(k)*h(k)
	   for (int i = 0; i < n; i++) {
			X[i] = x[i] + A*h[i];
		}

	} while (Stop1(x, X, n) > E); // Условие остановки: || x(k-1) - x(k) || < E
	delete[]h;
}

void DFPMethod(double *X, double *x, int n, double E) {
	double sum = 0, A;
	int k = 1;
	double *delta_x = new double[n];
	double *delta_y = new double[n];
	double *h = new double[n];
	double *h_pred = new double[n];
	double **A_matrix = new double*[n];
	for (int i = 0; i < n; i++) {
		A_matrix[i] = new double[n];
	}

	double **delta_A = new double*[n]; // Добавочная матрица 
	for (int i = 0; i < n; i++) {
		delta_A[i] = new double[n];
	}

	for (int i = 0; i < n; i++) { // A1 = E (на первом шаге итерации матрица А - единичная матрица)
		for (int j = 0; j < n; j++) {
			if (i == j) A_matrix[i][j] = 1;
			else A_matrix[i][j] = 0;
		}
	}

	do {
		for (int i = 0; i < n; i++) {
			x[i] = X[i];
		}

	    // Задаем h_pred(k) = gradf(x(k-1))
	    h_pred[0] = -dfdx1(x);
	    h_pred[1] = -dfdx2(x);
		//h_pred[2] = -dfdx3(x);

		// Находим направление спуска: h(k) = A(k)*h_pred(k) = -A(k)*gradf(x(k-1))
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum = sum + A_matrix[i][j]*h_pred[j];
			}
			h[i] = sum;
			sum = 0;
		}

		// Находим длину шага спуска A методом одномерной минимизации
        A = Alpha(x, h);

		// Задаем новую точку X(k) = x(k-1) + A(k)*h(k)
		for (int i = 0; i < n; i++) {
			X[i] = x[i] + A*h[i];
		}

		// Начинаем строить добавочную матрицу
		for (int i = 0; i < n; i++) {
			delta_x[i] = X[i] - x[i]; // порядок X и х ????
		}

		delta_y[0] = dfdx1(x) - dfdx1(X);
		delta_y[1] = dfdx2(x) - dfdx2(X);
		//delta_y[2] = dfdx3(x) - dfdx3(X);

	// Построение добавочной матрицы delta_A

		if (k%n == 0) { // "Обнуление алгоритма"
			for (int i = 0; i < n; i++) { 
				for (int j = 0; j < n; j++) {
					if (i == j) A_matrix[i][j] = 1;
			        else A_matrix[i][j] = 0;
				}
			}
		}
		else { // Построение в соответствии с ДФП-методом
			for (int i = 0; i < n; i++) { 
				for (int j = 0; j < n; j++) {
					DeltaA(x, delta_y, A_matrix, delta_A, n);
					A_matrix[i][j] = A_matrix[i][j] + delta_A[i][j];
				}
			}
		}

		k++;

	} while (Stop2(X, n) > E*10); // Условие остановки: || grad(x(k)) || < E


	for (int i = 0; i < n; i++) {
		delete[]A_matrix[i];
	}
	delete[]A_matrix;

	for (int i = 0; i < n; i++) {
		delete[]delta_A[i];
	}
	delete[]delta_A;
	delete[]delta_y;
	delete[]h;
	delete[]h_pred;

}