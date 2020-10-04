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
template<typename T>
inline
auto rate_of_convergence(const T& e1, const T& e2)
{
	return (log(e1) - log(e2)) / log(2); 
}



int main()
{
	std::cout.flags( std::ios::dec | std::ios::scientific ) ; 
	std::cout.precision(6) ;

	//L2 and Linfty error vs N
	std::vector<int> 		N{32, 64, 128, 256};
	std::vector<double>		linfty{2.655393e-03, 2.012193e-04, 8.542100e-06, 1.995890e-07};
	std::vector<double>		l2{1.292740e-03, 9.325463e-05, 3.731197e-06, 1.273324e-07};

	for (int i = 1; i < N.size(); ++i){
		std::cout<<N[i]<<"\t"<<rate_of_convergence(linfty[i-1],linfty[i])<<"\t"<<
							   rate_of_convergence(l2[i-1],l2[i])<<std::endl;
	}



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