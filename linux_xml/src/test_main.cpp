/***************************************************************************************
    > File Name:        test_main.cpp
	> Author:           Sundae
	> Mail:
	> Created Time:     2018年08月08日 星期三 15时08分41秒
	> Description:
	> Modification:
	> Version:          V0.01
 ***************************************************************************************/
#include "xmlDocumentHandle.h"

#define fileName "text.xml"
int main(void) {
    xmlDocumentHandle  *pXMLDoc = new xmlDocumentHandle();
    pXMLDoc->setXMLName(fileName);
    if (access(fileName, F_OK) == 0) {
        std::cout << "file exist.." << std::endl;
        xmlNodePtr rootNodePtr = pXMLDoc->getRootNode("userID");
#if 0
        xmlNodePtr childNode = rootNodePtr->xmlChildrenNode;
        while(childNode != NULL) {
            if(xmlStrcmp(childNode->name, (const xmlChar *)"person") == 0) {
                std::cout << "children name " << childNode->name << " " << std::endl;
            }
            childNode = childNode->next;
        }
#endif
    } else {
        std::cout << "create file" << std::endl;
        pXMLDoc->createXMLFile();
    }
    return 1;
}
