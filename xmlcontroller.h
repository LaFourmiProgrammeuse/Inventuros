#ifndef XMLCONTROLLER_H
#define XMLCONTROLLER_H

#include <QString>
#include <QStringList>
#include <QDomDocument>
#include <QDomElement>
#include <QFile>
#include <QDebug>
#include <QTextStream>

class XmlController
{
public:
    XmlController();
    XmlController(QString file_path);
    ~XmlController();

    bool SetXmlFile(QString file_path);

    /* Retourne la valeur de l'attribut donné en parametre */
    //QString GetValueFromAttribute(QString attribute);
    //void SetValueFromAttribute(QString value, QString attribute);

    /* Retourne le contenu de la balise résultante du chemin donné avec les nodes */
    //QString GetDataFromNodePath(QStringList node_list);
    //bool SetDataFromNodePath(QString data, QStringList node_list);

    /* Retourne les contenus des balises en fonction du nom de la balise donné en parametre */
    QStringList GetDataFromTagName(QString tag_name);
    void SetDataFromTagName(QString data, QString tag_name);

    QDomDocument *GetDocument();
    bool UpdateXmlFile();

private:
    QDomDocument document;
    QDomElement root;

    QFile *xml_file;
    QString xml_file_path;
};

#endif // XMLCONTROLLER_H
