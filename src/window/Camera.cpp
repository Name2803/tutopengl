#include "camera.h"
#include "window.h"

#include <glm/ext.hpp>


Camera::Camera(vec3 position, float fov) : position(position), fov(fov), rotation(1.0f) {
	updateVectors();
}

void Camera::updateVectors() {
	front = vec3(rotation * vec4(0, 0, -1, 1));
	right = vec3(rotation * vec4(1, 0, 0, 1));
	up = vec3(rotation * vec4(0, 1, 0, 1));
}

void Camera::rotate(float x, float y, float z) {
	rotation = glm::rotate(rotation, z, vec3(0, 0, 1));
	rotation = glm::rotate(rotation, y, vec3(0, 1, 0));
	rotation = glm::rotate(rotation, x, vec3(1, 0, 0));

	updateVectors();
}

mat4 Camera::getProjection() {
	
	//float width = this->width;
	//float height = this->height;

	float aspect = (float)Window::getWinWidth() / (float)Window::getWinHeight();
	return glm::perspective(fov, aspect, 0.1f, 45.0f);
}

mat4 Camera::getView() {
	return glm::lookAt(position, position + front, up);
}