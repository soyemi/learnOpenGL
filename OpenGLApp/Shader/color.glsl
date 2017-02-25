#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texcoord;

out vec2 Texcoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0f);
	Texcoord = texcoord;
	Texcoord.y = 1.0- Texcoord.y;
}

@

#version 330 core
in vec2 Texcoord;
out vec4 color;

uniform sampler2D ourTexture;

void main()
{
    color = texture(ourTexture,Texcoord);
}