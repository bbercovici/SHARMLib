#include <SHARMLib.hpp>
#include <armadillo>

int main(){

	std::cout << "Found SHARMLib! \n";


	arma::mat Cnm2f(1,1);
	arma::mat Snm2f(1,1);

	int n_degree =0;
	double ref_radius = 1;
	double polygon_mass = 1;
	double density = 1;
	double total_mass = 1;

	double r0[3] = {1,1,1};
	double r1[3] = {1,1,1};
	double r2[3] = {1,1,1};

	bool normalized = true;


	SHARMLib::ComputePolyhedralCS(Cnm2f,
		Snm2f,
		n_degree,
		ref_radius,
		polygon_mass,
		density,
		total_mass,
		r0,
		r1,
		r2,                   
		normalized);

	return 0;
}



