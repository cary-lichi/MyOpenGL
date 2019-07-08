#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform vec3 viewPos;//���λ��

//uniform vec3 objectColor;//������ɫ
//uniform float ambientStrength;//������ǿ��
//uniform float specularStrength;//����ǿ��
//uniform int shininess;//�����
//uniform vec3 lightColor;//����ɫ
//uniform vec3 lightPos;//��Դλ��

//����
struct Material {
    sampler2D diffuse;
	sampler2D specular;
	sampler2D emission;
    float     shininess;
}; 
uniform Material material;

//��
struct Light {
    vec3 pos;//��Դλ��
    vec3 ambient;//��������
    vec3 diffuse;//������
    vec3 specular;//����
};
uniform Light light;


void main()
{
	//--------------����������ɫ---------------//
    //vec3 ambient = light.ambient * material.ambient;
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));

	//-----------------������---------------//
	//������
	vec3 norm = normalize(Normal);
	//��Դ����
	vec3 lightDir = normalize(light.pos - FragPos);
	//������
	float diff = max(dot(norm, lightDir), 0.0);
	//��������ɫ
	//vec3 diffuse = light.diffuse * (diff * material.diffuse);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));

	//-----------------�����---------------//
	//��Ƭ��ָ���Դλ�õ�����
	vec3 viewDir = normalize(viewPos - FragPos);
	//���淽��
	vec3 reflectDir = reflect(-lightDir, norm);
	//����ǿ��
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	//������ɫ
	//vec3 specular = light.specular * ( spec * material.specular );
	vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
	
	//����
	vec3 emission = vec3(texture(material.emission, TexCoords));

	//-----------------��ʵ��---------------//
	//������ɫ
	vec3 result = ambient + diffuse + specular + emission ;
	FragColor = vec4(result, 1.0);
}
