#include <iostream>
#include "Eigen/Eigen"
#include <Eigen/SVD>
#include<vector>
#include<iomanip>
#include<cmath>
#include <random>
#include <ctime>


double condA(const Eigen::MatrixXd& A)
{
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
  Eigen::VectorXd singularValuesA = svd.singularValues();
  return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}


Eigen::VectorXd GradienteConiugato(const Eigen::MatrixXd& A,const Eigen::VectorXd& b, double res_tol, unsigned int it_max, unsigned int& it){
	int n=A.rows();
	Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
	Eigen::VectorXd res = b - A * x;
	double res_norm_0 = res.norm();
	Eigen::VectorXd p=res;
	it=0;
	while (it<it_max && (res.norm()/res_norm_0) > res_tol){
			
		double alfa=p.dot(res)/p.dot(A*p);
		x+= alfa*p;
		res= res-alfa*(A*p);
		double beta=p.dot(A*res)/p.dot(A*p);
		p= res-beta*p;
		it++;
	}
	return x;
}


int main(int argc, char **argv){
  srand(static_cast<unsigned int>(time(nullptr)));


  const double tol = 1.0e-15;
  const unsigned int it_max=10000;
  const double res_tol = 1.0e-12;
  std::vector<unsigned int> dimensioni={3,5,10,20,50,100};
  
  std::cout << "=========================================================================\n";
  std::cout << "   N   |   Cond(A)    |  Iterazioni  |  Residuo Rel.  |   Errore Rel.    \n";
  std::cout << "=========================================================================\n";
  
  for(unsigned int n : dimensioni){

	Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

	if (std::abs(B.determinant()) < tol){
		std::cout<<" Errore,matrice B singolare per N= "<<n<<"\n";
		continue;
	}

	Eigen::MatrixXd A = B.transpose() * B;
	Eigen::VectorXd x_sol = Eigen::VectorXd::Ones(n);

	Eigen::VectorXd b = A * x_sol;
	unsigned int it=0;
	Eigen::VectorXd x=GradienteConiugato(A ,b ,res_tol ,it_max ,it);
	
	double condizionamento=condA(A);
	
	Eigen::VectorXd res_finale=b-A*x;
	double res_norm_0=(b-A*Eigen::VectorXd::Zero(n)).norm();
	double res_rel=res_finale.norm()/res_norm_0;
	
	double err_rel;
	if(x_sol.norm()==0.0){
		err_rel=(x-x_sol).norm();
	}else {
		err_rel=((x-x_sol).norm()/x_sol.norm());
	}
	std::cout << std::setw(6) << n << " | "
          << std::scientific << std::setprecision(2)
          << std::setw(12) << condizionamento << " | "
          << std::setw(12) << it << " | "
          << std::setw(14) << res_rel << " | "
          << std::setw(14) << err_rel << "\n";
  }
  return 0;
}

	
	

  

  

	/*std::cout.precision(2);
  std::cout<< std::scientific<< "Matrix Cond: "<< condA(A)<< std::endl;

  

  std::cout.precision(4);
  std::cout<< std::scientific<< "it"<< "/"<< "it_max"<< "\n";
  std::cout<< std::scientific<< it<< "/"<< it_max<< "\n";
  std::cout<< std::scientific<< "res"<< "/"<< "res_tol"<< "\n";
  std::cout<< std::scientific<< res_rel.norm() / res_norm_0<< "/"<< res_tol<< "\n";
  std::cout<< std::scientific<< "err_rel"<< "\n";
  std::cout<< std::scientific<< err_rel<< "\n";
  std::cout<< std::scientific<< "soluzione"<< "\n";
  std::cout<< std::scientific<< x << "\n";*/


  
  

