#include "entity.h"

Entity::Entity(QObject *parent)
    : QObject(parent)
{
}

Entity::Entity(const QString &name,const QString &isEntry, const QString &type,QObject *parent)
    : QObject(parent), m_name(name), m_isEntry(isEntry), m_type(type)
{
}

QString Entity::name() const
{
    return m_name;
}

void Entity::setName(const QString &name)
{
    if (name != m_name) {
        m_name = name;
        emit nameChanged();
    }
}

QString Entity::isEntry() const
{
    return m_isEntry;
}

void Entity::setIsEntry(const QString &isEntry)
{
    if (isEntry != m_isEntry) {
        m_isEntry = isEntry;
        emit isEntryChanged();
    }
}

QString Entity::type() const
{
    return m_type;
}

void Entity::setType(const QString &type)
{
    if (type != m_type) {
        m_type = type;
        emit typeChanged();
    }
}
