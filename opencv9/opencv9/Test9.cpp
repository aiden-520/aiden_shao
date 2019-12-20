#include<opencv2/opencv.hpp>
#include<tinyxml.h>
#include<tinystr.h>



TiXmlDocument doc;
//�����ĵ�
if (!doc.LoadFile(xml_file))
{
	std::cerr << doc.ErrorDesc() << std::endl;
	exit(1);
}
//��ȡ���ڵ㣬Ҳ��xml�ĵ�����������
TiXmlElement* root = doc.FirstChildElement();
if (root == NULL)
{
	std::cerr << "Failed to load file: No root element." << std::endl;
	doc.Clear();
	exit(1);
}
std::string xml_time;
TiXmlNode *source_node = NULL;
//����sourceAttributes�ڵ�
source_node = root->IterateChildren("sourceAttributes", source_node);

TiXmlElement *source_elem = NULL;
source_elem = source_node->ToElement();

TiXmlNode *rawdata_node = NULL;
//����rawDataStarTime�ڵ�
rawdata_node = source_elem->IterateChildren("rawDataStartTime", rawdata_node);
//��ȡ�ýڵ���ı���Ϣ��
xml_time = rawdata_node->ToElement()->GetText();
return xml_time;
