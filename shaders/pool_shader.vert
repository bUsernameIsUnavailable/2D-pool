#version 400

layout(location = 0u) in vec4 in_Position;
layout(location = 1u) in vec4 in_Color;
layout(location = 2u) in vec2 texCoord;

out vec4 gl_Position; 
out vec4 ex_Color;
out vec2 tex_Coord;

uniform mat4 currentTransform;


void main()
{
    gl_Position = currentTransform * in_Position;
    ex_Color = in_Color;
    tex_Coord = vec2(texCoord.x, 1.0f - texCoord.y);
}
