#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in vec2 offset;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main() {
    vec3 translatedPos = aPos + vec3(offset.x, 0.0, offset.y);
    gl_Position = projection * view * model * vec4(translatedPos, 1.0);
    TexCoord = aTexCoord;
}
