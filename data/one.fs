#version 410

layout (location = 0) out vec4 FragColor;

in vec2 texcoord;
uniform sampler2D img;
uniform vec4 highlight;

void main(){
   if(texcoord.x > highlight.x && texcoord.x < highlight.z && texcoord.y > highlight.y && texcoord.y < highlight.w){
      FragColor = vec4(1.0, 1.0, 1.0, 2.0) - texture(img, texcoord);
   }else{
      FragColor = texture(img, texcoord);
   }
}