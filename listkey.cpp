#include "listkey.h"

ListKey::ListKey(QObject *parent)
    : QObject(parent)
{
}

ListKey::ListKey(const QString &value, const QString &index,QObject *parent)
    : QObject(parent), m_value(value), m_index(index)
{
}

QString ListKey::value() const
{
    return m_value;
}

void ListKey::setValue(const QString &value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged();
    }
}

QString ListKey::index() const{
    return m_index;
}

void ListKey::setIndex(const QString &index){
    if (index != m_index) {
        m_index = index;
        emit indexChanged();
    }
}
