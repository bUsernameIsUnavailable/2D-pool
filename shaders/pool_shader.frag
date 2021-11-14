#version 400

in vec4 ex_Color;
in vec2 tex_Coord;

out vec4 out_Color;

uniform int colourCode;
uniform sampler2D texture;


void main()
{
    switch (colourCode) {
        case 1:
            out_Color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
            break;

        default:
            out_Color = ex_Color;
    }
}
