#version 440 core

uniform vec2 windowSize;
uniform sampler2D textureSampler;
uniform float colorInterpolation;
uniform vec3 colorA;
uniform vec3 colorB;
uniform vec3 sourceLight;
uniform vec3 forwardCamera;

in vec2 uvsFragmentShader;
in vec4 normalsFragmentShader;
in vec4 primitivePosition;

out vec4 fragColor;

void main() {
        
        vec2 adjustedTexCoord = vec2(uvsFragmentShader.x, 1.0 - uvsFragmentShader.y);
        vec4 baseColor = texture(textureSampler, adjustedTexCoord);  

        vec3 lineToLight = normalize(sourceLight - primitivePosition.xyz); 
        float sourceLightAngle = dot(lineToLight, normalize(-forwardCamera)); 
        vec3 ambientColor = vec3(1,1,1);

        float distance = length(primitivePosition.xyz - sourceLight);
        float intensity = 1 / (distance * distance);
        
        float distance2D = length(primitivePosition.xy - sourceLight.xy);

        float multy = 2; 
   
        if(distance2D < 0.6)
        {
            multy *= 4; 
        }
        else if(distance2D < 0.8)
        {
            multy *= 2;
        }


        if(sourceLightAngle > 0.976 && sourceLightAngle < 0.986)
        fragColor =  vec4(baseColor.rgb * ambientColor.rgb, 0.3) * (sourceLightAngle / 5 * multy * intensity); 
        else if(sourceLightAngle > 0.996)
        {
          fragColor =  vec4(baseColor.rgb * ambientColor.rgb, 0.3) * (sourceLightAngle * multy * intensity); 
        }
         else if(sourceLightAngle > 0.986 && sourceLightAngle < 0.996)
        {
          fragColor =  vec4(baseColor.rgb * ambientColor.rgb, 0.3) * (sourceLightAngle/ 2 * multy * intensity); 
        }


}
