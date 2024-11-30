// sphere.hpp
#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "abcgOpenGL.hpp"

#include <glm/glm.hpp>

class Sphere {
 public:
  void create(GLuint program);
  void paint();
  void destroy();

 private:
  GLuint m_VAO{};
  GLuint m_VBO{};
  GLuint m_EBO{};

  int m_indicesCount{};

  GLuint m_program{};
};

#endif
