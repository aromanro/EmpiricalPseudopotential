#pragma once

#include <string>
#include <unordered_map>

#include "Pseudopotential.h"

namespace EmpiricalPseudopotential
{

	class Material
	{
	public:
		Material() = default;
		Material(const std::string& Name, double a, double V3S, double V8S, double V11S, double V3A = 0, double V4A = 0, double V11A = 0);

		std::string name;

		double m_a = 0;

		Pseudopotential pseudopotential;
	};


	class Materials
	{
	public:
		Materials();

		const Material& getMaterial(const std::string& matName) const;

	protected:
		std::unordered_map<std::string, Material> materials;
	};

}