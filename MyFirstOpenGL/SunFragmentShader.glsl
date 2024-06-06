#version 440 core

uniform vec2 windowSize;
uniform vec4 ambientColor;


out vec4 fragColor;

void main() {        
        fragColor =  ambientColor;
}
