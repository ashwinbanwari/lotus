#version 440 core
out vec4 FragColor;

in vec4 VertColor;

void main()
{
    FragColor = VertColor;
}