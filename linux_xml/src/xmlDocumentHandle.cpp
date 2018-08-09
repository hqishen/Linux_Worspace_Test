/***************************************************************************************
    > File Name:        xmlDocumentHandle.cpp
	> Author:           Sundae
	> Mail:
	> Created Time:     2018年08月08日 星期三 14时47分29秒
	> Description:
	> Modification:
	> Version:          V0.01
 ***************************************************************************************/
#include "xmlDocumentHandle.h"

void setNodeData(PersonInfo *info) {
    if(info == NULL) {
        return;
    }
    info->id = 18;
    sprintf(info->name, "%s", "sundae");
    sprintf(info->address, "%s", "惠州市惠城区");
    sprintf(info->phone, "%s", "888888888");
}

xmlDocumentHandle::xmlDocumentHandle()
: m_pXMLDoc(NULL)
, m_fileName("")
{

}

xmlDocumentHandle::~xmlDocumentHandle() {
    if(m_pXMLDoc != NULL)
        xmlFreeDoc(m_pXMLDoc);
    m_pXMLDoc = NULL;
}


void xmlDocumentHandle::setXMLName(std::string fileName) {
    assert(fileName.c_str());
    m_fileName = fileName;
}

std::string xmlDocumentHandle::getXMLName() {
    return m_fileName;
}

int xmlDocumentHandle::createXMLFile() {

    assert(m_fileName.c_str());
    m_pXMLDoc = xmlNewDoc(BAD_CAST"1.0");
    if(m_pXMLDoc == NULL) {
        fprintf(stderr, "failed to new doc.\n");
        return -1;
    }
    xmlNodePtr rootNode = NULL;

    rootNode = xmlNewNode(NULL, BAD_CAST"userID");
    if(rootNode == NULL) {
        fprintf(stderr, "failed to new node. \n");
        return -1;
    }
    //将节点添加到文件中
    xmlDocSetRootElement(m_pXMLDoc, rootNode);
    createXMLRootNode(rootNode);
    //将文档保存到文件中，按照utf-8编码格式进行保存
    xmlSaveFormatFileEnc(m_fileName.c_str(), m_pXMLDoc, "UTF-8", 1);
    return 0;
}

int xmlDocumentHandle::createXMLRootNode(xmlNodePtr node) {
    assert(node);
    PersonInfo *pInfo = (PersonInfo *)malloc(sizeof(PersonInfo));
    if(pInfo == NULL) {
        fprintf(stderr, "Failed to malloc memory .");
        return -1;
    }
    setNodeData(pInfo);
    xmlNodePtr childNode = createObjectNode(pInfo);
    if(childNode == NULL) {
        fprintf(stderr, "Failed to malloc memory .\n");
        return -1;
    }

    xmlAddChild(node, childNode);
    free(pInfo);
    return 0;
}

xmlNodePtr xmlDocumentHandle::createObjectNode(PersonInfo *node) {
    assert(node);
    xmlNodePtr xNodePtr = xmlNewNode(NULL, BAD_CAST"person");
    if(xNodePtr == NULL) {
        fprintf(stderr, "Failed to create new node. \n");
        return NULL;
    }
    char id[3] = {0};
    sprintf(id, "%d", node->id);
    xmlNewProp(xNodePtr, BAD_CAST"id", (xmlChar*)id);
    xmlNewChild(xNodePtr, NULL, BAD_CAST"name", (xmlChar*)node->name);
    xmlNewChild(xNodePtr, NULL, BAD_CAST"address", (xmlChar*)node->address);
    xmlNewChild(xNodePtr, NULL, BAD_CAST"phone", (xmlChar*)node->phone);

    return xNodePtr;
}


void xmlDocumentHandle::processXML(xmlNodePtr node, xmlDocPtr doc) {
    node = node->xmlChildrenNode;
    while(node != NULL) {
        std::cout << "name " << node->name << std::endl;
        //xmlChar * data = xmlNodeGetContent(node);
        //std::cout << data << std::endl;
        //xmlFree(data);
        if(xmlStrcmp(node->name , (const xmlChar*)"text")) {
            xmlNodeSetContent(node, (const xmlChar *)"8899");
            xmlSaveFile(m_fileName.c_str(), m_pXMLDoc);
        }
        node = node->next;
    }
}

xmlNodePtr xmlDocumentHandle::getRootNode(const char *rootNodeName) {

    if(m_pXMLDoc == NULL)
        m_pXMLDoc = xmlParseFile(m_fileName.c_str());

    assert(m_pXMLDoc);
    xmlNodePtr rootNode = xmlDocGetRootElement(m_pXMLDoc);
    if(rootNode == NULL) {
        fprintf(stderr, "Failed get root element . \n");
        return NULL;
    }

    if(xmlStrcmp(rootNode->name, (const xmlChar*)rootNodeName)) {
        fprintf(stderr, "Failed get root %s element . \n", rootNodeName);
        return NULL;
    }

    rootNode = rootNode->xmlChildrenNode;
    while(rootNode != NULL) {
        if((!xmlStrcmp(rootNode->name, (const xmlChar *)"person"))) {
            xmlChar* id = xmlGetProp(rootNode, (const xmlChar*)"id");
            //std::cout << "xml id is " << id << std::endl;
            //std::cout << xmlNodeGetContent(rootNode) << std::endl;
            processXML(rootNode, m_pXMLDoc);
            //xmlNodePtr child = rootNode->xmlChildrenNode;
            //if((!xmlStrcmp(child->name, (const xmlChar *)"name"))) {
                //std::cout << child->name << std::endl;
            //}
        }
        rootNode = rootNode->next;
    }

    return rootNode;
}

