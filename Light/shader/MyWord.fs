#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

uniform sampler2D texture1;
uniform sampler2D texture2;
//物体颜色
uniform vec3 objectColor;
//光颜色
uniform vec3 lightColor;
//光源位置
uniform vec3 lightPos;
//相机位置
uniform vec3 viewPos;
//环境光照强度
uniform float ambientStrength;
//镜面强度
uniform float specularStrength;
//反光度
uniform int shininess;
void main()
{
	//环境光照颜色
    vec3 ambient = ambientStrength * lightColor;
	//法向量
	vec3 norm = normalize(Normal);
	//光源方向
	vec3 lightDir = normalize(lightPos - FragPos);
	//漫反射
	float diff = max(dot(norm, lightDir), 0.0);
	//漫反射颜色
	vec3 diffuse = diff * lightColor;
	//从片段指向光源位置的向量
	vec3 viewDir = normalize(viewPos - FragPos);
	//镜面方向
	vec3 reflectDir = reflect(-lightDir, norm);
	//镜面强度
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
	//镜面颜色
	vec3 specular = specularStrength * spec * lightColor;
	//最终颜色
	vec3 result = (ambient + diffuse + specular) * objectColor;

	FragColor = vec4(result, 1.0);

}
