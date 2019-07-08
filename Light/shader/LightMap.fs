#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform vec3 viewPos;//相机位置

//uniform vec3 objectColor;//物体颜色
//uniform float ambientStrength;//环境光强度
//uniform float specularStrength;//镜面强度
//uniform int shininess;//反光度
//uniform vec3 lightColor;//光颜色
//uniform vec3 lightPos;//光源位置

//材质
struct Material {
    sampler2D diffuse;
	sampler2D specular;
	sampler2D emission;
    float     shininess;
}; 
uniform Material material;

//光
struct Light {
    vec3 pos;//光源位置
    vec3 ambient;//环境光照
    vec3 diffuse;//漫反射
    vec3 specular;//镜面
};
uniform Light light;


void main()
{
	//--------------环境光照颜色---------------//
    //vec3 ambient = light.ambient * material.ambient;
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));

	//-----------------漫反射---------------//
	//法向量
	vec3 norm = normalize(Normal);
	//光源方向
	vec3 lightDir = normalize(light.pos - FragPos);
	//漫反射
	float diff = max(dot(norm, lightDir), 0.0);
	//漫反射颜色
	//vec3 diffuse = light.diffuse * (diff * material.diffuse);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));

	//-----------------镜面光---------------//
	//从片段指向光源位置的向量
	vec3 viewDir = normalize(viewPos - FragPos);
	//镜面方向
	vec3 reflectDir = reflect(-lightDir, norm);
	//镜面强度
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	//镜面颜色
	//vec3 specular = light.specular * ( spec * material.specular );
	vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
	
	//发射
	vec3 emission = vec3(texture(material.emission, TexCoords));

	//-----------------真实光---------------//
	//最终颜色
	vec3 result = ambient + diffuse + specular + emission ;
	FragColor = vec4(result, 1.0);
}
