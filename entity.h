#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>

class Entity : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString isEntry READ isEntry WRITE setIsEntry NOTIFY isEntryChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)

public:
    Entity(QObject *parent=0);
    Entity(const QString &name, const QString &isEntry, const QString &type , QObject *parent=0);

    QString name() const;
    void setName(const QString &name);

    QString type() const;
    void setType(const QString &type);

    QString isEntry() const;
    void setIsEntry(const QString &isEntry);

signals:
    void nameChanged();
    void isEntryChanged();
    void typeChanged();

private:
    QString m_name;
    QString m_isEntry;
    QString m_type;
};

#endif // ENTITY_H
