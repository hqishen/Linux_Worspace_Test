/***************************************************************************************
    > File Name:        xmlDocmentHandle.h
	> Author:           Sundae
	> Created Time:     2018年08月08日 星期三 14时38分57秒
	> Description:
	> Modification:     create files
	> Version:          V0.01
 ***************************************************************************************/
#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <assert.h>

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlmemory.h>

typedef struct _personInfo {
    uint8_t id;
    char    name[128];
    char    address[128];
    char    phone[128];
} PersonInfo;

class xmlDocumentHandle {

public:
    xmlDocumentHandle();
    virtual ~ xmlDocumentHandle();

    int createXMLFile();
    int parserXMLFile();

    void setXMLName(std::string filename);
    std::string getXMLName();

    int createXMLRootNode(xmlNodePtr node);
    xmlNodePtr createObjectNode(PersonInfo *info);
    xmlNodePtr getRootNode(const char *rootNodeName);
    void processXML(xmlNodePtr node, xmlDocPtr doc);


private:
    xmlDocPtr   m_pXMLDoc;
    std::string m_fileName;
};
