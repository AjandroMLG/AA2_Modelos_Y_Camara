#version 440 core

uniform vec2 windowSize;
uniform sampler2D textureSampler;

uniform float colorInterpolation;
uniform vec3 colorA;
uniform vec3 colorB;

uniform bool activeLight;
uniform bool day;

uniform vec3 cameraPosition;
uniform vec3 forwardCamera;

uniform vec3 sunPosition;

in vec2 uvsFragmentShader;
in vec4 normalsFragmentShader;
in vec4 primitivePosition;

out vec4 fragColor;

int flashLightDistance = 20;
float lightForce;

void main() {
        
        vec2 adjustedTexCoord = vec2(uvsFragmentShader.x, 1.0 - uvsFragmentShader.y);
        vec4 baseColor = texture(textureSampler, adjustedTexCoord);  
        vec3 ambientColor = mix(colorA, colorB, colorInterpolation);

        vec4 color;

        //OrbitLight
        vec3 sunToObject = normalize(sunPosition - primitivePosition.xyz);
        float sunLightAngle = dot(sunToObject, normalsFragmentShader.xyz);

        if(sunLightAngle < 0.15f)
        sunLightAngle = 0.15f;

        if(day)
        lightForce = sunLightAngle * 5;

        else
         lightForce = sunLightAngle;

        color = vec4(baseColor.rgb * ambientColor.rgb * lightForce, 1.0);

        //FlashLight
        if(activeLight)
        {
            vec3 lineToLight = normalize(cameraPosition - primitivePosition.xyz); 
            float angleFlashLight = dot(lineToLight, normalize(-forwardCamera)); 

            float distance = length(primitivePosition.xyz - cameraPosition);
            float intensity = 1 / (distance * distance);
        
            float distance2D = length(primitivePosition.xy - cameraPosition.xy);            

            float spotlightEffect = smoothstep(cos(radians(20)), cos(radians(10)), angleFlashLight) * 0.9;
      
            color += vec4(baseColor.rgb * spotlightEffect * intensity * flashLightDistance, 1.0);
        }
       

        fragColor = vec4(color.rgb, 1); 
}

