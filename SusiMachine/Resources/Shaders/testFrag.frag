#version 330 core
out vec4 FragColor;

in vec2 texCoords;
in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightColor;
uniform vec3 lightPosition;
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPosition - FragPos);
	float diffuse = max(dot(norm, lightDir), 0.0);

	float ambientStrength = .5;
	vec3 ambient = (ambientStrength + diffuse) * lightColor;
	vec4 result = texture(texture2, texCoords) * vec4(ambient, 1.0);

	FragColor = result;
}