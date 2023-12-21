#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

uniform float time;

out vec4 finalColor;

const vec2 size = vec2(800, 800); // window size
const float scale = 0.00005;

void main()
{
    vec2 uv = fragTexCoord.xy / (size.xy * scale);
   
    vec4 texture_color = vec4(0.192156862745098, 0.6627450980392157, 0.9333333333333333, 1.0); // Background RGBA color
    
    vec4 k = vec4(time) * 0.8;
	k.xy = uv * 7.0; // Vector k based on time and uv

    float val1 = length(0.5 - fract(k.xyw *= mat3(vec3(-2.0,-1.0,0.0), vec3(3.0,-1.0,1.0), vec3(1.0,-1.0,-1.0)) * 0.5)); // Perlin noice
    float val2 = length(0.5 - fract(k.xyw *= mat3(vec3(-2.0,-1.0,0.0), vec3(3.0,-1.0,1.0), vec3(1.0,-1.0,-1.0)) * 0.2)); // Perlin noice
    float val3 = length(0.5 - fract(k.xyw *= mat3(vec3(-2.0,-1.0,0.0), vec3(3.0,-1.0,1.0), vec3(1.0,-1.0,-1.0)) * 0.5)); // Perlin noice

    vec4 color = vec4 ( pow(min(min(val1,val2),val3), 7.0) * 3.0) + texture_color; // Final color

    finalColor = color; // output color
}