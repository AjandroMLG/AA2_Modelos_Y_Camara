#version 440 core

uniform vec2 windowSize;
uniform sampler2D textureSampler;
uniform vec4 ambientColor;

out vec4 fragColor;

in vec2 uvsFragmentShader;

void main() {
        vec2 adjustedTexCoord = vec2(uvsFragmentShader.x, 1.0 - uvsFragmentShader.y);
        vec4 baseColor = texture(textureSampler, adjustedTexCoord);
        fragColor = texture(textureSampler, uvsFragmentShader) * ambientColor;
}
