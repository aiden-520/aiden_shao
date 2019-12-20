#include<opencv2/opencv.hpp>
#include<tinyxml.h>
#include<tinystr.h>



TiXmlDocument doc;
//加载文档
if (!doc.LoadFile(xml_file))
{
	std::cerr << doc.ErrorDesc() << std::endl;
	exit(1);
}
//获取根节点，也是xml文档的声明部分
TiXmlElement* root = doc.FirstChildElement();
if (root == NULL)
{
	std::cerr << "Failed to load file: No root element." << std::endl;
	doc.Clear();
	exit(1);
}
std::string xml_time;
TiXmlNode *source_node = NULL;
//查找sourceAttributes节点
source_node = root->IterateChildren("sourceAttributes", source_node);

TiXmlElement *source_elem = NULL;
source_elem = source_node->ToElement();

TiXmlNode *rawdata_node = NULL;
//查找rawDataStarTime节点
rawdata_node = source_elem->IterateChildren("rawDataStartTime", rawdata_node);
//获取该节点的文本信息。
xml_time = rawdata_node->ToElement()->GetText();
return xml_time;
