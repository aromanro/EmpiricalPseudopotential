#pragma once

#include <vector>
#include <atomic>

#include "Vector3D.h"

#include "Material.h"
#include "SymmetryPoints.h"

namespace EmpiricalPseudopotential
{

	class BandStructure
	{
	public:
		BandStructure();

		Materials materials;
		SymmetryPoints symmetryPoints;

		std::vector<std::vector<double>> results;
		std::vector<unsigned int> symmetryPointsPositions;

		void Initialize(std::vector<std::string> path, unsigned int nrPoints = 600,  unsigned int nearestNeighborsNumber = 10);
		std::vector<std::vector<double>> Compute(const Material& material, unsigned int startPoint, unsigned int endPoint, unsigned int nrLevels, std::atomic_bool& terminate) const;

		double AdjustValues();

		unsigned int GetPointsNumber() const { return static_cast<unsigned int>(kpoints.size()); }

		const std::vector<std::string>& GetPath() const { return m_path; }

	private:
		std::vector<std::string> m_path;

		std::vector<Vector3D<int>> basisVectors;

		std::vector<Vector3D<double>> kpoints;
		
		static bool FindBandgap(const std::vector<std::vector<double>>& results, double& maxValValence, double& minValConduction);
		bool GenerateBasisVectors(unsigned int nearestNeighborsNumber);
	};

}

