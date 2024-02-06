#pragma once

#include <Eigen/eigen>

#include <complex>

#include "Material.h"

namespace EmpiricalPseudopotential
{


	class Hamiltonian
	{
	public:
		Hamiltonian(const Material& material, const std::vector<Vector3D<int>>& basisVectors);

		void SetMatrix(const Vector3D<double>& k);
		void Diagonalize();

		const Eigen::VectorXd& eigenvalues() const { return solver.eigenvalues(); }

	protected:
		const Material& m_material;
		const std::vector<Vector3D<int>>& m_basisVectors;

		Eigen::MatrixXcd matrix;

		Eigen::SelfAdjointEigenSolver<Eigen::MatrixXcd> solver;
	};

}

