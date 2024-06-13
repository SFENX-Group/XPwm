#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <qobject.h>
#include <qobjectdefs.h>

#include <QIcon>
#include <QString>

class Platform : public QObject {
    Q_OBJECT
  public:
    explicit Platform(QString name, QIcon icon) : m_name(std::move(name)), m_icon(std::move(icon)) {}
    [[nodiscard]] const QIcon icon() const { return m_icon; }
    [[nodiscard]] const QString name() const { return m_name; }

  private:
    QString m_name;
    QIcon m_icon;
};

// Platform base template
template <typename T>
class PlatformTemplate : public Platform {
  public:
    PlatformTemplate() : Platform(T::name(), QIcon(T::iconPath())) {}
};

#endif  // PLATFORM_HPP