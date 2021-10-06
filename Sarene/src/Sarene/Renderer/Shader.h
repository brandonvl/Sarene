#pragma once

#include <string>

namespace Sarene
{
	class Shader
	{
	public:
		Shader(const std::string& vertixSrc, const std::string& fragmentSrc);
		~Shader();

		void Bind() const;
		void Unbind() const;
	private:
		uint32_t m_RendererID;
	};
}