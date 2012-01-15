#include "directory.h"

Directory::Directory(QObject *parent)
    : QObject(parent)
{
}

Directory::Directory(const QString &name, QObject *parent)
    : QObject(parent), m_name(name)
{
}

QString Directory::name() const
{
    return m_name;
}

void Directory::setName(const QString &name)
{
    if (name != m_name) {
        m_name = name;
        emit nameChanged();
    }
}
