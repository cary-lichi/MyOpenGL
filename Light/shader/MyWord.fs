#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

uniform sampler2D texture1;
uniform sampler2D texture2;
//������ɫ
uniform vec3 objectColor;
//����ɫ
uniform vec3 lightColor;
//��Դλ��
uniform vec3 lightPos;
//���λ��
uniform vec3 viewPos;
//��������ǿ��
uniform float ambientStrength;
//����ǿ��
uniform float specularStrength;
//�����
uniform int shininess;
void main()
{
	//����������ɫ
    vec3 ambient = ambientStrength * lightColor;
	//������
	vec3 norm = normalize(Normal);
	//��Դ����
	vec3 lightDir = normalize(lightPos - FragPos);
	//������
	float diff = max(dot(norm, lightDir), 0.0);
	//��������ɫ
	vec3 diffuse = diff * lightColor;
	//��Ƭ��ָ���Դλ�õ�����
	vec3 viewDir = normalize(viewPos - FragPos);
	//���淽��
	vec3 reflectDir = reflect(-lightDir, norm);
	//����ǿ��
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
	//������ɫ
	vec3 specular = specularStrength * spec * lightColor;
	//������ɫ
	vec3 result = (ambient + diffuse + specular) * objectColor;

	FragColor = vec4(result, 1.0);

}
