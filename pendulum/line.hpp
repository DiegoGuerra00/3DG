#ifndef LINE_HPP_
#define LINE_HPP_

#include "abcgOpenGL.hpp"
#include <glm/glm.hpp>

class Line {
 public:
  void create(GLuint program);
  void paint(const glm::vec3 &start, const glm::vec3 &end);
  void destroy();

 private:
  GLuint m_VAO{};
  GLuint m_VBO{};

  GLuint m_program{};
};

#endif
