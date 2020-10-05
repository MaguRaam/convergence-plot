#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>


//plotting library:
#include "matplotlibcpp.h"


//simplify the namespace:
namespace plt = matplotlibcpp;

//convergence rate
inline
double rate_of_convergence(size_t N1, double e1, size_t N2, double e2)
{
	return (log(e1) - log(e2)) / (log(N2) - log(N1)); 
}


int main()
{
	std::cout.flags( std::ios::dec | std::ios::scientific ); 
	std::cout.precision(6);

	//L2 and Linfty error vs N
	std::vector<int> 		N{32,64, 96, 128, 192};
	std::vector<double>		linfty{2.655393e-03, 2.012193e-04, 3.481511e-05, 8.542100e-06, 1.461659e-06};
	std::vector<double>		l2{1.292740e-03, 9.325463e-05, 1.575852e-05, 3.731197e-06, 8.588976e-07};

	for (int i = 1; i < N.size(); ++i) 
		std::cout<<N[i]<<"\t"<<rate_of_convergence(N[i-1], linfty[i-1], N[i], linfty[i])<<"\t"<<
							   rate_of_convergence(N[i-1], l2[i-1], 	N[i], l2[i])<<std::endl;


	//Convergence plot:
  	plt::loglog(N, l2, {{"label", "l2"}, {"marker", "o"}});
  	plt::loglog(N, linfty, {{"label", "linfty_error"}, {"marker", "o"}});
  	plt::legend();
  	plt::xlabel("N");
  	plt::ylabel("Error");
  	plt::title("Convergence");
  	plt::savefig("../convergence.png");
  	plt::show();	

	return 0;
}
