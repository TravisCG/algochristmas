#version 410

layout(location = 0) in vec2 vc;
layout(location = 1) in vec2 tc;

out vec2 texcoord;

void main(){
   gl_Position = vec4(vc, 0.0, 1.0);
   texcoord = tc;
}