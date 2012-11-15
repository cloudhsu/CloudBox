/*
 *  CBLibXMLUtility.h
 *  CloudBox Cross Platform Framework
 *
 *  Created by Cloud Hsu on 2012/10/15.
 *  Copyright 2012 Cloud. All rights reserved.
 *
 */

#include "CBLibXMLUtility.h"
#ifdef __CBIOS__
#include <libxml2/libxml/parser.h>
#include <libxml2/libxml/tree.h>
#else
extern "C" {
#include <libxml/parser.h>
#include <libxml/tree.h>
}
#endif
#include "CBLibrary.h"
#include <iostream>
#include <map>
using namespace std;

CBLibXMLUtility::CBLibXMLUtility(void)
{
}

CBLibXMLUtility::~CBLibXMLUtility(void)
{
}

void CBLibXMLUtility::saveToXML(map<string,string>& data,const string& fileName)
{
    saveWithLibXML(data,fileName);
}
map<string,string> CBLibXMLUtility::loadFromXML(string fileName)
{
    map<string,string> data = loadWithLibXML(fileName);
    return data;
}

void CBLibXMLUtility::saveWithLibXML(map<string,string>& data,const string& fileName)
{
	DebugLog("CBLibXMLUtility::saveWithLibXML 1\n");
    // create xml document
    xmlDocPtr doc = xmlNewDoc(BAD_CAST"1.0");
    xmlNodePtr root = xmlNewNode(NULL,BAD_CAST"CloudBoxRoot");
    DebugLog("CBLibXMLUtility::saveWithLibXML 2\n");
    //set root
    xmlDocSetRootElement(doc,root);

    for(map<string,string>::iterator iter = data.begin(); iter != data.end(); iter++)
    {
        cout<<"key:"<<iter->first<<"   value:"<<iter->second<<endl;
        xmlNewTextChild(root, NULL, BAD_CAST (*iter).first.c_str(), BAD_CAST (*iter).second.c_str());
    }
    DebugLog("CBLibXMLUtility::saveWithLibXML 3\n");
    //save xml

    int nRel = xmlSaveFile(fileName.c_str(),doc);
    DebugLog("CBLibXMLUtility::saveWithLibXML 4\n");
    if (nRel != -1)
    {
        //cout<<"create a xml:"<<nRel<<"bytes"<<endl;
        DebugLog("Create a xml %d bytes\n",nRel);
    }

    //release
    xmlFreeDoc(doc);
    DebugLog("CBLibXMLUtility::saveWithLibXML 5\n");
}

map<string,string> CBLibXMLUtility::loadWithLibXML(string fileName)
{
    map<string,string> data;
    xmlDocPtr doc;
    xmlNodePtr root;
    // load an exist xml file.
    doc = xmlParseFile(fileName.c_str());
    if (doc != NULL )
    {
        root = xmlDocGetRootElement(doc);
        if (root != NULL) 
        { 
            // list all child of root
            xmlNodePtr head = root->children;
            while(head != NULL)
            {
                if(head->type == XML_ELEMENT_NODE)
                {
                    cout<<"Name:"<<head->name<<endl;
                    cout<<"Content:"<<xmlNodeGetContent(head->children)<<endl;
                    string key = string((char*)head->name);
                    string value = string((char*)xmlNodeGetContent(head->children));
                    data[key] = value;
                }
                head = head->next;
            }
        }
        xmlFreeDoc(doc);
    }
    return data;
}
