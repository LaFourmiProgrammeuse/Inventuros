#include "xmlcontroller.h"

XmlController::XmlController()
{

}

XmlController::XmlController(QString file_path)
{
    qDebug() << "Constructor XmlController";

    xml_file_path = file_path;

    xml_file = new QFile(file_path);
    if(!xml_file->open(QIODevice::ReadWrite | QIODevice::Text)){

        qDebug() << "Error during opening of xml file : " << file_path;
        return;
    }
    if(!document.setContent(xml_file)){

        qDebug() << "Error during associating of xml file : " << file_path;
        return;
    }

    root = document.documentElement();

    xml_file->close();

}

XmlController::~XmlController()
{
    qDebug() << "Destructor XmlController";

    delete xml_file;
}

bool XmlController::SetXmlFile(QString file_path){

    xml_file_path = file_path;

    xml_file = new QFile(file_path);
    if(!xml_file->open(QIODevice::ReadWrite | QIODevice::Text)){

        qDebug() << "Error during opening of xml file : " << file_path;
        return false;
    }
    if(!document.setContent(xml_file)){

        qDebug() << "Error during associating of xml file : " << file_path;
        return false;
    }

    root = document.documentElement();

    xml_file->close();

    return true;
}


/*void XmlController::SetDataFromTagName(QString data, QString tag_name){

    QDomNodeList l_tag_name_element;
    l_tag_name_element = root.elementsByTagName(tag_name);

    for(int i = 0; i < l_tag_name_element.size(); i++){

        QDomNode tag_name_element = l_tag_name_element.at(i);
        data = tag_name_element.firstChild().nodeValue();
    }
}*/

QStringList XmlController::GetDataFromTagName(QString tag_name){

    QStringList l_data;
    QDomNodeList l_tag_name_element;
    l_tag_name_element = root.elementsByTagName(tag_name);

    for(int i = 0; i < l_tag_name_element.size(); i++){

        QString data;
        QDomNode tag_name_element = l_tag_name_element.at(i);
        data = tag_name_element.firstChild().nodeValue();
        l_data.append(data);
    }

    return l_data;
}

QDomDocument *XmlController::GetDocument(){
    return &document;
}

bool XmlController::UpdateXmlFile(){

    QString document_string;
    document_string = document.toString();

    if(!xml_file->open(QIODevice::WriteOnly)){

        qDebug() << "Error during opening of xml file : " << xml_file_path;
        return false;
    }

    QTextStream ts(xml_file);
    ts << document_string;

    xml_file->close();

    return true;
}
