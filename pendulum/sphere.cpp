// sphere.cpp
#include "sphere.hpp"

#include <vector>
#include <cmath>

void Sphere::create(GLuint program) {
  m_program = program;

  std::vector<glm::vec3> positions;
  std::vector<GLuint> indices;

  const unsigned int X_SEGMENTS = 32;
  const unsigned int Y_SEGMENTS = 32;
  const float PI = 3.14159265359f;

  for (unsigned int y = 0; y <= Y_SEGMENTS; ++y) {
    for (unsigned int x = 0; x <= X_SEGMENTS; ++x) {
      float xSegment = static_cast<float>(x) / X_SEGMENTS;
      float ySegment = static_cast<float>(y) / Y_SEGMENTS;
      float xPos = std::cos(xSegment * 2.0f * PI) * std::sin(ySegment * PI);
      float yPos = std::cos(ySegment * PI);
      float zPos = std::sin(xSegment * 2.0f * PI) * std::sin(ySegment * PI);

      positions.emplace_back(xPos, yPos, zPos);
    }
  }

  bool oddRow = false;
  for (unsigned int y = 0; y < Y_SEGMENTS; ++y) {
    if (!oddRow) {
      for (unsigned int x = 0; x <= X_SEGMENTS; ++x) {
        indices.push_back(y * (X_SEGMENTS + 1) + x);
        indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
      }
    } else {
      for (int x = X_SEGMENTS; x >= 0; --x) {
        indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
        indices.push_back(y * (X_SEGMENTS + 1) + x);
      }
    }
    oddRow = !oddRow;
  }
  m_indicesCount = static_cast<int>(indices.size());

  // Generate buffers
  glGenVertexArrays(1, &m_VAO);
  glGenBuffers(1, &m_VBO);
  glGenBuffers(1, &m_EBO);

  glBindVertexArray(m_VAO);

  glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
  glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(glm::vec3), positions.data(), GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

  // Position attribute
  GLint positionAttribute = glGetAttribLocation(m_program, "inPosition");
  glEnableVertexAttribArray(positionAttribute);
  glVertexAttribPointer(positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), nullptr);

  glBindVertexArray(0);
}

void Sphere::paint() {
  glBindVertexArray(m_VAO);
  glDrawElements(GL_TRIANGLE_STRIP, m_indicesCount, GL_UNSIGNED_INT, nullptr);
  glBindVertexArray(0);
}

void Sphere::destroy() {
  glDeleteBuffers(1, &m_VBO);
  glDeleteBuffers(1, &m_EBO);
  glDeleteVertexArrays(1, &m_VAO);
}
