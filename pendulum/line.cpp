#include "line.hpp"

void Line::create(GLuint program) {
  m_program = program;

  // Generate buffers
  glGenVertexArrays(1, &m_VAO);
  glGenBuffers(1, &m_VBO);
}

void Line::paint(const glm::vec3 &start, const glm::vec3 &end) {
  std::array<glm::vec3, 2> vertices = {start, end};

  glBindVertexArray(m_VAO);
  glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_DYNAMIC_DRAW);

  // Position attribute
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

  glDrawArrays(GL_LINES, 0, 2);

  // Disable the vertex attribute array
  glDisableVertexAttribArray(0);

  glBindVertexArray(0);
}

void Line::destroy() {
  glDeleteBuffers(1, &m_VBO);
  glDeleteVertexArrays(1, &m_VAO);
}
