#pragma once
#include "Shader_Manager.h"
#include "Models_Manager.h"
#include "../Core/Init/IListener.h"

namespace Managers
{
	class Scene_Manager : public Core::IListener
	{
	public:
		Scene_Manager();
		~Scene_Manager();
 
		virtual void notifyBeginFrame();
		virtual void notifyDisplayFrame();
		virtual void notifyEndFrame();
		virtual void notifyReshape(	int width,
									int height,
									int previous_width,
									int previous_height);
	private:
		Managers::Shader_Manager* shader_manager;
		Managers::Models_Manager* models_manager;
		glm::mat4 view_matrix;
		glm::mat4 projection_matrix;
		glm::mat4 LookAt(const glm::vec3& position,
						 const glm::vec3& target,
						 const glm::vec3& up);
	};
}