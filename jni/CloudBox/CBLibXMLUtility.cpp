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
#include "CBAchievementItem.h"
#include "CBAchievements.h"
#include "CBConvert.h"
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
    // create xml document
    xmlDocPtr doc = xmlNewDoc(BAD_CAST"1.0");
    xmlNodePtr root = xmlNewNode(NULL,BAD_CAST"CloudBoxRoot");
    //set root
    xmlDocSetRootElement(doc,root);

    for(map<string,string>::iterator iter = data.begin(); iter != data.end(); iter++)
    {
        cout<<"key:"<<iter->first<<"   value:"<<iter->second<<endl;
#ifdef __CBBLACKBERRY__
        xmlNewChild(root, NULL, BAD_CAST (*iter).first.c_str(), BAD_CAST (*iter).second.c_str());
#else
        xmlNewTextChild(root, NULL, BAD_CAST (*iter).first.c_str(), BAD_CAST (*iter).second.c_str());
#endif
    }
    //save xml

    int nRel = xmlSaveFile(fileName.c_str(),doc);
    if (nRel != -1)
    {
        DebugLog("Create a xml %d bytes\n",nRel);
    }

    //release
    xmlFreeDoc(doc);
    DebugLog("CBLibXMLUtility::saveWithLibXML succeed.\n");
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

CBAchievements* CBLibXMLUtility::loadAchievement( const string& fileName )
{
    CBAchievements* achievements = new CBAchievements();
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
                if(head->type == XML_TEXT_NODE)
                {
                    cout<<"Name:"<<head->name<<endl;
                    cout<<"Content:"<<xmlNodeGetContent(head->children)<<endl;
                    string name = string((char*)head->name);
                    string value = string((char*)xmlNodeGetContent(head->children));
                    if(name == "info")
                    {
                        achievements->setInfo(value);
                    }
                    else if(name == "ver")
                    {
                        achievements->setVersion(value);
                    }
                }
                else if(head->type == XML_ELEMENT_NODE)
                {
                    cout<<"Name:"<<head->name<<endl;
                    cout<<"Content:"<<xmlNodeGetContent(head->children)<<endl;
                    string key = string((char*)head->name);
                    string value = string((char*)xmlNodeGetContent(head->children));
                }
                head = head->next;
            }
        }
        xmlFreeDoc(doc);
    }
    return NULL;
}

void CBLibXMLUtility::saveAchievement( const string& fileName, CBAchievements* achievements )
{
    // create xml document
    xmlDocPtr doc = xmlNewDoc(BAD_CAST"1.0");
    xmlNodePtr root = xmlNewNode(NULL,BAD_CAST"CloudBoxAchievement");
    //set root
    xmlDocSetRootElement(doc,root);
    
    // add achievement infomation
    xmlNewTextChild(root, NULL, BAD_CAST"info", BAD_CAST achievements->getInfo().c_str());
    xmlNewTextChild(root, NULL, BAD_CAST"ver", BAD_CAST achievements->getVersion().c_str());
    
    for (std::map<string,CBAchievementItem* >::iterator it = achievements->getAchievements().begin(); it != achievements->getAchievements().end(); ++it)
    {
        string key = it->first;
        CBAchievementItem* item = it->second;
        xmlNodePtr itemNode = xmlNewNode(NULL,BAD_CAST"AchievementItem");
        xmlNewTextChild(itemNode, NULL, BAD_CAST "id", BAD_CAST item->getId().c_str());
        xmlNewTextChild(itemNode, NULL, BAD_CAST "description", BAD_CAST item->getDescription().c_str());
        xmlNewTextChild(itemNode, NULL, BAD_CAST "current_value", BAD_CAST CBConvert::toCString(item->getCurrentValue()));
        xmlNewTextChild(itemNode, NULL, BAD_CAST "target_value", BAD_CAST CBConvert::toCString(item->getTargetValue()));
        xmlNewTextChild(itemNode, NULL, BAD_CAST "completed", BAD_CAST CBConvert::toCString(item->getIsComplete()));
        xmlAddChild(root, itemNode);
    }
    
    //save xml
    int nRel = xmlSaveFile(fileName.c_str(),doc);
    if (nRel != -1)
    {
        DebugLog("Create a xml %d bytes\n",nRel);
    }
    
    //release
    xmlFreeDoc(doc);
    DebugLog("CBLibXMLUtility::saveWithLibXML succeed.\n");
}