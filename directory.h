#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <QObject>

class Directory : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    Directory(QObject *parent=0);
    Directory(const QString &name, QObject *parent=0);

    QString name() const;
    void setName(const QString &name);

signals:
    void nameChanged();

private:
    QString m_name;
};

#endif // DIRECTORY_H
