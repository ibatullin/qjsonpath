#include "qjsonpath.h"
#include "jsonpath.h"
#include <QJsonObject>

QJsonPath::QJsonPath(QQuickItem *parent)
    : QQuickItem(parent)
    , m_valid(false)
{
}


void QJsonPath::setValid(bool v)
{
    if(m_valid != v) {
        m_valid = v;
        emit validChanged(m_valid);
    }
}

bool QJsonPath::getValid() const
{
    return m_valid;
}


QString QJsonPath::getPath() const
{
    return m_path;
}

void QJsonPath::setPath(const QString &r)
{
    if(m_path != r) {
        m_path = r;
        emit pathChanged(m_path);
        update();
    }
}

QString QJsonPath::getJson() const
{
    return m_json;
}

void QJsonPath::setJson(const QString &r)
{
    if(m_json != r) {
        m_json = r;
        emit jsonChanged(m_json);
        update();
    }
}

void QJsonPath::update()
{
    try {
        if(!m_json.isEmpty() && !m_path.isEmpty()) {
            //QJsonParseError err;
            QJsonDocument doc = QJsonDocument::fromJson(m_json.toLatin1());   //, &err );
            if(! doc.isNull()) {
                QJsonObject obj = doc.object();
                QJsonValue root(obj);
                m_jsonDocument = ::JsonPath::JsonPath::Parse(root, m_path.toLatin1());
                setValid(true);
                emit jsonDocumentChanged(m_jsonDocument);
                return;
            }
        }
    } catch(...) {
    }
    setValid(false);
}

QJsonDocument QJsonPath::getJsonDocument() const
{
    return m_jsonDocument;
}

