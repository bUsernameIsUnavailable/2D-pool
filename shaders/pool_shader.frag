#version 400

in vec4 ex_Color;
in vec2 tex_Coord;

out vec4 out_Color;

uniform int colourCode;
uniform sampler2D poolTexture;


void main()
{
    switch (colourCode) {
        case 1:
            out_Color = texture(poolTexture, tex_Coord);
            break;

        default:
            out_Color = ex_Color;
    }
}
