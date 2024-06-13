#ifndef CREATEENCRYPTEDFILE_HPP
#define CREATEENCRYPTEDFILE_HPP

#include <qglobal.h>
#include <qobject.h>
#include <qobjectdefs.h>

class CreateEncryptedFile : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(CreateEncryptedFile)
  public:
    explicit CreateEncryptedFile(const QString &fileName, const QString &masterPassword, QObject *base = nullptr);
    ~CreateEncryptedFile() override = default;

  private:
    QByteArray getDefaultJSON(const QString &fileName);
};

#endif  // CREATEENCRYPTEDFILE_HPP