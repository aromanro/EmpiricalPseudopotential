#pragma once

#include <string>
#include <unordered_map>

#include "Pseudopotential.h"

namespace EmpiricalPseudopotential
{

	class Material
	{
	public:
		Material() : m_a(0) {}

		Material(const std::string& Name, double a, double V3S, double V8S, double V11S, double V3A = 0, double V4A = 0, double V11A = 0);

		std::string name;

		double m_a;

		Pseudopotential pseudopotential;
	};


	class Materials
	{
	public:
		Materials();

		const Material& getMaterial(const std::string& matName);

	protected:
		std::unordered_map<std::string, Material> materials;
	};

}