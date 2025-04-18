#ifndef SHADER_H
#define SHADER_H
#include <GL/gl.h>
#include <GL/glew.h>
#include <fstream>
#include <string>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "util.h"

class Shader {
    public:
        unsigned int program, vertexShader, fragmentShader;
        Shader(std::string vertexFile, std::string fragmentFile) {
            std::string svSource = read_file(vertexFile);
            std::string sfSource = read_file(fragmentFile);
            const char* sSource = svSource.c_str();
            const char* fSource = sfSource.c_str();
            vertexShader = glCreateShader(GL_VERTEX_SHADER);
            fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(vertexShader, 1, &sSource, NULL);
            glCompileShader(vertexShader);
            glShaderSource(fragmentShader, 1, &fSource, NULL);
            glCompileShader(fragmentShader);
            program = glCreateProgram();
            glAttachShader(program, vertexShader);
            glAttachShader(program, fragmentShader);
            glLinkProgram(program);
            int success;
            char infoLog[512];
            glGetProgramiv(program, GL_LINK_STATUS, &success);
            if (!success) {
                glGetProgramInfoLog(program, 512, NULL, infoLog);
                std::cout << infoLog << std::endl;
            }

        }

        void SetInt(const std::string &name, int value) const {
            glUniform1i(glGetUniformLocation(program, name.c_str()), value);
        }

        void SetFloat(const std::string &name, float value) const {
            glUniform1f(glGetUniformLocation(program, name.c_str()), value);
        }

        void SetBool(const std::string &name, bool value) const {
            glUniform1i(glGetUniformLocation(program, name.c_str()), (int) value);
        }

        void SetMat4(const std::string &name, glm::mat4 value) {
            glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
        }

        void SetVec2(const std::string &name, float x, float y) {
            glUniform2f(glGetUniformLocation(program, name.c_str()), x, y);
        }

        void use() {
            glUseProgram(program);
        }

        ~Shader() {
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);
        }
};
#endif
