#version 440 core

uniform vec2 windowSize;
uniform sampler2D textureSampler;
uniform float colorInterpolation;
uniform vec3 colorA;
uniform vec3 colorB;
uniform vec3 sourceLight;

in vec2 uvsFragmentShader;
in vec4 normalsFragmentShader;
in vec4 primitivePosition;

out vec4 fragColor;

void main() {
        
        vec2 adjustedTexCoord = vec2(uvsFragmentShader.x, 1.0 - uvsFragmentShader.y);
        vec4 baseColor = texture(textureSampler, adjustedTexCoord);  

        vec3 lineToLight = normalize(sourceLight - primitivePosition.xyz); 
        float sourceLightAngle = dot(lineToLight, normalsFragmentShader.xyz); 
        vec3 ambientColor = mix(colorA,colorB, colorInterpolation);

        fragColor =  vec4(baseColor.rgb * ambientColor.rgb, 1.0) * sourceLightAngle; 
}
