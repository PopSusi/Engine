#version 330 core
out vec4 FragColor;

in vec2 texCoords;
in vec3 Normal;
in vec3 FragPos;

struct Material {
    float shiny;
    sampler2D specular;
    sampler2D diffuse;
}; 

struct Light {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    vec3 position;
}; 
  
uniform Material material;

uniform vec3 viewPos;
uniform Light light;

void main()
{
	// ambient
    vec3 ambient  = light.ambient  * texture(material.diffuse, texCoords).rgb;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse  = light.diffuse  * diff * texture(material.diffuse, texCoords).rgb;
    
    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = light.specular * spec * texture(material.specular, texCoords).rgb;  
        
    vec3 result = ambient + diffuse + specular;
    //FragColor = vec4(ambient, 1.0);
    FragColor = vec4(diffuse, 1.0);
    //FragColor = vec4(ambient + diffuse, 1.0);
    //FragColor = vec4(specular, 1.0);
    //FragColor = vec4(result, 1.0);
}